#include<stdio.h>
int CheckLetter(char a)
{
	if(a>='A'&&a<='Z')
		return a-'A'+1;
	if(a>='a'&&a<='z')
		return a-'a'+1;
	if(a==10)//回车符的ASCII码是10，要排除掉
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
			printf("%c不是字母\n",n);
		else 
		{
			if(b==-1)
				continue;
			else
				printf("%c是字母，其位置是%d\n",n,n);
		}
	}
	return 0;
}