#!/usr/bin/tcc -run

#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums,int numSize,int target)
{
	int* ret = (int*)malloc(sizeof(int)*2);
	*ret = -1;
	*(ret+1) = -1;
	for(size_t i = 0;i < numSize;i++)
	{
		for(size_t j = i + 1 ; j < numSize ; j ++)
		{
			if (*(nums + i) + *(nums +j) == target)
			{
				*ret = i;
				*(ret+1) = j;
				return ret;
			}
		}
	}
	return ret;
}
int main()
{
	int arr[] = {2,7,11,15,2,5,6,9,10,0,20};
	int target = 15;
	int numSize = 11;
	int * ret = twoSum(arr,numSize,target);
	printf("%d   %d",*ret,*(ret+1));	
	return 0;
}


