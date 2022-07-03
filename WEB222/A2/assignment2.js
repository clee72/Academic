/*********************************************************************************
*  WEB222 – Assignment 02
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  
*  No part of this assignment has been copied manually or electronically from any other source
*  (including web sites) or distributed to other students.
* 
*  Name: _WONHWA LEE____ Student ID: _076086149___ Date: __2019/06/08__
*
********************************************************************************/

/**********************************
 *          ALL DATA              *
 *  write your CustomerDB Object  *
 *      BELOW this Object         *
 **********************************/

var allData = [
    { type: "store", data: { store_id: 297, name: "Scotiabank - Main Branch", address_id: 1023 } },
    { type: "store", data: { store_id: 614, name: "Scotiabank - Hamilton", address_id: 1984 } },
    { type: "store", data: { store_id: 193, name: "Scotiabank - Mississauga", address_id: 1757 } },
    { type: "customer", data: { customer_id: 26, store_id: 297, first_name: "Dave", last_name: "Bennett", email: "dbennett@gmail.com", address_id: 4536, add_date: null } },
    { type: "customer", data: { customer_id: 59, store_id: 193, first_name: "John", last_name: "Stevens", email: "jstevens22@hotmail.com", address_id: 2473, add_date: null } },
    { type: "customer", data: { customer_id: 29, store_id: 614, first_name: "Sarah", last_name: "Pym", email: "spym99@hotmail.com", address_id: 1611, add_date: null } },
    { type: "customer", data: { customer_id: 63, store_id: 297, first_name: "Steven", last_name: "Edwards", email: "steven2231@hotmail.com", address_id: 1836, add_date: null } },
    { type: "customer", data: { customer_id: 71, store_id: 614, first_name: "Martin", last_name: "Scott", email: "mdog33@gmail.com", address_id: 2727, add_date: null } },
    { type: "customer", data: { customer_id: 24, store_id: 614, first_name: "Jonathan", last_name: "Pym", email: "jjpym@yahoo.ca", address_id: 1611, add_date: null } },
    { type: "customer", data: { customer_id: 36, store_id: 193, first_name: "Kaitlyn", last_name: "Adams", email: "katy38@hotmail.com", address_id: 5464, add_date: null } },
    { type: "customer", data: { customer_id: 73, store_id: 297, first_name: "Melissa", last_name: "Bennett", email: "mbennett@gmail.com", address_id: 4536, add_date: null } },
    { type: "address", data: { address_id: 1023, address: "2895 Yonge St.", city: "Toronto", province: "ON", postal_code: "L4C02G" } },
    { type: "address", data: { address_id: 1984, address: "3611 Main St. West", city: "Hamilton", province: "ON", postal_code: "R5O8H5" } },
    { type: "address", data: { address_id: 1757, address: "1177 Ontario St. Unit 8", city: "Mississauga", province: "ON", postal_code: "L9H6B3" } },
    { type: "address", data: { address_id: 4536, address: "3945 John St.", city: "Ajax", province: "ON", postal_code: "L7M4T9" } },
    { type: "address", data: { address_id: 2473, address: "391 Baker St. Apt 231", city: "Mississauga", province: "ON", postal_code: "M4T8S3" } },
    { type: "address", data: { address_id: 1611, address: "183 City Ct.", city: "Hamilton", province: "ON", postal_code: "J3T9V2" } },
    { type: "address", data: { address_id: 1836, address: "67 Rhymer Ave.", city: "Stouffville", province: "ON", postal_code: "L3C8H4" } },
    { type: "address", data: { address_id: 2727, address: "287 Brant St. Apt 4A", city: "Waterdown", province: "ON", postal_code: "R93G3P" } },
    { type: "address", data: { address_id: 5464, address: "11 New St. Apt 2B", city: "Brampton", province: "ON", postal_code: "L694R7" } },
];




/*  Write your CustomerDB Object Here.  Do not forget to uncomment the "TEST DATA" section
when you're ready.  Your code is required to run against these tests before you submit */

var CustomerDB =
{
    customers: [],
    addresses: [],
    stores: [],

    //1.insertData()
    insertData: function (data) {
        for (var i = 0; i < data.length; i++) {
            this.addCustomer(data[i]);
            this.addAddress(data[i]);
            this.addStore(data[i]);
        }
    },

    //2.addCustomer(customerObj)
    addCustomer: function (customerObj) {
        if (customerObj.type == "customer") {
            customerObj.data.add_date = new Date();
            this.customers.push(customerObj.data);
        }
    },

    //3.outputCustomerById(customer_id)
    outputCustomerById: function (customer_id) {
        for (var i = 0; i < this.customers.length; i++) {
            if (customer_id == this.customers[i].customer_id) {
                var fN = this.customers[i].first_name;
                var lN = this.customers[i].last_name;
                var em = this.customers[i].email;
                var ad = this.getAddressById(this.customers[i].address_id).address;
                var city = this.getAddressById(this.customers[i].address_id).city;
                var prov = this.getAddressById(this.customers[i].address_id).province;
                var p_code = this.getAddressById(this.customers[i].address_id).postal_code;
                var jDate = this.customers[i].add_date;
                console.log('\nCustomer ' + this.customers[i].customer_id + ': ' + fN + ' ' + lN + ' (' + em + ')\nHome Address: ' + ad + ' ' + city + ', ' + prov + '. ' + p_code + '\nJoined: ' + jDate);
            }
        }
    },

    //4.outputAllCustomers()
    outputAllCustomers: function () {
        console.log("All Customers\n");
        for (var i = 0; i < this.customers.length; i++) {
            this.outputCustomerById(this.customers[i].customer_id);
        }
    },

    //5.outputCustomersByStore(store_id)
    outputCustomersByStore: function (store_id) {
        var sName = this.getStoreById(store_id).name;
        console.log('Customers in Store： ' + sName);

        for (var i = 0; i < this.customers.length; i++) {
            if (store_id == this.customers[i].store_id) {
                var fN = this.customers[i].first_name;
                var lN = this.customers[i].last_name;
                var em = this.customers[i].email;
                var ad = this.getAddressById(this.customers[i].address_id).address;
                var city = this.getAddressById(this.customers[i].address_id).city;
                var prov = this.getAddressById(this.customers[i].address_id).province;
                var p_code = this.getAddressById(this.customers[i].address_id).postal_code;
                var jDate = this.customers[i].add_date;
                console.log('\nCustomer ' + this.customers[i].customer_id + ': ' + fN + ' ' + lN + ' (' + em + ')\nHome Address: ' + ad + ' ' + city + ', ' + prov + '. ' + p_code + '\nJoined: ' + jDate);
            }
        }
    },

    //6.removeCustomerById(customer_id)
    removeCustomerById: function (customer_id) {

        for (var i = 0; i < this.customers.length; i++) {
            if (customer_id == this.customers[i].customer_id) {
                var a_id = this.customers[i].address_id;
                this.customers.splice(i, 1);
                this.removeAddressById(a_id);
            }
        }
    },

    //7.addAddress(addressObj)
    addAddress: function (addressObj) {
        if (addressObj.type == "address") {
            this.addresses.push(addressObj.data);
        }
    },

    //8.getAddressById(address_id)
    getAddressById: function (address_id) {
        for (var i = 0; i < this.addresses.length; i++) {
            if (address_id == this.addresses[i].address_id) {
                return this.addresses[i];
            }
        }
    },

    //9.outputAllAddresses()
    outputAllAddresses: function () {
        console.log('All Addresses');
        for (var i = 0; i < this.addresses.length; i++) {
            var a_id = this.addresses[i].address_id;
            var ad = this.addresses[i].address;
            var city = this.addresses[i].city;
            var prov = this.addresses[i].province;
            var p_code = this.addresses[i].postal_code;
            console.log('\nAddress ' + a_id + ': ' + ad + ' ' + city + ', ' + prov + '. ' + p_code);
        }
    },

    //10.removeAddressById(address_id)
    removeAddressById: function (address_id) {
        var flag = 1;
        for (var i = 0; i < this.customers.length && flag != 0; i++) {
            if (address_id == this.customers[i].address_id) {
                flag = 0;
            }         
        }

        if (flag) {
            for (var i = 0; i < this.addresses.length; i++) {
                if (address_id == this.addresses[i].address_id) {
                    this.addresses.splice(i, 1);
                }
            }
        }
    },

    //11.addStore(storeObj)
    addStore: function (storeObj) {
        if (storeObj.type == "store") {
            this.stores.push(storeObj.data);
        }
    },

    //12.getStoreById()
    getStoreById: function (store_id) {
        for (var i = 0; i < this.stores.length; i++) {
            if (store_id == this.stores[i].store_id) {
                return this.stores[i];
            }
        }
    },
    //13.outputAllStores()
    outputAllStores: function () {
        console.log("All stores\n");
        for (var i = 0; i < this.stores.length; i++) {
            var s_id = this.stores[i].store_id;
            var sN = this.stores[i].name;
            var ad = this.getAddressById(this.customers[i].address_id).address;
            var city = this.getAddressById(this.customers[i].address_id).city;
            var prov = this.getAddressById(this.customers[i].address_id).province;
            var p_code = this.getAddressById(this.customers[i].address_id).postal_code;
            console.log('\nstore ' + s_id + ': ' + sN + '\nLocation: ' + ad + ' ' + city + ', ' + prov + '. ' + p_code);
        }
    },
};


/**********************************
 *          TEST DATA             *
 *  write your CustomerDB Object  *
 *      ABOVE this code           *
 *                                *
 *  Uncomment this block of code  *
 *  when you're ready to test     *
 *  your CustomerDB Object        *
 *                                *
 *  You MUST Hand in your code    *
 *  with the test data            *
 *  uncommented, as this will     *
 *  help check your code for      *
 *  correctness                   *
 **********************************/



// Insert all Data into the Database

CustomerDB.insertData(allData);

// output all customers

console.log("CustomerDB.outputAllCustomers();\n\n--------------------------\n\n");
CustomerDB.outputAllCustomers();
console.log("--------------------------\n\n");

// output all addresses

console.log("CustomerDB.outputAllAddresses();\n\n--------------------------\n\n");
CustomerDB.outputAllAddresses();
console.log("--------------------------\n\n");

// output all stores

console.log("CustomerDB.outputAllStores();\n\n--------------------------\n\n");
CustomerDB.outputAllStores();
console.log("--------------------------\n\n");

// output all customers in the "Main Branch"

console.log("CustomerDB.outputCustomersByStore(297);\n\n--------------------------\n\n");
CustomerDB.outputCustomersByStore(297);
console.log("--------------------------\n\n");

// remove Customer Dave Bennett (customer_id 26) and Martin Scott (customer_id 71)

console.log("CustomerDB.removeCustomerById(26);\nCustomerDB.removeCustomerById(71);\n\n");
CustomerDB.removeCustomerById(26);
CustomerDB.removeCustomerById(71);
console.log("--------------------------\n\n");

// output all customers again
// NOTE: Dave Bennett and Martin Scott should be missing

console.log("CustomerDB.outputAllCustomers();\n\n--------------------------\n\n");
CustomerDB.outputAllCustomers();
console.log("--------------------------\n\n");

// output all addresses again
// NOTE: only addrss 287 Brant St. Apt 4A Waterdown, ON. R93G3P should be missing

console.log("CustomerDB.outputAllAddresses();\n\n--------------------------\n\n");
CustomerDB.outputAllAddresses();
console.log("--------------------------\n\n");


