#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,tearDown,fixtureSetup,fixtureTearDown,test_to_filter_the_array,test_to_filter_the_array_returns_zero_if_result_array_is_empty,test_to_filter_the_array_populates_result_array,test_to_filter_the_float_array,test_to_filter_the_float_array_populates_result_array,test_to_filter_the_char_array,test_to_filter_the_char_array_populates_result_array,test_to_map_0_1_2_3_4_to_0_2_4_6_8,test_to_map_array_with_no_elements_give_to_0,test_to_map_decimal_numbers_by_adding_1_to_each_element,test_to_map_float_array_with_no_elements_give_to_0,test_to_map_char_by_changing_caes,test_to_map_char_array_with_no_elements_give_to_0;
Test test[] = {"test_to_filter_the_array",test_to_filter_the_array,"test_to_filter_the_array_returns_zero_if_result_array_is_empty",test_to_filter_the_array_returns_zero_if_result_array_is_empty,"test_to_filter_the_array_populates_result_array",test_to_filter_the_array_populates_result_array,"test_to_filter_the_float_array",test_to_filter_the_float_array,"test_to_filter_the_float_array_populates_result_array",test_to_filter_the_float_array_populates_result_array,"test_to_filter_the_char_array",test_to_filter_the_char_array,"test_to_filter_the_char_array_populates_result_array",test_to_filter_the_char_array_populates_result_array,"test_to_map_0_1_2_3_4_to_0_2_4_6_8",test_to_map_0_1_2_3_4_to_0_2_4_6_8,"test_to_map_array_with_no_elements_give_to_0",test_to_map_array_with_no_elements_give_to_0,"test_to_map_decimal_numbers_by_adding_1_to_each_element",test_to_map_decimal_numbers_by_adding_1_to_each_element,"test_to_map_float_array_with_no_elements_give_to_0",test_to_map_float_array_with_no_elements_give_to_0,"test_to_map_char_by_changing_caes",test_to_map_char_by_changing_caes,"test_to_map_char_array_with_no_elements_give_to_0",test_to_map_char_array_with_no_elements_give_to_0};
char testFileName[] = {"arrayOpsTest.c"};
void _setup(){/*CALL_SETUP*/}
void _tearDown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("\t%s\n",name);
	_setup();
		test();
	_tearDown();
	if(!currentTestFailed) passCount++;	
}

int main(){
	int i,total = sizeof(test)/sizeof(Test);
	fixtureSetup();
	testCount=0,passCount=0;
	printf("********* Starting tests of %s\n\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();
	return 0;
}