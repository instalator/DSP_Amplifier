let host = window.location.host;
let ws_url = 'ws://' + host + ':81';
let ws, ws_waiting = 0, hostname, timeout, opentimeout, parse;

function wsSendCommand(cmd){
    console.log("Send WebSocket command:", cmd);
    load(true);
    if (ws_waiting === 0){
        ws.send(cmd);
        ws_waiting++;
    } else {
        console.log("WS call waiting, skip");
        ws.send(cmd);
        ws_waiting++;
    }
    timeout = setTimeout(function (){
        load(false);
        M.toast({html: 'No response from module!'});
        ws_waiting = 0;
    }, 10000);
}

function getJson(time){
    opentimeout && clearTimeout(opentimeout);
    opentimeout = setTimeout(function (){
        if ($("#main").is(":visible") && ws.readyState === 1){
            $.getJSON("http://" + host + "/get_param", function (d){
                console.log(d);
                hostname = d.host_name;
                $("#logo-container").text(hostname);
                //$(document).prop('title', hostname);
                $(".version").text('ver. ' + d.ver);
                parse(d);
                getJson(5000);
            }).fail(function (jqxhr, textStatus, error){
                load(true);
                ws && ws.close();
                M.toast({html: 'getJSON Error - ' + textStatus + ", " + error});
                opentimeout && clearTimeout(opentimeout);
                //init();
            })
        }
    }, time);
}

function load(state){
    var element = $('.indeterminate');
    state ? element.show() :element.hide();
}

function reload(time){
    load(true);
    setTimeout(function (){
        window.location.href = window.location.href.split('#')[0];
    }, time);
}

function init(){
    ws && ws.close();
    load(true);
    console.log("Connection websockets to:", ws_url);
    ws = new WebSocket(ws_url, ['arduino']);
    ws.onopen = function (){
        console.log('WebSocket Open');
        load(false);
        getJson(1);
    };
    ws.onerror = function (){
        M.toast({html: 'WebSocket Error. Reconnect...'});
        init();
    };
    ws.onmessage = function (e){
        console.log('WebSocket from server: ' + e.data);
        if (e.data === 'OK'){
            load(false);
            timeout && clearTimeout(timeout);
        }
        ws_waiting = 0;
    };
}

$(document).ready(function (){
    $('select').not('.disabled').formSelect();
    $('.dropdown-trigger').dropdown();
    $('#settings input').characterCounter();
    $('.sidenav').sidenav();
    $('.modal').modal();
    load(true);

    $('#update_form').on('submit', function (){
        load(true);
        var form = new FormData(this);
        $.ajax({
            url:         '/update',
            method:      'POST',
            data:        form,
            contentType: false,
            processData: false
        }).done(function (r){
            load(false);
            if (r === "OK"){
                M.toast({html: 'Update Success! Rebooting...'});
                reload(1000);
            } else {
                M.toast({html: 'Update Error!' + r});
            }
        }).fail(function (){
            load(false);
            M.toast({html: 'Update Error!'});
        });
    });
    $(".restart").on("click", function (){
        wsSendCommand('Q');
        reload(5000);
    });
    $(".reset_agree").on("click", function (){
        wsSendCommand('T');
        reload(5000);
    });
    $(".save").on("click", function (){
        var obj = {
            mqtt_server:    $("#mqtt_server").val(),
            mqtt_port:      $("#mqtt_port").val(),
            mqtt_user:      $("#mqtt_user").val(),
            mqtt_pass:      $("#mqtt_pass").val(),
            mqtt_client_id: $("#mqtt_client_id").val().replaceAll(".", "_"),
            mqtt_topic:     $("#mqtt_topic").val().replaceAll(".", "_"),
            host_name:      $("#host_name").val(),
            retain:         $("#retain").prop('checked').toString(),
        };
        if (obj.mqtt_topic.slice(-1) !== '/'){
            obj.mqtt_topic += '/';
        }
        wsSendCommand(JSON.stringify(obj));
        //M.toast({html: 'No response from module!'});
        setTimeout(function (){
            $('#settings_link').click();
        }, 1000);
    });
    $("#settings_link").click(function (){
        $('.sidenav').sidenav('close');
        load(true);
        $('#main').hide();
        $('#update').hide();
        $('#settings').show();
        if ($("#settings").is(":visible")){
            $.getJSON("http://" + host + "/get_settings", function (d){
                //console.log(d);
                $("#mqtt_server").val(d.mqtt_server);
                $("#mqtt_port").val(d.mqtt_port);
                $("#mqtt_user").val(d.mqtt_user);
                $("#mqtt_pass").val(d.mqtt_pass);
                $("#mqtt_client_id").val(d.mqtt_client_id);
                $("#mqtt_topic").val(d.mqtt_topic);
                $("#host_name").val(d.host_name);
                $('#retain').prop('checked', d.retain === 'true');
                load(false);
                M.updateTextFields();
            });
        }
    });
    $("#update_link").click(function (){
        $('.sidenav').sidenav('close');
        $('#main').hide();
        $('#settings').hide();
        $('#update').show();
    });
    init();
});
