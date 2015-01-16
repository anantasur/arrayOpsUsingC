int filter_int(int *array, int (*operation)(int,int,int *), int length, int **result);

int filter_float(float *array,int (*operation)(float,int,float *),int len,float **result);

int filter_char(char *array,int (*operation)(char,int,char *),int len,char **result);

int* map_int(int *array, int (*operation)(int,int,int *), int length);

float* map_float(float *array, float (*operation)(float,int,float *), int length);

char* map_char(char *array, char (*operation)(char,int,char *), int length);
