#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

#define N 10

FILE *fp;//文件


typedef struct book//定义结构体数组用于缓存数据
{
	char num[N];//序号
	char name[N];//书名
	char writer[N];//作者
	char press[N];//出版社
	char category[N];//类别
}bo;

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

int compare(char *p,char *p1);//工具函数，用来对比两个字符串的长度
int check_repeat_book(char num[30]);//查重书籍序号

int main()
{
	
	system("cls");//清屏
	
	//查询储存图书信息的文件是否存在
	if((fp=fopen("d:\\yuruijiebook.txt","rb+"))==NULL)
	{
		printf("在d盘根目录下没有找到储存图书信息的yuruijiebook.txt文件\n请选择  1--手动导入！  2--创建此文件\n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("请把名为yuruijiebook.txt的文件复制到d盘根目录下\n\n");break;
		
		case 2:if((fp=fopen("d:\\yuruijiebook.txt","ab+"))!=NULL)
				   printf("创建成功\n\n");
		
		}
	system("pause");
	}

	Menu();//跳转至菜单

	return 0;

}


//定义一个工具函数，用来对比两个字符串的相关度
int compare(char *p,char *p1)
{
	int fri=0,sec=1;
	int i;
	for(i=0;i<(int)strlen(p1);i++){
		if(p[0]==p1[i]){
			fri=i;
			break;
		}
	}
	if((int)strlen(p)>(int)strlen(p1)-fri+1)
		return 0;
	else
		for(i=0;i<(int)strlen(p);i++){
			if(p[i]!=p1[fri+i])
				sec=0;
		}
		return sec;
}

//查重书籍序号
int check_repeat_book(char num[30])
{
	FILE *fp;
	bo book[100];
	int flag=0,n,booknumber;
	
    fp=fopen("d:\\yuruijiebook.txt","r");
   	booknumber=0;
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s \n",book[booknumber].num,book[booknumber].name,book[booknumber].writer,book[booknumber].press,book[booknumber].category);
       	booknumber++;
    }
    fclose(fp);
	for(n=0;n<booknumber;n++)
    	if(strcmp(book[n].num,num)==0)
    	{
    	    flag=1;
			break;
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
    bo newbook[100];
	char choice;
	int i=0,n=1;

	do{
      	fflush(stdin);
		printf("请输入图书序号:");
		gets(newbook[i].num);
		
		if(check_repeat_book(newbook[i].num))
		{	
			printf("该图书序号已被使用！");
			getch();

		}
		else
		{
			 
			printf("请输入书名:");
			gets(newbook[i].name);
		
			printf("请输入作者:");
			gets(newbook[i].writer);
		
			printf("请输入出版社:");
			gets(newbook[i].press);
				
			printf("请输入类别(专业书/工具书/报告/小说/其他):");
			gets(newbook[i].category);
				
			i++;n++;
      		
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

	printf("共录入%d次书目。\n",n);
	printf("提示:记得保存数据\n");
	fflush (stdin);
	system("pause");
	Menu();
		
}


//定义保存函数	wei	
void Save()
{
/*	char choice;

    int n;
	printf("请输入已录入条数:");
	scanf("%d",&n);

	printf("是否保存已录入书目(Y/N):");
    choice=getch();
	while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n') choice=getch();
	printf("%c",choice);
    if(choice=='N'||choice=='n')
	{
       	printf("\n书目未保存!\n");
	}
	if(choice=='Y'||choice=='y')
	{
        fp=fopen("d:\\yuruijiebook.txt","wb");
		for(int i=0;i<n;i++)
		{
			fprintf(fp,"%s %s %s %s %s\n",bo[i].num,bo[i].name,bo[i].writer,bo[i].press,bo[i].category);
		}
		fclose(fp);
        if() printf("\n保存失败!\n");
		else printf("\n保存成功!\n");
	}
	
	fflush (stdin);
	system("pause");
	Menu();
*/
}
			

//定义浏览函数         wei
void Browse()                                           
{
	FILE *fp;
    int n;
    bo boo[100];
    int booknumber=0;

    fflush(stdin);
    fp=fopen("d:\\yuruijiebook.txt","r");
    char ch=fgetc(fp);
	if(ch==EOF) printf("文件为空，没有书籍信息。\n");
	else
	{
		while(!feof(fp))
		{
      		fscanf(fp,"%s %s %s %s %s\n",boo[booknumber].num,boo[booknumber].name,boo[booknumber].writer,boo[booknumber].press,boo[booknumber].category);
      		booknumber++;
		}
		fclose(fp);
		n=0;
		printf("*************************************************图书总览***********************************************\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("\n序号     书名     作者     出版社    类别     \n");

		while(n<=booknumber)
		{
			printf("%-10s%-10s%-10s%-10s%-10s\n",boo[n].num,boo[n].name,boo[n].writer,boo[n].press,boo[n].category);
			n++;
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
    char name_compare[30]="";//name_compare用来存放要查询的书名
   	char press_compare[30]=""; //number_compare用来存放要查询的出版社
   	char writer_compare[30]="";//author_compare用来存放要查询的作者姓名
	char category_compare[30]="";//author_compare用来存放要查询的类别
	char search[30]="";//search是比对数组,将需要查找的数组读进比对数组
	char compare[30]="";//compare是比对数组,将书库中的数组读进比对数组
    int n=0;
    FILE *fp;
    char choice;
    bo bookinfo[100];
    int booknumber=0;

    system("cls");
    fflush(stdin);
    fp=fopen("d:\\yuruijiebook.txt","r");
    while(!feof(fp))
    {
      	fscanf(fp,"%s %s %s %s %s\n",bookinfo[booknumber].num,bookinfo[booknumber].name,bookinfo[booknumber].writer,bookinfo[booknumber].press,bookinfo[booknumber].category);
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

     	for(n=0;n<booknumber;n++)
      	{
      		switch(select)
      		{
      			case '1':strcpy(compare,bookinfo[n].name);break;
      			case '2':strcpy(compare,bookinfo[n].writer);break;
      			case '3':strcpy(compare,bookinfo[n].press);break;
				case '4':strcpy(compare,bookinfo[n].category);
			}
        	if(strcmp(compare,search)==0)
          	{
         		printf("---------------------------------图书信息---------------------------------\n");
      			printf("序号      书名      作者      出版社    类别      \n");
      			printf("                                                                          \n");
    			printf("%-10s%-10s%-10s%-10s%-10s%\n",bookinfo[n].num,bookinfo[n].name,bookinfo[n].writer,bookinfo[n].press,bookinfo[n].category);
       			break;
			}
		}
		
   			if(n>=booknumber)
       		printf("\n没有查找符合您要求的书籍!\n");
       		
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
	bo newbook;

	char choice;

    while(1)
    {

      	fflush(stdin);
		printf("请输入图书序号:");
		gets(newbook.num);
		
		if(check_repeat_book(newbook.num))
		{	
			printf("该图书序号已被使用！");
			printf("\n按任意键重新输入\n\n");
			getch();

		}
		else
		{
			 
			printf("请输入书名:");
			gets(newbook.name);
		
			printf("请输入作者:");
			gets(newbook.writer);
		
			printf("请输入出版社:");
			gets(newbook.press);
			
			printf("请输入类别(专业书/工具书/报告/小说/其他):");
			gets(newbook.category);

			fflush(stdin);
      		printf("是否保存该条书目(y/n):");
      		choice=getch();
			while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      			choice=getch();
			printf("%c",choice);
     		if(choice=='Y'||choice=='y')
			{
        		fp=fopen("d:\\yuruijiebook.txt","ab");
				fprintf(fp,"%s %s %s %s %s\n",newbook.num,newbook.name,newbook.writer,newbook.press,newbook.category);
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
    int n,i;
    FILE *fp;
    char choice;
    bo bookinfo[100];
    char number[10];

	while(1)
    {
    	fflush(stdin);
		printf("请输入要删除的图书序号:");
		gets(number);

     	fp=fopen("d:\\yuruijiebook.txt","r");
      	int booknumber=0;
      	while(!feof(fp))
        {
        	fscanf(fp,"%s %s %s %s %s\n",bookinfo[booknumber].num,bookinfo[booknumber].name,bookinfo[booknumber].writer,bookinfo[booknumber].press,bookinfo[booknumber].category);
        	booknumber++;
        }
     	fclose(fp);
        
		for(n=0;n<=booknumber;n++)
		{
			if(strcmp(bookinfo[n].num,number)==0)//如果重复
			{
				printf("\n"); 
         		printf("|---------------------------------图书信息---------------------------------|\n");
      			printf("|序号      书名      作者      出版社    类别      |\n");
      			printf("|                                                                          |\n");
    			printf("|%-10s%-10s%-10s%-10s%-10s\n",bookinfo[n].num,bookinfo[n].name,bookinfo[n].writer,bookinfo[n].press,bookinfo[n].category);

           		printf("\n是否确认需要删除该条书目(Y/N):");
           		choice=getch();
				while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    		choice=getch();
      			printf("%c",choice);
           		
				if(choice=='Y'||choice=='y')
				{
					for(i=n;i<booknumber;i++)
					{
						bookinfo[i]=bookinfo[i+1];
					}
           			fp=fopen("d:\\yuruijiebook.txt","w");
					for(n=0;n<booknumber;n++)
					{
						fscanf(fp,"%s %s %s %s %s\n",bookinfo[n].num,bookinfo[n].name,bookinfo[n].writer,bookinfo[n].press,bookinfo[n].category);
					}
					fclose(fp);
           			printf("\n删除成功!");
				 }
           		else
				{
					printf("\n该条书目没有被删除!");
				}
				break;
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
	int flag=1,flag1=1,flag2,n;
	char change,choice;
	char number[15];//图书序号
    char name[30];//图书名称
    char writer[20];//作者
   	char press[30];//出版社
	char category[20];//类别 
    
	char yuan[15];//要修改的序号
	FILE *fp;
	bo boo[100];
	int booknumber;
    while(flag)
    {
    	flag2=0;
    	fflush(stdin);
      	printf("输入要修改信息的书序号:");
      	gets(yuan);
      	fp=fopen("d:\\yuruijiebook.txt","r");
      	booknumber=0;
      	while(!feof(fp))
        {
        	fscanf(fp,"%s %s %s %s %s \n",boo[booknumber].num,boo[booknumber].name,boo[booknumber].writer,boo[booknumber].press,boo[booknumber].category);
        	booknumber++;
        }
      	fclose(fp);
      //	if(bookinfo[0].quantity==0)
      //  {
      //  	printf("书库中没有任何信息!\n\n");
      //  	printf("按任意键回到主菜单!\n\n");
      //  	getch();
      //  	break;
      //  }
      //  else
      //  {
        	for(n=0;n<booknumber;n++)
         		if(strcmp(boo[n].num,yuan)==0)
            	{
            		printf("\n"); 
         			printf("|---------------------------------图书信息---------------------------------|\n");
      				printf("|编号  书名        作者      出版社          类别    |\n");
      				printf("|                                                                          |\n");
    				printf("|%-10s%-10s%-10s%-10s%-10s\n",boo[booknumber].num,boo[booknumber].name,boo[booknumber].writer,boo[booknumber].press,boo[booknumber].category);
       				
					while(flag1){
					printf("\n1.书籍序号\n2.书籍名称\n3.书籍作者\n4.出版社\n5.书籍类别\n\n您想要修改的是:");
					change=getch();
					while(change!='1'&&change!='2'&&change!='3'&&change!='4'&&change!='5')
  						change=getch();
  					printf("%c",change);
           			printf("\n请输入新的信息:");
           			fflush(stdin);
            		switch(change)
            		{
            			case '1':gets(number);flag1=0;flag2=check_repeat_book(number);
									if(!flag2)
										strcpy(boo[n].num,number);
								break;
            			case '2':gets(name);strcpy(boo[n].name,name);flag1=0;break;
            			case '3':gets(writer);strcpy(boo[n].writer,writer);flag1=0;break;
            			case '4':gets(press);strcpy(boo[n].press,press);flag1=0;break;
            			case '5':gets(category);strcpy(boo[n].category,category);flag1=0;break;
            			default:break;//虽然压根不会读到default情况，但是怕后来开发者漏掉新加的case的while处理，所以加上
					}
				}
			flag1=1;
            break;
        //    }
        if(n>=booknumber)
           printf("\n没有查找该书的任何信息!");
        else
		{
			if(!flag2)
			{
				fp=fopen("d:\\yuruijiebook.txt","w");
				for(n=0;n<booknumber;n++)
				fprintf(fp,"%s %s %s %s %s \n",boo[n].num,boo[n].name,boo[n].writer,boo[n].press,boo[n].category);
				fclose(fp);
				printf("\n修改成功!");
			}
			else
        		printf("您想修改的图书信息与馆内信息重复。"); 
		}
   		printf("\n是否继续进行修改(y/n):");
        choice=getch();
        while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    choice=getch();
      	printf("%c",choice);
      	printf("\n");
        if(choice=='Y'||choice=='y')
            flag=1;
        if(choice=='N'||choice=='n')
            flag=0;
			Menu();
    	}
	}
}

			
//定义统计函数
void Statistics()
{
	char temp[10];
	int n=0,i=0,count=0;
	bo bookinfo[100];
	
	fp=fopen("d:\\yuruijiebook.txt","r");
    while(!feof(fp))
    {
		fscanf(fp,"%s %s %s %s %s\n",bookinfo[n].num,bookinfo[n].name,bookinfo[n].writer,bookinfo[n].press,bookinfo[n].category);
       	n++;
    }
    fclose(fp);

	printf("请输入你想统计的类别：");
	scanf("%s",temp);
	for(i=0;i<=n;i++)
	{
		if(strcmp(bookinfo[i].category,temp)==0)//如果重复
		{
			count++;
		}
	}
	printf("该类别的书籍共有%d本\n",count);
	printf("|---------------------------------图书信息---------------------------------|\n");
    printf("|序号    书名    作者    出版社    类别    |\n");
    printf("|                                                                          |\n");

	for(i=0;i<=n;i++)
	{
		if(strcmp(bookinfo[i].category,temp)==0)//如果重复
		{
			printf("%-10s%-10s%-10s%-10s%-10s\n",bookinfo[i].num,bookinfo[i].name,bookinfo[i].writer,bookinfo[i].press,bookinfo[i].category);
		}
	}
	system("pause");
	Menu();
}
			
//定义排序函数
void Sort()
{
	int i,n,j;
	bo bookinfo[100],booq;
	
	fp=fopen("d:\\yuruijiebook.txt","r");
    while(!feof(fp))
    {
		fscanf(fp,"%s %s %s %s %s\n",bookinfo[n].num,bookinfo[n].name,bookinfo[n].writer,bookinfo[n].press,bookinfo[n].category);
       	n++;
    }
    fclose(fp);

	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<=n-i;j++)
		{
			if(strcmp(bookinfo[j].name,bookinfo[j+1].name)>0)
			{
				booq=bookinfo[j];
				bookinfo[j]=bookinfo[j+1];
				bookinfo[j+1]=booq;
			}
			if(strcmp(bookinfo[j].name,bookinfo[j+1].name)==0||strcmp(bookinfo[j].num,bookinfo[j+1].num)>0)
			{
				booq=bookinfo[j];
				bookinfo[j]=bookinfo[j+1];
				bookinfo[j+1]=booq;
			}
		}
	}
	printf("按照书名排序结果如下 ：\n");
	printf("|---------------------------------图书信息---------------------------------|\n");
    printf("|序号    书名    作者    出版社    类别                                    |\n");
    printf("|                                                                          |\n");

	for(i=0;i<=n;i++)
	{
		printf("%-10s%-10s%-10s%-10s%-10s\n",bookinfo[i].num,bookinfo[i].name,bookinfo[i].writer,bookinfo[i].press,bookinfo[i].category);
	}

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