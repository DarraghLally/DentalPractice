#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"other.h"
#include"search.h"

int validEmail(char email[31]) {

	int len = strlen(email);
	int valEmail = 0;

	for (int i = 0; i < len; i++) {
		if (email[i] == '@') {
			valEmail++;
			break; //get out of loop
		}
	}

	if (email[len - 4] == '.') {
		valEmail++;
	}

	if (email[len - 3] == 'c') {
		valEmail++;
	}

	if (email[len - 2] == 'o') {
		valEmail++;
	}

	if (email[len - 1] == 'm') {
		valEmail++;
	}

	//Should return 5 if email is valid ie contains '@' and '.com' 
	return valEmail;
}

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
