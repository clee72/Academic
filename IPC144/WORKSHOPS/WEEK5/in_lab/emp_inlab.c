/*
	Name:           WONHWA LEE
	Student Number: 076086149
	Email:          wlee72@myseneca.ca
	Section:        SGG
	Workshop:       5 (in-lab)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define SIZE 2


struct Employee {
	int employID;
	int employAge;
	double employSalary;
};

int main(void) {

	int option = 0;
	int i = 0;

	struct Employee emp[SIZE] = { {0} };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		case 1:
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i < SIZE; i++) {
				if (emp[i].employID > 0)
					printf("%6d%9d%11.2lf\n", emp[i].employID, emp[i].employAge, emp[i].employSalary);
			}printf("\n");
			break;
			
		case 2:
			printf("Adding Employee\n");
			printf("===============\n");
			printf("i: %d ", i);
			if (i < SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[i].employID);

				printf("Enter Employee Age: ");
				scanf("%d", &emp[i].employAge);

				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[i].employSalary);
				printf("\n");
				i++;
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n");
				printf("\n");
			}
			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0;
}


