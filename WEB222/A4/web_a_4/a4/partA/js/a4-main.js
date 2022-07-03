
/********************************************************************************* 
*
* WEB222 – Assignment #4a
*
* I declare that this assignment is my own work in accordance with Seneca 
* Academic Policy. No part of this assignment has been copied manually or 
* electronically from any other source (including web sites) or distributed to 
* other students. 
* 
* Name: _WONHWA LEE_ Student ID: _076086149_ Date: _2019/07/17_ 
* 
********************************************************************************/

var filterType = ""; // sets the filter type to "" (will later be dog, cat or bird)
var filterAgeMin = 0; // sets the filter age min to 0 (for no minimum age filter)
var filterAgeMax = Number.MAX_VALUE; // sets the filter age max to the largest number possible (for no maximum age filter)


function loadTableWithFilters() {

    var mTable = document.querySelector("#main-table-body");
    mTable.innerHTML = "";

    for (var i = 0; i < petData.length; i++) {

        if ((filterType == "") || (filterType == "Cat" && petData[i].type == "cat") || (filterType == "Dog" && petData[i].type == "dog") || (filterType == "Birds" && petData[i].type == "bird")) {

            if (petData[i].age <= filterAgeMax && petData[i].age >= filterAgeMin) {

                var tr = document.createElement("tr");
                var imageTd = document.createElement("td");
                var img = document.createElement("img");
                img.src = petData[i].image.src;
                img.alt = petData[i].image.alt;
                img.width = petData[i].image.width;
                img.height = petData[i].image.height;
                imageTd.appendChild(img);

                var textTd = document.createElement("td");
                var h4 = document.createElement("h4");
                h4.appendChild(document.createTextNode(petData[i].name));
                textTd.appendChild(h4);

                var p = document.createElement("p");
                p.innerHTML = petData[i].description;
                textTd.appendChild(p);

                var span = document.createElement("span");
                span.appendChild(document.createTextNode("Age: " + petData[i].age + " years old."));
                textTd.appendChild(span);

                tr.appendChild(imageTd);
                tr.appendChild(textTd);

                mTable.appendChild(tr);

            }
        }
    }
}


function filterDog() {
    filterType = "Dog";
    loadTableWithFilters();
}

function filterCat() {
    filterType = "Cat";
    loadTableWithFilters();
}

function filterBird() {
    filterType = "Birds";
    loadTableWithFilters();
}

function filter_zero_1() {
    filterAgeMin = 0;
    filterAgeMax = 1;
    loadTableWithFilters();
}

function filter_1_3() {
    filterAgeMin = 1;
    filterAgeMax = 3;
    loadTableWithFilters();
}

function filter_4_plus() {
    filterAgeMin = 4;
    filterAgeMax = Number.MAX_VALUE;
    loadTableWithFilters();
}

function filterAllPets() {
    filterType = "";
    filterAgeMax = Number.MAX_VALUE;
    filterAgeMin = 0;
    loadTableWithFilters();
}

window.onload = function () {
    loadTableWithFilters();
}
