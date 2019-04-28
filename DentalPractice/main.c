//Advanced Procedural Project
//Dental Practice Patient Database
//Darragh Lally - G00220290
//Visual Studio 2017

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"search.h"
#include"other.h"
#include"load.h"
#include"outputs.h"

typedef struct {
	char fileUserName[11];
	char filePassWord[7];
}login_t;

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
	int searchChoice; //search option 3
	char searchFirst[11];
	char searchLast[11];
	int totalPatients;

//////////////////////////////////////////////////////////////////	

	//Login
	char userName[11];
	char passWord[7];
	FILE* readLogin;
	login_t login;
	int numInputs;
	int isLogin = 0;
	readLogin = fopen("login.txt", "r");

	printf("Enter User Name: \n");
	scanf("%s", userName);
	printf("Enter Password: \n");
	scanf("%s", passWord);

	if (readLogin == NULL) {
		//No login file found
		printf("No Login File Found...\n");
	}
	else {
		while (!feof(readLogin)) {

			numInputs = fscanf(readLogin, "%s %s", login.fileUserName, login.filePassWord);

			if (numInputs == 2 && strcmp(userName, login.fileUserName) == 0 && strcmp(passWord, login.filePassWord) == 0)
			{
				printf("LOGIN SUCCESS!\n\n");				

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
						//print database to file patient.txt
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





