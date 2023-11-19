#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

#define N 10

FILE *fp;//�ļ�



typedef struct Book//����ṹ���������ڻ�������
{
	char num[N];//���
	char name[N];//����
	char writer[N];//����
	char press[N];//������
	char category[N];//���
}bo;

bo book[100];

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

int check_repeat(char num[30]);//�����鼮���


int main()
{

	//��ѯ����ͼ����Ϣ���ļ��Ƿ����
	if((fp=fopen("d:\\boook.txt","rb+"))==NULL)
	{
		printf("��d�̸�Ŀ¼��û���ҵ�����ͼ����Ϣ��boook.txt�ļ�\n��ѡ��  1--�ֶ����룡  2--�������ļ�\n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("�����Ϊboook.txt���ļ����Ƶ�d�̸�Ŀ¼��\n\n");break;
		
		case 2:if((fp=fopen("d:\\boook.txt","ab+"))!=NULL)
				   printf("�����ɹ�\n\n");
		
		}
	system("pause");
	}

	Menu();//��ת���˵�

	return 0;

}



//�����鼮���
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

	char choice;
	int i=0;

	do{
      	fflush(stdin);
		printf("������ͼ�����:");
		gets(book[i].num);
		
		if(check_repeat(book[i].num))
		{	
			printf("��ͼ������ѱ�ʹ�ã�");
			getch();

		}
		else
		{
			 
			printf("����������:");
			gets(book[i].name);
		
			printf("����������:");
			gets(book[i].writer);
		
			printf("�����������:");
			gets(book[i].press);
				
			printf("���������(רҵ��/������/����/С˵/����):");
			gets(book[i].category);
				
			i++;
      		
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

	fp=fopen("d:\\boook.txt","wb");
//	for(int n=0;n<=i;n++)
//	{
//		fprintf(fp,"%s %s %s %s %s\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);
//	}
	for(int n=0;n<=i;n++)
		fwrite(&book[n],sizeof(struct Book),1,fp);
	fclose(fp);

	printf("��ʾ:�ǵñ�������\n");
	fflush (stdin);
	system("pause");
	Menu();
		
}


//���屣�溯��
void Save()
{
	char choice;
	printf("�Ƿ񱣴���¼����Ŀ(Y/N):");
    choice=getch();
	while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n') choice=getch();
	printf("%c",choice);
    if(choice=='N'||choice=='n')
	{
       	printf("\n��Ŀδ����!\n");
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
			if(strcmp(book[n].num,number)==0)//����ظ�
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
		printf("\n����ɹ�!\n");
		//fp=fopen("d:\\boook.txt","wb");
		//for(int n=0;n<i;n++)
		//fwrite(&newbook[n],sizeof(bo),1,fp);
		//fclose(fp);

	}
	
	fflush (stdin);
	system("pause");
	Menu();


}
			

//�����������         wei
void Browse()                                           
{
	FILE *fp;
    int n;

    int booknumber=0;

    fflush(stdin);
    fp=fopen("d:\\boook.txt","r");
    char ch=fgetc(fp);
	if(ch==EOF) printf("�ļ�Ϊ�գ�û���鼮��Ϣ��\n");
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
		printf("*************************************************ͼ������***********************************************\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("\n���      ����      ����      ������    ���      \n");

		for(n=0;n<=booknumber;n++)//while(n<=booknumber)
		{
			printf("%-10s%-10s%-10s%-10s%-10s\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);
			//n++;
			//if(boo[n]==) break;
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
    char name_compare[30]="";//�������Ҫ��ѯ������
   	char press_compare[30]=""; //�������Ҫ��ѯ�ĳ�����
   	char writer_compare[30]="";//�������Ҫ��ѯ����������
	char category_compare[30]="";//�������Ҫ��ѯ�����
	char search[30]="";//�ȶ�����,����Ҫ���ҵ���������ȶ�����
	char compare[30]="";//�ȶ�����,������е���������ȶ�����
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

     	if(n>=booknumber)
		{
			printf("\nû�в��ҷ�����Ҫ����鼮!\n");
		}
		else
		{
			printf("---------------------------------ͼ����Ϣ---------------------------------\n");
      		printf("���      ����      ����      ������    ���      \n");
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

bo book;
	char choice;

    while(1)
    {

      	fflush(stdin);
		printf("������ͼ�����:");
		gets(book.num);
		
		if(check_repeat(book.num))
		{	
			printf("��ͼ������ѱ�ʹ�ã�");
			printf("\n���������������\n\n");
			getch();
		}
		else
		{
			 
			printf("����������:");
			gets(book.name);
		
			printf("����������:");
			gets(book.writer);
		
			printf("�����������:");
			gets(book.press);
			
			printf("���������(רҵ��/������/����/С˵/����):");
			gets(book.category);

			fflush(stdin);
      		printf("�Ƿ񱣴������Ŀ(y/n):");
      		choice=getch();
			while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      			choice=getch();
			printf("%c",choice);
     		if(choice=='Y'||choice=='y')
			{
        		fp=fopen("d:\\boook.txt","ab");
				fprintf(fp,"%s %s %s %s %s\n",book.num,book.name,book.writer,book.press,book.category);
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
    int n,i,j;
    FILE *fp;
    char choice;

    char number[10];

	while(1)
    {
    	fflush(stdin);
		printf("������Ҫɾ����ͼ�����:");
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
			if(strcmp(book[n].num,number)==0)//����ظ�
			{break;}
		}
			if(strcmp(book[n].num,number))
				printf("\nû�в��Ҹ�����κ���Ϣ!\n");
			else
			{
				printf("\n"); 
         		printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
      			printf("|���      ����      ����      ������    ���                              |\n");
      			printf("|                                                                          |\n");
    			printf("|%-10s%-10s%-10s%-10s%-10s\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);

           		printf("\n�Ƿ�ȷ����Ҫɾ��������Ŀ(Y/N):");
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
           			printf("\nɾ���ɹ�!");
				 }
           		else
				{
					printf("\n������Ŀû�б�ɾ��!");
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
	int n,j;
	char change,choice;
	char number[15];//ͼ�����
    char name[30];//ͼ������
    char writer[20];//����
   	char press[30];//������
	char category[20];//��� 
    
	char yuan[15];//Ҫ�޸ĵ����
	FILE *fp;

	int booknumber;
    while(1)
    {
    	fflush(stdin);
      	printf("����Ҫ�޸���Ϣ�������:");
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
         			printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
      				printf("|���      ����      ����      ������    ���                              |\n");
      				printf("|                                                                          |\n");
    				printf("|%-10s%-10s%-10s%-10s%-10s\n",book[n].num,book[n].name,book[n].writer,book[n].press,book[n].category);
       				
						printf("\n1.�鼮���\n2.�鼮����\n3.�鼮����\n4.������\n5.�鼮���\n\n����Ҫ�޸ĵ���:");
						change=getch();
						while(change!='1'&&change!='2'&&change!='3'&&change!='4'&&change!='5')
  							change=getch();
  						printf("%c",change);
           				printf("\n�������µ���Ϣ:");
           				fflush(stdin);
            			switch(change)
            			{
            				case '1':gets(number);if(!check_repeat(number))strcpy(book[n].num,number);break;
            				case '2':gets(name);strcpy(book[n].name,name);break;
            				case '3':gets(writer);strcpy(book[n].writer,writer);break;
            				case '4':gets(press);strcpy(book[n].press,press);break;
            				case '5':gets(category);strcpy(book[n].category,category);break;
            				default:break;//��Ȼѹ���������default����������º���������©���¼ӵ�case��while�������Լ���
						}
						if(check_repeat(number))
						{
							printf("�����޸ĵ�ͼ����Ϣ�������Ϣ�ظ���");
							break;
						}
						FILE *fp;
						fp=fopen("d:\\boook.txt","wb");
						for(j=0;j<booknumber;j++)
							fprintf(fp,"%s %s %s %s %s \n",book[j].num,book[j].name,book[j].writer,book[j].press,book[j].category);
						fclose(fp);
						printf("\n�޸ĳɹ�!");	
					break;
				}//if����	
				
			}//for����
						
				//if()printf("\nû�в��ҵ�������κ���Ϣ!");		
						
			
				
		
		

   			printf("\n�Ƿ���������޸�(y/n):");
			choice=getch();
			while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      			choice=getch();
      		printf("%c",choice);
      		printf("\n");
			if(choice=='Y'||choice=='y')
				continue;
			if(choice=='N'||choice=='n')
				break;
	}//while(1)����
	Menu();
}

			
//����ͳ�ƺ���
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

	printf("����������ͳ�Ƶ����");
	scanf("%s",temp);
	for(i=0;i<=n;i++)
	{
		if(strcmp(book[i].category,temp)==0)//����ظ�
		{
			count++;
		}
	}
	printf("�������鼮����%d��\n",count);
	printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
    printf("|���      ����      ����      ������    ���                              |\n");
    printf("|                                                                          |\n");

	for(i=0;i<=n;i++)
	{
		if(strcmp(book[i].category,temp)==0)//����ظ�
		{
			printf("%-10s%-10s%-10s%-10s%-10s\n",book[i].num,book[i].name,book[i].writer,book[i].press,book[i].category);
		}
	}
	system("pause");
	Menu();
}
			
//����������
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
	printf("������������������ ��\n");
	printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
    printf("|���      ����      ����      ������    ���                              |\n");
    printf("|                                                                          |\n");

	for(i=1;i<=n;i++)
	{
		printf("%-10s%-10s%-10s%-10s%-10s\n",book[i].num,book[i].name,book[i].writer,book[i].press,book[i].category);
	}
	system("pause"); 
	Menu();
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