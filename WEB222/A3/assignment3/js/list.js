// Data for the "HTML Lists" Page

var fruits = ["Apples", "Oranges", "Pears", "Grapes", "Pineapples", "Mangos"];

var directory = [
    { type: "file", name: "file1.txt" },
    { type: "file", name: "file2.txt" },
    { type: "directory", name: "HTML Files", files: [{ type: "file", name: "file1.html" }, { type: "file", name: "file2.html" }] },
    { type: "file", name: "file3.txt" },
    { type: "directory", name: "JavaScript Files", files: [{ type: "file", name: "file1.js" }, { type: "file", name: "file2.js" }, { type: "file", name: "file3.js" }] }
];

function fruitLists() {
    var fLists = document.querySelector("#FruitLists");
    var fList2 = "<ol>";
    for (var i = 0; i < fruits.length; i++) {
        fList2 += '<li>' + fruits[i] + '</li>';
    }
    fList2 += '</ol>';

    fLists.innerHTML += fList2;
};
function list() {
    var file = document.querySelector("#FileLists");
    var file2 = "<ul>";
    var file3 = "<ul>";

    for (var i = 0; i < directory.length; i++) {
        file2 += '<li>' + directory[i].name + '</li>';
        if (directory[i].type == "directory") {
            for (var j = 0; j < directory[i].files.length; j++) {
                file3 += '<li>' + directory[i].files[j].name + '</li>';
            }
            file3 += '</ul>';
        }

    }

    file2 += file3 + '</ul>';
    file.innerHTML += file2;
}
window.onload = function () {
    fruitLists();
    list()

};

