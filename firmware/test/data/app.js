$(document).ready(function () {
    parse = function (d) {
        for(key in d){
            if(key[0] === 'V'){
                let el = '#knob_' + key[3] + '_' + key[5];
                $(el).val(d[key]);
                $(el).parent().parent().find('.val').text(parseFloat(d[key]).toFixed(2));
            } else if(key[0] === 'M'){
                let el = '.mute.' + (parseInt(key[3], 10) + 1);
                $(el).prop('checked', !!parseInt(d[key], 10));
            }
        }
    };

    var div = "<div class='row'> " +
        "  <div class='col s1 offset-s1 switch center'></div>" +
        "  <div class='col s1 switch center'><label> Mute 1 <input class='mute 1' type='checkbox'> <span class='lever'></span> </label></div>" +
        "  <div class='col s1 switch center'><label> Mute 2 <input class='mute 2' type='checkbox'> <span class='lever'></span> </label></div>" +
        "  <div class='col s1 switch center'><label> Mute 3 <input class='mute 3' type='checkbox'> <span class='lever'></span> </label></div>" +
        "  <div class='col s1 switch center'><label> Mute 4 <input class='mute 4' type='checkbox'> <span class='lever'></span> </label></div>" +
        "  <div class='col s1 switch center'><label> Mute 5 <input class='mute 5' type='checkbox'> <span class='lever'></span> </label></div>" +
        "  <div class='col s1 switch center'><label> Mute 6 <input class='mute 6' type='checkbox'> <span class='lever'></span> </label></div>" +
        "  <div class='col s1 switch center'><label> Mute 7 <input class='mute 7' type='checkbox'> <span class='lever'></span> </label></div>" +
        "  <div class='col s1 switch center'><label> Mute 8 <input class='mute 8' type='checkbox'> <span class='lever'></span> </label></div>" +
        "  </div>" +
        " <div class='row'>";
    div += "<div class='col s1 offset-s1 switch center'></div>";
    for(let iOut = 0; iOut < 8; iOut++){
        div += "<div class='col s1 blue-grey-text center'><span>OUTPUT " + iOut + "</span></div>";
    }
    div += "  </div><div class='row' style='margin-bottom: 0px;'>"
    for(let iIn = 0; iIn < 10; iIn++){
        div += "  <div class='row'>"
        div += "<div class='col s1 offset-s1 blue-grey-text center' style='height: 100%;margin-top: 33px'><span>INPUT " + iIn + "</span></div>";
        for(let iOut = 0; iOut < 8; iOut++){
            div += "<div class='col s1 blue-grey-text center'>" +
                    "<label>VOl "+iOut+iIn+"" +
                        "<input step='0.25' type='range' id='knob_" + iOut + "_" + iIn + "' style='margin: 0px 0;display: -webkit-inline-box;' class='input-knob' data-diameter='50' data-src='./knob70.png\'>" +
                    "</label>" +
                "   <p class='val' style='margin-top: -10px;margin-bottom: 0;'>0</p>" +
                "</div>";
        }
        div += "  </div>"
    }
    div += "  </div>";

    $("#main").html(div).promise().done(function () {
        $(".mute").on("change", function () {
            console.log($(this).prop('className'));
            var mute = parseInt($(this).prop('className').match(/\d+/));
            if ($(this).prop('checked')) {
                wsSendCommand("M" + mute + "_1");
            } else {
                wsSendCommand("M" + mute + "_0");
            }
        });
        $(".input-knob").on("input", function (){
            $(this).parent().parent().find('.val').text(this.value);
        });
        $(".input-knob").on("change", function() {
            var arr = $(this).prop('id').split('_');
            wsSendCommand("V" + arr[1] + "" + arr[2] + "_" + $(this).val());
        });
    });
});
