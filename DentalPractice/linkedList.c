#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
/*Function Definitions for Linked List*/

void addElementAtStart(struct node ** top) {

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

	printf("Please enter PPS of Patient: \nFormat: 1234567A\n");
	scanf("%s", pps);

	/*
	If patient PPS is already saved
	ask if they want to update
	*/
	if (searchList(*top, pps) == 1) {
		printf("Sorry the PPS alread exists in the Database\n");

		//Add option to update patient here

		return; //Break out of function
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

	printf("Enter Next of Kin:\n");
	scanf("%s", newNode->kin);
	printf("Enter Last appointment date:\nFormat: dd/mm/yy\n");
	scanf("%s", newNode->lastApp);
	printf("Enter Weight (kg):\n");
	scanf("%f", &newNode->weight);
	printf("Enter Height (cm):\n");
	scanf("%f", &newNode->height);
	printf("Any Allergies to medication:\nFormat Y - Yes / N - No\n");
	scanf(" %c", &newNode->allergies);

	/*Multiple choice responses w/ input validation*/
	//Cigerette intake
	printf("How many Cigerettes per Day? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
	scanf("%d", &smoke);
	valSmoke = validMultiChoice(smoke);
	while (valSmoke != 1) {
		printf("Invaild input, please try again...\n");
		printf("How many Cigerettes per Day? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
		scanf("%d", &smoke);
		valSmoke = validMultiChoice(smoke);
	}
	newNode->smoke = smoke;

	//Alcohol intake
	printf("How many Alcohol units per Week? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
	scanf("%d", &alco);
	valAlco = validMultiChoice(alco);
	while (valAlco != 1) {
		printf("Invaild input, please try again...\n");
		printf("How many Alcohol units per Week? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
		scanf("%d", &alco);
		valAlco = validMultiChoice(alco);
	}
	newNode->alco = alco;

	//Exercise intake
	printf("How much Excerise per Week? :\n\t(1) None\n\t(2) Less than 2\n\t(3) More than 2\n");
	scanf("%d", &exercise);
	valExercise = validMultiChoice(exercise);
	while (valExercise != 1) {
		printf("Invaild input, please try again...\n");
		printf("How much Excerise per Week? :\n\t(1) None\n\t(2) Less than 2\n\t(3) More than 2\n");
		scanf("%d", &exercise);
		valExercise = validMultiChoice(exercise);
	}
	newNode->exercise = exercise;

	//New nodes NEXT points to top
	newNode->NEXT = *top;
	//Top updated with newNode
	*top = newNode;
}

void addElementToEnd(struct node *top) {
	struct node* temp;
	struct node* newNode;
	temp = top;
	char pps[8];

	char emailAddress[31];
	int valEmail = 0;

	int smoke;
	int valSmoke = 0;

	int alco;
	int valAlco = 0;

	int exercise;
	int valExercise = 0;

	printf("Please enter PPS of Patient: \nFormat: 1234567A");
	scanf("%s", pps);

	/*
	If patient PPS is already saved
	ask if they want to update
	*/
	if (searchList(top, pps) == 1) {
		printf("Sorry the PPS alread exists in the Database\n");

		//Add option to update patient here

		return; //Break out of function
	}

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

	printf("Enter Next of Kin:\n");
	scanf("%s", newNode->kin);
	printf("Enter Last appointment date:\nFormat: dd/mm/yy\n");
	scanf("%s", newNode->lastApp);
	printf("Enter Weight:\n");
	scanf("%f", &newNode->weight);
	printf("Enter Height:\n");
	scanf("%f", &newNode->height);
	printf("Any Allergies to medication:\nFormat Y - Yes / N - No\n");
	scanf(" %c", &newNode->allergies);

	/*Multiple choice responses w/ input validation*/
	//Cigerette intake
	printf("How many Cigerettes per Day? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
	scanf("%d", &smoke);
	valSmoke = validMultiChoice(smoke);
	while (valSmoke != 1) {
		printf("Invaild input, please try again...\n");
		printf("How many Cigerettes per Day? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
		scanf("%d", &smoke);
		valSmoke = validMultiChoice(smoke);
	}
	newNode->smoke = smoke;

	//Alcohol intake
	printf("How many Alcohol units per Week? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
	scanf("%d", &alco);
	valAlco = validMultiChoice(alco);
	while (valAlco != 1) {
		printf("Invaild input, please try again...\n");
		printf("How many Alcohol units per Week? :\n\t(1) None\n\t(2) Less than 10\n\t(3) More than 10\n");
		scanf("%d", &alco);
		valAlco = validMultiChoice(alco);
	}
	newNode->alco = alco;

	//Exercise intake
	printf("How much Excerise per Week? :\n\t(1) None\n\t(2) Less than 2\n\t(3) More than 2\n");
	scanf("%d", &exercise);
	valExercise = validMultiChoice(exercise);
	while (valExercise != 1) {
		printf("Invaild input, please try again...\n");
		printf("How much Excerise per Week? :\n\t(1) None\n\t(2) Less than 2\n\t(3) More than 2\n");
		scanf("%d", &exercise);
		valExercise = validMultiChoice(exercise);
	}
	newNode->exercise = exercise;

	//Point end to NULL
	newNode->NEXT = NULL;
	temp->NEXT = newNode;
}

/*Add At Position*/
//void addElementAtPos(struct node * top, int position) {
//	int i;
//	struct node * temp;
//	struct node * prevTemp;
//	struct node * newNode;
//	char ID[10];
//
//	printf("Please enter ID of student: \n");
//	scanf("%s", ID);
//
//	if (searchList(top, ID) == 1) {
//		printf("Sorry the ID already exists\n");
//		return;
//	}
//
//	temp = top;
//	for (i = 0; i < (position - 1); i++) {
//		prevTemp = temp;
//		temp = temp->NEXT;
//	}
//
//	newNode = (struct node*)malloc(sizeof(struct node));
//	printf("Enter Name of Student:\n");
//	scanf("%s", newNode->name);
//	printf("Enter age of Student:\n");
//	scanf("%d", &newNode->age);
//	strcpy(newNode->id, ID);
//	//printf("Enter ID of Student:\n");
//	//scanf("%s", newNode->id);
//	printf("Enter average grade of Student:\n");
//	scanf("%f", &newNode->avg);
//	printf("Enter email of Student:\n");
//	scanf("%s", newNode->email);
//	printf("Enter mobile of Student:\n");
//	scanf("%s", newNode->mobile);
//
//	newNode->NEXT = temp;
//	prevTemp->NEXT = newNode;
//}

/*Delete nodes complete*/
void deleteElementAtStart(struct node ** top) {
	struct node * temp;
	temp = *top;
	*top = temp->NEXT;
	free(temp);
}

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

}

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
}

void printList(struct node *top) {
	struct node* temp;
	temp = top;
	while (temp != NULL) {
		printf("***********************************************************************/n");
		printf("PPS;\n%s\n\n", temp->pps);
		printf("NAME:\%s %s\n\n", temp->fName, temp->lName);
		printf("DOB:\n%s\n\n", temp->dob);
		printf("GENDER:\n %c\n\n", temp->gender);
		printf("EMAIL:\n %s\n\n", temp->email);
		printf("NEXT OF KIN:\n %s\n\n", temp->kin);
		printf("LAST APPOINTMENT DATE:\n %s\n\n", temp->lastApp);
		printf("WEIGHT - kg:\n %.3f\n\n", temp->weight);
		printf("HEIGHT - cm:\n %.3f\n\n", temp->height);
		printf("ALLERGIES TO MEDS:\n %c\n\n", temp->allergies);

		switch (temp->smoke) {
		case 1:
			printf("SMOKER:\nNo\n\n");
			break;
		case 2:
			printf("SMOKER:\nLess than 10 per day\n\n");
			break;
		case 3:
			printf("SMOKER:\nMore than 10 per day\n\n");
			break;
		default:
			printf("SMOKER INPUT BROKEN\n");
		}

		switch (temp->alco) {
		case 1:
			printf("ALCOHOL:\nNone\n");
			break;
		case 2:
			printf("ALCOHOL:\nLess than 10 units per week\n");
			break;
		case 3:
			printf("ALCOHOL:\nMore than 10 units week\n");
			break;
		default:
			printf("ALCOHOL INPUT BROKEN\n");
		}

		switch (temp->exercise) {
		case 1:
			printf("EXCERCISE:\nNone\n");
			break;
		case 2:
			printf("EXCERCISE:\nLess than 2 per week\n");
			break;
		case 3:
			printf("EXCERCISE:\nMore than 2 per week\n");
			break;
		default:
			printf("EXCERCISE INPUT BROKEN\n");
		}
		temp = temp->NEXT;
	}
}

//Specific to searching via PPS number
void printSingle(struct node *top, char pps[9]) {
	//int found = 0;
	struct node * temp = top;

	while (temp != NULL) {
		if (strcmp(temp->pps, pps) == 0) {
			//found = 1;
			//return found;
			printf("***********************************************************************\n");
			printf("PPS;\n%s\n\n", temp->pps);
			printf("NAME:\n%s %s\n\n", temp->fName, temp->lName);
			printf("DOB:\n%s\n\n", temp->dob);
			printf("GENDER:\n %c\n\n", temp->gender);
			printf("EMAIL:\n %s\n\n", temp->email);
			printf("NEXT OF KIN:\n %s\n\n", temp->kin);
			printf("LAST APPOINTMENT DATE:\n %s\n\n", temp->lastApp);
			printf("WEIGHT - kg:\n %.3f\n\n", temp->weight);
			printf("HEIGHT - cm:\n %.3f\n\n", temp->height);
			printf("ALLERGIES TO MEDS:\n %c\n\n", temp->allergies);
			
			switch (temp->smoke) {
			case 1:
				printf("SMOKER:\nNo\n\n");
				break;
			case 2:
				printf("SMOKER:\nLess than 10 per day\n\n");
				break;
			case 3:
				printf("SMOKER:\nMore than 10 per day\n\n");
				break;
			default:
				printf("SMOKER INPUT BROKEN\n");
			}

			switch (temp->alco) {
			case 1:
				printf("ALCOHOL:\nNone\n");
				break;
			case 2:
				printf("ALCOHOL:\nLess than 10 units per week\n");
				break;
			case 3:
				printf("ALCOHOL:\nMore than 10 units week\n");
				break;
			default:
				printf("ALCOHOL INPUT BROKEN\n");
			}

			switch (temp->exercise) {
			case 1:
				printf("EXCERCISE:\nNone\n");
				break;
			case 2:
				printf("EXCERCISE:\nLess than 2 per week\n");
				break;
			case 3:
				printf("EXCERCISE:\nMore than 2 per week\n");
				break;
			default:
				printf("EXCERCISE INPUT BROKEN\n");
			}
		}
		temp = temp->NEXT;
	}
	//return found;
}

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

int searchList(struct node * top, char pps[9]) {
	int found = 0;
	struct node * temp = top;

	while (temp != NULL) {
		if (strcmp(temp->pps, pps) == 0) {
			found = 1;
			return found;
		}
		temp = temp->NEXT;
	}
	return found;
}
