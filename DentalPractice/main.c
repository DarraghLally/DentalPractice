//Advanced Procedural Project
//Dental Practice Patient Database
//Darragh Lally - G00220290

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"

/*Function declarations*/
float BMI(float h, float w);

///////////////// M A I N \\\\\\\\\\\\\\\\\ M A I N ///////////////// M A I N \\\\\\\\\\\\\\\\\ M A I N ///////////////// M A I N \\\\\\\\\\\\\\\\\ M A I N /////////////////

void main() {

	//Variables
	int menuChoice;
	int editChoice;
	struct node* headPtr = NULL;
	char searchPPS[9];
	char userName[20];
	char passWord[20];


	//Check UserName and Password
	/*printf("Enter Username:\n");
	scanf("%s", userName);
	printf("Enter Password:\n");
	scanf("%s", passWord);*/

	do {
		printf("(1) Add Patient\n(2) Display All Patients\n(3) Display Patient Details\n(4) Update Patient Details\n(5) Delete Patient\n(6) Generate Statistics\n(7) Create Report\n(8) List All Patients (Ordered by)\n(-1) Exit\n");
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
			//updatePatient(headPtr);
			//Search with either Name or PPS
			//Update details
			do {
				switch (editChoice) {
				case 1:
					//Search via Name
					break;
				case 2:
					//Search via PPS
					break;
				default:
					printf("Invalid choice, please try again.\n");
				}
				printf("(1) Enter Name:\n(2) Enter PPS:\n");
				scanf("%d", &editChoice);
			} while (editChoice!=1 || editChoice!=2);

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
			break;
		case 8:
			//List all patients by order of last appointment
			printf("%f", BMI(185.4, 88.9));
			break;
		case -1:
			printf("Exiting...\n\n\n");
			//Update patient files here
			break;
		default:
			//printf("MENU INPUT VALIDATION WRONG");
			break;
		}
		
	} while (menuChoice != -1);
}//main()

///////////////// F U N C T I O N S \\\\\\\\\\\\\\\\\ F U N C T I O N S ///////////////// F U N C T I O N S \\\\\\\\\\\\\\\\\ F U N C T I O N S /////////////////

float BMI(float h, float w) {
	//kg*M^2
	float BMI;
	float hM = h / 100; //hM = height in Meters
	BMI = w*(hM*hM);
	return BMI;
}
