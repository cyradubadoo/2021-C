#include<stdio.h>
int main()
{
	int x,a,b,c,d,e;
	printf("请输入一个不多于5位的正整数：");
	scanf("%d",&x);
	a=x/10000;
	b=x/1000;
	c=x/100;
	d=x/10;
	e=x/1;
	if(a>=1&&a<=9)
	{
		printf("该数为5位数\n");
		printf("该数各个位数的数字为：%d,%d,%d,%d,%d\n",a,b-a*10,c-b*10,d-c*10,e-d*10);
		printf("该数的反序输出为：%d%d%d%d%d\n",e-d*10,d-c*10,c-b*10,b-a*10,a);
	}
	else
		if(b>=1&&b<=9)
	{
		printf("该数为4位数\n");
		printf("该数各个位数的数字为：%d,%d,%d,%d\n",b-a*10,c-b*10,d-c*10,e-d*10);
		printf("该数的反序输出为：%d%d%d%d\n",e-d*10,d-c*10,c-b*10,b-a*10);
	}
		else
			if(c>=1&&c<=9)
			{
				printf("该数为3位数\n");
				printf("该数各个位数的数字为：%d,%d,%d\n",c-b*10,d-c*10,e-d*10);
				printf("该数的反序输出为：%d%d%d\n",e-d*10,d-c*10,c-b*10);
			}
			else
				if(d>=1&&d<=9)
			{
				printf("该数为2位数\n");
				printf("该数各个位数的数字为：%d,%d\n",d-c*10,e-d*10);
				printf("该数的反序输出为：%d%d\n",e-d*10,d-c*10);
			}
				else
					if(e>=1&&e<=9)
					{
						printf("该数为1位数\n");
						printf("该数各个位数的数字为：%d\n",e-d*10);
						printf("该数的反序输出为：%d\n",e-d*10);
					}
	return 0;
}