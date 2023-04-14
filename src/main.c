#include <inplace_linear_sort.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define NUMBER_COUNT 16
#define NUMBER_MAX 32



static _Bool _check_if_above(const void* element,void* ctx){
	return *((const unsigned int*)element)>=*((unsigned int*)ctx);
}



int main(int argc,const char*const* argv){
	srand((unsigned int)time(NULL));
	unsigned int data[NUMBER_COUNT];
	for (unsigned int i=0;i<NUMBER_COUNT;i++){
		data[i]=rand()%NUMBER_MAX;
	}
	unsigned int break_value=rand()%NUMBER_MAX;
	unsigned int break_index=inplace_linear_sort(data,sizeof(unsigned int),NUMBER_COUNT,_check_if_above,&break_value);
	unsigned int i=0;
	while (1){
		if (i==break_index){
			printf("==> Break: %u\n",break_value);
		}
		if (i==NUMBER_COUNT){
			break;
		}
		printf("[%u]: %u\n",i,data[i]);
		i++;
	}
	return 0;
}
