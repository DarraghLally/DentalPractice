#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"search.h"
#include"other.h"
#include"load.h"
#include"outputs.h"

//Add patient, only used if no patients exist
void addElementAtStart(struct node ** top) {

	//Variables
	struct node* newNode;
	char pps[9];
	char emailAddress[31];
	int valEmail = 0;
	int smoke;
	int valSmoke = 0;
	int alco;
	int valAlco = 0;
	int exercise;
	int valExercise = 0;
	int updatePPS;

	//Prompt and read PPS
	printf("Please enter PPS of Patient: \nFormat: 1234567A\n");
	scanf("%s", pps);

	//Add new patient node
	newNode = (struct node*)malloc(1 * sizeof(struct node));

	//copy pps from search into struct 
	strcpy(newNode->pps, pps); 

	//First name
	printf("Enter First Name:\n");
	scanf("%s", newNode->fName);

	//Last name
	printf("Enter Last Name:\n");
	scanf("%s", newNode->lName);

	//Year of birth
	printf("Enter Year of Birth:\nFormat: yyyy\n");
	scanf("%s", newNode->dob);

	//Gender
	printf("Enter Gender:\nFormat: F - Female / M - Male\n");
	scanf(" %c", &newNode->gender);

	//Prompt, read and validate email address
	printf("Enter valid email:\n");
	scanf("%s", emailAddress);
	valEmail = validEmail(emailAddress);
	while (valEmail != 5) {
		printf("Invalid email, try again...\n");
		printf("Enter valid email:\n");
		scanf("%s", emailAddress);
		valEmail = validEmail(emailAddress);
	}
	strcpy(newNode->email, emailAddress);

	//Next of kin, first and last
	printf("Next of Kin:\n");
	printf("Enter First Name:\n");
	scanf("%s", newNode->fKin);
	printf("Enter Second Name:\n");
	scanf("%s", newNode->lKin);

	//Last appointment date
	printf("Enter Last appointment date:\nFormat: dd/mm/yy\n");
	scanf("%s", newNode->lastApp);

	//Dont allow weights of zero or less
	do {
		printf("Enter Weight (kg):\n");
		scanf("%f", &newNode->weight);
	} while (newNode->weight < 0);

	//Dont allow heights of zero or less
	do {
		printf("Enter Height (cm):\n");
		scanf("%f", &newNode->height);
	} while (newNode->height < 0);

	//Allergies to meds
	printf("Any Allergies to medication:\nFormat Y - Yes / N - No\n");
	scanf(" %c", &newNode->allergies);
	
	/*Multiple choice responses w/ input validation*/
	//Cigerette intake
	printf("How many Cigerettes per Day? :\n(1) None\n(2) Less than 10\n(3) More than 10\n");
	scanf("%d", &smoke);
	valSmoke = validMultiChoice(smoke);
	while (valSmoke != 1) {
		printf("Invaild input, please try again...\n");
		printf("How many Cigerettes per Day? :\n(1) None\n(2) Less than 10\n(3) More than 10\n");
		scanf("%d", &smoke);
		valSmoke = validMultiChoice(smoke);
	}
	newNode->smoke = smoke;

	//Alcohol intake
	printf("How many Alcohol units per Week? :\n(1) None\n(2) Less than 10\n(3) More than 10\n");
	scanf("%d", &alco);
	valAlco = validMultiChoice(alco);
	while (valAlco != 1) {
		printf("Invaild input, please try again...\n");
		printf("How many Alcohol units per Week? :\n(1) None\n(2) Less than 10\n(3) More than 10\n");
		scanf("%d", &alco);
		valAlco = validMultiChoice(alco);
	}
	newNode->alco = alco;

	//Exercise intake
	printf("How much Excerise per Week? :\n(1) None\n(2) Less than 2\n(3) More than 2\n");
	scanf("%d", &exercise);
	valExercise = validMultiChoice(exercise);
	while (valExercise != 1) {
		printf("Invaild input, please try again...\n");
		printf("How much Excerise per Week? :\n(1) None\n(2) Less than 2\n(3) More than 2\n");
		scanf("%d", &exercise);
		valExercise = validMultiChoice(exercise);
	}
	newNode->exercise = exercise;

	//Set BMI according to patients weight and height
	newNode->BMI = BMI(newNode->height, newNode->weight);

	//New nodes NEXT points to top
	newNode->NEXT = *top;
	//Top updated with newNode
	*top = newNode;
}

//Add patient, used every time but the first
void addElementToEnd(struct node *top) {

	//Variables
	struct node* temp;
	struct node* newNode;
	temp = top;
	char pps[9];
	char emailAddress[31];
	int valEmail = 0;
	int smoke;
	int valSmoke = 0;
	int alco;
	int valAlco = 0;
	int exercise;
	int valExercise = 0;

	printf("Please enter PPS of Patient: \nFormat: 1234567A\n");
	scanf("%s", pps);

	//If patient PPS is already save ask if they want to update
	if (searchList(top, pps) == 1) {
		int choice;
		printf("Sorry the PPS alread exists in the Database\n");
		printf("Do you wish to edit the patients details?\n(1) Yes\n(2) No\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			searchPPSEdit(top, pps);
			break;
		case 2: 
			return;
			break;
		default:
			printf("Incorrect choice\n");
			break;
		}
		return; //Break out of function
	}

	//Find end
	while (temp->NEXT != NULL) {
		temp = temp->NEXT;
	}

	//Add new patient node
	newNode = (struct node*)malloc(1 * sizeof(struct node));
	strcpy(newNode->pps, pps); //copy pps from search into struct 
	printf("Enter First Name:\n");
	scanf("%s", newNode->fName);
	printf("Enter Last Name:\n");
	scanf("%s", newNode->lName);
	printf("Enter Year of Birth:\nFormat: yyyy\n");
	scanf("%s", newNode->dob);
	printf("Enter Gender:\nFormat: F - Female / M - Male\n");
	scanf(" %c", &newNode->gender);

	//Email validation - Must include '@' and '.com'
	printf("Enter valid email:\n");
	scanf("%s", emailAddress);
	valEmail = validEmail(emailAddress);
	while (valEmail != 5) {
		printf("Invalid email, try again...\n");
		printf("Enter valid email:\n");
		scanf("%s", emailAddress);
		valEmail = validEmail(emailAddress);
	}
	strcpy(newNode->email, emailAddress);

	printf("Next of Kin:\n");
	printf("Enter First Name:\n");
	scanf("%s", newNode->fKin);
	printf("Enter Second Name:\n");
	scanf("%s", newNode->lKin);
	printf("Enter Last appointment date:\nFormat: dd/mm/yy\n");
	scanf("%s", newNode->lastApp);
	do {
		printf("Enter Weight (kg):\n");
		scanf("%f", &newNode->weight);
	} while (newNode->weight < 0);
	do {
		printf("Enter Height (cm):\n");
		scanf("%f", &newNode->height);
	} while (newNode->height < 0);


	printf("Any Allergies to medication:\nFormat Y - Yes / N - No\n");
	scanf(" %c", &newNode->allergies);

	//Multiple choice responses w/ input validation
	//Cigerette intake
	printf("How many Cigerettes per Day? :\n(1) None\n(2) Less than 10\n(3) More than 10\n");
	scanf("%d", &smoke);
	valSmoke = validMultiChoice(smoke);
	while (valSmoke != 1) {
		printf("Invaild input, please try again...\n");
		printf("How many Cigerettes per Day? :\n(1) None\n(2) Less than 10\n(3) More than 10\n");
		scanf("%d", &smoke);
		valSmoke = validMultiChoice(smoke);
	}
	newNode->smoke = smoke;

	//Alcohol intake
	printf("How many Alcohol units per Week? :\n(1) None\n(2) Less than 10\n(3) More than 10\n");
	scanf("%d", &alco);
	valAlco = validMultiChoice(alco);
	while (valAlco != 1) {
		printf("Invaild input, please try again...\n");
		printf("How many Alcohol units per Week? :\n(1) None\n(2) Less than 10\n(3) More than 10\n");
		scanf("%d", &alco);
		valAlco = validMultiChoice(alco);
	}
	newNode->alco = alco;

	//Exercise intake
	printf("How much Excerise per Week? :\n(1) None\n(2) Less than 2\n(3) More than 2\n");
	scanf("%d", &exercise);
	valExercise = validMultiChoice(exercise);
	while (valExercise != 1) {
		printf("Invaild input, please try again...\n");
		printf("How much Excerise per Week? :\n(1) None\n(2) Less than 2\n(3) More than 2\n");
		scanf("%d", &exercise);
		valExercise = validMultiChoice(exercise);
	}
	newNode->exercise = exercise;

	newNode->BMI = BMI(newNode->height, newNode->weight);

	//Point end to NULL
	newNode->NEXT = NULL;
	temp->NEXT = newNode;
}

//Delete from start
void deleteElementAtStart(struct node ** top) {
	struct node * temp;
	temp = *top;
	*top = temp->NEXT;
	free(temp);
	printf("Patient record deleted\n");
}

//Delete from end
void deleteElementAtEnd(struct node * top) {
	struct node* temp;
	struct node * prevTemp;

	temp = top;
	while (temp->NEXT != NULL) {
		prevTemp = temp;
		temp = temp->NEXT;
	}
	prevTemp->NEXT = NULL;
	free(temp);
	printf("Patient record deleted\n");
}

//Delete from Position, position found through patient PPS number
void deleteElementAtPos(struct node * top, int position) {
	int i;
	struct node * temp;
	struct node * prevTemp;
	struct node * newNode;

	temp = top;
	for (i = 0; i < (position - 1); i++) {
		prevTemp = temp;
		temp = temp->NEXT;
	}

	prevTemp->NEXT = temp->NEXT;
	free(temp);
	printf("Patient record deleted\n");
}

//Return the length of the database
int listLength(struct node * top) {
	struct node * temp;
	int count = 0;
	temp = top;
	while (temp != NULL) {
		count++;
		temp = temp->NEXT;
	}
	return count;
}



