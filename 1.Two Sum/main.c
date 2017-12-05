#!/usr/bin/tcc -run

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* twoSum(int* nums,int numSize,int target)
{
	int* ret = (int*)malloc(sizeof(int)*2);
	*ret = -1;
	*(ret+1) = -1;

	int i =0 ;
	int j = 0;
	for(;i < numSize;i++)
	{
		for(j = i + 1 ; j < numSize ; j ++)
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

int lengthOfLongestSubstring(char* s) {
	int i,j,k;
	int ret = 0;
	int len = strlen(s);
	int maxLen = 0;
	if (len == 1) 
	{
		return 1;
	}
	i=j=k=0;
	for(i=0;i<len,j<len;)
	{
		for(j=i+1;j<len;)
		{
			ret = 0;
			for(k=i;k<j;k++)
			{
				if (s[j] == s[k])
				{
					ret = 1;
					break;
				}
			}
			if (ret)
			{
				i = k+1;
				j = i+1;
			}
			else
			{
				j = j +1;
			}
			maxLen = j-i > maxLen ? j-i:maxLen;
		}
	}
	return maxLen;

}

int lengthOfLongestSubstringForWindow(char* s) {
	// int len = strlen(s);
	// int ascii[128];
	// int i,j;
	// int ans = 0;
	// memset(ascii,0,sizeof(int)*128);
	// i = j =0;
	// for(;j<len;j++)
	// {
	// 	i = i > ascii[s[j]]? i:ascii[s[j]];
	// 	ans = ans > j - i + 1 ? ans:j - i + 1;
	// 	ascii[s[j]] = j +1;
	// }
	int len=0;
    char *end=s,*temp;
	char* addressTable[128]={NULL};
	while(*end){
		temp = addressTable[*end];
		addressTable[*end]=end;
		if(temp>=s){
		len=end-s>len?end-s:len;
		s = temp+1;
		}end++;
	}
	len=end-s>len?end-s:len;
	return len;
	// return ans;
} 	

void testTwoSum()
{
	int arr[] = {2,7,11,15,-3,5,6,9,10,0,20,3};
	int target = -1;
	int numSize = 12;
	int * ret = twoSum(arr,numSize,target);
	printf("%d   %d",*ret,*(ret+1));
}

void testLengthOfLongestSubstring()
{
	char* str1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ ";
	char* str2 = "c";
	char* str3 = "pwwkew";
	int  ret1, ret2 , ret3;
	ret1 = ret2= ret3 = 0;
	ret1 = lengthOfLongestSubstringForWindow(str1);
	ret2 = lengthOfLongestSubstring(str2);
	ret3 = lengthOfLongestSubstring(str3);
	// printf("%d ",ret1);
	printf("%d   %d  %d",ret1,ret2,ret3);
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int m = nums1Size;
    int n = nums2Size;
	if (m > n) { // to ensure m<=n
		int* temp = nums1;
		nums1 = nums2; 
		nums2 = temp;
		int tmp = m; 
		m = n; 
		n = tmp;
	}
	int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
	while (iMin <= iMax) {
		int i = (iMin + iMax) / 2;
		int j = halfLen - i;
		if (i < iMax && nums2[j-1] > nums1[i]){
			iMin = iMin + 1; // i is too small
		}
		else if (i > iMin && nums1[i-1] > nums2[j]) {
			iMax = iMax - 1; // i is too big
		}
		else { // i is perfect
			int maxLeft = 0;
			if (i == 0) { maxLeft = nums2[j-1]; }
			else if (j == 0) { maxLeft = nums1[i-1]; }
			else { maxLeft = nums1[i-1] > nums2[j-1]?nums1[i-1]:nums2[j-1]; }
			if ( (m + n) % 2 == 1 ) { return maxLeft; }

			int minRight = 0;
			if (i == m) { minRight = nums2[j]; }
			else if (j == n) { minRight = nums1[i]; }
			else { minRight = nums2[j] < nums1[i] ?nums2[j]:nums1[i] ; }

			return (maxLeft + minRight) / 2.0;
		}
	}
	return 0.0;
}

int isPalindrome(char*s,int start,int end)
{
	int len = end - start + 1;
	int i = 0;
	for(;i<len/2;i++)
	{
		if (s[i + start] != s[len - i -1 + start])
		{
			return 0;
		}
	}
	return 1;
}
char* longestPalindrome(char* s) {
	int len = strlen(s);
	int startPos=0;
	int endPos=0;
	int i=0;
	int j = 0;
	int max = 0;
	char* ret=NULL;
	for(;i<len;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if (isPalindrome(s,i,j))
			{
				// max = max < j-i+1?j-i+1:max;
				if (j-i+1 > max)
				{
					startPos = i;
					endPos = j;
					max = j-i+1;
				}
			}
		}
	}
	printf("start:%d,end:%d",startPos,endPos);
	if ((endPos - startPos + 1) > 0)
	{
		ret = (char*)malloc((endPos - startPos + 2)*sizeof(char));
		
	}
	return NULL;
}

int main()
{
	// testLengthOfLongestSubstring();
	printf("abc  %d\n",isPalindrome("abc",0,2));
	printf("abcba  %d\n",isPalindrome("abcba",0,4));
	printf("a  %d\n",isPalindrome("aa",0,1));
	longestPalindrome("abc");
	return 0;
}


