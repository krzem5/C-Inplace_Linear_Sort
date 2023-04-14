#include <stddef.h>



unsigned int inplace_linear_sort(void* data,unsigned int stride,unsigned int length,_Bool (*compare_fn)(const void*,void*),void* ctx){
	if (!length){
		return 0;
	}
	if (length==1){
		return !compare_fn(data,ctx);
	}
	unsigned int i=0;
	unsigned int start=0;
	unsigned int end=length;
	for (unsigned int j=0;j<length;j++){
		unsigned char* swap_ptr=NULL;
		if (compare_fn(data+i*stride,ctx)){
			end--;
			if (i==end){
				i--;
			}
			else{
				swap_ptr=data+end*stride;
			}
		}
		else{
			if (i==start){
				i++;
			}
			else{
				swap_ptr=data+start*stride;
			}
			start++;
		}
		if (!swap_ptr){
			continue;
		}
		unsigned char* elem_ptr=data+i*stride;
		for (unsigned int k=0;k<stride;k++){
			unsigned char tmp=*elem_ptr;
			*elem_ptr=*swap_ptr;
			*swap_ptr=tmp;
			elem_ptr++;
			swap_ptr++;
		}
	}
	return start;
}
