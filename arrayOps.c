#include <stdio.h>
#include <stdlib.h>
#include "arrayOps.h"

int filter_int(int *array, int (*operation)(int,int,int *),int len, int **result){
	int i,j=0;
	for(i=0;i<len;i++){
		if(operation(array[i],i,array)){
			j++;
		}
	}
	*result=(int *)malloc(sizeof(int)*j);
	j=0;
	for(i=0;i<len;i++){
		if(operation(array[i],i,array)){
			(*result)[j]=array[i];
			j++;
		}
	}
	return j;
}

int filter_float(float *array,int (*operation)(float,int,float *),int len,float **result){
	int i,j=0;
	for(i=0;i<len;i++){
		if(operation(array[i],i,array)){
			j++;
		}
	}
	*result = (float *)malloc(sizeof(float)*j);
	j=0;
	for(i=0;i<len;i++){
		if(operation(array[i],i,array)){
			(*result)[j]=array[i];
			j++;
		}
	}
	return j;
}

int filter_char(char *array,int (*operation)(char,int,char *),int len,char **result){
	int i,count=0;
	for(i=0;i<len;i++){
		if(operation(array[i],i,array)){
			count++;
		}
	}
	*result = (char *)malloc(sizeof(char)*count);
	count=0;
	for(i=0;i<len;i++){
		if(operation(array[i],i,array)){
			(*result)[count]=array[i];
			count++;
		}
	}
	return count;
}	

int* map_int(int *array, int (*operation)(int,int,int *), int length){
	int i=0,*result;
	result=(int *)malloc(sizeof(int)*length);
	for(i=0;i<length;i++){
		result[i]=operation(array[i],i,array);
	}
	return result;
}

float* map_float(float *array, float (*operation)(float,int,float *), int length){
	int i=0;
	float *result;
	result=(float *)malloc(sizeof(float)*length);
	for(i=0;i<length;i++){
		result[i]=operation(array[i],i,array);
	}
	return result;
}

char* map_char(char *array, char (*operation)(char,int,char *), int length){
	int i=0;
	char *result;
	result=(char *)malloc(sizeof(char)*length);
	for(i=0;i<length;i++){
		result[i]=operation(array[i],i,array);
	}
	return result;
}
