#include<stdio.h>
#include<math.h>
int main()
{
	double p,r,n;
	r=0.09;
	n=10;
	p=pow((1+r),n);//��ʦ��֪��ʲôԭ���Ǹ���ʽ���Ĳ���ȫ������������ѧϰ��һ�����������ʽ
	printf("p=%f\n",p);
	return 0;
}