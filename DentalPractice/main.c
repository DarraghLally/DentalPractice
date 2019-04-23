//Advanced Procedural Project
//Dental Practice Patient Database
//Darragh Lally - G00220290

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"search.h"
#include"other.h"
#include"load.h"

/*Function declarations*/
void filePrint(struct node *top);
void reportPrint(struct node *top);

void printStats(struct node *top, int total);

///////////////// M A I N \\\\\\\\\\\\\\\\\ M A I N ///////////////// M A I N \\\\\\\\\\\\\\\\\ M A I N ///////////////// M A I N \\\\\\\\\\\\\\\\\ M A I N /////////////////

void main() {

	//Variables
	int menuChoice;
	int editChoice;//Edit patient
	char fNameIn[11];//Edit patient
	char lNameIn[11];//Edit patient
	char ppsIn[9];//edit patient
	struct node* headPtr = NULL;
	char searchPPS[9];
	char userName[20];//Login
	char passWord[20];//Login
	int searchChoice; //search option 3
	char searchFirst[11];
	char searchLast[11];
	int totalPatients;
	
	//open employee file
	FILE* readIn;
	readIn = fopen("patient.txt", "r");

	//load patient report
	if (readIn == NULL){
		//No file found
		printf("\nPatient records not found!\n");
	}
	else{
		//load patient file
		while (!feof(readIn)){
			//check if head pointer in null
			if (headPtr == NULL){
				//head pointer is empty (not loaded)
				loadFront(&headPtr, readIn);
			}
			else{
				//list already contains items
				loadEnd(headPtr, readIn);
			}
		}//while

		//close file
		fclose(readIn);
	}//else

	//Check UserName and Password
	/*printf("Enter Username:\n");
	scanf("%s", userName);
	printf("Enter Password:\n");
	scanf("%s", passWord);*/

	do {
		printf("---------------------------------------\n");
		printf("(1) Add Patient\n(2) Display All Patients\n(3) Display Patient Details\n(4) Update Patient Details\n(5) Delete Patient\n"
			"(6) Generate Statistics\n(7) Create Report\n(8) List All Patients (Ordered by)\n(-1) Exit\n");
		printf("---------------------------------------\n\n");
		scanf("%d", &menuChoice);

		switch (menuChoice) {
		case 1:
			//If the database is empty, add at start. Otherwise add to end
			if (headPtr == NULL) { 
				addElementAtStart(&headPtr);
			}
			else {
				addElementToEnd(headPtr);
			}
			break;

		case 2:
			//Print all patients
			printList(headPtr);
			break;

		case 3:
			//Search for patient via PPS, print details
			//add search via name:  void searchName(headPtr, char first[11], char last[11])
			do {
				printf("(1) Search via Name\n(2) Search via PPS\n(0) Back\n");
				scanf("%d", &searchChoice);
				if (searchChoice == 1) {
					printf("Enter First Name:\n");
					scanf("%s", searchFirst);
					printf("Enter Last Name:\n");
					scanf("%s", searchLast);
					searchName(headPtr, searchFirst, searchLast);
				}
				else if (searchChoice == 2) {
					printf("Enter PPS to search: \n");
					scanf("%s", searchPPS);
					printSingle(headPtr, searchPPS);
				}
			} while (searchChoice!=0);
			break;

		case 4:
			//Search and Edit with either Name or PPS	
			do{
				printf("Please choose\n(1) Edit by Name or\n(2) Edit by PPS\n");
				scanf("%d", &editChoice);
				switch (editChoice) {
				case 1:
					//Search via Name
					printf("Enter First Name:\n");
					scanf("%s", fNameIn);
					printf("Enter Last Name:\n");
					scanf("%s", lNameIn);
					searchNameEdit(headPtr, fNameIn, lNameIn);
					break;
				case 2:
					//Search via PPS
					printf("Enter PPS:\n");
					scanf("%s", ppsIn);
					if (searchList(headPtr, ppsIn) == 1) {
						searchPPSEdit(headPtr, ppsIn);					
					}
					else {
						printf("Sorry the PPS does not exists in the Database\n");
					}
					break;
				default:
					printf("Invalid choice, please try again.\n");
					break;
				}
			} while (editChoice != 1 && editChoice != 2);
			break;

		case 5:
			//Delete Patent via PPS
			printf("Please enter PPS of Patient to be removed:\n");
			scanf("%s", searchPPS);
			int pos = findPos(headPtr, searchPPS);
			if (pos == 1) {
				deleteElementAtStart(&headPtr);
				printf("Patient record deleted\n");
			}
			else if(pos<listLength(headPtr)){
				deleteElementAtPos(headPtr, pos);
				printf("Patient record deleted\n");
			}
			else {
				break;
			}
			break;

		case 6:
			//Generate Stats
			totalPatients = listLength(headPtr);
			printStats(headPtr, totalPatients);				
			break;

		case 7:
			//Create Report.txt
			reportPrint(headPtr);
			printf("Report Generated...\n\n");
			break;

		case 8:
			//List all patients by order of last appointment
			break;
		case -1:
			filePrint(headPtr); //print database to file patient.txt
			printf("Exiting...\n\n\n");
						
			break;
		default:
			//printf("MENU INPUT VALIDATION WRONG");
			break;
		}
		
	} while (menuChoice != -1);
}//main()

///////////////// F U N C T I O N S \\\\\\\\\\\\\\\\\ F U N C T I O N S ///////////////// F U N C T I O N S \\\\\\\\\\\\\\\\\ F U N C T I O N S /////////////////

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

	//Second option - Smoke or Exercise
	printf("Generate BMI statistics based on one of the following:\n(1) Cigarette Intake\n(2) Exercise Amount\n(0) Back\n\n");
	scanf("%d", &statChoice);	
	//Smoke 
	if (statChoice == 1) {
		printf("(1) No smoking\n(2) Less than 10 per day\n(3) More than 10 per day\n\n");
		scanf("%d", &smokeChoice);
		while (temp != NULL) {
			if (smokeChoice == temp->smoke && temp->BMI < 18.5) {
				totalOne++;
			}
			if (smokeChoice == temp->smoke && temp->BMI < 25) {
				totalTwo++;
			}
			if (smokeChoice == temp->smoke && temp->BMI < 30) {
				totalThree++;
			}
			if (smokeChoice == temp->smoke && temp->BMI > 30) {
				totalFour++;
			}
			//Move to next patient
			temp = temp->NEXT;
		}
		
		//Find %'s
		aVal = ((float) totalOne /(float) patientTotal) * 100;
		bVal = ((float) totalTwo / (float)patientTotal) * 100;
		cVal = ((float) totalThree / (float)patientTotal) * 100;
		dVal = ((float) totalFour / (float) patientTotal) * 100;

		printf("DEBUG SMOKER STATS\n");
		printf("aVal: %f\n", aVal);
		printf("bVal: %f\n", bVal);
		printf("cVal: %f\n", cVal);
		printf("dVal: %f\n", dVal);
	}

	//Exercise
	if (statChoice == 2) {
		printf("(1) No exercise\n(2) Less than twice per week\n(3) More than twice per\n");
		scanf("%d", &exerciseChoice);
		while (temp != NULL) {
			if (exerciseChoice == temp->exercise && temp->BMI < 18.5) {
				totalOne++;
			}
			if (exerciseChoice == temp->exercise && temp->BMI < 25) {
				totalTwo++;
			}
			if (exerciseChoice == temp->exercise && temp->BMI < 30) {
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

		printf("DEBUG EXERCISE STATS\n");
		printf("aVal: %f\n", aVal);
		printf("bVal: %f\n", bVal);
		printf("cVal: %f\n", cVal);
		printf("dVal: %f\n", dVal);
	}
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
		//Formatting smoke integer values for report output for ease of reading
		//if (temp->smoke == 1) {
		//	strcpy(smokeReport, "None");
		//}
		//else if (temp->smoke == 2) {
		//	strcpy(smokeReport, "Less than 10 per day");
		//}
		//else if (temp->smoke == 3) {
		//	//smokeReport[50] = "More than 10 per day";
		//	strcpy(smokeReport, "More than 10 per day");
		//}
		//else {
		//	printf("ERROR in smoker question intake\n");
		//}

		////Formatting alcohol
		//if (temp->alco == 1) {
		//	alcoReport[50] = "None";
		//}
		//else if (temp->alco == 2) {
		//	alcoReport[50] = "Less than 10 units per week";
		//}
		//else if (temp->alco == 3) {
		//	alcoReport[50] = "More than 10 units per week";
		//}
		//else {
		//	printf("ERROR in alcohol question intake\n");
		//}

		////Formatting exercise
		//if (temp->exercise == 1) {
		//	exerciseReport[50] = "Never";
		//}
		//else if (temp->exercise == 2) {
		//	exerciseReport[50] = "Less than twice per week";
		//}
		//else if (temp->exercise == 3) {
		//	exerciseReport[50] = "More than twice per week";
		//}
		//else {
		//	exerciseReport[50] = "ERROR";
		//	printf("ERROR in exercise question intake\n");
		//}

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



