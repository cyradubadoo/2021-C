#include<stdio.h>
#define N 4
int main()
{
	int a[N][N],i,j,s=0,m=1,max=a[0][0];
	int A,B;
	printf("������һ��4*4�����飺\n");
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
			if(i==j||i+j==N-1)
			{
				s+=a[i][j];
				if(i%2==0&&j%2==0)
					m*=a[i][j];
				if(a[i][j]>max){
					max=a[i][j];
					A=i;
					B=j;
				}
			}
		}
	printf("�Խ����ϸ�Ԫ�صĺ�=%d\n�Խ������С����±��Ϊż���ĸ�Ԫ�صĻ�=%d\n�Խ�������ֵ����Ԫ��Ϊ%d,���������е�λ����%d�У�%d��\n",s,m,max,A+1,B+1);
	return 0;
}