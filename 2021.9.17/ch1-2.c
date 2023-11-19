#include<stdio.h>
int main()
{
	int Max(int x,int y);
	int a,b,c,i,max;
	scanf("%d,%d,%d",&a,&b,&c);
	i=Max(a,b);
	max=Max(i,max);
	printf("max is %d\n",max);
	return 0;
}
int Max(int x,int y)
{
	int z;
	if(x>y)
		z=x;
	else
		z=y;
	return(z);
}