#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	printf("������һ��С��1000������\n");
	scanf("%d",&n);
	if(n>1000)
		printf("����������������롣\n");
	if(n<0)
		printf("����������������롣\n");
	else
	{
		i=sqrt(n);
		printf("������ƽ����ȡ����Ϊ%d\n",i);
	}
	return 0;
}