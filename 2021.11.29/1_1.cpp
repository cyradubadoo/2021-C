#include<stdio.h>
int main()
{
	float j,sum=0.0,i,flag;
	flag=-1;
	for(i=1;i<=100;i++)
	{
		flag=-1*flag;
		j=flag*(1/i);
		sum+=j;
	}
	printf("%f\n",sum);
	return 0;
}