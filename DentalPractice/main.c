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

/*Function declarations*/
void filePrint(struct node *top);
void reportPrint(struct node *top);

void loadFront(struct node **top, FILE* report);
void loadEnd(struct node *top, FILE* report);

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
	
	//open employee file
	FILE* readIn;
	readIn = fopen("patient.txt", "r");

	//load patient report
	if (readIn == NULL){
		//No patient records found
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
			/*printf("%.2f\n", BMI(185.4, 88.9));
			printf("%.2f\n", BMI(headPtr->height, headPtr->weight));*/
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

void loadFront(struct node **top, FILE* report){

	//file input variables
	int numRead;
	char pps[9];
	char fName[11];
	char lName[11];
	char dob[5];
	char gender;
	char email[31];
	char kin[21]; //change to two inputs?
	char lastApp[9];
	float weight;
	float height;
	char allergies;
	int smoke;
	int alco;
	int exercise;
	float BMI;

	//check number of entries
	numRead = fscanf(report, "%s %s %s %s %c %s %s %s %f %f %c %d %d %d %f", pps, fName, lName, dob, &gender, email, kin, 
		lastApp, &weight, &height, &allergies, &smoke, &alco, &exercise, &BMI);

	if (numRead == 15)
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
			strcpy(newNode->kin, kin);
			strcpy(newNode->lastApp, lastApp);
			newNode->weight = weight;
			newNode->height = height;
			newNode->allergies = allergies;
			newNode->smoke = smoke;
			newNode->alco = alco;
			newNode->exercise = exercise;
			newNode->BMI = BMI;
			
			//next pointer is the "old" head of list
			newNode->NEXT = *top;

			//new head is the new node
			*top = newNode;

		}//if
	}//if
}//loadFront

void loadEnd(struct node *top, FILE* report){

	//file input variables
	int numRead;
	char pps[9];
	char fName[11];
	char lName[11];
	char dob[5];
	char gender;
	char email[31];
	char kin[21]; //change to two inputs?
	char lastApp[9];
	float weight;
	float height;
	char allergies;
	int smoke;
	int alco;
	int exercise;
	float BMI;

	//check number of entries
	numRead = fscanf(report, "%s %s %s %s %c %s %s %s %f %f %c %d %d %d %f", pps, fName, lName, dob, &gender, email, kin,
		lastApp, &weight, &height, &allergies, &smoke, &alco, &exercise, &BMI);

	if (numRead == 15){

		//set new node pointer
		struct node* temp = top;
		struct node* newNode;

		//find end of list
		while (temp->NEXT != NULL)
		{
			temp = temp->NEXT;
		}

		//allocate memory for new node and set values
		newNode = (struct node*)malloc(1 * sizeof(struct node));
		
		strcpy(newNode->pps, pps);
		strcpy(newNode->fName, fName);
		strcpy(newNode->lName, lName);
		strcpy(newNode->dob, dob);
		newNode->gender = gender;
		strcpy(newNode->email, email);
		strcpy(newNode->kin, kin);
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

		//second last node points to new node
		temp->NEXT = newNode;

	}//if
}//loadEnd

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



