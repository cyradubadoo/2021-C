#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	printf("请输入一个小于1000的正数\n");
	scanf("%d",&n);
	if(n>1000)
		printf("输入错误，请重新输入。\n");
	if(n<0)
		printf("输入错误，请重新输入。\n");
	else
	{
		i=sqrt(n);
		printf("该数的平方根取整后为%d\n",i);
	}
	return 0;
}