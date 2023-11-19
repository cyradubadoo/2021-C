#include<stdio.h>
#include<math.h>
int main()
{
	double p,r,n;
	r=0.09;
	n=10;
	p=pow((1+r),n);//老师不知道什么原因，那个公式给的不完全，所以我上网学习了一下用了这个公式
	printf("p=%f\n",p);
	return 0;
}