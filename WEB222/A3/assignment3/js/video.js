// Data for the "HTML Video" Page

var video = {
    controls: true,
    width: 320,
    height: 240,
    source: [
        { src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.mp4", type: "video/mp4" },
        { src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.ogg", type: "video/ogg" },
        { src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.webm", type: "video/webm" }
    ]
};

window.onload = function () {
    var vid = document.querySelector("#video");
    var vid2 = "<figure><video ";
    var vid1;
    var i;
    for (i = 0; i < video.source.length; i++) {
        vid1 += '<source src ="' + video.source[i].src + '" type="' + video.source[i].type + '">';
    }
    if (video.controls == true) {
        vid2 += 'width = "' + video.width + '" height = "' + video.height + '" controls>' + vid1;

    } else {
        vid2 += '>' + vid1;
    }
    vid2 += '</video></figure>';
    vid.innerHTML += vid2;
} 