// Data for the "HTML Audio" Page

var audio = {
    controls: true,
    source: [
        { src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.mp3", type: "audio/mpeg" },
        { src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.ogg", type: "audio/ogg" }
    ]
};
window.onload = function () {
    var auds = document.querySelector("#audio");
    var auds2 = "";
    var auds1;
    for (var i = 0; i < audio.source.length; i++) {
        auds1 += '<source src ="' + audio.source[i].src + '" type="' + audio.source[i].type + '">';
    }
    if (audio.controls == true) {
        auds2 += '<figure><audio controls>' + auds1 + '</audio></figure>';
    } else {
        auds2 += '<figure><audio>' + auds1 + '</audio></figure>';
    }

    auds.innerHTML += auds2;
};