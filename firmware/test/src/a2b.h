
#include "configFromSigma/adi_a2b_i2c_commandlist.h" // Положить файл из проекта SigmaStudio

/**
 * Конфигурация шины A2B, при включении, со всеми слейвами на нодах
 * Комнады инициализации слейвов добавляются в SigmaStudio в проекте A2B.
**/
static void a2b_Concat_Addr_Data(unsigned char *pDstBuf, unsigned int nAddrwidth, unsigned int nAddr) {
    switch (nAddrwidth) { /* Byte */
        case 1u:
            pDstBuf[0u] = (unsigned char) nAddr;
            break;
        case 2u: //16 bit word
            pDstBuf[0u] = (unsigned char) (nAddr >> 8u);
            pDstBuf[1u] = (unsigned char) (nAddr & 0xFFu);
            break;
        case 3u: //24 bit word
            pDstBuf[0u] = (unsigned char) ((nAddr & 0xFF0000u) >> 16u);
            pDstBuf[1u] = (unsigned char) ((nAddr & 0xFF00u) >> 8u);
            pDstBuf[2u] = (unsigned char) (nAddr & 0xFFu);
            break;
        case 4u: //32 bit word
            pDstBuf[0u] = (unsigned char) (nAddr >> 24u);
            pDstBuf[1u] = (unsigned char) ((nAddr & 0xFF0000u) >> 16u);
            pDstBuf[2u] = (unsigned char) ((nAddr & 0xFF00u) >> 8u);
            pDstBuf[3u] = (unsigned char) (nAddr & 0xFFu);
            break;
        default:
            break;
    }
}

static void a2b_init() {
    ADI_A2B_DISCOVERY_CONFIG *pOPUnit;
    unsigned int nIndex, nIndex1;
    //unsigned int status;
    /* Maximum number of writes */
    static unsigned char aDataBuffer[6000];
    static unsigned char aDataWriteReadBuf[4u];
    unsigned int nDelayVal;
    for (nIndex = 0; nIndex < CONFIG_LEN; nIndex++) {
        pOPUnit = &gaA2BConfig[nIndex];
        switch (pOPUnit->eOpCode) {
            case WRITE:
                a2b_Concat_Addr_Data(&aDataBuffer[0u], pOPUnit->nAddrWidth, pOPUnit->nAddr);
                (void) memcpy(&aDataBuffer[pOPUnit->nAddrWidth], pOPUnit->paConfigData, pOPUnit->nDataCount);
                a2b_I2C_Write(pOPUnit->nDeviceAddr, (pOPUnit->nAddrWidth + pOPUnit->nDataCount), &aDataBuffer[0u]);
                break;
            case READ:
                (void) memset(&aDataBuffer[0u], 0u, pOPUnit->nDataCount);
                a2b_Concat_Addr_Data(&aDataWriteReadBuf[0u], pOPUnit->nAddrWidth, pOPUnit->nAddr);
                delay(2); // Couple of milliseconds should be OK
                break;
            case DELAY:
                nDelayVal = 0u;
                for (nIndex1 = 0u; nIndex1 < pOPUnit->nDataCount; nIndex1++) {
                    nDelayVal = pOPUnit->paConfigData[nIndex1] | nDelayVal << 8u;
                }
                delay(nDelayVal);
                break;
            default:
                break;
        }
    }
}
