#include <stdio.h>
extern int .load(int x,int y);

int main()
{
	int result=0;
	int count=9;
	result=load(0x0,count+1);
	printf("sum of numbers from 1 to %d is %d \n",count,result);	
