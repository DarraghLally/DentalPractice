#ifndef SEARCH_FUNCTIONS
#define SEARCH_FUNCTIONS

int searchList(struct node * top, char pps[9]);
void printSingle(struct node *top, char pps[9]); //Print via search with PPS
void searchName(struct node *top, char first[11], char last[11]);
void searchNameEdit(struct node *top, char first[11], char last[11]);
void searchPPSEdit(struct node *top, char pps[9]);
int findPos(struct node *top, char pps[9]);

#endif
