#ifndef LINKED_LIST
#define LINKED_LIST

//Structure of a Patient
typedef struct node {
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

	struct node* NEXT;
}patient_t;

/*Function declarations*/

//LinkedList
void addElementAtStart(struct node **top);
void addElementToEnd(struct node *top);
void deleteElementAtStart(struct node ** top);
void deleteElementAtEnd(struct node * top);
void deleteElementAtPos(struct node * top, int position);
int listLength(struct node * top);


#endif // !LINKED_LIST
