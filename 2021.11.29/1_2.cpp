#include<stdio.h>
int main()
{
	int a,b,c,i;
	for(i=200;i<=300;i++)
	{
		a=i/100;//�����λ����
		b=(i/10)%10;//���ʮλ����
		c=i%10;//�����λ����
		if((a*b*c==42)&&(a+b+c==12))
			printf("%d\n",i);
	}
	return 0;
}