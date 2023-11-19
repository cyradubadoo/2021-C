#include<stdio.h>
int main()
{
	int a,b,c,i;
	for(i=200;i<=300;i++)
	{
		a=i/100;//算出百位数字
		b=(i/10)%10;//算出十位数字
		c=i%10;//算出个位数字
		if((a*b*c==42)&&(a+b+c==12))
			printf("%d\n",i);
	}
	return 0;
}