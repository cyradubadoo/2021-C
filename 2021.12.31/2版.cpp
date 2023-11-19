#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

#define N 10

FILE *fp;//�ļ�


typedef struct book//����ṹ���������ڻ�������
{
	char num[N];//���
	char name[N];//����
	char writer[N];//����
	char press[N];//������
	char category[N];//���
}bo;

//�������ú���
void Menu();//�˵�
void Input();//¼��	
void Save();//����
void Browse();//���
void Search();//��ѯ
void Add();//����
void Delete();//ɾ��
void Revise();//�޸�
void Statistics();//ͳ��
void Sort();//����
void Quit();//�˳�

int compare(char *p,char *p1);//���ߺ����������Ա������ַ����ĳ���
int check_repeat_book(char num[30]);//�����鼮���

int main()
{
	
	system("cls");//����
	
	//��ѯ����ͼ����Ϣ���ļ��Ƿ����
	if((fp=fopen("d:\\yuruijiebook.txt","rb+"))==NULL)
	{
		printf("��d�̸�Ŀ¼��û���ҵ�����ͼ����Ϣ��yuruijiebook.txt�ļ�\n��ѡ��  1--�ֶ����룡  2--�������ļ�\n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("�����Ϊyuruijiebook.txt���ļ����Ƶ�d�̸�Ŀ¼��\n\n");break;
		
		case 2:if((fp=fopen("d:\\yuruijiebook.txt","ab+"))!=NULL)
				   printf("�����ɹ�\n\n");
		
		}
	system("pause");
	}

	Menu();//��ת���˵�

	return 0;

}


//����һ�����ߺ����������Ա������ַ�������ض�
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

//�����鼮���
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
			return 1;//Ϊ�棬�ظ�
   		}
   		else
		{
            return 0;//Ϊ�٣�δ�ظ�
		}
}


//����˵�����
void Menu()
{
	while(1)//ʹ������������������
	{
		system("cls");//����
		printf("\t************��ӭʹ�ø����鼮ϵͳ************\n");
		printf("\t--------------------------------------------\n");
		printf("\t----------------1.¼���鼮��Ϣ--------------\n");
		printf("\t----------------2.�����鼮��Ϣ--------------\n");
		printf("\t----------------3.����鼮��Ϣ--------------\n");	
		printf("\t----------------4.��ѯ�鼮��Ϣ--------------\n");
		printf("\t----------------5.�����鼮��Ϣ--------------\n");
		printf("\t----------------6.ɾ���鼮��Ϣ--------------\n");
		printf("\t----------------7.�޸��鼮��Ϣ--------------\n");
		printf("\t----------------8.�����ͳ���鼮������------\n");
		printf("\t----------------9.���������鼮��������------\n");
		printf("\t----------------10.�˳�---------------------\n");
		printf("\t--------------------------------------------\n");
		printf("\t*****************ллʹ��*******************\n");
		printf("\n");
	
		printf("��ѡ��(1-10):\n");
		int choice;
		scanf("%d",&choice);
		system("cls");//����

		switch(choice)//���в���ѡ��
		{
			case 1:printf("��¼���鼮��Ϣ��\n\n"); Input(); break;
			
			case 2:printf("�������鼮��Ϣ��\n\n"); Save(); break;
				
			case 3:printf("������鼮��Ϣ��\n\n"); Browse(); break;
			
			case 4:printf("����ѯ�鼮��Ϣ��\n\n"); Search(); break;
			
			case 5:printf("�������鼮��Ϣ��\n\n"); Add(); break;
			
			case 6:printf("��ɾ���鼮��Ϣ��\n\n"); Delete(); break;
			
			case 7:printf("���޸��鼮��Ϣ��\n\n"); Revise(); break;
			
			case 8:printf("�������ͳ���鼮��������\n\n"); Statistics(); break;
			
			case 9:printf("�����������鼮��������\n\n"); Sort(); break;
			
			case 10:printf("���˳���\n\n"); Quit(); break;

			default:printf("�Ƿ�����!\n");
		}
	}
}


//����¼�뺯��
void Input()
{
    bo newbook[100];
	char choice;
	int i=0,n=1;

	do{
      	fflush(stdin);
		printf("������ͼ�����:");
		gets(newbook[i].num);
		
		if(check_repeat_book(newbook[i].num))
		{	
			printf("��ͼ������ѱ�ʹ�ã�");
			getch();

		}
		else
		{
			 
			printf("����������:");
			gets(newbook[i].name);
		
			printf("����������:");
			gets(newbook[i].writer);
		
			printf("�����������:");
			gets(newbook[i].press);
				
			printf("���������(רҵ��/������/����/С˵/����):");
			gets(newbook[i].category);
				
			i++;n++;
      		
		} 	
		printf("\n\n�Ƿ���������Ŀ(y/n):");
		choice=getch();
		while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      		choice=getch();
      	printf("%c",choice);
      	printf("\n");
     	if(choice=='Y'||choice=='y') continue;
      	if(choice=='N'||choice=='n') break;		
		
	}while(i<100);

	printf("��¼��%d����Ŀ��\n",n);
	printf("��ʾ:�ǵñ�������\n");
	fflush (stdin);
	system("pause");
	Menu();
		
}


//���屣�溯��	wei	
void Save()
{
/*	char choice;

    int n;
	printf("��������¼������:");
	scanf("%d",&n);

	printf("�Ƿ񱣴���¼����Ŀ(Y/N):");
    choice=getch();
	while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n') choice=getch();
	printf("%c",choice);
    if(choice=='N'||choice=='n')
	{
       	printf("\n��Ŀδ����!\n");
	}
	if(choice=='Y'||choice=='y')
	{
        fp=fopen("d:\\yuruijiebook.txt","wb");
		for(int i=0;i<n;i++)
		{
			fprintf(fp,"%s %s %s %s %s\n",bo[i].num,bo[i].name,bo[i].writer,bo[i].press,bo[i].category);
		}
		fclose(fp);
        if() printf("\n����ʧ��!\n");
		else printf("\n����ɹ�!\n");
	}
	
	fflush (stdin);
	system("pause");
	Menu();
*/
}
			

//�����������         wei
void Browse()                                           
{
	FILE *fp;
    int n;
    bo boo[100];
    int booknumber=0;

    fflush(stdin);
    fp=fopen("d:\\yuruijiebook.txt","r");
    char ch=fgetc(fp);
	if(ch==EOF) printf("�ļ�Ϊ�գ�û���鼮��Ϣ��\n");
	else
	{
		while(!feof(fp))
		{
      		fscanf(fp,"%s %s %s %s %s\n",boo[booknumber].num,boo[booknumber].name,boo[booknumber].writer,boo[booknumber].press,boo[booknumber].category);
      		booknumber++;
		}
		fclose(fp);
		n=0;
		printf("*************************************************ͼ������***********************************************\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("\n���     ����     ����     ������    ���     \n");

		while(n<=booknumber)
		{
			printf("%-10s%-10s%-10s%-10s%-10s\n",boo[n].num,boo[n].name,boo[n].writer,boo[n].press,boo[n].category);
			n++;
		}
	}
	 printf("\n\n�������������һ���˵�!\n");
	 getch();
	 Menu();
}



//�����ѯ����
void Search()
{
		
	int flag=1,flag1=1;
	char select;
    char name_compare[30]="";//name_compare�������Ҫ��ѯ������
   	char press_compare[30]=""; //number_compare�������Ҫ��ѯ�ĳ�����
   	char writer_compare[30]="";//author_compare�������Ҫ��ѯ����������
	char category_compare[30]="";//author_compare�������Ҫ��ѯ�����
	char search[30]="";//search�Ǳȶ�����,����Ҫ���ҵ���������ȶ�����
	char compare[30]="";//compare�Ǳȶ�����,������е���������ȶ�����
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
	
			printf("��ѡ���ѯ���ͣ�\n\n\t\t1-������������ѯ     2-�������ߡ���ѯ\n");
			printf("                \n\t\t3-���������硿��ѯ     4-������𡿲�ѯ\n");
    		select=getch();
    		printf("%c",select);
			printf("\n\n�������������Ϣ:");		
			switch(select)
			{
				case '1':gets(name_compare);strcpy(search,name_compare);flag1=0;break;
				case '2':gets(writer_compare);strcpy(search,writer_compare);flag1=0;break;
				case '3':gets(press_compare);strcpy(search,press_compare);flag1=0;break;
				case '4':gets(category_compare);strcpy(search,category_compare);flag1=0;break;
				default :
					printf("\n��Ҫ����˵�֮�������~�������������");
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
         		printf("---------------------------------ͼ����Ϣ---------------------------------\n");
      			printf("���      ����      ����      ������    ���      \n");
      			printf("                                                                          \n");
    			printf("%-10s%-10s%-10s%-10s%-10s%\n",bookinfo[n].num,bookinfo[n].name,bookinfo[n].writer,bookinfo[n].press,bookinfo[n].category);
       			break;
			}
		}
		
   			if(n>=booknumber)
       		printf("\nû�в��ҷ�����Ҫ����鼮!\n");
       		
      		printf("\n\n�Ƿ������ѯ(y/n):");
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


			
//�������Ӻ���
void Add()
{
	bo newbook;

	char choice;

    while(1)
    {

      	fflush(stdin);
		printf("������ͼ�����:");
		gets(newbook.num);
		
		if(check_repeat_book(newbook.num))
		{	
			printf("��ͼ������ѱ�ʹ�ã�");
			printf("\n���������������\n\n");
			getch();

		}
		else
		{
			 
			printf("����������:");
			gets(newbook.name);
		
			printf("����������:");
			gets(newbook.writer);
		
			printf("�����������:");
			gets(newbook.press);
			
			printf("���������(רҵ��/������/����/С˵/����):");
			gets(newbook.category);

			fflush(stdin);
      		printf("�Ƿ񱣴������Ŀ(y/n):");
      		choice=getch();
			while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      			choice=getch();
			printf("%c",choice);
     		if(choice=='Y'||choice=='y')
			{
        		fp=fopen("d:\\yuruijiebook.txt","ab");
				fprintf(fp,"%s %s %s %s %s\n",newbook.num,newbook.name,newbook.writer,newbook.press,newbook.category);
				fclose(fp);
        		printf("\n������Ŀ����ӵ��ļ���!\n");
       		}
			if(choice=='N'||choice=='n')
			{
       			printf("\n������Ŀδ����!\n");
			}
			break;
		}
	
	}
	system("pause");
	Menu();
}




			
//����ɾ������wei
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
		printf("������Ҫɾ����ͼ�����:");
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
			if(strcmp(bookinfo[n].num,number)==0)//����ظ�
			{
				printf("\n"); 
         		printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
      			printf("|���      ����      ����      ������    ���      |\n");
      			printf("|                                                                          |\n");
    			printf("|%-10s%-10s%-10s%-10s%-10s\n",bookinfo[n].num,bookinfo[n].name,bookinfo[n].writer,bookinfo[n].press,bookinfo[n].category);

           		printf("\n�Ƿ�ȷ����Ҫɾ��������Ŀ(Y/N):");
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
           			printf("\nɾ���ɹ�!");
				 }
           		else
				{
					printf("\n������Ŀû�б�ɾ��!");
				}
				break;
			}
			
		}

		printf("\n\n�Ƿ��������ɾ������(y/n):");
		choice=getch();
		while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
			choice=getch();
		printf("%c",choice);
		printf("\n");
		if(choice=='Y'||choice=='y')
			continue;
		else
			break;
	}//while(1)����
	Menu();
}


//�����޸ĺ���wei
void Revise()
{
	int flag=1,flag1=1,flag2,n;
	char change,choice;
	char number[15];//ͼ�����
    char name[30];//ͼ������
    char writer[20];//����
   	char press[30];//������
	char category[20];//��� 
    
	char yuan[15];//Ҫ�޸ĵ����
	FILE *fp;
	bo boo[100];
	int booknumber;
    while(flag)
    {
    	flag2=0;
    	fflush(stdin);
      	printf("����Ҫ�޸���Ϣ�������:");
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
      //  	printf("�����û���κ���Ϣ!\n\n");
      //  	printf("��������ص����˵�!\n\n");
      //  	getch();
      //  	break;
      //  }
      //  else
      //  {
        	for(n=0;n<booknumber;n++)
         		if(strcmp(boo[n].num,yuan)==0)
            	{
            		printf("\n"); 
         			printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
      				printf("|���  ����        ����      ������          ���    |\n");
      				printf("|                                                                          |\n");
    				printf("|%-10s%-10s%-10s%-10s%-10s\n",boo[booknumber].num,boo[booknumber].name,boo[booknumber].writer,boo[booknumber].press,boo[booknumber].category);
       				
					while(flag1){
					printf("\n1.�鼮���\n2.�鼮����\n3.�鼮����\n4.������\n5.�鼮���\n\n����Ҫ�޸ĵ���:");
					change=getch();
					while(change!='1'&&change!='2'&&change!='3'&&change!='4'&&change!='5')
  						change=getch();
  					printf("%c",change);
           			printf("\n�������µ���Ϣ:");
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
            			default:break;//��Ȼѹ���������default����������º���������©���¼ӵ�case��while�������Լ���
					}
				}
			flag1=1;
            break;
        //    }
        if(n>=booknumber)
           printf("\nû�в��Ҹ�����κ���Ϣ!");
        else
		{
			if(!flag2)
			{
				fp=fopen("d:\\yuruijiebook.txt","w");
				for(n=0;n<booknumber;n++)
				fprintf(fp,"%s %s %s %s %s \n",boo[n].num,boo[n].name,boo[n].writer,boo[n].press,boo[n].category);
				fclose(fp);
				printf("\n�޸ĳɹ�!");
			}
			else
        		printf("�����޸ĵ�ͼ����Ϣ�������Ϣ�ظ���"); 
		}
   		printf("\n�Ƿ���������޸�(y/n):");
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

			
//����ͳ�ƺ���
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

	printf("����������ͳ�Ƶ����");
	scanf("%s",temp);
	for(i=0;i<=n;i++)
	{
		if(strcmp(bookinfo[i].category,temp)==0)//����ظ�
		{
			count++;
		}
	}
	printf("�������鼮����%d��\n",count);
	printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
    printf("|���    ����    ����    ������    ���    |\n");
    printf("|                                                                          |\n");

	for(i=0;i<=n;i++)
	{
		if(strcmp(bookinfo[i].category,temp)==0)//����ظ�
		{
			printf("%-10s%-10s%-10s%-10s%-10s\n",bookinfo[i].num,bookinfo[i].name,bookinfo[i].writer,bookinfo[i].press,bookinfo[i].category);
		}
	}
	system("pause");
	Menu();
}
			
//����������
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
	printf("������������������ ��\n");
	printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
    printf("|���    ����    ����    ������    ���                                    |\n");
    printf("|                                                                          |\n");

	for(i=0;i<=n;i++)
	{
		printf("%-10s%-10s%-10s%-10s%-10s\n",bookinfo[i].num,bookinfo[i].name,bookinfo[i].writer,bookinfo[i].press,bookinfo[i].category);
	}

}
			
//�����˳�����
void Quit()
{
	char choice;
	printf("��ȷ��Ҫ�˳���(Y/N):");//ѯ���û��Ƿ�ȷ���˳�

    while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
		choice=getch();
	printf("%c",choice);
	printf("\n");
	
	if(choice=='Y'||choice=='y') exit(0);//��������

	if(choice=='N'||choice=='n') printf("���ز˵�"); system("pause"); Menu();//��ת���˵�
}