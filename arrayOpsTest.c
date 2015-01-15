#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayOps.h"

int checkCOndition(int ele,int index,int *array){
	return ele>3;
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