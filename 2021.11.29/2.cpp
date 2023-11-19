#include<stdio.h>
int a[101];
int main()
{
	
	while(1)             //通过while循环来实现数组中多个数据的输入
	{
		int n;
		scanf("%d",&n);
		if(-1==n) break;   //如果输入-1就跳出循环，停止输入
		a[n]++;
	}
	int i,j;
	for(i=100;i>0;i--)   //i表示该数据出现的次数，从大到小从而实现降序排列
	{
		for(j=100;j>=-100;j--)   //j表示一个数，后续通过a[j]表示数组中的数
		{		
			if(a[j]==i) printf("%d ",j);
		}
	}
	for(i=100;i>0;i--)   //i表示该数据出现的次数，从大到小从而实现降序排列
	{
		for(j=100;j>=-100;j--)   //j表示一个数，后续通过a[j]表示数组中的数
		{		
			
			if(a[j]==i) printf("出现%d次的数字是:%d\n",i,j);
		}
	}
	return 0;
}