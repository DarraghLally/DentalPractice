#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"search.h"
#include"other.h"
#include"load.h"
#include"outputs.h"

void printStats(struct node *top, int total) {
	struct node * temp = top;
	int statChoice, smokeChoice, exerciseChoice;
	int patientTotal = total;
	int totalOne = 0;
	int totalTwo = 0;
	int totalThree = 0;
	int totalFour = 0;
	float aVal = 0;
	float bVal = 0;
	float cVal = 0;
	float dVal = 0;

	//File pointer & open as patient.txt
	FILE* output;
	output = fopen("stats.txt", "a");


	//Second option - Smoke or Exercise
	printf("Generate BMI statistics based on one of the following:\n(1) Cigarette Intake\n(2) Exercise Amount\n(0) Back\n\n");
	scanf("%d", &statChoice);
	//Smoke 
	if (statChoice == 1) {
		printf("(1) No smoking\n(2) Less than 10 per day\n(3) More than 10 per day\n\n");
		scanf("%d", &smokeChoice);
		while (temp != NULL) {
			if (smokeChoice == temp->smoke && temp->BMI <= 18.5) {
				totalOne++;
			}
			if (smokeChoice == temp->smoke && temp->BMI > 18.5 && temp->BMI <= 25) {
				totalTwo++;
			}
			if (smokeChoice == temp->smoke && temp->BMI > 25 && temp->BMI <= 30) {
				totalThree++;
			}
			if (smokeChoice == temp->smoke && temp->BMI > 30) {
				totalFour++;
			}
			//Move to next patient
			temp = temp->NEXT;
		}

		//Find %'s
		aVal = ((float)totalOne / (float)patientTotal) * 100;
		bVal = ((float)totalTwo / (float)patientTotal) * 100;
		cVal = ((float)totalThree / (float)patientTotal) * 100;
		dVal = ((float)totalFour / (float)patientTotal) * 100;

		printf("SMOKER STATS\n");
		printf("aVal: %.2f\n", aVal);
		printf("bVal: %.2f\n", bVal);
		printf("cVal: %.2f\n", cVal);
		printf("dVal: %.2f\n\n", dVal);

		fprintf(output, "SMOKER STATS\n");
		fprintf(output, "A: %% of patients with BMI less than 18.5 -> %.2f%%\n", aVal);
		fprintf(output, "B: %% of patients with BMI less than 25 -> %.2f%%\n", bVal);
		fprintf(output, "C: %% of patients with BMI less than 30 -> %.2f%%\n", cVal);
		fprintf(output, "D: %% of patients with BMI greater than 30 -> %.2f%%\n\n", dVal);
	}

	//Exercise
	if (statChoice == 2) {
		printf("(1) No exercise\n(2) Less than twice per week\n(3) More than twice per\n");
		scanf("%d", &exerciseChoice);
		while (temp != NULL) {
			if (exerciseChoice == temp->exercise && temp->BMI <= 18.5) {
				totalOne++;
			}
			if (exerciseChoice == temp->exercise && temp->BMI > 18.5 && temp->BMI <= 25) {
				totalTwo++;
			}
			if (exerciseChoice == temp->exercise && temp->BMI > 25 && temp->BMI <= 30) {
				totalThree++;
			}
			if (exerciseChoice == temp->exercise && temp->BMI > 30) {
				totalFour++;
			}
			//Move to next patient
			temp = temp->NEXT;
		}
		//Find %'s
		aVal = ((float)totalOne / (float)patientTotal) * 100;
		bVal = ((float)totalTwo / (float)patientTotal) * 100;
		cVal = ((float)totalThree / (float)patientTotal) * 100;
		dVal = ((float)totalFour / (float)patientTotal) * 100;

		printf("EXERCISE STATS\n");
		printf("aVal: %.2f\n", aVal);
		printf("bVal: %.2f\n", bVal);
		printf("cVal: %.2f\n", cVal);
		printf("dVal: %.2f\n\n", dVal);

		fprintf(output, "EXERCISE STATS\n");
		fprintf(output, "A: %% of patients with BMI less than 18.5 -> %.2f%%\n", aVal);
		fprintf(output, "B: %% of patients with BMI less than 25 -> %.2f%%\n", bVal);
		fprintf(output, "C: %% of patients with BMI less than 30 -> %.2f%%\n", cVal);
		fprintf(output, "D: %% of patients with BMI greater than 30 -> %.2f%%\n\n", dVal);
	}

	//Close file
	fclose(output);
}

void reportPrint(struct node *top) {
	//File pointer & open as patient.txt
	FILE* output;
	output = fopen("report.txt", "w");

	struct node* temp;
	temp = top;

	char smokeReport[50];
	char alcoReport[50];
	char exerciseReport[50];

	while (temp != NULL) {
		//Print to file report.txt
		fprintf(output, "PPS: %s\n", temp->pps);
		fprintf(output, "Fname: %s\n", temp->fName);
		fprintf(output, "Lname: %s\n", temp->lName);
		fprintf(output, "DOB: %s\n", temp->dob);
		fprintf(output, "Gender: %c\n", temp->gender);
		fprintf(output, "Email: %s\n", temp->email);
		fprintf(output, "Next of kin: %s\n", temp->kin);
		fprintf(output, "Last App: %s\n", temp->lastApp);
		fprintf(output, "Weight: %.2f\n", temp->weight);
		fprintf(output, "Height: %.2f\n", temp->height);
		fprintf(output, "Allergies: %c\n", temp->allergies);
		fprintf(output, "Smoke: %d\n", temp->smoke);
		fprintf(output, "Alcohol: %d\n", temp->alco);
		fprintf(output, "Exercise: %d\n", temp->exercise);
		fprintf(output, "BMI: %.2f\n", temp->BMI);
		fprintf(output, "--------------------------------------------------------------------------------------------\n");
		//point to next node
		temp = temp->NEXT;
	}
	//Close file
	fclose(output);
}

void filePrint(struct node *top) {
	//File pointer & open as patient.txt
	FILE* output;
	output = fopen("patient.txt", "w");

	struct node* temp;
	temp = top;

	while (temp != NULL) {
		fprintf(output, "%s %s %s %s %c %s %s %s %f %f %c %d %d %d %f\n", temp->pps, temp->fName, temp->lName, temp->dob, temp->gender,
			temp->email, temp->kin, temp->lastApp, temp->weight, temp->height, temp->allergies, temp->smoke, temp->alco, temp->exercise, temp->BMI);
		temp = temp->NEXT;
	}
	//Close file
	fclose(output);
}