#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

#define clean system("cls");//����
#define stop system("pause");//��ͣ

struct administrator//����Ա��Ϣ
{
	char name[20];//�û���
	char password[8];//����
};

typedef struct student//ѧ����Ϣ
{
    char num[20];//ѧ��
	char name[20];//ѧ������
	char sex[10];//�Ա� 
    int birth[3];//���� 
    char dep[16];//ϵ�� 
    float score1,score2,score3,score4,score5;//ѧ���ɼ� 
    struct student* next;//��һ��ѧ����ָ��
}Stu;

Stu* students;//ѧ������

void setxy(int x, int y);  //�������룬�����λ�ã�Ҳ���ǵ�ǰ���λ�� 
void Vexits();//�˳�����
int Ireturnmenu();//�������˵� 
void print();//����Ѻý��� 
void Vmainmenu();//���˵�
void Vhelp();//�汾��Ϣ 
void Vstudentmenu();//ѧ�����˵�
void Vtotallist();//ѧ�� �ܰ�˵�
void Vsorttotal();//�ܷ�����
void Vsinglelist();//ѧ�� �ܰ� ���������˵�
void Vsorthigh();//�������� 
void Vsortlogic();//�����߼����� 
void Vsortdisperse();//��ɢ���� 
void Vsingleinfor();//��ѯ������Ϣ
void Vtallest();//��߷ֲ�ѯ 
void Voverallsituationmenu();//��������˵�
void Voverallsituationtotal();//����������ƽ���֣�ƽ����������������������������ռ�� 
void Voverallsituationhigh();//����ƽ���֣�����ƽ��������������ƽ��������������ռ�ȣ����㣬���ã����񣬲�����
void Voverallsituationlogic();//�����߼� �������  
void Voverallsituationdisperse();//��ɢ��ѧ �������  
void Vadministratorregister();//����Ա��¼���� 
void Vencrypt(char *pwd);//�������
int IcherkUserValid(struct administrator *psu);//������Ա��¼��Ϣ�Ƿ���ȷ
void Vadministratormenu();//����Ա�˵�
void Vmodificationmenu();//�޸Ĳ˵� 
void Vmodificationsinglemenu();//�޸ĵ�����Ϣ�˵� 
void Vmodificationsinglename(char *num);//�޸�����
void Vmodificationsinglesex(char *num);//�޸��Ա�
void Vmodificationsinglebirth(char *num);//�޸�����
void Vmodificationsingledep(char *num);//�޸�ѧԺ
void Vmodificationsinglehigh(char *num);//�޸ĸ����ɼ�
void Vmodificationsinglelogic(char *num);//�޸������߼�
void Vmodificationsingledisperse(char *num);//�޸���ɢ�ɼ�
void Vmodificationall();//�޸�ѧ��������Ϣ
void Vcleanall();//�������
void Vdeletemenu();//ɾ���˵�
void Vfiletostruct();//���ļ�����Ϣ��������
void Vprintstruct();//����Ϣ�������Ļ
void Vaddscanf();//������Ϣ��Ļ����
int Icherknum(char *num);//����Ƿ�����ͬ��ѧ��
void Vadd(char* num, char* name, char* sex,int *birth,char *dep,float score1,float score2,float score3);//������Ϣ
void Vdelete(char* num);//ɾ����Ϣ(ѧ��)
void Vdeletename(char * name);//ɾ����Ϣ(����)
void VreWrite();//��д���ļ�
void Vstructtofile(Stu* stu);//���ṹ��������д���ļ�
int leap (int year);//�ж�����
int datelegal (int year,int month, int day)	;//�ж����������Ƿ�Ϸ�����

void setxy(int x, int y)  //�������룬�����λ�ã�Ҳ���ǵ�ǰ���λ��
{
   COORD coord = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Vexits()//�˳�����
{
	char n[1];
	clean;
	setxy(55,14);
	printf("***** ȷ��Ҫ�˳���?(��y�˳�������������������) *****");
	setxy(79,15);
	scanf("%s",n);
	if(n[0]=='y'||n[0]=='Y')
	{
		setxy(73,16);
		printf("��л����ʹ��!\n");
		Sleep(500);
		setxy(77,17);
		printf("�ټ�!\n");
		Sleep(400);
		exit(0);
	}
}

int Ireturnmenu()//�������˵� 
{
	char n[1];
	clean;
	setxy(58,14);
	printf("ȷ��Ҫ�������˵���?(��y�˳�������������������)");
	setxy(80,15);
	scanf("%s",n);
	if(n[0]=='y'||n[0]=='Y')
	{
		setxy(75,16);
		printf("�����������˵�...\n");
		Sleep(500);
		return 1;
	}
	return 0;
}

void print()//����Ѻý��� 
{
	setxy(57,8);
	printf("+-----------------------------------------+");
	setxy(57,9);
	printf("|* * * * * * * * * * * * * * * * * * * * *|");
	setxy(57,10);
	printf("|*                                       *|");
	setxy(57,11);
	printf("|*     �� ӭ ʹ �� ѧ �� �� �� ϵ ͳ     *|");
	setxy(57,12);
	printf("|*                                       *|");
	setxy(57,13);
	printf("|* * * * * * * * * * * * * * * * * * * * *|");
	setxy(57,14);
	printf("+-----------------------------------------+");
}

void Vmainmenu()//���˵�
{
	int n;
RR:	clean;
	print();
	Sleep(500);
	setxy(67,16);
	printf("�� ѡ �� �� �� �� ��:");
	setxy(70,18);
	printf("[1] ѧ ��");
	setxy(70,20);
	printf("[2] �� �� Ա");
	setxy(70,22);
	printf("[3] �� �� ˵ ��");
	setxy(70,24);
	printf("[0] �� �� �� ��");
	setxy(70,26);
	scanf("%d",&n);
	if(n==0)
	{
		Vexits();
		goto RR;

	}
	else if(n==1)
		Vstudentmenu();
	else if(n==2)
		Vadministratorregister();
	else if(n==3)
	{
		Vhelp();
		goto RR;
	}	
	else
	{
		setxy(71,28);
		printf("û�����ѡ��Ŷ!\n");
		Sleep(1000);
		goto RR;
	}
}

void Vhelp()//�汾��Ϣ 
{
	clean; 
	print();
	setxy(67,17);
	printf("****** �汾˵�� ******");
	setxy(48,19);
	printf("1��ʹ�ø����ǰ����ȷ���ڸ������ͬĿ¼�´���'stu.txt'��'register.txt'�ļ���") ;
	setxy(48,20);
	printf("2����ͨ��'���ù���Ա��Ϣ'����޸Ĺ���Ա��Ϣ��");
	setxy(48,21);
	printf("3���������VC++��Dev C++�Ͽ��������У��������뻷�����޲��ԡ�"); 
	setxy(48,22);
	printf("4����ӭ�Ա��������Ľ������");
	setxy(48,24);
	printf("***   ������:����ʦ����ѧ ���������Ϣ����ѧԺ ʦ������ κ����   ***");
	setxy(48,26);
	stop;
}

void Vstudentmenu()//ѧ�����˵�
{
	char n[2];
RR:	clean;
	print();
	setxy(63,16);
	printf("�� �� �� �� Ҫ �� ѯ �� �� Ϣ:");
	setxy(71,18);
	printf("[1] �ܰ�");
	setxy(71,19);
	printf("[2] ������Ϣ"); 
	setxy(71,20);
	printf("[3] ��߷�");
	setxy(71,21);
	printf("[4] ����ɼ����"); 
	setxy(71,22);
	printf("[#] ������һ��");
	setxy(71,23);
	printf("[0] �˳�����");
	setxy(71,24);
	scanf("%s",n);

	if(n[1]!='\0')
	{
		setxy(70,26);
		printf("û�����ѡ��Ŷ!\n");
		Sleep(500);
		clean;
		goto RR;
	}
	switch(n[0])
	{
		case '1':Vtotallist();break;
		case '2':Vsingleinfor();goto RR;break;
		case '3':Vtallest();goto RR;break;
		case '4':Voverallsituationmenu();break; 
		case '#':Vmainmenu();break;
		case '0':{Vexits();goto RR;};break;
		default:{setxy(70,26);printf("û�����ѡ��Ŷ!\n");Sleep(500);clean;goto RR;};break;
	}
}

void Vtotallist()//ѧ�� �ܰ�˵�
{
	char n[2];
RR:	clean;
	print();
	setxy(58,16);
	printf("�� �� �� �� �� �� ѯ �� �� �� ˳ �� �� ��:");
	setxy(70,18);
	printf("[1] Ĭ��˳��");//��� 
	setxy(70,19);
	printf("[2] �ܷ�����˳��");
	setxy(70,20);
	printf("[3] ��������˳��");
	setxy(70,21);
	printf("[#] ������һ��");
	setxy(70,22);
	printf("[*] �������˵�");
	setxy(70,23);
	printf("[0] �˳�����");
	setxy(70,24);
	scanf("%s",n);
	if(n[1]!='\0')
	{
		setxy(69,26);
		printf("û�����ѡ��Ŷ!\n");
		Sleep(500);
		clean;
		goto RR;
	}
	switch(n[0])
	{
		case '1':clean;printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ****ѧ���ɼ��Ű�****\n\n\n");Vprintstruct();stop;goto RR;break;
		case '2':Vsorttotal();goto RR;break;
		case '3':Vsinglelist();break;
		case '#':Vstudentmenu();break;
		case '*':
				{
					if(Ireturnmenu())
						Vmainmenu();
					else
						goto RR;
					break;
				}
		case '0':{Vexits();goto RR;};break;
		default:{setxy(69,26);printf("û�����ѡ��Ŷ!\n");setxy(69,26);Sleep(500);goto RR;};break;
	}
}

void Vsorttotal()//�ܷ�����
{
	Stu * stu=students->next;
	Stu *p=students->next;
	float score[100]={0};
	int i,j,c=0,k=1;
	float temp;
	clean;
	if(stu==NULL)
	{
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t*�������Ϣ*");
		stop;
		Vtotallist();
	}		
	while(stu!=NULL)
    {
      score[c]=stu->score4;//�������ܳɼ�����������
      c++;
      stu=stu->next;
    }
    for(i=0;i<c-1;i++)//�������������
    {
       for(j=0;j<c-1-i;j++)
       {
          if(score[j]<score[j+1])
          {
             temp=(float)score[j];
             score[j]=score[j+1];
             score[j+1]=temp;      
          } 
       }
    }
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ****ѧ���ɼ��Ű�****\n\n\n");
	printf("���\tѧ��\t\t  ����\t\t�Ա�\t����\t\tѧԺ\t\t�ߵ���ѧ\t�����߼�\t��ɢ��ѧ\t�ܳɼ�\t\tƽ����\n");
	for(j=0;j<c;j++)
    {
        if(j>=1)
        {      
			if(score[j]!=score[j-1])
        	while(p!=NULL)
        	{
        		if(score[j]==p->score4)
                	printf("%d\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",k++,p->num,p->name,p->sex,p->birth[0],p->birth[1],p->birth[2],p->dep,p->score1,p->score2,p->score3,p->score4,p->score5);
            	p=p->next;  
           	}
        }
        else
            while(p!=NULL)
         {
          if(score[j]==p->score4)
                printf("%d\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",k++,p->num,p->name,p->sex,p->birth[0],p->birth[1],p->birth[2],p->dep,p->score1,p->score2,p->score3,p->score4,p->score5);
           p=p->next;  
         }
          p=students->next;
    }
	stop;
} 

void Vsinglelist()//ѧ�� �ܰ� ���������˵�
{
	char n[2];
RR:	clean;
	print();
	setxy(64,16);
	printf("�� �� �� �� �� �� ѯ �� �� Ŀ:");
	setxy(70,18);
	printf("[1]�ߵ���ѧ");
	setxy(70,19);
	printf("[2]�����߼�");
	setxy(70,20);
	printf("[3]��ɢ��ѧ");
	setxy(70,21);
	printf("[4]����ѧ�����˵�");
	setxy(70,22);
	printf("[#]������һ��");
	setxy(70,23);
	printf("[*]�������˵�");
	setxy(70,24);
	printf("[0]�˳�����");
	setxy(70,25);
	scanf("%s",n);
	if(n[1]!='\0')
	{
		setxy(71,27);
		printf("û�����ѡ��Ŷ!\n");
		Sleep(500);
		clean;
		goto RR;
	}
	switch(n[0])
	{
		case '1':Vsorthigh();goto RR;break;
		case '2':Vsortlogic();goto RR;break; 
		case '3':Vsortdisperse();goto RR;break;
		case '4':Vstudentmenu();break;
		case '#':Vtotallist();break;
		case '*':
				{
					if(Ireturnmenu())
						Vmainmenu();
					else
						goto RR;
					break;
				}
		case '0':{Vexits();goto RR;};break;
		default:{setxy(71,27);printf("û�����ѡ��Ŷ!\n");Sleep(500);goto RR;};break;
	}
}

void Vsorthigh()//�������� 
{
	Stu * stu=students->next;
	Stu *p=students->next;
	float score[100]={0};
	int i,j,c=0,k=1;
	float temp;
	clean;
	if(stu==NULL)
	{
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t*�������Ϣ*");
		stop;
		Vtotallist();
	}		
	while(stu!=NULL)
    {
      score[c]=stu->score1;
      c++;
      stu=stu->next;
    }
    for(i=0;i<c-1;i++)
    {
       for(j=0;j<c-1-i;j++)
       {
          if(score[j]<score[j+1])
          {
             temp=score[j];
             score[j]=score[j+1];
             score[j+1]=temp;      
          } 
       }
    }
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ****ѧ���ɼ��Ű�****\n\n\n");
	printf("���\tѧ��\t\t  ����\t\t�Ա�\t����\t\tѧԺ\t\t�ߵ���ѧ\t�����߼�\t��ɢ��ѧ\t�ܳɼ�\t\tƽ����\n");
	for(j=0;j<c;j++)
    {
        if(j>=1)
        {      
			if(score[j]!=score[j-1])
        	while(p!=NULL)
        	{
        		if(score[j]==p->score1)
                	printf("%d\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",k++,p->num,p->name,p->sex,p->birth[0],p->birth[1],p->birth[2],p->dep,p->score1,p->score2,p->score3,p->score4,p->score5);
            	p=p->next;  
           	}
        }
        else
            while(p!=NULL)
         {
          if(score[j]==p->score1)
                printf("%d\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",k++,p->num,p->name,p->sex,p->birth[0],p->birth[1],p->birth[2],p->dep,p->score1,p->score2,p->score3,p->score4,p->score5);
           p=p->next;  
         }
          p=students->next;
    }
	stop;
} 

void Vsortlogic()//�����߼����� 
{
	Stu * stu=students->next;
	Stu *p=students->next;
	float score[100]={0};
	int i,j,c=0,k=1;
	float temp;
	clean;
	if(stu==NULL)
	{
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t*�������Ϣ*");
		stop;
		Vtotallist();
	}		
	while(stu!=NULL)
    {
      score[c]=stu->score2;
      c++;
      stu=stu->next;
    }
    for(i=0;i<c-1;i++)
    {
       for(j=0;j<c-1-i;j++)
       {
          if(score[j]<score[j+1])
          {
             temp=score[j];
             score[j]=score[j+1];
             score[j+1]=temp;      
          } 
       }
    }
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ****ѧ���ɼ��Ű�****\n\n\n");
	printf("���\tѧ��\t\t  ����\t\t�Ա�\t����\t\tѧԺ\t\t�ߵ���ѧ\t�����߼�\t��ɢ��ѧ\t�ܳɼ�\t\tƽ����\n");
	for(j=0;j<c;j++)
    {
        if(j>=1)
        {      
			if(score[j]!=score[j-1])
        	while(p!=NULL)
        	{
        		if(score[j]==p->score2)
                	printf("%d\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",k++,p->num,p->name,p->sex,p->birth[0],p->birth[1],p->birth[2],p->dep,p->score1,p->score2,p->score3,p->score4,p->score5);
            	p=p->next;  
           	}
        }
        else
            while(p!=NULL)
         {
          if(score[j]==p->score2)
                printf("%d\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",k++,p->num,p->name,p->sex,p->birth[0],p->birth[1],p->birth[2],p->dep,p->score1,p->score2,p->score3,p->score4,p->score5);
           p=p->next;  
         }
          p=students->next;
    }
	stop;
} 

void Vsortdisperse()//��ɢ���� 
{
	Stu * stu=students->next;
	Stu *p=students->next;
	float score[100]={0};
	int i,j,c=0,k=1;
	float temp;
	clean;
	if(stu==NULL)
	{
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t*�������Ϣ*");
		stop;
		Vtotallist();
	}		
	while(stu!=NULL)
    {
      score[c]=stu->score3;
      c++;
      stu=stu->next;
    }
    for(i=0;i<c-1;i++)
    {
       for(j=0;j<c-1-i;j++)
       {
          if(score[j]<score[j+1])
          {
             temp=score[j];
             score[j]=score[j+1];
             score[j+1]=temp;      
          } 
       }
    }
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ****ѧ���ɼ��Ű�****\n\n\n");
	printf("���\tѧ��\t\t  ����\t\t�Ա�\t����\t\tѧԺ\t\t�ߵ���ѧ\t�����߼�\t��ɢ��ѧ\t�ܳɼ�\t\tƽ����\n");
	for(j=0;j<c;j++)
    {
        if(j>=1)
        {      
			if(score[j]!=score[j-1])
        	while(p!=NULL)
        	{
        		if(score[j]==p->score3)
                	printf("%d\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",k++,p->num,p->name,p->sex,p->birth[0],p->birth[1],p->birth[2],p->dep,p->score1,p->score2,p->score3,p->score4,p->score5);
            	p=p->next;  
           	}
        }
        else
            while(p!=NULL)
         {
          if(score[j]==p->score3)
                printf("%d\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",k++,p->num,p->name,p->sex,p->birth[0],p->birth[1],p->birth[2],p->dep,p->score1,p->score2,p->score3,p->score4,p->score5);
           p=p->next;  
         }
          p=students->next;
    }
	stop;
} 

void Vsingleinfor()//��ѯ������Ϣ
{
	char num[20];
	Stu * stu=students->next;
RR:	clean;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t����������Ҫ��ѯ��Ϣ��ѧ��:");
	scanf("%s",num);
	if(!Icherknum(num))
	{
		printf("\t\t\t\t\t\t\t     δ���ҵ���ѧ������˶���Ϣ!");
		Sleep(600);
		goto RR;
	}
	while (strcmp(stu->num,num))
        stu = stu->next;
    printf("\n\tѧ��\t\t  ����\t\t�Ա�\t����\t\tѧԺ\t\t�ߵ���ѧ\t�����߼�\t��ɢ��ѧ\t�ܳɼ�\t\tƽ����\n");
    printf("\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n\n\n\t\t\t\t\t\t\t\t",stu->num,stu->name,stu->sex,stu->birth[0],stu->birth[1],stu->birth[2],stu->dep,stu->score1,stu->score2,stu->score3,stu->score4,stu->score5);
    stop;
	
} 

void Vtallest()//��߷ֲ�ѯ
{
	Stu * stu=students->next;
	float a[4]={0};
	int i;
	clean;
	if(stu==NULL)      //��������Ƿ�Ϊ�� 
    {
    	printf("\n\n\t\t\t\t\t\t\t\t\t*�������Ϣ*");
    	return;
    }
    else
    	while (stu!=NULL)    //������߷ֲ�������д������ 
    	{
        	if(stu->score1>a[0])
        		a[0]=(float)(stu->score1);
        	if(stu->score2>a[1])
        		a[1]=(float)(stu->score2);
        	if(stu->score3>a[2])
        		a[2]=(float)(stu->score3);
        	if(stu->score4>a[3])
        		a[3]=(float)(stu->score4);
        	stu = stu->next;
    	}
    stu=students->next;
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    �ܷ���߷�:%.2f  \n\n",a[3]);
    i=1;
	while(stu!=NULL)    //���ҵ���߷ֵ�ȫ����Ϣ����� 
    {
    	if(stu->score4==a[3])
    	{
			printf("\t\t\t\t\t\t\t\t%d   %s\t%s\t%.2f\n",i,stu->num,stu->name,stu->score4);
			i++;
    	}
    	stu=stu->next;	
	}
	printf("\n\n");
	stu=students->next;
	i=1;
	printf("\t\t\t\t\t\t\t\t\t  �ߵ���ѧ��߷�:%.2f\n",a[0]);
	while(stu!=NULL)
    {
    	if(stu->score1==a[0])
    	{
			printf("\t\t\t\t\t\t\t\t%d   %s\t%s\t%.2f\n",i,stu->num,stu->name,stu->score1);
			i++;
    	}
    	stu=stu->next;
	}
	printf("\n\n");
	stu=students->next;
	printf("\t\t\t\t\t\t\t\t\t  �����߼���߷�:%.2f\n",a[1]);
	i=1;
	while(stu!=NULL)
    {
    	if(stu->score2==a[1])
    	{
			printf("\t\t\t\t\t\t\t\t%d   %s\t%s\t%.2f\n",i,stu->num,stu->name,stu->score2);
			i++;
    	}
    	stu=stu->next;
	}
	printf("\n\n");
	stu=students->next;
	printf("\t\t\t\t\t\t\t\t\t  ��ɢ��ѧ��߷�:%.2f\n",a[2]);
	i=1;
	while(stu!=NULL)
    {
    	if(stu->score3==a[2])
    	{
			printf("\t\t\t\t\t\t\t\t%d   %s\t%s\t%.2f\n",i,stu->num,stu->name,stu->score3);
			i++;
    	}
    	stu=stu->next;
	}
    stop;
} 

void Voverallsituationmenu()//��������˵� 
{
	char a[2];
RR:	clean;
	print();
	setxy(64,16);
	printf("�� ѡ ��:");
	setxy(68,18);
	printf("[1]�ܳɼ��������");//��� 
	setxy(68,19);
	printf("[2]�ߵ���ѧ�ɼ��������");
	setxy(68,20);
	printf("[3]�����߼��ɼ��������");
	setxy(68,21);
	printf("[4]��ɢ��ѧ�ɼ��������");
	setxy(68,22);
	printf("[5]����ѧ�����˵�");
	setxy(68,23); 
	printf("[#]������һ��");
	setxy(68,24);
	printf("[0]�˳�����");
	setxy(68,25); 
	scanf("%s",a);
	switch(a[0])
	{
		case '1':Voverallsituationtotal();goto RR;break;
		case '2':Voverallsituationhigh();goto RR;break;
		case '3':Voverallsituationlogic();goto RR;break;
		case '4':Voverallsituationdisperse();goto RR;break;
		case '5':Vstudentmenu();break;
		case '#':Vstudentmenu();break;
		case '0':Vexits();goto RR;break;
		default:setxy(71,27);printf("û�����ѡ��Ŷ!\n");Sleep(500);clean;goto RR;break;
	}
} 

void Voverallsituationtotal()  //����������ƽ���֣�ƽ����������������������������ռ�� 
{
	Stu* stu=students->next;
	float total=0,ave=0;
	int i=0,j=0;
	float s=0; 
	clean;
	while(stu!=NULL)  //�ܷ� 
	{
		total+=stu->score4;
		stu=stu->next;
		i++;
	}
	ave=total/i;  //ƽ���� 
	stu=students->next;
	while(stu!=NULL)  //����ƽ���ֵ����� 
	{
		if(stu->score4>=ave)
			j++;
		stu=stu->next;
	}
	s=(float)1.0*j/i*100;  //����ƽ���ֵı��� 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t       ������:%d   ��ƽ����:%.2f\n",i,ave);
	printf("\t\t\t\t\t\t\t     ƽ������������:%d   ռ��:%.2f%%\n",j,s);
	printf("\t\t\t\t\t\t\t     ƽ������������:%d   ռ��:%.2f%%\n",(i-j),(100-s));
	printf("\n\n\t\t\t\t\t\t\t          ");
	stop;
}

void Voverallsituationhigh()//����ƽ���֣�����ƽ��������������ƽ��������������ռ�ȣ����㣬���ã����񣬲����� 
{
	Stu* stu=students->next;
	float total=0,ave=0;
	int i=0,j=0,a=0,b=0,c=0,d=0;
	float s=0; 
	clean;
	while(stu!=NULL)
	{
		total+=stu->score1;
		stu=stu->next;
		i++;
	}
	ave=total/i;
	stu=students->next;
	while(stu!=NULL)
	{
		if(stu->score1>=ave)
			j++;
		if(stu->score1>=90)
			a++;
		if(stu->score1>=80&&stu->score1<90)
			b++;
		if(stu->score1>=60&&stu->score1<80)
			c++;
		if(stu->score1<60)
			d++;
		stu=stu->next;
	}
	s=(float)1.0*j/i*100;
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  �ߵ���ѧƽ����:%.2f\n",ave);
	printf("\t\t\t\t\t\t\t     ƽ������������:%d   ռ��:%.2f%%\n",j,s);
	printf("\t\t\t\t\t\t\t     ƽ������������:%d   ռ��:%.2f%%\n",(i-j),(100-s));
	printf("\t\t\t\t\t\t\t     ��������:%d         ռ��:%.2f%%\n",a,100.0*a/i);
	printf("\t\t\t\t\t\t\t     ��������:%d         ռ��:%.2f%%\n",b,100.0*b/i);
	printf("\t\t\t\t\t\t\t     ��������:%d         ռ��:%.2f%%\n",c,100.0*c/i);
	printf("\t\t\t\t\t\t\t     ����������:%d       ռ��:%.2f%%\n",d,100.0*d/i);
	printf("\n\n\t\t\t\t\t\t\t          ");
	stop;
}

void Voverallsituationlogic()//�����߼�
{
	Stu* stu=students->next;
	float total=0,ave=0;
	int i=0,j=0,a=0,b=0,c=0,d=0;
	float s=0; 
	clean;
	while(stu!=NULL)
	{
		total+=stu->score2;
		stu=stu->next;
		i++;
	}
	ave=total/i;
	stu=students->next;
	while(stu!=NULL)
	{
		if(stu->score2>=ave)
			j++;
		if(stu->score2>=90)
			a++;
		if(stu->score2>=80&&stu->score2<90)
			b++;
		if(stu->score2>=60&&stu->score2<80)
			c++;
		if(stu->score2<60)
			d++;
		stu=stu->next;
	}
	s=(float)1.0*j/i*100;
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  �����߼�ƽ����:%.2f\n",ave);
	printf("\t\t\t\t\t\t\t     ƽ������������:%d   ռ��:%.2f%%\n",j,s);
	printf("\t\t\t\t\t\t\t     ƽ������������:%d   ռ��:%.2f%%\n",(i-j),(100-s));
	printf("\t\t\t\t\t\t\t     ��������:%d         ռ��:%.2f%%\n",a,100.0*a/i);
	printf("\t\t\t\t\t\t\t     ��������:%d         ռ��:%.2f%%\n",b,100.0*b/i);
	printf("\t\t\t\t\t\t\t     ��������:%d         ռ��:%.2f%%\n",c,100.0*c/i);
	printf("\t\t\t\t\t\t\t     ����������:%d       ռ��:%.2f%%\n",d,100.0*d/i);
	printf("\n\n\t\t\t\t\t\t\t          ");
	stop;
}

void Voverallsituationdisperse()//��ɢ��ѧ 
{
	Stu* stu=students->next;
	float total=0,ave=0;
	int i=0,j=0,a=0,b=0,c=0,d=0;
	float s=0; 
	clean;
	while(stu!=NULL)
	{
		total+=stu->score3;
		stu=stu->next;
		i++;
	}
	ave=total/i;
	stu=students->next;
	while(stu!=NULL)
	{
		if(stu->score3>=ave)
			j++;
		if(stu->score3>=90)
			a++;
		if(stu->score3>=80&&stu->score3<90)
			b++;
		if(stu->score3>=60&&stu->score3<80)
			c++;
		if(stu->score3<60)
			d++;
		stu=stu->next;
	}
	s=(float)1.0*j/i*100;
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ��ɢ��ѧƽ����:%.2f\n",ave);
	printf("\t\t\t\t\t\t\t     ƽ������������:%d   ռ��:%.2f%%\n",j,s);
	printf("\t\t\t\t\t\t\t     ƽ������������:%d   ռ��:%.2f%%\n",(i-j),(100-s));
	printf("\t\t\t\t\t\t\t     ��������:%d         ռ��:%.2f%%\n",a,100.0*a/i);
	printf("\t\t\t\t\t\t\t     ��������:%d         ռ��:%.2f%%\n",b,100.0*b/i);
	printf("\t\t\t\t\t\t\t     ��������:%d         ռ��:%.2f%%\n",c,100.0*c/i);
	printf("\t\t\t\t\t\t\t     ����������:%d       ռ��:%.2f%%\n",d,100.0*d/i);
	printf("\n\n\t\t\t\t\t\t\t          ");
	stop;
}

void Vadministratorregister()//����Ա��¼���� 
/*����Ա����
  tom tm524
  mary my956
  lisa la846
  open op654
  green gn381*/
{
	struct administrator ad;
	int i,j=0; 
	clean;
	for(i=0;i<3;i++)
	{
		j=0;
		clean;
		print();
		setxy(53,16);
		printf("�� �� �� �� ¼ �� Ϣ ( �� �� 3 �� �� �� ��ʣ �� %d ��)\n",3-i);
		setxy(70,18);
		printf("�� �� ��:");
		scanf("%s",ad.name);
		setxy(70,19);
		printf("��    ��:");
		for(j=0;j<100;j++) //�������ڸǳ�* 
		{
			ad.password[j]=getch();
			if(ad.password[j]=='\r')
				break;
			printf("*");
		}
		ad.password[j]='\0';
		printf("\n");
		if(IcherkUserValid(&ad)==1)  //������Ա��Ϣ�Ƿ���ȷ 
		{
			setxy(70,21);
			printf("�� ¼ �� ��!\n");
			Sleep(1000);
			Vadministratormenu();
		}
		else
		{
			setxy(67,21);
			printf("���������û�������!\n"); 
			Sleep(1000);
		}
	}
	setxy(65,23);
	printf("�� �� �� �� �� �� �� Ŷ!");
	Sleep(700);
	setxy(64,25);
	printf("�� �� �� �� ѧ �� �� ��...\n\n");
	Sleep(1500);
	stop;
	Vstudentmenu();
}

void Vencrypt(char *pwd)  //������� 
{
	int i,len=strlen(pwd);
	for(i=0;i<len;i++)
		pwd[i]=pwd[i]^15;    //��15���ݽ��м��ܴ��� 
}

int IcherkUserValid(struct administrator *psu)  //������Ա��¼��Ϣ�Ƿ���ȷ 
{
	FILE *fp;
	char usr[30],usr1[30],pwd[10];
	int check=0;
	strcpy(usr,psu->name);
	strcpy(pwd,psu->password);
	Vencrypt(pwd);      //������ܴ��� 
	strcat(usr," ");
	strcat(usr,pwd);
	strcat(usr,"\n");
	if((fp=fopen("register.txt","r"))==NULL)
	{
		printf("�ļ�����!\n");
		exit(0);
	}
	while(!feof(fp))
	{
		fgets(usr1,30,fp);
		if(strcmp(usr,usr1)==0)  //�Ա���Ϣ�Ƿ�һ�� 
		{
			check=1;
			break;
		}		
	}
	fclose(fp);
	return check;
}
/*����Ա*/
void Vadministratormenu()//����Ա�˵�
{
	char n[2],a[1]; 
RR:	clean;
	print();//����Ѻý���
	
RB:	setxy(63,16);
	printf("�� ѡ �� �� �� �� �� �� �� ��:");
	setxy(68,18);
	printf("[1] ���ѧ����Ϣ(��Ȼ˳��)");  
	setxy(68,19);
	printf("[2] ����ѧ����Ϣ"); 
	setxy(68,20);
	printf("[3] ɾ��ѧ����Ϣ");
	setxy(68,21);
	printf("[4] �޸�ѧ����Ϣ");
	setxy(68,22);
	printf("[5] �������ѧ����Ϣ"); 
	setxy(68,23);
	printf("[6] ����ѧ������");
	setxy(68,24);
	printf("[*] �������˵�");
	setxy(68,25);
	printf("[0] �˳�����");
	setxy(68,26);
	scanf("%s",n);
	if(n[1]!='\0')
	{
		setxy(67,28);
		printf("û�����ѡ��Ŷ!\n");
		Sleep(500);
		clean;
		goto RR;
	}
	switch(n[0])
	{
		case '1':clean;Vprintstruct();goto RB;break;
		case '2':clean;Vaddscanf();clean;Vprintstruct();goto RB;break;
		case '3':Vdeletemenu();clean;Vprintstruct();break;
		case '4':Vmodificationmenu();clean;Vprintstruct();break; 
		case '5':
				{
					printf("\t\t\t\t\t\t\t\tȷ�����������Ϣ��(ȷ������y)");
					scanf("%s",a);
					if(a[0]=='y'||a[0]=='Y')
					{
						Vcleanall();
						printf("\t\t\t\t\t\t\t\t\t  ����ɹ�!\n");
						stop;
						Sleep(1000);
					}	
					else
						goto RR;
					clean;
					Vprintstruct();
					goto RB;
					break;
				}
		case '6':Vstudentmenu();break;
		case '*':
				{
					if(Ireturnmenu())
						Vmainmenu();
					else
						goto RR;
					break;
				}
		case '0':Vexits();goto RR;break;
		default:setxy(67,28);printf("û�����ѡ��Ŷ!\n");Sleep(500);goto RR;break;
	}
} 

void Vmodificationmenu()//�޸Ĳ˵� 
{
	char a[2];
RR:	clean;
	Vprintstruct();
	setxy(67,16);
	printf("�� ѡ ��:");
	setxy(71,18);
	printf("[1] �޸�ѧ��������Ϣ");
	setxy(71,19);
	printf("[2] �޸�ѧ��ȫ����Ϣ");
	setxy(71,20);
	printf("[3] ����ѧ������");
	setxy(71,21);
	printf("[#] ������һ��");
	setxy(71,22);
	printf("[*] �������˵�");
	setxy(71,23);
	printf("[0] �˳�����");
	setxy(71,24);
	scanf("%s",a);
	switch(a[0])
	{
		case '1':Vmodificationsinglemenu();goto RR;break;
		case '2':Vmodificationall();goto RR;break;
		case '3':Vstudentmenu();break;
		case '#':Vadministratormenu();break;
		case '*':
				{
					if(Ireturnmenu())
						Vmainmenu();
					else
						goto RR;
					break;
				}
		case '0':Vexits();goto RR;break;
		default:setxy(68,26);printf("û�����ѡ��Ŷ!\n");Sleep(500);clean;goto RR;break;
	} 
}

void Vmodificationsinglemenu()//�޸ĵ�����Ϣ�˵�
{
	char a[2],num[20];
RR:	clean;
	Vprintstruct();
	setxy(64,16);
	printf("�� ѡ ��:");
	setxy(69,18);
	printf("[1] �޸�ѧ��������Ϣ");
	setxy(69,19);
	printf("[2] �޸�ѧ���Ա���Ϣ"); 
	setxy(69,20);
	printf("[3] �޸�ѧ��������Ϣ");
	setxy(69,21);
	printf("[4] �޸�ѧ��ѧԺ��Ϣ");
	setxy(69,22);
	printf("[5] �޸�ѧ���ߵ���ѧ�ɼ���Ϣ");
	setxy(69,23);
	printf("[6] �޸�ѧ�������߼��ɼ���Ϣ");
	setxy(69,24);
	printf("[7] �޸�ѧ����ɢ��ѧ�ɼ���Ϣ");
	setxy(69,25);
	printf("[8] ���ع���Ա���˵�");
	setxy(69,26);
	printf("[9] ����ѧ������");
	setxy(69,27);
	printf("[#] ������һ��");
	setxy(69,28);
	printf("[*] �������˵�");
	setxy(69,29);
	printf("[0] �˳�����");
	setxy(69,30);
	scanf("%s",a);
	switch(a[0])
	{
		case '1':
				{
RB:					clean;
					Vprintstruct();	
					setxy(59,21);	
					printf("�����������޸ĵ�ѧ����ѧ��:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsinglename(num);
					else
					{
						printf("\t\t\t\t\t\t\t\tδ���ҵ���ѧ������˶�������Ϣ!\n");
						Sleep(1500);
						goto RB;
					}
					goto RR;
					break;
				}
		case '2':
				{
RD:					clean;
					Vprintstruct();	
					setxy(59,21);	
					printf("�����������޸ĵ�ѧ����ѧ��:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsinglesex(num);
					else
					{
						printf("\t\t\t\t\t\t\t\tδ���ҵ���ѧ������˶�������Ϣ!\n");
						Sleep(1500);
						goto RD;
					}
					goto RR;
					break;
				}
		case '3':
				{
RE:					clean;
					Vprintstruct();	
					setxy(59,21);	
					printf("�����������޸ĵ�ѧ����ѧ��:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsinglebirth(num);
					else
					{
						printf("\t\t\t\t\t\t\t\tδ���ҵ���ѧ������˶�������Ϣ!\n");
						Sleep(1500);
						goto RE;
					}
					goto RR;
					break;
				}
		case '4':
				{
RF:					clean;
					Vprintstruct();	
					setxy(59,21);	
					printf("�����������޸ĵ�ѧ����ѧ��:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsingledep(num);
					else
					{
						printf("\t\t\t\t\t\t\t\tδ���ҵ���ѧ������˶�������Ϣ!\n");
						Sleep(1500);
						goto RF;
					}
					goto RR;
					break;
				}
		case '5':
				{
RC:					clean;
					Vprintstruct();	
					setxy(59,21);
					printf("�����������޸ĵ�ѧ����ѧ��:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsinglehigh(num);
					else
					{
						printf("\t\t\t\t\t\t\t\tδ�ҵ���ѧ������˶���Ϣ!\n");
						Sleep(1000);
						goto RC;
					}	
					goto RR;
					break;
				}
		case '6':
				{
RG:					clean;
					Vprintstruct();	
					setxy(59,21);
					printf("�����������޸ĵ�ѧ����ѧ��:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsinglelogic(num);
					else
					{
						printf("\t\t\t\t\t\t\t\tδ���ҵ���ѧ������˶�������Ϣ!\n");
						Sleep(1500);
						goto RG;
					}
					goto RR;
					break;
				}
		case '7':
				{
RH:					clean;
					Vprintstruct();	
					setxy(59,21);
					printf("�����������޸ĵ�ѧ����ѧ��:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsingledisperse(num);
					else
					{
						printf("\t\t\t\t\t\t\t\tδ���ҵ���ѧ������˶�������Ϣ!\n");
						Sleep(1500);
						goto RH;
					}
					goto RR;
					break;
				}
		case '8':Vadministratormenu();break;
		case '9':Vstudentmenu();break;
		case '#':Vmodificationmenu();break;
		case '*':
				{
					if(Ireturnmenu())
						Vmainmenu();
					else
						goto RR;
					break;
				}
		case '0':Vexits();goto RR;break;
		default:setxy(68,32);printf("û�����ѡ��Ŷ!\n");Sleep(500);clean;goto RR;break;
	} 
}

void Vmodificationsinglename(char *num)//�޸����� 
{
	Stu* stu = students->next;//��ǰ�ڵ�
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t��ѧ����ǰ����Ϊ:%s\n",stu->name);
	printf("\t\t\t\t\t\t\t\t�����޸ĺ�����:");
	scanf("%s",stu->name);
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t�޸ĳɹ�!");
	Sleep(1000);
}

void Vmodificationsinglesex(char *num)//�޸��Ա� 
{
	Stu* stu = students->next;//��ǰ�ڵ�
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t��ѧ����ǰ�Ա�Ϊ:%s\n",stu->sex);
	printf("\t\t\t\t\t\t\t\t�����޸ĺ��Ա�Ϊ:");
	scanf("%s",stu->sex);
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t�޸ĳɹ�!");
	Sleep(1000);
}

void Vmodificationsinglebirth(char *num)  //�޸�����
{
	int a,b,c;
	Stu* stu = students->next;  //��ǰ�ڵ�
	while (strcmp(stu->num,num))  //�ҵ�Ҫ�޸ĵ�λ�� 
        stu = stu->next;
RR: clean;
	Vprintstruct();  //�����ǰ�ṹ����Ϣ 
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t��ѧ����ǰ����Ϊ:%d.%d.%d\n",stu->birth[0],stu->birth[1],stu->birth[2]);
	printf("\t\t\t\t\t\t\t\t�����޸ĺ�����(������֮����.���):");
	scanf("%d.%d.%d",&a,&b,&c);
	if(datelegal(a,b,c))  //�˶�������Ϣ�Ƿ�Ϸ� 
	{
		printf("\t\t\t\t\t\t\t\t��������ղ��Ϸ�����˶���Ϣ��\n");
		Sleep(1000);
		goto RR;
	}
	stu->birth[0]=a;
	stu->birth[1]=b;
	stu->birth[2]=c;
	VreWrite();  //���޸ĺ�Ľṹ������д���ļ� 
	printf("\t\t\t\t\t\t\t\t\t�޸ĳɹ�!");
	Sleep(1000);
}

void Vmodificationsingledep(char *num)//�޸�ѧԺ 
{
	Stu* stu = students->next;//��ǰ�ڵ�
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t��ѧ����ǰѧԺΪ:%s\n",stu->dep);
	printf("\t\t\t\t\t\t\t\t�����޸ĺ�ѧԺ:");
	scanf("%s",stu->dep);
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t�޸ĳɹ�!");
	Sleep(1000);
}

void Vmodificationsinglehigh(char *num)//�޸ĸ����ɼ� 
{
	Stu* stu = students->next;//��ǰ�ڵ�
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t��ѧ����ǰ�����ɼ�Ϊ:%.2f\n",stu->score1);
	printf("\t\t\t\t\t\t\t\t�����޸ĺ�ɼ�:");
	scanf("%f",&(stu->score1));
	stu->score4=stu->score1+stu->score2+stu->score3;
	stu->score5=stu->score4/3;
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t�޸ĳɹ�!");
	Sleep(1000);
}

void Vmodificationsinglelogic(char *num)//�޸������߼�
{
	Stu* stu = students->next;//��ǰ�ڵ�
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t��ѧ����ǰ�����߼��ɼ�Ϊ:%.2f\n",stu->score2);
	printf("\t\t\t\t\t\t\t\t�����޸ĺ�ɼ�:");
	scanf("%f",&(stu->score2));
	stu->score4=stu->score1+stu->score2+stu->score3;
	stu->score5=stu->score4/3;
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t�޸ĳɹ�!");
	Sleep(1000);
} 

void Vmodificationsingledisperse(char *num)//�޸���ɢ�ɼ� 
{
	Stu* stu = students->next;//��ǰ�ڵ�
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t��ѧ����ǰ��ɢ�ɼ��ɼ�Ϊ:%.2f\n",stu->score3);
	printf("\t\t\t\t\t\t\t\t�����޸ĺ�ɼ�:");
	scanf("%f",&(stu->score3));
	stu->score4=stu->score1+stu->score2+stu->score3;
	stu->score5=stu->score4/3;
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t�޸ĳɹ�!");
	Sleep(1000);
} 

void Vmodificationall()//�޸�ѧ��������Ϣ 
{
	char num[20],num1[20];	
RB:	clean;
	Vprintstruct();	
	setxy(59,20);	
	printf("�����������޸ĵ�ѧ����ѧ��:");
	scanf("%s",num);
	if(!Icherknum(num))
	{
		printf("δ���ҵ���ѧ������˶���Ϣ!");
		Sleep(1500);
		goto RB;
	}
RR:	clean;
	Vprintstruct();
	if(Icherknum(num))
	{
		Stu* stu = students->next;//��ǰ�ڵ�
		while (strcmp(stu->num,num))
        	stu = stu->next;
        printf("\n\n\n\t\t\tѧ��\t\t  ����\t\t�Ա�\t����\t\tѧԺ\t\t�ߵ���ѧ\t�����߼�\t��ɢ��ѧ\n");
		printf("\t\t\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n",stu->num,stu->name,stu->sex,stu->birth[0],stu->birth[1],stu->birth[2],stu->dep,stu->score1,stu->score2,stu->score3);
		printf("\n\t\t\t\t\t\t\t\t�����޸ĺ���Ϣ:\n");
		printf("\t\t\t\t\t\t\t\t\tѧ��:");
		scanf("%s",num1);
		if(!Icherknum(num1)||strcmp(stu->num,num1)==0)
			strcpy(stu->num,num1);
		else
		{
			printf("\t\t\t\t\t\t\t\t\t��ѧ���Ѵ��ڣ���˶���Ϣ��\n");
			Sleep(1500);
			goto RR; 
		}	
		printf("\t\t\t\t\t\t\t\t\t����:");
		scanf("%s",stu->name);
		printf("\t\t\t\t\t\t\t\t\t�Ա�(��/Ů):");
		scanf("%s",stu->sex);
		printf("\t\t\t\t\t\t\t\t\t����(������֮����.���):");
		scanf("%d.%d.%d",&(stu->birth[0]),&(stu->birth[1]),&(stu->birth[2]));
		if(datelegal(stu->birth[0],stu->birth[1],stu->birth[2]))
		{
			printf("\t\t\t\t\t\t\t\t��������ղ��Ϸ�����˶���Ϣ��");
			Sleep(1000);
			goto RR;
		}
		printf("\t\t\t\t\t\t\t\t\tѧԺ:");
		scanf("%s",stu->dep);
		printf("\t\t\t\t\t\t\t\t\t�����ɼ�:");
		scanf("%f",&(stu->score1));
		printf("\t\t\t\t\t\t\t\t\t�����߼��ɼ�:");
		scanf("%f",&(stu->score2));
		printf("\t\t\t\t\t\t\t\t\t��ɢ�ɼ�:");
		scanf("%f",&(stu->score3));
		stu->score4=stu->score1+stu->score2+stu->score3;
		stu->score5=stu->score4/3;
		VreWrite();
		printf("\t\t\t\t\t\t\t\t\t�޸ĳɹ�!");
		Sleep(1000);
	}
}

void Vcleanall()//������� 
{
	FILE* file;
	file=fopen("stu.txt","w");
	fclose(file);
	Vfiletostruct();
} 

void Vdeletemenu()//ɾ���˵� 
{
	char a[2],num[20],name[20];
RR:	clean;
	Vprintstruct();
	setxy(67,16);
	printf("�� ѡ ��:");
	setxy(71,18);
	printf("[1] ��ѧ��ɾ��");
	setxy(71,19);
	printf("[2] ������ɾ��"); 
	setxy(71,20);
	printf("[#] ������һ��");
	setxy(71,21);
	printf("[*] �������˵�");
	setxy(71,22);
	printf("[0] �˳�����");
	setxy(71,23);
	scanf("%s",a);
	switch(a[0])
	{
		case '1':setxy(63,24);printf("��������ɾ����ѧ����ѧ��:");scanf("%s",num);Vdelete(num);goto RR;break;
		case '2':setxy(63,24);printf("��������ɾ����ѧ��������:");scanf("%s",name);Vdeletename(name);goto RR;break;
		case '#':Vadministratormenu();break;
		case '*':
				{
					if(Ireturnmenu())
						Vmainmenu();
					else
						goto RR;
					break;
				}
		case '0':Vexits();goto RR;break;
		default:setxy(68,25);printf("û�����ѡ��Ŷ!\n");Sleep(500);clean;goto RR;break;
	} 
}



void Vfiletostruct()//���ļ�����Ϣ�������� 
{ 
    FILE* file;
	Stu* s;
    students = (Stu*)malloc(sizeof(Stu));//�������ͷ�ڵ�����ڴ�
    students->next = NULL;//ָ����Ϊ��
	s = students;//��ǰ���
    file = fopen("stu.txt", "r");//����Ϣ�ļ�
    if (file == NULL)
    {
        printf("���ļ�ʧ��!");
        return;
    }
    
    while (1)
    {
        Stu* stu = (Stu*)malloc(sizeof(Stu));
        //���ı�����ѧ����Ϣ�����stu��
        if (fscanf(file, "%s %s %s %d.%d.%d %s %f %f %f %f %f",stu->num ,stu->name,stu->sex,&(stu->birth[0]),&(stu->birth[1]),&(stu->birth[2]),stu->dep,&(stu->score1),&(stu->score2),&(stu->score3),&(stu->score4),&(stu->score5)) == EOF)
        {
            //�������ΪEOF��Ҳ��˵Ϊ����Ϊ�գ���ô�ո��½���stu�Ͳ�Ҫ�ˣ��ͷŷ�����ڴ�
            free(stu);
            break;
        }   
        stu->next = NULL;

        s->next = stu;//����ǰ�ڵ���½��Ľڵ���������
        s = stu;//������ǰ�ڵ�Ϊ�½ڵ�
    }
    fclose(file);
}

void Vprintstruct()//����Ϣ�������Ļ 
{
	int i=1;
    Stu* stu = students->next;
    if(stu==NULL)
    	printf("\n\n\t\t\t\t\t\t\t\t\t*�������Ϣ*");
    else
	{
		printf("���\tѧ��\t\t  ����\t\t�Ա�\t����\t\tѧԺ\t\t�ߵ���ѧ\t�����߼�\t��ɢ��ѧ\t�ܳɼ�\t\tƽ����\n");
    	while (stu!=NULL)
    	{
        	printf("%d\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",i, stu->num,stu->name,stu->sex,stu->birth[0],stu->birth[1],stu->birth[2],stu->dep,stu->score1,stu->score2,stu->score3,stu->score4,stu->score5);
        	stu = stu->next;//ָ����һ�ڵ�
        	i++;
    	}
    }
}

void Vaddscanf()//������Ϣ��Ļ����
{
	char num[20];//ѧ��
	char name[20];//ѧ������
	char sex[10];//�Ա� 
    int birth[3];//���� 
    char dep[16];//ϵ�� 
    float score1,score2,score3; 
    int n,i;
    Vprintstruct();
    setxy(64,20);
    printf("������Ҫ��ӵ�ѧ������:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
RR: 	clean;
    	Vprintstruct();
    	setxy(71,18);
    	printf("*��%d��ѧ��*",i); 
    	setxy(65,19);
    	printf("������ѧ��:");
		scanf("%s",num);
		if(Icherknum(num))
		{
			setxy(64,20);
			printf("��ѧ���Ѵ��ڣ���˶���Ϣ��");
			Sleep(1500);
			goto RR; 
		}
		setxy(65,20);
		printf("����������:");
		scanf("%s",name);
		setxy(65,21);
		printf("�������Ա�(��/Ů):");
		scanf("%s",sex);
		setxy(65,22);
		printf("������������:");
		scanf("%d",&birth[0]);
		setxy(65,23);
		printf("����������·�:");
		scanf("%d",&birth[1]);
		setxy(65,24);
		printf("�����������:");
		scanf("%d",&birth[2]);
		if(datelegal (birth[0],birth[1],birth[2]))
		{
			setxy(62,25); 
			printf("��������ղ��Ϸ�����˶���Ϣ��");
			Sleep(1500);
			goto RR; 
		}
		setxy(65,25);
		printf("������ѧԺ:");
		scanf("%s",dep);
		setxy(65,26);
		printf("����������ɼ�:");
		scanf("%f",&score1);
		setxy(65,27);
		printf("�����������߼�:");
		scanf("%f",&score2);
		setxy(65,28);
		printf("��������ɢ�ɼ�:");
		scanf("%f",&score3);
		Vadd(num,name,sex,birth,dep,score1,score2,score3);
    }

    
} 

int Icherknum(char *num)//����Ƿ�����ͬ��ѧ�� 
{
	Stu* p=students->next;
	while(p!=NULL)
	{
		if(strcmp(p->num,num)==0)
			return 1;
		p=p->next;
	}
	return 0;
}

int leap (int year)					//�ж����꺯��
{
	if((year%4==0 && year%100!=0)||year%400==0)			
		return 1;
	else
		return 0;
}

int datelegal (int year,int month, int day)		//�ж����������Ƿ�Ϸ����������Ϸ�����0�����Ϸ�����1
{													
	int leap (int year);
	switch(month)
	{	
		case 1:;
		case 3:;
		case 5:;
		case 7:;
		case 8:;
		case 10:;
		case 12:{	
					if(day>0&&day<=31) 
					{
						return 0;
						break;
					}
					else 
					{
						return 1;
						break;
					}		
				}
		case 4:;
		case 6:;
		case 9:;
		case 11:{	
					if(day<=30 && day>0) 
					{
						return 0;
						break;
					}
					else 
					{
						return 1;
						break;
					}		
				}	
		case 2:{	
					if(leap (year)==1)
					{
						if(day>0&&day<=29) 
						{
							return 0;
							break;
						}
						else 
						{
							return 1;
							break;
						}
					}

					else
					{
						if(day>0&&day<=28) 
						{
							return 0;
							break;
						}
						else 
						{
							return 1;
							break;
						}
					}
					
			   }
		default:{return 1;break;}
	}
}

void Vadd(char* num, char* name, char* sex,int *birth,char *dep,float score1,float score2,float score3)  //������Ϣ 
{
    Stu* news = (Stu*)malloc(sizeof(Stu));  //�½�һ���½ڵ�
	Stu* p = students;
    news->next = NULL;
    //���½ڵ㸳ֵ
    strcpy(news->num, num);
    strcpy(news->name, name);
    strcpy(news->sex, sex);
    news->birth[0]=birth[0];
    news->birth[1]=birth[1];
    news->birth[2]=birth[2];
    strcpy(news->dep, dep);
    news->score1 = score1;
    news->score2 = score2;
    news->score3 =score3;
    news->score4 =score3+score2+score1;
    news->score5 =(score3+score2+score1)/3;
    
    while (p->next!=NULL)  //����p�����һ���ڵ�
        p = p->next;
    p->next = news;  //p�����½ڵ㣬��������Ϣ
    Vstructtofile(news);
    printf("\n\t\t\t\t\t\t\t\t\t���ӳɹ���\n");
	Sleep(1000); 
}

void Vdelete(char* num)//ɾ����Ϣ(ѧ��)
{
	char a[1];
    Stu* stu = students->next;//��ǰ�ڵ�
    Stu* p = students;
    int flag = 0;//�Ƿ��ҵ�ѧ��
    while (stu != NULL)
    {
        if (strcmp(stu->num, num) == 0)//�ж�id�Ƿ���ͬ
        {
            flag = 1;
            break;
        }
        p = p->next;
        stu = stu->next;
    }
    if (flag)
    {
		setxy(65,26);
        printf("ȷ��ɾ����(ȷ������y)");
        scanf("%s",a);
        if(a[0]=='y'||a[0]=='Y')
        {
			p->next = stu->next;
            free(stu);
            VreWrite();//��д���ļ�
			printf("\t\t\t\t\t\t\t\t\tɾ���ɹ�!\n");
			Sleep(1000);
		}
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t   û���ҵ���ѧ������˶���Ϣ!\n");
        Sleep(1000);
    }
}

void Vdeletename(char * name)//ɾ����Ϣ(����)
{
	Stu* stu = students->next;//��ǰ�ڵ�
    Stu* p = students;
    int flag = 0;//�Ƿ��ҵ�ѧ��
	char a[1];
    while (stu != NULL)
    {
        if (strcmp(stu->name, name) == 0)//�ж�id�Ƿ���ͬ
        {
            flag = 1;
            break;
        }
        p = p->next;
        stu = stu->next;
    }
    if (flag)
    {
		setxy(65,26);
        printf("ȷ��ɾ����(ȷ������y)");
        scanf("%s",a);
       	if(a[0]=='y'||a[0]=='Y')
       	{
            p->next = stu->next;
            free(stu);
            VreWrite();//��д���ļ�
			printf("\t\t\t\t\t\t\t\t\tɾ���ɹ�!\n");
			Sleep(1000);
		}
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t\tû���ҵ���ѧ������˶���Ϣ!\n");
        Sleep(1000);
    }
}

void VreWrite()//��д���ļ�
{
    Stu* stu = students->next;
    FILE* file = fopen("stu.txt", "w");//����ļ�
    fclose(file);
    if (stu == NULL)//�������ǰû��ѧ����ֱ�ӷ���
        return;

    while (stu != NULL)
    {   
        Vstructtofile(stu);
        stu = stu->next;
    }
}

void Vstructtofile(Stu* stu)  //���ṹ��������д���ļ� 
{
    FILE* file;
    file=fopen("stu.txt","a");
    if (file == NULL)  //�ж��ļ��Ƿ�ɹ��� 
    {
        printf("�ļ�д�벻�ɹ�!");
        return;
    }
    fprintf(file, "%s %s %s %d.%d.%d %s %.2f %.2f %.2f %.2f %.2f\n", stu->num,stu->name,stu->sex,stu->birth[0],stu->birth[1],stu->birth[2],stu->dep,stu->score1,stu->score2,stu->score3,stu->score4,stu->score5);
    fclose(file);
}



int main()
{
	char title1[]="�� ӭ �� �� ѧ �� �� Ϣ �� �� ϵ ͳ";
	char title2[]="�� �� : κ �� ��";
	int i=0;
	system("color 1F");
	system("mode con cols=155 lines=48");
	Vfiletostruct();
	Sleep(500);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       *******************************************************************\n");
	printf("\t\t\t\t\t       ***********                                             ***********\n");
	printf("\t\t\t\t\t       ***********                                             ***********\n");
	printf("\t\t\t\t\t       ***********                                             ***********\n");
	printf("\t\t\t\t\t       ***********                                             ***********\n");
	printf("\t\t\t\t\t       ***********                                             ***********\n");
	printf("\t\t\t\t\t       ***********                                             ***********\n");
	printf("\t\t\t\t\t       ***********                                             ***********\n");
	printf("\t\t\t\t\t       ***********                                             ***********\n");
	printf("\t\t\t\t\t       ***********                                             ***********\n");
	printf("\t\t\t\t\t       *******************************************************************\n\n\n");
	Sleep(500);
	setxy(63,17);
	while(title1[i]!=0)
	{
		printf("%c",title1[i]);
		i++;
		Sleep(50);//����
	}
	i=0;
	setxy(72,19);
	while(title2[i]!=0)
	{
		printf("%c",title2[i]);
		i++;
		Sleep(50);//����
	}
	Sleep(1700); 
	Vmainmenu();

	return 0;
}
