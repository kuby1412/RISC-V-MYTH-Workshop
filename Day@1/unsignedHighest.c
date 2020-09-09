#include <stdio.h>
#include <math.h>
int main()
	{
		signed long long int max = (signed long long int) (pow(2,63) - 1);
		signed long long int min = (signed long long int) (-1 * pow(2,63));
		printf(" highest number represented by signed doubleword(RV64) is %llu \n",max);
		printf(" lowest number represented by signed doubleword(RV64) is  %llu \n",min);
		return 0;
	}
