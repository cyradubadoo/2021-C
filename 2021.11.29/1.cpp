#include<stdio.h>
#include<math.h>
int main()
{
	double i,j,sum=0;
	for(i=1;i<=100;i++)
	{
		if(i%2==0) j=-1.0/i;
		else j=1/i;
		sum+=j;
	}
	printf("%f\n",sum);
	return 0;
}