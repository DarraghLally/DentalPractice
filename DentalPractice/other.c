#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
#include"validation.h"
#include"other.h"
#include"search.h"
#include"load.h"

float BMI(float h, float w) {
	// BMI = kg/(M^M) where M is height in meters
	float hM = h / 100; //hM = height in Meters
	return w / (hM*hM);
}