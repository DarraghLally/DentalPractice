//Advanced Procedural Project
//Dental Practice Patient Database
//Darragh Lally - G00220290

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"search.h"

/*Function declarations*/
void filePrint(struct node *top);
void reportPrint(struct node *top);

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
			//Search for patient via PPS
			printf("Enter PPS to search: \n");
			scanf("%s", searchPPS);
			printSingle(headPtr, searchPPS);
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
					searchNameEdit(headPtr, fNameIn, lNameIn); //Search and edit patient details via name
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
						
						//Add option to add to database
					}
					break;
				default:
					printf("Invalid choice, please try again.\n");
					break;
				}
			} while (editChoice != 1 && editChoice != 2);

			break;
		case 5:
			//deleteElementAtPos(headPtr, pps);
			//Need to fix function to take in string pps and search using string functions

			break;
		case 6:
			//Generate Stats
			break;
		case 7:
			//Create Report.txt
			reportPrint(headPtr);
			printf("Report Generated...\n\n");
			break;
		case 8:
			//List all patients by order of last appointment
			printf("%.2f\n", BMI(185.4, 88.9));
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
		//	smokeReport[50] = "None";
		//}
		//else if (temp->smoke == 2) {
		//	smokeReport[50] = "Less than 10 per day";
		//}
		//else if (temp->smoke == 3) {
		//	smokeReport[50] = "More than 10 per day";
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
		fprintf(output, "PPS: \t%s\n", temp->pps);
		fprintf(output, "Fname: \t\t%s\n", temp->fName);
		fprintf(output, "Lname: \t\t%s\n", temp->lName);
		fprintf(output, "DOB: \t%s\n", temp->dob);
		fprintf(output, "GEN: \t%c\n", temp->gender);
		fprintf(output, "EMAIL: \t%s\n", temp->email);
		fprintf(output, "Kin: \t%s\n", temp->kin);
		fprintf(output, "Last App: \t%s\n", temp->lastApp);
		fprintf(output, "weight: \t%.2f\n", temp->weight);
		fprintf(output, "height: \t%.2f\n", temp->height);
		fprintf(output, "allergies: \t%c\n", temp->allergies);
		fprintf(output, "smoke: \t%d\n", temp->smoke);
		fprintf(output, "alcohol: \t%d\n", temp->alco);
		fprintf(output, "exercise: \t%d\n", temp->exercise);
		fprintf(output, "BMI: \t%.2f\n", temp->BMI);

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



