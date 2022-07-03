/* -------------------------------
Date:April 2, 2019
----------------------------------
Assignment: 2
Milestone:  4
---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contactHelpers.h"

#define MAXCONTACTS 5

void clearKeyboard(void)
{
  while (getchar() != '\n')
    ;
}

void pause(void)
{
  printf("(Press Enter to Continue)\n");
  clearKeyboard();
}

int getInt(void)
{
  int value;
  char nl;

  scanf("%d%c", &value, &nl);

  while (nl != '\n') {
    if (nl != '\n') {
      clearKeyboard();
      printf("*** INVALID INTEGER *** <Please enter an integer>: ");
      scanf("%d%c", &value, &nl);
    }
  }
  return value;
}

int getIntInRange(int min, int max)
{
  int value;
  int flag = 1;

  do {
    value = getInt();

    if (value < min || value > max) {
      printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
    }
    else {
      flag = 0;
    }
  } while (flag);

  return value;
}

int yes(void)
{
  char answer, nl;
  int value, flag = 1;

  do {
    scanf("%c%c", &answer, &nl);
    if (nl != '\n') {
      clearKeyboard();
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
    }
    else if (answer == 'Y' || answer == 'y' || answer == 'N' || answer == 'n') {
      flag = 0;
    }
    else {
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
    }
  } while (flag);

  if (answer == 'Y' || answer == 'y') {
    value = 1;
  }
  else {
    value = 0;
  }
  return value;
}

int menu(void)
{
  int choose;

  printf("Contact Management System\n");
  printf("-------------------------\n");
  printf("1. Display contacts\n");
  printf("2. Add a contact\n");
  printf("3. Update a contact\n");
  printf("4. Delete a contact\n");
  printf("5. Search contacts by cell phone number\n");
  printf("6. Sort contacts by cell phone number\n");
  printf("0. Exit\n");
  printf("\n");
  printf("Select an option:> ");

  choose = getIntInRange(0, 6);
  return choose;
}

void contactManagerSystem(void)
{
  int flag = 1, answer = 0;

  struct Contact contacts[MAXCONTACTS] = { { { "Rick",{ '\0' }, "Grimes" },
      { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
      { "4161112222", "4162223333", "4163334444" } },

      { { "Maggie", "R.", "Greene" },
      { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
      { "9051112222", "9052223333", "9053334444" } },

      { { "Morgan", "A.", "Jones" },
      { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
      { "7051112222", "7052223333", "7053334444" } },

      { { "Sasha",{ '\0' }, "Williams" },
      { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
      { "9052223333", "9052223333", "9054445555" } },
  };


  do {
    switch (menu()) {
    case 1:
      displayContacts(contacts, MAXCONTACTS);
      pause();

      break;
    case 2:
      addContact(contacts, MAXCONTACTS);
      pause();
      break;
    case 3:
      updateContact(contacts, MAXCONTACTS);
      pause();
      break;
    case 4:
      deleteContact(contacts, MAXCONTACTS);
      pause();
      break;
    case 5:
      searchContacts(contacts, MAXCONTACTS);
      pause();
      break;
    case 6:
      sortContacts(contacts, MAXCONTACTS);
      pause();
      break;
    case 0:
      printf("\nExit the program? (Y)es/(N)o: ");
      answer = yes();
      printf("\n");
      break;
    default:
      break;
    }

    if (answer == 1) {
      printf("Contact Management System: terminated\n");
      flag = 0;
    }

  } while (flag);
}

void getTenDigitPhone(char phoneNum[])
{
  int i, num = 0, needInput = 1;

  while (needInput == 1) {
    scanf("%s", phoneNum);
    clearKeyboard();
    num = 0;

    if (strlen(phoneNum) == 10) {
      for (i = 0; i < 10; i++) {
        if (isdigit(phoneNum[i]) != 0) {
          num++;
        }
      }
      if (num == 10) {
        needInput = 0;
      }
      else {
        printf("Enter a 10-digit phone number: ");
      }
    }
    else
      printf("Enter a 10-digit phone number: ");
  }
}

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{

  int i, index = 0, result = 0, flag = 1;

  for (i = 0; i < size && flag == 1; i++) {
    index = strcmp(contacts[i].numbers.cell, cellNum);
    if (index == 0) {
      result = i;
      flag = 0;
    }
    else {
      result = -1;
    }
  }
  return result;
}

void displayContactHeader(void)
{
  printf("\n");
  printf("+-----------------------------------------------------------------------------+\n");
  printf("|                              Contacts Listing                               |\n");
  printf("+-----------------------------------------------------------------------------+\n");

}

void displayContactFooter(int count)
{
  printf("+-----------------------------------------------------------------------------+\n");
  printf("Total contacts: %d\n\n", count);
}


void displayContact(const struct Contact* contact)
{
  printf(" %s", contact->name.firstName);
  if (strlen(contact->name.middleInitial) != 0) {
    printf(" %s", contact->name.middleInitial);
  }
  printf(" %s\n", contact->name.lastName);

  printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
  printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
  if (contact->address.apartmentNumber > 0) {
    printf("Apt# %d, ", contact->address.apartmentNumber);
  }
  printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

void displayContacts(const struct Contact contacts[], int size)
{
  int i, count = 0;
  displayContactHeader();

  for (i = 0; i < size; i++) {
    if (strlen(contacts[i].numbers.cell) > 0) {
      displayContact(&contacts[i]);
      count++;
    }
  }
  displayContactFooter(count);
}


void searchContacts(const struct Contact contacts[], int size)
{
  int value;
  char cellNum[11] = { '\0' };

  printf("\n");
  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(cellNum);

  value = findContactIndex(contacts, size, cellNum);
  if (value != -1) {
    printf("\n");
    displayContact(&contacts[value]);
    printf("\n");
  }
  else {
    printf("*** Contact NOT FOUND ***\n");
    printf("\n");
  }
}

void addContact(struct Contact contacts[], int size)
{
  int value;

  value = findContactIndex(contacts, size, "\0");
  if (value >= 0) {
    printf("\n");
    getContact(&contacts[value]);
    printf("--- New contact added! ---\n\n");
  }
  else {
    printf("\n");
    printf("*** ERROR: The contact list is full! ***\n\n");
  }
}

void updateContact(struct Contact contacts[], int size)
{
  int value;
  char cellNum[11] = { '\0' };

  printf("\n");
  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(cellNum);

  value = findContactIndex(contacts, size, cellNum);
  if (value != -1) {
    printf("\n");
    printf("Contact found:\n");
    displayContact(&contacts[value]);
    printf("\n");

    printf("Do you want to update the name? (y or n): ");
    if (yes()) {
      getName(&contacts[value].name);
    }

    printf("Do you want to update the address? (y or n): ");
    if (yes()) {
      getAddress(&contacts[value].address);
    }

    printf("Do you want to update the numbers? (y or n): ");
    if (yes()) {
      getNumbers(&contacts[value].numbers);
    }
    printf("--- Contact Updated! ---\n");
    printf("\n");
  }
  else {
    printf("*** Contact NOT FOUND ***\n");
    printf("\n");
  }
}

void deleteContact(struct Contact contacts[], int size)
{
  int value;
  char cellNum[11] = { '\0' };

  printf("\n");
  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(cellNum);

  value = findContactIndex(contacts, size, cellNum);
  if (value != -1) {
    printf("\n");
    printf("Contact found:\n");
    displayContact(&contacts[value]);
    printf("\n");

    printf("CONFIRM: Delete this contact? (y or n): ");
    if (yes()) {
      contacts[value].numbers.cell[0] = '\0';
      printf("--- Contact deleted! ---\n");
      //printf("\n");
    }
    printf("\n");
  }
  else {
    printf("*** Contact NOT FOUND ***\n");
    printf("\n");
  }
}

void sortContacts(struct Contact contacts[], int size)
{
  printf("\n");
  printf("<<< Feature to sort is unavailable >>>\n");
  printf("\n");
}


