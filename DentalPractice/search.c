#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"other.h"
#include"search.h"

void searchPPSEdit(struct node *top, char pps[9]) {
	struct node * temp = top;
	int choice;
	char email[31];
	int valEmail;
	int smoke;
	int valSmoke;
	int alco;
	int valAlco;
	int exercise;
	int valExercise;

	while (temp != NULL) {
		if (strcmp(temp->pps, pps) == 0) {
			do {
				printf("(1) Edit First Name\n(2) Edit Last Name\n(3) Edit Gender\n(4) Edit Email\n(5) Edit Next Of Kin\n(6) Edit Weight\n"
					"(7) Edit Height\n(8) Edit Smoking Details\n(9) Edit Alcohol Details\n(10) Edit Exercise Details\n(0) Main Menu\n");
				scanf("%d", &choice);
				switch (choice) {

				case 1:
					//First
					printf("Current first name: %s\n", temp->fName);
					printf("Enter new first name:\n");
					scanf("%s", temp->fName);
					break;

				case 2:
					//Last
					printf("Current last name: %s\n", temp->lName);
					printf("Enter new last name:\n");
					scanf("%s", temp->lName);
					break;

				case 3:
					//Gender
					printf("Current gender: %c\n", temp->gender);
					printf("Enter new gender:\n");
					scanf(" %c", &temp->gender);
					break;

				case 4:
					//Email
					printf("Current Email: %s\n", temp->email);
					printf("Enter valid email:\n");
					scanf("%s", email);
					valEmail = validEmail(email);
					while (valEmail != 5) {
						printf("Invalid email, try again...\n");
						printf("Enter valid email:\n");
						scanf("%s", email);
						valEmail = validEmail(email);
					}
					strcpy(temp->email, email);
					break;

				case 5:
					//Next of kin
					printf("Current next of Kin: %s", temp->kin);
					printf("Enter new next of kin:\n");
					scanf("%s", temp->kin);
					break;

				case 6:
					//Weight
					printf("Current Weight: %d", temp->weight);
					printf("Enter new weight:\n");
					scanf("%f", temp->weight);
					//Update BMI
					temp->BMI = BMI(temp->height, temp->weight);
					printf("BMI updated to: %.2f\n", temp->BMI);
					break;

				case 7:
					//Height
					printf("Current Height: %d", temp->height);
					printf("Enter new height:\n");
					scanf("%f", temp->height);
					//Update BMI
					temp->BMI = BMI(temp->height, temp->weight);
					printf("BMI updated to: %.2f\n", temp->BMI);
					break;

				case 8:
					//Smoking
					if (temp->smoke == 1) {
						printf("Currently non-smoker\n");
					}
					else if (temp->smoke == 2) {
						printf("Currently less than 10 per day\n");
					}
					else if (temp->smoke == 3) {
						printf("Currently more than 10 per day\n");
					}
					else {
						printf("Smoking Input Error\n");
					}
					printf("How many Cigerettes per Day? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
					scanf("%d", &smoke);
					valSmoke = validMultiChoice(smoke);
					while (valSmoke != 1) {
						printf("Invaild input, please try again...\n");
						printf("How many Cigerettes per Day? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
						scanf("%d", &smoke);
						valSmoke = validMultiChoice(smoke);
					}
					temp->smoke = smoke;
					break;

				case 9:
					//Alcohol
					if (temp->alco == 1) {
						printf("Currently no alcohol\n");
					}
					else if (temp->alco == 2) {
						printf("Currently less than 10 units per week\n");
					}
					else if (temp->alco == 3) {
						printf("Currently more than 10 units per week\n");
					}
					else {
						printf("Alcohol Input Error\n");
					}
					printf("How many Alcohol units per Week? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
					scanf("%d", &alco);
					valAlco = validMultiChoice(alco);
					while (valAlco != 1) {
						printf("Invaild input, please try again...\n");
						printf("How many Alcohol units per Week? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
						scanf("%d", &alco);
						valAlco = validMultiChoice(alco);
					}
					temp->alco = alco;
					break;

				case 10:
					//Exercise
					if (temp->exercise == 1) {
						printf("Currently no exercise\n");
					}
					else if (temp->alco == 2) {
						printf("Currently less than 2 times per week\n");
					}
					else if (temp->alco == 3) {
						printf("Currently more than 2 times per week\n");
					}
					else {
						printf("Exercise Input Error\n");
					}
					printf("How much Excerise per Week? :\n\t(1) None\n\t(2) Less than 2\n\t(3) More than 2\n");
					scanf("%d", &exercise);
					valExercise = validMultiChoice(exercise);
					while (valExercise != 1) {
						printf("Invaild input, please try again...\n");
						printf("How much Excerise per Week? :\n\t(1) None\n\t(2) Less than 2\n\t(3) More than 2\n");
						scanf("%d", &exercise);
						valExercise = validMultiChoice(exercise);
					}
					temp->exercise = exercise;
					break;
				case 0:
					return;
					break;
				default:
					printf("EDIT VIA PPS BROKEN\n");
				}
			} while (choice < 1 && choice > 10);
		}
		temp = temp->NEXT;
	}
}

void searchNameEdit(struct node *top, char first[11], char last[11]) {
	struct node * temp = top;
	int choice;
	char email[31];
	int valEmail;
	int smoke;
	int valSmoke;
	int alco;
	int valAlco;
	int exercise;
	int valExercise;

	while (temp != NULL) {
		if (strcmp(temp->fName, first) == 0 && strcmp(temp->lName, last) == 0) {
			do {
				printf("---------------------------------------\n");
				printf("(1) Edit First Name\n(2) Edit Last Name\n(3) Edit Gender\n(4) Edit Email\n(5) Edit Next Of Kin\n(6) Edit Weight\n"
					"(7) Edit Height\n(8) Edit Smoking Details\n(9) Edit Alcohol Details\n(10) Edit Exercise Details\n(0) Main menu\n");
				printf("---------------------------------------\n\n");
				scanf("%d", &choice);
				switch (choice) {

				case 1:
					//First
					printf("Current first name: %s\n", temp->fName);
					printf("Enter new first name:\n");
					scanf("%s", temp->fName);
					break;

				case 2:
					//Last
					printf("Current last name: %s\n", temp->lName);
					printf("Enter new last name:\n");
					scanf("%s", temp->lName);
					break;

				case 3:
					//Gender
					printf("Current gender: %c\n", temp->gender);
					printf("Enter new gender:\n");
					scanf(" %c", &temp->gender);
					break;

				case 4:
					//Email
					printf("Current Email: %s\n", temp->email);
					printf("Enter valid email:\n");
					scanf("%s", email);
					valEmail = validEmail(email);
					while (valEmail != 5) {
						printf("Invalid email, try again...\n");
						printf("Enter valid email:\n");
						scanf("%s", email);
						valEmail = validEmail(email);
					}
					strcpy(temp->email, email);
					break;

				case 5:
					//Next of kin
					printf("Current next of Kin: %s", temp->kin);
					printf("Enter new next of kin:\n");
					scanf("%s", temp->kin);
					break;

				case 6:
					//Weight
					printf("Current Weight: %d", temp->weight);
					printf("Enter new weight:\n");
					scanf("%f", temp->weight);
					//Update BMI
					temp->BMI = BMI(temp->height, temp->weight);
					printf("BMI updated to: %.2f\n", temp->BMI);
					break;

				case 7:
					//Height
					printf("Current Height: %d", temp->height);
					printf("Enter new height:\n");
					scanf("%f", temp->height);
					//Update BMI
					temp->BMI = BMI(temp->height, temp->weight);
					printf("BMI updated to: %.2f\n", temp->BMI);
					break;

				case 8:
					//Smoking
					if (temp->smoke == 1) {
						printf("Currently non-smoker\n");
					}
					else if (temp->smoke == 2) {
						printf("Currently less than 10 per day\n");
					}
					else if (temp->smoke == 3) {
						printf("Currently more than 10 per day\n");
					}
					else {
						printf("Smoking Input Error\n");
					}
					printf("How many Cigerettes per Day? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
					scanf("%d", &smoke);
					valSmoke = validMultiChoice(smoke);
					while (valSmoke != 1) {
						printf("Invaild input, please try again...\n");
						printf("How many Cigerettes per Day? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
						scanf("%d", &smoke);
						valSmoke = validMultiChoice(smoke);
					}
					temp->smoke = smoke;
					break;

				case 9:
					//Alcohol
					if (temp->alco == 1) {
						printf("Currently no alcohol\n");
					}
					else if (temp->alco == 2) {
						printf("Currently less than 10 units per week\n");
					}
					else if (temp->alco == 3) {
						printf("Currently more than 10 units per week\n");
					}
					else {
						printf("Alcohol Input Error\n");
					}
					printf("How many Alcohol units per Week? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
					scanf("%d", &alco);
					valAlco = validMultiChoice(alco);
					while (valAlco != 1) {
						printf("Invaild input, please try again...\n");
						printf("How many Alcohol units per Week? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
						scanf("%d", &alco);
						valAlco = validMultiChoice(alco);
					}
					temp->alco = alco;
					break;

				case 10:
					//Exercise
					if (temp->exercise == 1) {
						printf("Currently no exercise\n");
					}
					else if (temp->alco == 2) {
						printf("Currently less than 2 times per week\n");
					}
					else if (temp->alco == 3) {
						printf("Currently more than 2 times per week\n");
					}
					else {
						printf("Exercise Input Error\n");
					}
					printf("How much Excerise per Week? :\n\t(1) None\n\t(2) Less than 2\n\t(3) More than 2\n");
					scanf("%d", &exercise);
					valExercise = validMultiChoice(exercise);
					while (valExercise != 1) {
						printf("Invaild input, please try again...\n");
						printf("How much Excerise per Week? :\n\t(1) None\n\t(2) Less than 2\n\t(3) More than 2\n");
						scanf("%d", &exercise);
						valExercise = validMultiChoice(exercise);
					}
					temp->exercise = exercise;
					break;
				case 0:
					return;
					break;
				default:
					printf("EDIT VIA NAME BROKEN\n");
				}
			} while (choice < 0 && choice > 10);
		}//if
		temp = temp->NEXT;
	}//while
}//searchNameEdit