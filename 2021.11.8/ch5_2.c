#include<stdio.h>
int main()
{
	int a,b,c;
	for(a=0;a<=100;a++)
	{
		for(b=0;b<=100;b++)
		{
			for(c=0;c<=100;c++)
			{
				if(a*5+b*3+c/3==100&&a+b+c==100)
					printf("������%dֻ����ĸ��%dֻ��������%dֻ��\n",a,b,c);
			}
		}
	}
	return 0;
}