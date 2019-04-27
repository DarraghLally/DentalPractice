#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"other.h"
#include"search.h"
#include"load.h"
#include"outputs.h"

void loadFront(struct node **top, FILE* report) {

	//file input variables
	int numRead;
	char pps[9];
	char fName[11];
	char lName[11];
	char dob[5];
	char gender;
	char email[31];
	char fKin[11];
	char lKin[11];
	char lastApp[9];
	float weight;
	float height;
	char allergies;
	int smoke;
	int alco;
	int exercise;
	float BMI;

	//check number of entries
	numRead = fscanf(report, "%s %s %s %s %c %s %s %s %s %f %f %c %d %d %d %f", pps, fName, lName, dob, &gender, email, fKin, lKin,
		lastApp, &weight, &height, &allergies, &smoke, &alco, &exercise, &BMI);

	if (numRead == 16)
	{
		if (*top == NULL)
		{
			//set new node pointer
			struct node* newNode;

			//allocate memory for new node and set values
			newNode = (struct node*)malloc(1 * sizeof(struct node));
			strcpy(newNode->pps, pps);
			strcpy(newNode->fName, fName);
			strcpy(newNode->lName, lName);
			strcpy(newNode->dob, dob);
			newNode->gender = gender;
			strcpy(newNode->email, email);
			strcpy(newNode->fKin, fKin);
			strcpy(newNode->lKin, lKin);
			strcpy(newNode->lastApp, lastApp);
			newNode->weight = weight;
			newNode->height = height;
			newNode->allergies = allergies;
			newNode->smoke = smoke;
			newNode->alco = alco;
			newNode->exercise = exercise;
			newNode->BMI = BMI;

			newNode->NEXT = *top;

			*top = newNode;

		}//if
	}//if
}//loadFront

void loadEnd(struct node *top, FILE* report) {

	//file input variables
	int numRead;
	char pps[9];
	char fName[11];
	char lName[11];
	char dob[5];
	char gender;
	char email[31];
	char fKin[11];
	char lKin[11];
	char lastApp[9];
	float weight;
	float height;
	char allergies;
	int smoke;
	int alco;
	int exercise;
	float BMI;

	//check number of entries
	numRead = fscanf(report, "%s %s %s %s %c %s %s %s %s %f %f %c %d %d %d %f", pps, fName, lName, dob, &gender, email, fKin, lKin,
		lastApp, &weight, &height, &allergies, &smoke, &alco, &exercise, &BMI);

	if (numRead == 16) {

		//set new node pointer
		struct node* temp = top;
		struct node* newNode;

		//find end of list
		while (temp->NEXT != NULL)
		{
			temp = temp->NEXT;
		}

		//allocate memory for new node
		newNode = (struct node*)malloc(1 * sizeof(struct node));

		strcpy(newNode->pps, pps);
		strcpy(newNode->fName, fName);
		strcpy(newNode->lName, lName);
		strcpy(newNode->dob, dob);
		newNode->gender = gender;
		strcpy(newNode->email, email);
		strcpy(newNode->fKin, fKin);
		strcpy(newNode->lKin, lKin);
		strcpy(newNode->lastApp, lastApp);
		newNode->weight = weight;
		newNode->height = height;
		newNode->allergies = allergies;
		newNode->smoke = smoke;
		newNode->alco = alco;
		newNode->exercise = exercise;
		newNode->BMI = BMI;

		//new node is end of list
		newNode->NEXT = NULL;

		//old last points to new last
		temp->NEXT = newNode;

	}//if
}//loadEnd
