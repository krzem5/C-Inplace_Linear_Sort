#ifndef _INPLACE_LINEAR_SORT_H_
#define _INPLACE_LINEAR_SORT_H_ 1



unsigned int inplace_linear_sort(void* data,unsigned int stride,unsigned int length,_Bool (*compare_fn)(const void*,void*),void* ctx);



#endif
