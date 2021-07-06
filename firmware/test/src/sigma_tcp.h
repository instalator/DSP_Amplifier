
#define CMD_WRITE   0x09
#define CMD_READ    0x0A
#define CMD_RESP    0x0B

uint16_t u8to16(uint8_t *u8) {
    return (*u8 << 8) | *(u8 + 1);
}

uint32_t u8to32(uint8_t *u8) {
    return (u8to16(u8) << 16) | u8to16(u8 + 2);
}

void u16to8(uint8_t *u8, uint16_t u16) {
    u8[0] = (u16 >> 8) & 0xff;
    u8[1] = (u16 >> 0) & 0xff;
}

void u32to8(uint8_t *u8, uint32_t u32) {
    u8[0] = (u32 >> 24) & 0xff;
    u8[1] = (u32 >> 16) & 0xff;
    u8[2] = (u32 >> 8) & 0xff;
    u8[3] = (u32 >> 0) & 0xff;
}

struct adauWriteHeader_s {
    uint8_t controlBit;
    uint8_t safeload;
    uint8_t channelNum;
    uint8_t totalLen[4];
    uint8_t chipAddr;
    uint8_t dataLen[4];
    uint8_t paramAddr[2];
    // follow data to be received
};
struct adauReqHeader_s {
    uint8_t controlBit;
    uint8_t totalLen[4];
    uint8_t chipAddr;
    uint8_t dataLen[4];
    uint8_t paramAddr[2];
    //uint8_t reserved[2];
};
struct adauRespHeader_s {
    uint8_t controlBit;
    uint8_t totalLen[4];
    uint8_t chipAddr;
    uint8_t dataLen[4];
    uint8_t paramAddr[2];
    uint8_t success;
    uint8_t reserved[1];
    // follow data to be sent back
};

enum STATE_ENUM {
    FSM_IDLE, \
    FSM_GOTCHAR, \
    FSM_CMD_READ, FSM_CMD_WRITE, \
    FSM_NET_WAITING_DATA, \
    FSM_I2C_WRITE, FSM_I2C_READ, \
    FSM_NET_RESP, \
    FSM_FLUSH, \
    FSM_STOP, FSM_ERR
};

//unsigned char buf[10 * 1024]; //50*1024
#define MAX_BUF_SIZE 20 * 1024
uint8_t buf[MAX_BUF_SIZE];
uint8_t *p = buf;

void check_sigma() {
    WiFiClient sigma_client = sigma_tcp.available();
    if (sigma_client) {
        ticker.attach(0.1, tick);
        //a2dp_sink.end(); //true
        web_server.stop();
        mqtt.disconnect();
        ws.close();
        IPAddress ip = sigma_client.remoteIP();
        Serial.printf("New SigmaStudio client:  %d.%d.%d.%d \n", ip[0], ip[1], ip[2], ip[3]);

        enum STATE_ENUM state = FSM_IDLE;
        int count = 0, ret = 0, dispose = 0;
        struct adauReqHeader_s *req = (struct adauReqHeader_s *) buf;
        struct adauWriteHeader_s *regWrite = (struct adauWriteHeader_s *) buf;

        while (sigma_client.connected()) {
            switch (state) {
                case FSM_IDLE:
                    while (sigma_client.available()) {
                        ret = sigma_client.read(p, MAX_BUF_SIZE - count);
                    }
                    if (ret <= 0) {
                        break;
                    } else {
                        count += ret;
                        ret = 0;
                        state = FSM_GOTCHAR;
                    }
                    break;
                case FSM_GOTCHAR:
                    if (count > 0) {
                        switch (buf[0]) {
                            case CMD_READ:
                                //printf("Start a READ transaction\n");
                                state = FSM_CMD_READ;
                                break;
                            case CMD_WRITE:
                                //printf("Start a WRITE transaction\n");
                                state = FSM_CMD_WRITE;
                                break;
                            default:
                                printf("command %x not managed for packet\n", buf[0]);
                                state = FSM_ERR;
                        }
                    }
                    break;
                case FSM_CMD_READ:
                    if (count >= sizeof(struct adauReqHeader_s)) {
                        // got enough info, send a read req
                        state = FSM_I2C_READ;
                        /*printf("read CMD: got the NET header, need to read %d byte on chip %x at param addr %d\n(0x%04x)\n",
                               u8to32(req->dataLen), req->chipAddr,
                               u8to16(req->paramAddr), u8to16(req->paramAddr));*/
                        if (u8to32(req->totalLen) != sizeof(struct adauReqHeader_s)) {
                            /*printf("read CMD: totalLen is %d when req header shoulb be %d; forcing!!\n",
                                   u8to32(req->totalLen), sizeof(struct adauReqHeader_s));*/
                            u32to8(req->totalLen, sizeof(struct adauReqHeader_s));
                        }
                    } else {
                        state = FSM_IDLE; // WAIT FOR MORE DATA..
                    }
                    break;
                case FSM_CMD_WRITE:
                    if (count >= sizeof(struct adauWriteHeader_s)) {
                        // got enough info, send a read req
                        state = FSM_NET_WAITING_DATA;
                        /*printf("write CMD: got the NET header, need to write %d bytes on chip %x at param addr %d(0x%04x)\n",
                               u8to32(regWrite->dataLen), regWrite->chipAddr,
                               u8to16(regWrite->paramAddr), u8to16(regWrite->paramAddr));*/
                        state = FSM_I2C_WRITE;
                    } else {
                        state = FSM_IDLE;
                    }
                    break;
                case FSM_NET_WAITING_DATA:
                    if (count >=
                        sizeof(struct adauWriteHeader_s) +
                        u8to32(regWrite->dataLen)) { // maybe just regWrite->totalLen?
                        state = FSM_I2C_WRITE;
                    } else {
                        state = FSM_IDLE;
                    }
                    break;
                case FSM_I2C_WRITE:
                    printf("write to I2C addr %x, param addr %d(0x%04x), huge data length: %d bytes, data 0x%08x\n",
                           regWrite->chipAddr, u8to16(regWrite->paramAddr),
                           u8to16(regWrite->paramAddr), u8to32(regWrite->dataLen),
                           u8to32(&buf[sizeof(struct adauWriteHeader_s)]));

                    dsp_I2C_Write(u8to16(regWrite->paramAddr), u8to32(regWrite->dataLen),
                                  (const uint8_t *) (&buf[sizeof(struct adauWriteHeader_s)]));

                    if (u8to32(regWrite->dataLen) + sizeof(struct adauWriteHeader_s) == u8to32(regWrite->totalLen)) {
                        dispose = u8to32(regWrite->totalLen);
                    } else {
                        printf("write req: length not matching: %d - %d\n",
                               u8to32(regWrite->dataLen) + sizeof(struct adauWriteHeader_s),
                               u8to32(regWrite->totalLen));
                    }
                    state = FSM_FLUSH;
                    break;
                case FSM_I2C_READ:
                    printf("read I2C addr %x, param %d (0x%04x), data length %d ", req->chipAddr,
                           u8to16(req->paramAddr),
                           u8to16(req->paramAddr), u8to32(req->dataLen));

                    if (u8to32(req->dataLen) < (128 - sizeof(struct adauRespHeader_s))) {
                        uint8_t bufResp[128];
                        struct adauRespHeader_s *resp = (struct adauRespHeader_s *) bufResp;
                        int respLen = dsp_I2C_Read(u8to16(req->paramAddr), u8to32(req->dataLen), bufResp,
                                                   sizeof(struct adauRespHeader_s));
                        switch (u8to32(req->dataLen)) {
                            case 2:
                                printf("returned value: 0x%04x\n", u8to16(bufResp + sizeof(struct adauRespHeader_s)));
                                break;
                            case 4:
                                printf("returned value: 0x%08x\n", u8to32(bufResp + sizeof(struct adauRespHeader_s)));
                                break;
                            default:
                                printf("returned value lonf %d bytes\n", u8to32(req->dataLen));
                        }
                        resp->controlBit = CMD_RESP;
                        u32to8(resp->totalLen, sizeof(struct adauRespHeader_s) + u8to32(req->dataLen));
                        resp->chipAddr = req->chipAddr;
                        u32to8(resp->dataLen, u8to32(req->dataLen));
                        resp->paramAddr[0] = req->paramAddr[0];
                        resp->paramAddr[1] = req->paramAddr[1];
                        resp->success = (respLen < 0) ? 1 : 0;
                        resp->reserved[0] = 0;
                        sigma_client.write((uint8_t *) bufResp, u8to32(resp->totalLen));
                    } else {
                        printf("cant manage too large reply! %d bytes", u8to32(req->dataLen));
                    }
                    if (sizeof(struct adauReqHeader_s) == u8to32(req->totalLen)) {
                        dispose = u8to32(req->totalLen) + 2;
                    } else {
                        printf("read req: disposable length not matching: %d - %d\n",
                               sizeof(struct adauWriteHeader_s),
                               u8to32(req->totalLen));
                    }
                    state = FSM_FLUSH;
                    break;
                case FSM_FLUSH:
                    count -= dispose;
                    // move the eventual new packet at the head of the buffer
                    memmove(buf, buf + dispose, count);
                    p = buf + count;
                    state = (count > 0) ? FSM_GOTCHAR : FSM_IDLE;
                    break;
                case FSM_ERR:
                    printf("bailing out..  no recover procedure now\n");
                    //state = FSM_STOP;
                    p = buf;
                    state = FSM_IDLE;
                    break;
                default:
                    printf("unmanaged state %d..  no recover procedure now\n", state);
                    //state = FSM_STOP;
                    state = FSM_IDLE;
                    break;
            }
        }
        sigma_client.stop();
        Serial.println("SigmaStudio disconnected.");
        ticker.detach();
        //ble_setup();
        fsbrowser_setup();
        websocket_setup();
    }
}

void sigma_tcp_setup() {
    sigma_tcp.begin();
    sigma_tcp.setNoDelay(true);
    sigma_tcp.setTimeout(2000);
}
