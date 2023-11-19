#include<stdio.h>
#include<string.h>
#define LEN 100
void mystrcat(char *s1,char *s2,char *new_s)//声明一个函数
{
	int a=strlen(s1),b=strlen(s2),i;
	if(a==b)//如果两个字符串等长
	{
		for(i=0;i<a;i++)
		{
			new_s[2*i]=s1[i];
			new_s[2*i+1]=s2[i];
		}
	}
	if(a>b)//如果前一个字符串更长
	{
		for(i=0;i<b;i++)
		{ 
			new_s[2*i]=s1[i];
			new_s[2*i+1]=s2[i];
		} 
		for(i=b;i<a;i++)
		{
			new_s[b+i]=s1[i];
		}
	}
	if(a<b)//如果后一个字符串更长
	{
		for (i=0;i<a;i++)
		{ 
			new_s[2*i]=s1[i];
			new_s[2*i+1]=s2[i];
		} 
		for(i=a;i<b;i++)
		{
			new_s[a+i]=s2[i];
		}
	}		
	new_s[a+b]='\0';
}
int main()
{
	char s1[LEN],s2[LEN],new_s[LEN];
	printf("请输入两个字符串,用Enter隔开：\n");
	scanf("%s",s1);
	scanf("%s",s2);
	mystrcat(s1,s2,new_s);
	printf("交叉连接后: %s\n", new_s);	
	return 0;
}
 


