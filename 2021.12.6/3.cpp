#include<stdio.h>
int CheckLetter(char a)
{
	if(a>='A'&&a<='Z')
		return a-'A'+1;
	if(a>='a'&&a<='z')
		return a-'a'+1;
	if(a==10)//�س�����ASCII����10��Ҫ�ų���
		return -1;
	else
		return 0;
}
int main()
{
	int n;
	while((n=getchar())!=EOF)
	{
		int b=CheckLetter(n);
		if(b==0)
			printf("%c������ĸ\n",n);
		else 
		{
			if(b==-1)
				continue;
			else
				printf("%c����ĸ����λ����%d\n",n,n);
		}
	}
	return 0;
}