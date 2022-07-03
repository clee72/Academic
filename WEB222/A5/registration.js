
/********************************************************************************* 
*
* WEB222 – Assignment #5
*
* I declare that this assignment is my own work in accordance with Seneca 
* Academic Policy. No part of this assignment has been copied manually or 
* electronically from any other source (including web sites) or distributed to 
* other students. 
* 
* Name: _WONHWA LEE_ Student ID: _076086149_ Date: _2019/07/30_ 
* 
********************************************************************************/

var form = document.getElementById("userInfo");
//name validation
function UnameValidate() {
    var name = document.signup.Username.value.trim();
    var patt = /^[a-zA-Z][a-zA-Z0-9]{5,}$/;
    if (name.match(patt)) {
        return true;
    } else {
        document.querySelector('#sidePanel').innerHTML += "<p>You must enter at least 6 characters for username<p>";
        document.name.select();
        return false;
    }
}

//password validation 1
function PwordRegValidate() {
    var pword = document.signup.Pword.value.trim();
    var patt2 = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])[0-9a-zA-Z]{8,8}$/;
    if (pword.match(patt2)) {
        return true;
    } else {
        document.querySelector('#sidePanel').innerHTML += "<p>You must enter at least one digit, one uppercase letter, and 8 characters long<p>";
        document.pword2.select();
        return false;
    }
}
//Password validation 2
function PwordMatchValidate() {
    var pword = document.signup.Pword.value.trim();
    var patt2 = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])[0-9a-zA-Z]{8,8}$/;
    var pword2 = document.signup.Pword2.value.trim();
    if (!pword2.match(patt2)) {
        document.querySelector('#sidePanel').innerHTML += "<p>You must enter at least one digit, one uppercase letter, and 8 characters long<p>";
        document.pword2.select();
        return false;
    } else if (pword != pword2) {
        document.querySelector('#sidePanel').innerHTML += "<p>The password you entered is not matched<p>";
        document.pword2.select();
        return false;
    } else {
        return true;
    }
}

//Phone number valiation
function PhoneValidate() {
    var phone = document.signup.Phone.value.trim();
    var patt3 = /^\d{3}[-]\d{3}[-]\d{4}$/;
    if (phone.match(patt3)) {
        return true;
    } else {
        document.querySelector('#sidePanel').innerHTML += "<p>Phone Number should be ###-###-####<p>";
        document.phone.select();
        return false;
    }
}

//Street name validation
function stNameValidate() {
    var street = document.signup.Street.value.trim();
    var patt4 = /^[a-zA-Z]+$/;
    if (street.match(patt4)) {
        return true;
    } else {
        document.querySelector('#sidePanel').innerHTML += "<p>The street name should not contain digits<p>";
        document.street.select();
        return false;
    }
}

//City name validation
function cityNameValidate() {
    var city = document.signup.City.value.trim();
    patt5 = /^[a-zA-Z]+$/;
    if (city.match(patt5)) {
        return true;
    } else {
        document.querySelector('#sidePanel').innerHTML += "<p>The city name must contain letters only<p>";
        document.city.select();
        return false;
    }
}

//postal code validation
function zipValidate() {
    var zip = document.signup.Zip.value.trim();
    patt6 = /^([a-zA-Z][0-9]){3}$/;
    if (zip.match(patt6)) {
        return true;
    } else {
        document.querySelector('#sidePanel').innerHTML += "<p>Only Canadian format allowed-(Letter Digit Letter Digit Letter Digit)<p>";
        document.zip.select();
        return false;
    }
}

function change() {
    var select = document.getElementById("prov").value;
    document.getElementById("selected").innerHTML = "You selected: " + select;
}

function validate() {
    var valid = false;
    valid = UnameValidate() && PwordValidate() && PhoneValidate() && stNameValidate() && cityNameValidate() && zipValidate();
    if (valid == true) {
        return true;
    }
}
