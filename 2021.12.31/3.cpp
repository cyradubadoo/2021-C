#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

#define N 10

FILE *fp;//文件



typedef struct Book//定义结构体数组用于缓存数据
{
	char num[N];//序号
	char name[N];//书名
	char writer[N];//作者
	char press[N];//出版社
	char category[N];//类别
}bo;

bo book[100];

//声明所用函数
void Menu();//菜单
void Input();//录入	
void Save();//保存
void Browse();//浏览
void Search();//查询
void Add();//增加
void Delete();//删除
void Revise();//修改
void Statistics();//统计
void Sort();//排序
void Quit();//退出

int check_repeat(char num[30]);//查重书籍序号


int main()
{

	//查询储存图书信息的文件是否存在
	if((fp=fopen("d:\\boook.txt","rb+"))==NULL)
	{
		printf("在d盘根目录下没有找到储存图书信息的boook.txt文件\n请选择  1--手动导入！  2--创建此文件\n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("请把名为boook.txt的文件复制到d盘根目录下\n\n");break;
		
		case 2:if((fp=fopen("d:\\boook.txt","ab+"))!=NULL)
				   printf("创建成功\n\n");
		
		}
	system("pause");
	}

	Menu();//跳转至菜单

	return 0;

}



//查重书籍序号
int check_repeat(char number[10])
{
	FILE *fp;
	bo book[10];
	int flag=0,n,booknumber;
	
    fp=fopen("d:\\boook.txt","r");
   	booknumber=0;
    rewind(fp);
	while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s \n",book[booknumber].num,book[booknumber].name,book[booknumber].writer,book[booknumber].press,book[booknumber].category);
       	booknumber++;
    }
    
	fclose(fp);
	for(n=0;n<booknumber;n++)
	{
    	if(strcmp(book[n].num,number)==0)
    	{
    	    flag=1;
			break;
		}
	}
		if(flag)
		{
			return 1;//为真，重复
   		}
   		else
		{
            return 0;//为假，未重复
		}
}


//定义菜单函数
void Menu()
{
	while(1)//使输入错误后还能重新输入
	{
		system("cls");//清屏
		printf("\t************欢迎使用个人书籍系统************\n");
		printf("\t--------------------------------------------\n");
		printf("\t----------------1.录入书籍信息--------------\n");
		printf("\t----------------2.保存书籍信息--------------\n");
		printf("\t----------------3.浏览书籍信息--------------\n");	
		printf("\t----------------4.查询书籍信息--------------\n");
		printf("\t----------------5.增加书籍信息--------------\n");
		printf("\t----------------6.删除书籍信息--------------\n");
		printf("\t----------------7.修改书籍信息--------------\n");
		printf("\t----------------8.按类别统计书籍的数量------\n");
		printf("\t----------------9.按书名对书籍进行排序------\n");
		printf("\t----------------10.退出---------------------\n");
		printf("\t--------------------------------------------\n");
		printf("\t*****************谢谢使用*******************\n");
		printf("\n");
	
		printf("请选择(1-10):\n");
		int choice;
		scanf("%d",&choice);
		system("cls");//清屏

		switch(choice)//进行操作选择
		{
			case 1:printf("【录入书籍信息】\n\n"); Input(); break;
			
			case 2:printf("【保存书籍信息】\n\n"); Save(); break;
				
			case 3:printf("【浏览书籍信息】\n\n"); Browse(); break;
			
			case 4:printf("【查询书籍信息】\n\n"); Search(); break;
			
			case 5:printf("【增加书籍信息】\n\n"); Add(); break;
			
			case 6:printf("【删除书籍信息】\n\n"); Delete(); break;
			
			case 7:printf("【修改书籍信息】\n\n"); Revise(); break;
			
			case 8:printf("【按类别统计书籍的数量】\n\n"); Statistics(); break;
			
			case 9:printf("【按书名对书籍进行排序】\n\n"); Sort(); break;
			
			case 10:printf("【退出】\n\n"); Quit(); break;

			default:printf("非法操作!\n");
		}
	}
}


//定义录入函数
void Input()
{

	char choice;
	int i=0;

	do{
      	fflush(stdin);
		printf("请输入图书序号:");
		gets(book[i].num);
		
		if(check_repeat(book[i].num))
		{	
			printf("该图书序号已被使用！");
			getch();

		}
		else
		{
			 
			printf("请输入书名:");
			gets(book[i].name);
		
			printf("请输入作者:");
			gets(book[i].writer);
		
			printf("请输入出版社:");
			gets(book[i].press);
				
			printf("请输入类别(专业书/工具书/报告/小说/其他):");
			gets(book[i].category);
				
			i++;
      		
		} 	
		printf("\n\n是否继续添加书目(y/n):");
		choice=getch();
		while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      		choice=getch();
      	printf("%c",choice);
      	printf("\n");
     	if(choice=='Y'||choice=='y') continue;
      	if(choice=='N'||choice=='n') break;		
		
	}while(i<100);

	fp=fopen("d:\\boook.txt","wb");
//	for(int n=0;n<=i;n++)
//	{
//		fprintf(fp,"%s %s %s %s %s\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);
//	}
	for(int n=0;n<=i;n++)
		fwrite(&book[n],sizeof(struct Book),1,fp);
	fclose(fp);

	printf("提示:记得保存数据\n");
	fflush (stdin);
	system("pause");
	Menu();
		
}


//定义保存函数
void Save()
{
	char choice;
	printf("是否保存已录入书目(Y/N):");
    choice=getch();
	while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n') choice=getch();
	printf("%c",choice);
    if(choice=='N'||choice=='n')
	{
       	printf("\n书目未保存!\n");
		/*int n,i;
		FILE *fp;
	
		bo book[n];
		char number[10];

     	fp=fopen("d:\\boook.txt","r");
      	int booknumber=0;
      	while(!feof(fp))
        {
        	fscanf(fp,"%s %s %s %s %s\n",bookinfo[booknumber].num,bookinfo[booknumber].name,bookinfo[booknumber].writer,bookinfo[booknumber].press,bookinfo[booknumber].category);
        	booknumber++;
        }
     	fclose(fp);
        
		for(n=0;n<booknumber;n++)
		{
			if(strcmp(book[n].num,number)==0)//如果重复
			{break;}
		}
					for(i=n;i<booknumber;i++)
					{
						book[i]=book[i+1];
					}
					booknumber--;
           			fp=fopen("d:\\boook.txt","w");
					for(n=0;n<booknumber;n++)
					{
						fscanf(fp,"%s %s %s %s %s\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);
					}
					fclose(fp);*/

	}
	if(choice=='Y'||choice=='y')
	{
		printf("\n保存成功!\n");
		//fp=fopen("d:\\boook.txt","wb");
		//for(int n=0;n<i;n++)
		//fwrite(&newbook[n],sizeof(bo),1,fp);
		//fclose(fp);

	}
	
	fflush (stdin);
	system("pause");
	Menu();


}
			

//定义浏览函数         wei
void Browse()                                           
{
	FILE *fp;
    int n;

    int booknumber=0;

    fflush(stdin);
    fp=fopen("d:\\boook.txt","r");
    char ch=fgetc(fp);
	if(ch==EOF) printf("文件为空，没有书籍信息。\n");
	else
	{	
		rewind(fp);
		while(!feof(fp))
		{
      		fscanf(fp,"%s %s %s %s %s\n",book[booknumber].num,book[booknumber].name,book[booknumber].writer,book[booknumber].press,book[booknumber].category);
      		booknumber++;
		
		}
		fclose(fp);
		n=0;
		printf("*************************************************图书总览***********************************************\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("\n序号      书名      作者      出版社    类别      \n");

		for(n=0;n<=booknumber;n++)//while(n<=booknumber)
		{
			printf("%-10s%-10s%-10s%-10s%-10s\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);
			//n++;
			//if(boo[n]==) break;
		}
	}
	 printf("\n\n按任意键返回上一级菜单!\n");
	 getch();
	 Menu();

}



//定义查询函数
void Search()
{
		
	int flag=1,flag1=1;
	char select;
    char name_compare[30]="";//用来存放要查询的书名
   	char press_compare[30]=""; //用来存放要查询的出版社
   	char writer_compare[30]="";//用来存放要查询的作者姓名
	char category_compare[30]="";//用来存放要查询的类别
	char search[30]="";//比对数组,将需要查找的数组读进比对数组
	char compare[30]="";//比对数组,将书库中的数组读进比对数组
    int n=0;
    FILE *fp;
    char choice;

    int booknumber=0;

    system("cls");
    fflush(stdin);
    fp=fopen("d:\\boook.txt","r");
	rewind(fp);
    while(!feof(fp))
    {
      	fscanf(fp,"%s %s %s %s %s\n",book[booknumber].num,book[booknumber].name,book[booknumber].writer,book[booknumber].press,book[booknumber].category);
      	booknumber++;
    }
    fclose(fp);

	while(flag)
    {
		system("cls");
    	while(flag1)
		{
			system("cls");
			fflush(stdin);
	
			printf("请选择查询类型：\n\n\t\t1-按【书名】查询     2-按【作者】查询\n");
			printf("                \n\t\t3-按【出版社】查询     4-按【类别】查询\n");
    		select=getch();
    		printf("%c",select);
			printf("\n\n请您输入查找信息:");		
			switch(select)
			{
				case '1':gets(name_compare);strcpy(search,name_compare);flag1=0;break;
				case '2':gets(writer_compare);strcpy(search,writer_compare);flag1=0;break;
				case '3':gets(press_compare);strcpy(search,press_compare);flag1=0;break;
				case '4':gets(category_compare);strcpy(search,category_compare);flag1=0;break;
				default :
					printf("\n不要输入菜单之外的数字~按任意键继续！");
					fflush(stdin);
            	    getch(); 
			}
		}

	flag1=1;

     	if(n>=booknumber)
		{
			printf("\n没有查找符合您要求的书籍!\n");
		}
		else
		{
			printf("---------------------------------图书信息---------------------------------\n");
      		printf("序号      书名      作者      出版社    类别      \n");
      		printf("                                                                          \n");
		}
		for(n=0;n<booknumber;n++)
      	{
      		switch(select)
      		{
      			case '1':strcpy(compare,book[n].name);break;
      			case '2':strcpy(compare,book[n].writer);break;
      			case '3':strcpy(compare,book[n].press);break;
				case '4':strcpy(compare,book[n].category);
			}
        	if(strcmp(compare,search)==0)
          	{
    			printf("%-10s%-10s%-10s%-10s%-10s%\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);
			}
		}
	
      		printf("\n\n是否继续查询(y/n):");
      		choice=getch();
     		while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    	choice=getch();
      		printf("%c",choice);
      		printf("\n");
      		if(choice=='Y'||choice=='y')
       			flag=1;
      		if(choice=='N'||choice=='n')
      			Menu();
	}		
}


			
//定义增加函数
void Add()
{

bo book;
	char choice;

    while(1)
    {

      	fflush(stdin);
		printf("请输入图书序号:");
		gets(book.num);
		
		if(check_repeat(book.num))
		{	
			printf("该图书序号已被使用！");
			printf("\n按任意键重新输入\n\n");
			getch();
		}
		else
		{
			 
			printf("请输入书名:");
			gets(book.name);
		
			printf("请输入作者:");
			gets(book.writer);
		
			printf("请输入出版社:");
			gets(book.press);
			
			printf("请输入类别(专业书/工具书/报告/小说/其他):");
			gets(book.category);

			fflush(stdin);
      		printf("是否保存该条书目(y/n):");
      		choice=getch();
			while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      			choice=getch();
			printf("%c",choice);
     		if(choice=='Y'||choice=='y')
			{
        		fp=fopen("d:\\boook.txt","ab");
				fprintf(fp,"%s %s %s %s %s\n",book.num,book.name,book.writer,book.press,book.category);
				fclose(fp);
        		printf("\n该条书目已添加到文件中!\n");
       		}
			if(choice=='N'||choice=='n')
			{
       			printf("\n本条书目未保存!\n");
			}
			break;
		}
	}
	system("pause");
	Menu();
}




			
//定义删除函数wei
void Delete()
{
    int n,i,j;
    FILE *fp;
    char choice;

    char number[10];

	while(1)
    {
    	fflush(stdin);
		printf("请输入要删除的图书序号:");
		gets(number);

     	fp=fopen("d:\\boook.txt","r");
      	int booknumber=0;
      	while(!feof(fp))
        {
        	fscanf(fp,"%s %s %s %s %s\n",book[booknumber].num,book[booknumber].name,book[booknumber].writer,book[booknumber].press,book[booknumber].category);
        	booknumber++;
        }
     	fclose(fp);
        
		for(n=0;n<booknumber;n++)
		{
			if(strcmp(book[n].num,number)==0)//如果重复
			{break;}
		}
			if(strcmp(book[n].num,number))
				printf("\n没有查找该书的任何信息!\n");
			else
			{
				printf("\n"); 
         		printf("|---------------------------------图书信息---------------------------------|\n");
      			printf("|序号      书名      作者      出版社    类别                              |\n");
      			printf("|                                                                          |\n");
    			printf("|%-10s%-10s%-10s%-10s%-10s\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);

           		printf("\n是否确认需要删除该条书目(Y/N):");
           		choice=getch();
				while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    		choice=getch();
      			printf("%c",choice);
           		
				if(choice=='Y'||choice=='y')
				{
					for(i=n;i<booknumber;i++)
					{
						book[i]=book[i+1];
						booknumber--;
					}
					printf("\nbooknumber=%d",booknumber);
           			fp=fopen("d:\\boook.txt","w");
					for(j=0;j<booknumber;j++)
					{
						fprintf(fp,"%s %s %s %s %s\n",book[j].num,book[j].name,book[j].writer,book[j].press,book[j].category);
					}
					fclose(fp);
           			printf("\n删除成功!");
				 }
           		else
				{
					printf("\n该条书目没有被删除!");
				}
			
			}

		printf("\n\n是否继续进行删除操作(y/n):");
		choice=getch();
		while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
			choice=getch();
		printf("%c",choice);
		printf("\n");
		if(choice=='Y'||choice=='y')
			continue;
		else
			break;
	}//while(1)结束
	Menu();
}


//定义修改函数wei
void Revise()
{
	int n,j;
	char change,choice;
	char number[15];//图书序号
    char name[30];//图书名称
    char writer[20];//作者
   	char press[30];//出版社
	char category[20];//类别 
    
	char yuan[15];//要修改的序号
	FILE *fp;

	int booknumber;
    while(1)
    {
    	fflush(stdin);
      	printf("输入要修改信息的书序号:");
      	gets(yuan);
      	fp=fopen("d:\\boook.txt","rb");
      	booknumber=0;
		rewind(fp);
      	while(!feof(fp))
        {
        	fscanf(fp,"%s %s %s %s %s \n",book[booknumber].num,book[booknumber].name,book[booknumber].writer,book[booknumber].press,book[booknumber].category);
        	booknumber++;
        }
      	fclose(fp);
      
        	for(n=0;n<booknumber;n++)
			{
         		if(strcmp(book[n].num,yuan)==0)
            	{
            		printf("\n"); 
         			printf("|---------------------------------图书信息---------------------------------|\n");
      				printf("|序号      书名      作者      出版社    类别                              |\n");
      				printf("|                                                                          |\n");
    				printf("|%-10s%-10s%-10s%-10s%-10s\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);
       				
						printf("\n1.书籍序号\n2.书籍名称\n3.书籍作者\n4.出版社\n5.书籍类别\n\n您想要修改的是:");
						change=getch();
						while(change!='1'&&change!='2'&&change!='3'&&change!='4'&&change!='5')
  							change=getch();
  						printf("%c",change);
           				printf("\n请输入新的信息:");
           				fflush(stdin);
            			switch(change)
            			{
            				case '1':gets(number);if(!check_repeat(number))strcpy(book[n].num,number);break;
            				case '2':gets(name);strcpy(book[n].name,name);break;
            				case '3':gets(writer);strcpy(book[n].writer,writer);break;
            				case '4':gets(press);strcpy(book[n].press,press);break;
            				case '5':gets(category);strcpy(book[n].category,category);break;
            				default:break;//虽然压根不会读到default情况，但是怕后来开发者漏掉新加的case的while处理，所以加上
						}
						if(check_repeat(number))
						{
							printf("您想修改的图书信息与馆内信息重复。");
							break;
						}
						FILE *fp;
						fp=fopen("d:\\boook.txt","wb");
						for(j=0;j<booknumber;j++)
							fprintf(fp,"%s %s %s %s %s \n",book[j].num,book[j].name,book[j].writer,book[j].press,book[j].category);
						fclose(fp);
						printf("\n修改成功!");	
					break;
				}//if结束	
				
			}//for结束
						
				//if()printf("\n没有查找到该书的任何信息!");		
						
			
				
		
		

   			printf("\n是否继续进行修改(y/n):");
			choice=getch();
			while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      			choice=getch();
      		printf("%c",choice);
      		printf("\n");
			if(choice=='Y'||choice=='y')
				continue;
			if(choice=='N'||choice=='n')
				break;
	}//while(1)结束
	Menu();
}

			
//定义统计函数
void Statistics()
{
	char temp[10];
	int n=0,i=0,count=0;

	
	fp=fopen("d:\\boook.txt","r");
    while(!feof(fp))
    {
		fscanf(fp,"%s %s %s %s %s\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);
       	n++;
    }
    fclose(fp);

	printf("请输入你想统计的类别：");
	scanf("%s",temp);
	for(i=0;i<=n;i++)
	{
		if(strcmp(book[i].category,temp)==0)//如果重复
		{
			count++;
		}
	}
	printf("该类别的书籍共有%d本\n",count);
	printf("|---------------------------------图书信息---------------------------------|\n");
    printf("|序号      书名      作者      出版社    类别                              |\n");
    printf("|                                                                          |\n");

	for(i=0;i<=n;i++)
	{
		if(strcmp(book[i].category,temp)==0)//如果重复
		{
			printf("%-10s%-10s%-10s%-10s%-10s\n",book[i].num,book[i].name,book[i].writer,book[i].press,book[i].category);
		}
	}
	system("pause");
	Menu();
}
			
//定义排序函数
void Sort()
{
	int i,n=0,j;
	bo booq,boow;
	
	fp=fopen("d:\\boook.txt","r");
    while(!feof(fp))
    {
		fscanf(fp,"%s %s %s %s %s\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);
       	n++;
    }
    fclose(fp);

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			int len1=strlen(book[j].name+1);
			int len2=strlen(book[j+1].name+1);
			if(len1>len2)
			{
				booq=book[j];
				book[j]=book[j+1];
				book[j+1]=booq;
			}
			if(len1=len2)
			{
				if(strcmp(book[j].num,book[j+1].num)>0)
				{
					boow=book[j];
					book[j]=book[j+1];
					book[j+1]=boow;
				}
			}
		}
	}
	printf("按照书名排序结果如下 ：\n");
	printf("|---------------------------------图书信息---------------------------------|\n");
    printf("|序号      书名      作者      出版社    类别                              |\n");
    printf("|                                                                          |\n");

	for(i=1;i<=n;i++)
	{
		printf("%-10s%-10s%-10s%-10s%-10s\n",book[i].num,book[i].name,book[i].writer,book[i].press,book[i].category);
	}
	system("pause"); 
	Menu();
}
			
//定义退出函数
void Quit()
{
	char choice;
	printf("您确定要退出吗？(Y/N):");//询问用户是否确定退出

    while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
		choice=getch();
	printf("%c",choice);
	printf("\n");
	
	if(choice=='Y'||choice=='y') exit(0);//结束程序

	if(choice=='N'||choice=='n') printf("返回菜单"); system("pause"); Menu();//跳转至菜单
}