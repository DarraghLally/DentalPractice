#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"search.h"
#include"other.h"
#include"load.h"
#include"outputs.h"

//Print Patient details to screen - Option 2
void printList(struct node *top) {
	struct node* temp;
	temp = top;
	while (temp != NULL) {
		printf("---------------------------------------\n\n");
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
			printf("EXCERCISE: Less than twice per week\n");
			break;
		case 3:
			printf("EXCERCISE: More than twice per week\n");
			break;
		default:
			printf("EXCERCISE INPUT BROKEN\n");
		}

		printf("BMI: %.2f\n", temp->BMI);

		temp = temp->NEXT;
	}
}

//Function for Menu Option 6 - Generate Stats
void printStats(struct node *top, int total) {

	//Variables
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

	//Generate on either: Smoke or Exercise
	printf("Generate BMI statistics based on one of the following:\n(1) Cigarette Intake\n(2) Exercise Amount\n(0) Back\n\n");
	scanf("%d", &statChoice);

	//Smoke 
	if (statChoice == 1) {

		//Prompt and read choice
		printf("(1) No smoking\n(2) Less than 10 per day\n(3) More than 10 per day\n\n");
		scanf("%d", &smokeChoice);

		//Go through database
		while (temp != NULL) {

			//Add to a total if conditions are met
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

		//Find and store %'s - 
		//calculation: (total number of patients who fit the requirements) / (total number of patients in database) * 100
		//totals need to be cast to floats because I am taking the info in as ints but want to display % accuratly
		aVal = ((float)totalOne / (float)patientTotal) * 100;
		bVal = ((float)totalTwo / (float)patientTotal) * 100;
		cVal = ((float)totalThree / (float)patientTotal) * 100;
		dVal = ((float)totalFour / (float)patientTotal) * 100;

		//Print stats to console
		printf("\n---------------------------------------\nSMOKER STATS\n");
		switch (smokeChoice) {
		case 1:
			printf("Based on Non-Smokers\n\n");
			break;
		case 2:
			printf("Based on less than ten per day\n\n");
			break;
		case 3:
			printf("Based on greater than ten per day\n\n");
			break;
		default:
			printf("\n");
		}
		printf("A: %% of patients with BMI less than 18.5 -> %.2f%%\n", aVal);
		printf("B: %% of patients with BMI less than 25 -> %.2f%%\n", bVal);
		printf("C: %% of patients with BMI less than 30 -> %.2f%%\n", cVal);
		printf("D: %% of patients with BMI greater than 30 -> %.2f%%\n", dVal);

		//Print to file - stats.txt
		fprintf(output, "\n---------------------------------------\nSMOKER STATS\n");
		switch (smokeChoice) {
		case 1:
			fprintf(output, "Based on Non-Smokers\n\n");
			break;
		case 2:
			fprintf(output, "Based on less than ten per day\n\n");
			break;
		case 3:
			fprintf(output, "Based on greater than ten per day\n\n");
			break;
		default:
			fprintf(output, "\n");
		}
		fprintf(output, "A: %% of patients with BMI less than 18.5 -> %.2f%%\n", aVal);
		fprintf(output, "B: %% of patients with BMI less than 25 -> %.2f%%\n", bVal);
		fprintf(output, "C: %% of patients with BMI less than 30 -> %.2f%%\n", cVal);
		fprintf(output, "D: %% of patients with BMI greater than 30 -> %.2f%%\n", dVal);
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

		//Console print
		printf("\n---------------------------------------\nEXERCISE STATS\n");
		switch (exerciseChoice) {
		case 1:
			printf("Based on No Exercise\n\n");
			break;
		case 2:
			printf("Based on less than twice per week\n\n");
			break;
		case 3:
			printf("Based on greater than twice per week\n\n");
			break;
		default:
			printf("\n");
		}
		printf("A: %% of patients with BMI less than 18.5 -> %.2f%%\n", aVal);
		printf("B: %% of patients with BMI less than 25 -> %.2f%%\n", bVal);
		printf("C: %% of patients with BMI less than 30 -> %.2f%%\n", cVal);
		printf("D: %% of patients with BMI greater than 30 -> %.2f%%\n", dVal);

		//File print
		fprintf(output, "\n---------------------------------------\nEXERCISE STATS\n");
		switch (exerciseChoice) {
		case 1:
			fprintf(output, "Based on No Exercise\n\n");
			break;
		case 2:
			fprintf(output, "Based on less than twice per week\n\n");
			break;
		case 3:
			fprintf(output, "Based on greater than twice per week\n\n");
			break;
		default:
			fprintf(output, "\n");
		}
		fprintf(output, "A: %% of patients with BMI less than 18.5 -> %.2f%%\n", aVal);
		fprintf(output, "B: %% of patients with BMI less than 25 -> %.2f%%\n", bVal);
		fprintf(output, "C: %% of patients with BMI less than 30 -> %.2f%%\n", cVal);
		fprintf(output, "D: %% of patients with BMI greater than 30 -> %.2f%%\n", dVal);
	}

	//Close file
	fclose(output);
}

//Print User Readable Report on all patients and their details to file - report.txt
void reportPrint(struct node *top) {

	//File pointer & open as patient.txt
	FILE* output;
	output = fopen("report.txt", "w");

	//Variables
	struct node* temp;
	temp = top;
	char smokeReport[50];
	char alcoReport[50];
	char exerciseReport[50];

	//Go through database
	while (temp != NULL) {

		//Print to file report.txt
		fprintf(output, "PPS: %s\n", temp->pps);
		fprintf(output, "Fname: %s\n", temp->fName);
		fprintf(output, "Lname: %s\n", temp->lName);
		fprintf(output, "DOB: %s\n", temp->dob);
		fprintf(output, "Gender: %c\n", temp->gender);
		fprintf(output, "Email: %s\n", temp->email);
		fprintf(output, "Next of kin: %s %s\n", temp->fKin, temp->lKin);
		fprintf(output, "Last App: %s\n", temp->lastApp);
		fprintf(output, "Weight: %.2f\n", temp->weight);
		fprintf(output, "Height: %.2f\n", temp->height);
		fprintf(output, "Allergies: %c\n", temp->allergies);
		//fprintf(output, "Smoke: %d\n", temp->smoke);
		//fprintf(output, "Alcohol: %d\n", temp->alco);
		//fprintf(output, "Exercise: %d\n", temp->exercise);
		switch (temp->smoke) {
		case 1:
			fprintf(output, "SMOKER: No\n");
			break;
		case 2:
			fprintf(output, "SMOKER: Less than 10 per day\n");
			break;
		case 3:
			fprintf(output, "SMOKER: More than 10 per day\n");
			break;
		default:
			fprintf(output, "SMOKER INPUT BROKEN\n");
		}

		switch (temp->alco) {
		case 1:
			fprintf(output, "ALCOHOL: None\n");
			break;
		case 2:
			fprintf(output, "ALCOHOL: Less than 10 units per week\n");
			break;
		case 3:
			fprintf(output, "ALCOHOL: More than 10 units week\n");
			break;
		default:
			fprintf(output, "ALCOHOL INPUT BROKEN\n");
		}

		switch (temp->exercise) {
		case 1:
			fprintf(output, "EXCERCISE: None\n");
			break;
		case 2:
			fprintf(output, "EXCERCISE: Less than 2 per week\n");
			break;
		case 3:
			fprintf(output, "EXCERCISE: More than 2 per week\n");
			break;
		default:
			fprintf(output, "EXCERCISE INPUT BROKEN\n");
		}
		fprintf(output, "BMI: %.2f\n", temp->BMI);
		fprintf(output, "---------------------------------------\n");

		//point to next node
		temp = temp->NEXT;
	}
	//Close file
	fclose(output);
}

//Print database to file
void filePrint(struct node *top) {

	//File pointer & open as patient.txt
	FILE* output;
	output = fopen("patient.txt", "w");

	struct node* temp;
	temp = top;

	//Go through database
	while (temp != NULL) {

		//Print patient variables to file
		fprintf(output, "%s %s %s %s %c %s %s %s %s %f %f %c %d %d %d %f\n", temp->pps, temp->fName, temp->lName, temp->dob, temp->gender,
			temp->email, temp->fKin, temp->lKin, temp->lastApp, temp->weight, temp->height, temp->allergies, temp->smoke, temp->alco, temp->exercise, temp->BMI);

		//Point to next patient
		temp = temp->NEXT;
	}
	//Close file
	fclose(output);
}