#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"other.h"
#include"search.h"
#include"outputs.h"

//Email Validation - Must include @ and .com
int validEmail(char email[31]) {

	int len = strlen(email);
	int valEmail = 0;

	//Check array for @ symbol. Add to count if found
	for (int i = 0; i < len; i++) {
		if (email[i] == '@') {
			valEmail++;
			break; //get out of loop
		}
	}

	//Check array for . at index-4 position, add to count if found
	if (email[len - 4] == '.') {
		valEmail++;
	}

	//Check array for c at index-3 position, add to count if found
	if (email[len - 3] == 'c') {
		valEmail++;
	}

	//Check array for c at index-2 position, add to count if found
	if (email[len - 2] == 'o') {
		valEmail++;
	}

	//Check array for c at index-1 position, add to count if found
	if (email[len - 1] == 'm') {
		valEmail++;
	}

	//Should return 5 if email is valid ie contains '@' and '.com' 
	return valEmail;
}

//Vaildation for multi choice resposes to questions.
int validMultiChoice(int input) {
	int val = 0;

	if (input == 1) {
		val++;
	}
	if (input == 2) {
		val++;
	}
	if (input == 3) {
		val++;
	}
	//returns 1 if input is correct
	return val;
}
