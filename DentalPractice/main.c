//Advanced Procedural Project
//Dental Practice Patient Database
//Darragh Lally - G00220290
//Visual Studio 2017 - Version 15.8.8

/*
(1) Run main.c

(2) Use login details -

	username: martin
	password: mhynes

	username: admin
	password: 123456

	username: test
	password: 654321

	username: daza
	password: 666666

	Or - add your own to login.txt in the project folder - Very secure :)

(3) Use menu to navigate

Note: Database has some patient details loaded when correct login details are entered
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"search.h"
#include"other.h"
#include"load.h"
#include"outputs.h"

//Struct to hold login information
typedef struct {
	char fileUserName[11];
	char filePassWord[7];
}login_t;

///////////////// M A I N \\\\\\\\\\\\\\\\\ M A I N ///////////////// M A I N \\\\\\\\\\\\\\\\\ M A I N ///////////////// M A I N \\\\\\\\\\\\\\\\\ M A I N /////////////////

void main() {

	//Variables
	int menuChoice;//Main menu option
	int editChoice;//Edit patient
	char fNameIn[11];//Edit patient
	char lNameIn[11];//Edit patient
	char ppsIn[9];//Edit patient
	char searchPPS[9];//search
	int searchChoice; //search option 3
	char searchFirst[11]; //search via name
	char searchLast[11]; //search via name
	int totalPatients;//Stats 
	char userName[11];//Login
	char passWord[7]; //login
	int numInputs; //file read validation
	int i = 0; //loop control
	struct node* headPtr = NULL;

	FILE* readLogin; //pointer to login file
	readLogin = fopen("login.txt", "r"); //open login
	login_t login; //struct

	//Print Display
	printf("---------------------------------------\n\nWELCOME TO ABC DENTAL PRACTICE\n\n---------------------------------------\n\n");

	//Prompt and read user input for username and password
	printf("Enter User Name: \n");
	scanf("%s", userName);
	printf("\nEnter Password (max 6 characters): \n");

	//Mask user input with * - code from https://www.geeksforgeeks.org/print-in-place-of-characters-for-reading-passwords-in-c/
	do {
		passWord[i] = getch();
		if (passWord[i] != '\r') {
			printf("*");
		}
		i++;
	} while (passWord[i - 1] != '\r');
	passWord[i - 1] = '\0';

	//No login
	if (readLogin == NULL) {
		//No login file found
		printf("No Login File Found...\n");
	}
	//Login found
	else {

		//Read login file
		while (!feof(readLogin)) {

			//Check num of inputs to prevent a re-read of last line in file
			numInputs = fscanf(readLogin, "%s %s", login.fileUserName, login.filePassWord);

			//Check numInputs and login details - If all ok, run program
			if (numInputs == 2 && strcmp(userName, login.fileUserName) == 0 && strcmp(passWord, login.filePassWord) == 0)
			{
				printf("\n\nLOGIN SUCCESS!\n");				

				//open patient file
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
							//First time around set the head pointer
							loadFront(&headPtr, readIn);
						}
						else{
							//Next time load frmo the end
							loadEnd(headPtr, readIn);
						}
					}//while

					//close file
					fclose(readIn);
				}//else

				do {
					//print menu until user enters -1
					printf("\n---------------------------------------\n");
					printf("(1) Add Patient\n(2) Display All Patients\n(3) Display Patient Details\n(4) Update Patient Details\n(5) Delete Patient\n"
						"(6) Generate Statistics\n(7) Create Report\n(8) List All Patients (Ordered by)\n(-1) Exit\n");
					printf("---------------------------------------\n");
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
						//Search for patient via PPS or Name, print details
						do {
							printf("---------------------------------------\n");
							printf("\n(1) Search via Name\n(2) Search via PPS\n(0) Back\n");
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
						}
						else if(pos<listLength(headPtr)){
							deleteElementAtPos(headPtr, pos);
						}
						else {
							deleteElementAtEnd(headPtr);
						}
						break;

					case 6:
						//Generate Stats
						totalPatients = listLength(headPtr);
						printStats(headPtr, totalPatients);				
						break;

					case 7:
						//Create report.txt - User readable report on all patients
						reportPrint(headPtr);
						printf("Report Generated...\n\n");
						break;

					case 8:
						//List all patients by order of last appointment
						break;

					case -1:
						//Exit and print database to file patient.txt
						filePrint(headPtr); 
						printf("Exiting...\n\n\n");					
						break;

					default:			
						break;
					}
				} while (menuChoice != -1);
			}//if

		}//while

		//close login file
		fclose(readLogin);

	}//else
}//main()

///////////////// F U N C T I O N S \\\\\\\\\\\\\\\\\ F U N C T I O N S ///////////////// F U N C T I O N S \\\\\\\\\\\\\\\\\ F U N C T I O N S /////////////////





