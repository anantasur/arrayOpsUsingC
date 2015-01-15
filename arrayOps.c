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