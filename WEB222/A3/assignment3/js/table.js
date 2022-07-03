// Data for the "HTML Tables" Page

var users = [
    { first_name: "Kaitlin", last_name: "Burns", age: 23, email: "kburns99753@usermail.com" },
    { first_name: "Joshua", last_name: "Feir", age: 31, email: "josh319726@usermail.com" },
    { first_name: "Stephen", last_name: "Shaw", age: 28, email: "steve.shaw47628@usermail.com" },
    { first_name: "Timothy", last_name: "McAlpine", age: 37, email: "Timbo72469@usermail.com" },
    { first_name: "Sarah", last_name: "Connor", age: 19, email: "SarahC6320@usermail.com" }
];

window.onload = function () {
    var userInfo = document.querySelector("#thirdTable");
    var thirdTable = '<table style="border:1 px solid;">';
    thirdTable += '<tr><td><b> First Name</b></td><td><b>Last Name</b></td><td><b>Age</b></td><td><b>Email</b></td></tr>';

    for (var i = 0; i < users.length; i++) {
        thirdTable += '<tr><td>' + users[i].first_name + '</td>';
        thirdTable += '<td>' + users[i].last_name + '</td>';
        thirdTable += '<td>' + users[i].age + '</td>';
        thirdTable += '<td><a href="mailto:' + users[i].email + '">' + users[i].email + '</a></td></tr>';

    }
    thirdTable += '</table>';
    userInfo.innerHTML += thirdTable;
};