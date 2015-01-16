#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayOps.h"

int checkCOndition(int ele,int index,int *array){
	return ele>3;
}

int checkConditionForChar(char ele,int index,char *array){
	return ele != 'a';
}

int checkConditionForFLoat(float ele,int index,float *array){
	return ele>2.1;
}

int multipler(int ele, int index, int *array){
	return ele*2;
}

float adder(float ele, int index, float *array){
	return ele+1;
}

char to_upperCase(char ele, int index, char *array){
	return (char)toupper((int)ele);
}

void test_to_filter_the_array(){
	int array[5] = {1,2,3,4,5};
	int len = 5,*result;
	assertEqual(filter_int(array,checkCOndition,len,&result), 2);
}

void test_to_filter_the_array_returns_zero_if_result_array_is_empty(){
	int array[3] = {1,2,3};
	int len = 3,*result;
	assertEqual(filter_int(array,checkCOndition,len,&result), 0);
}

void test_to_filter_the_array_populates_result_array(){
	int array[5] = {1,2,3,4,5};
	int len = 5,*result;
	assertEqual(filter_int(array,checkCOndition,len,&result), 2);
	assertEqual(result[0], 4);
	assertEqual(result[1], 5);
}


void test_to_filter_the_float_array(){
	float array[3] = {1.23,2.54,3.50};
	float len = 3,*result;
	assertEqual(filter_float(array,checkConditionForFLoat,len,&result), 2);
}


void test_to_filter_the_float_array_populates_result_array(){
	float array[5] = {1.0,2.0,3.0,4.34,5.87};
	float len = 5,*result;
	assertEqual(filter_float(array,checkConditionForFLoat,len,&result), 3);
	assertEqual(result[0], 3.0);
}


void test_to_filter_the_char_array(){
	char array[3] = {'a','b','a'};
	char len = 3,*result;
	assertEqual(filter_char(array,checkConditionForChar,len,&result), 1);
}


void test_to_filter_the_char_array_populates_result_array(){
	char array[4] = {'a','b','a','c'};
	char len = 4,*result;
	assertEqual(filter_char(array,checkConditionForChar,len,&result), 2);
	assertEqual(result[0], 'b');
	assertEqual(result[1], 'c');
}

void test_to_map_0_1_2_3_4_to_0_2_4_6_8(){
	int array[5]={0,1,2,3,4},*result;
	result=map_int(array, multipler, 5);
	assertEqual(result[0], 0);
	assertEqual(result[1], 2);
	assertEqual(result[2], 4);
	assertEqual(result[3], 6);
	assertEqual(result[4], 8);
}

void test_to_map_array_with_no_elements_give_to_0(){
	int array[]={},*result;
	result=map_int(array, multipler, 0);
	assertEqual(result[0], 0);
}

void test_to_map_decimal_numbers_by_adding_1_to_each_element(){
	float array[5]={0.0,0.1,0.2,0.3,0.4};
	float *result_array;
	result_array=map_float(array, adder, 5);
	assertEqual(result_array[0], 1.0);
	assertEqual(result_array[1], (float)1.1);
	assertEqual(result_array[2], (float)1.2);
	assertEqual(result_array[3], (float)1.3);
	assertEqual(result_array[4], (float)1.4);
}

void test_to_map_float_array_with_no_elements_give_to_0(){
	float array[]={},*result;
	result=map_float(array, adder, 0);
	assertEqual(result[0], 0);
}

void test_to_map_char_by_changing_caes(){
	char array[5]={'a','b','c','d','e'};
	char *result;
	result=map_char(array, to_upperCase, 5);
	assertEqual(result[0], 'A');
	assertEqual(result[1], 'B');
	assertEqual(result[2], 'C');
	assertEqual(result[3], 'D');
	assertEqual(result[4], 'E');
}

void test_to_map_char_array_with_no_elements_give_to_0(){
	char array[]={},*result;
	result=map_char(array, to_upperCase, 0);
	assertEqual(result[0], 0);
}