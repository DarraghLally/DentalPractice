#ifndef LINKED_LIST
#define LINKED_LIST

//Structure of a Patient
typedef struct node {
	char pps[9];
	char fName[11];
	char lName[11];
	char dob[4];
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

	struct node* NEXT;
}patient_t;

/*Function declarations*/

//LinkedList
void addElementAtStart(struct node **top);
void addElementToEnd(struct node *top);
//void addElementAtPos(struct node * top, int position);
void deleteElementAtStart(struct node ** top);
void deleteElementAtEnd(struct node * top);
void deleteElementAtPos(struct node * top, int position);
void printList(struct node *top);
void printSingle(struct node *top, char pps[9]); //Print via search with PPS
int listLength(struct node * top);
int searchList(struct node * top, char pps[9]);


#endif // !LINKED_LIST
