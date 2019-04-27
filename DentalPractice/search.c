#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"other.h"
#include"search.h"
#include"load.h"
#include"outputs.h"

//Search Database for patient via PPS, return the position in the database
int searchList(struct node * top, char pps[9]) {
	int found = 0;
	struct node * temp = top;

	//Search until PPS is encountered, adding to count each time. Return count when found, indicates position in linked list
	while (temp != NULL) {
		if (strcmp(temp->pps, pps) == 0) {
			found = 1;
			return found;
		}
		temp = temp->NEXT;
	}
	return found;
}

//Specific to searching via PPS number
void printSingle(struct node *top, char pps[9]) {
	struct node * temp = top;

	//Search untill PPS found, print details to console
	while (temp != NULL) {
		if (strcmp(temp->pps, pps) == 0) {
			printf("\n***********************************************************************\n");
			printf("PPS: %s\n", temp->pps);
			printf("NAME: %s %s\n", temp->fName, temp->lName);
			printf("DOB: %s\n", temp->dob);
			printf("GENDER: %c\n", temp->gender);
			printf("EMAIL: %s\n", temp->email);
			printf("NEXT OF KIN: %s %s\n", temp->fKin, temp->lKin);
			printf("LAST APPOINTMENT DATE: %s\n", temp->lastApp);
			printf("WEIGHT - kg: %.3f\n", temp->weight);
			printf("HEIGHT - cm: %.3f\n", temp->height);
			printf("ALLERGIES TO MEDS: %c\n", temp->allergies);

			switch (temp->smoke) {
			case 1:
				printf("SMOKER: No\n");
				break;
			case 2:
				printf("SMOKER: Less than 10 per day\n");
				break;
			case 3:
				printf("SMOKER: More than 10 per day\n");
				break;
			default:
				printf("SMOKER INPUT BROKEN\n");
			}

			switch (temp->alco) {
			case 1:
				printf("ALCOHOL: None\n");
				break;
			case 2:
				printf("ALCOHOL: Less than 10 units per week\n");
				break;
			case 3:
				printf("ALCOHOL: More than 10 units week\n");
				break;
			default:
				printf("ALCOHOL INPUT BROKEN\n");
			}

			switch (temp->exercise) {
			case 1:
				printf("EXCERCISE: None\n");
				break;
			case 2:
				printf("EXCERCISE: Less than 2 per week\n");
				break;
			case 3:
				printf("EXCERCISE: More than 2 per week\n");
				break;
			default:
				printf("EXCERCISE INPUT BROKEN\n");
			}

			printf("BMI: %.2f\n", temp->BMI);
		}//if
		temp = temp->NEXT;
	}//while
}

//Search and print patent via name
void searchName(struct node *top, char first[11], char last[11]) {
	struct node * temp = top;

	while (temp != NULL) {
		if (strcmp(temp->fName, first) == 0 && strcmp(temp->lName, last) == 0) {
			printf("\n***********************************************************************\n");
			printf("PPS: %s\n", temp->pps);
			printf("NAME: %s %s\n", temp->fName, temp->lName);
			printf("DOB: %s\n", temp->dob);
			printf("GENDER: %c\n", temp->gender);
			printf("EMAIL: %s\n", temp->email);
			printf("NEXT OF KIN: %s %s\n", temp->fKin, temp->lKin);
			printf("LAST APPOINTMENT DATE: %s\n", temp->lastApp);
			printf("WEIGHT - kg: %.3f\n", temp->weight);
			printf("HEIGHT - cm: %.3f\n", temp->height);
			printf("ALLERGIES TO MEDS: %c\n", temp->allergies);

			switch (temp->smoke) {
			case 1:
				printf("SMOKER: No\n");
				break;
			case 2:
				printf("SMOKER: Less than 10 per day\n");
				break;
			case 3:
				printf("SMOKER: More than 10 per day\n");
				break;
			default:
				printf("SMOKER INPUT BROKEN\n");
			}

			switch (temp->alco) {
			case 1:
				printf("ALCOHOL: None\n");
				break;
			case 2:
				printf("ALCOHOL: Less than 10 units per week\n");
				break;
			case 3:
				printf("ALCOHOL: More than 10 units week\n");
				break;
			default:
				printf("ALCOHOL INPUT BROKEN\n");
			}

			switch (temp->exercise) {
			case 1:
				printf("EXCERCISE: None\n");
				break;
			case 2:
				printf("EXCERCISE: Less than 2 per week\n");
				break;
			case 3:
				printf("EXCERCISE: More than 2 per week\n");
				break;
			default:
				printf("EXCERCISE INPUT BROKEN\n");
			}

			printf("BMI: %.2f\n", temp->BMI);

			//If found get out of function after printing
			return;
		}//if

		//Point to next patient
		temp = temp->NEXT;
	}//while

	//If not found
	printf("Sorry, name not found\n\n");
}

//Search and edit patient via PPS number
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
					printf("Current next of Kin: %s %s", temp->fKin, temp->lKin);
					printf("Enter new First name:\n");
					scanf("%s", temp->fKin);
					printf("Enter new Last name:\n");
					scanf("%s", temp->lKin);
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

//Search and edit patient via name
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
					printf("Current next of Kin: %s %s", temp->fKin, temp->lKin);
					printf("Enter new First name:\n");
					scanf("%s", temp->fKin);
					printf("Enter new Last name:\n");
					scanf("%s", temp->lKin);
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
					printf("Invalid Choice, please try again...\n");
				}
			} while (choice!=0);
		}//if
		temp = temp->NEXT;
	}//while
}//searchNameEdit

//Find position in list passed on patient pps, return value and use for delete function
int findPos(struct node *top, char pps[9]) {
	struct node * temp = top;
	int count = 0;
	while (temp != NULL) {
		count++;
		if (strcmp(temp->pps, pps) == 0) {
			return count;
		}
		temp = temp->NEXT;
	}//while
	printf("Patient not found\n");
	return;
}