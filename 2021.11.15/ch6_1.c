#include<stdio.h>
#define N 4
int main()
{
	int a[N][N],i,j,s=0,m=1,max=a[0][0];
	int A,B;
	printf("请输入一个4*4的数组：\n");
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
	printf("对角线上各元素的和=%d\n对角线上行、列下标均为偶数的各元素的积=%d\n对角线上其值最大的元素为%d,它在数组中的位置是%d行，%d列\n",s,m,max,A+1,B+1);
	return 0;
}