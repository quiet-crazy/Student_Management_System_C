#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

#define clean system("cls");//清屏
#define stop system("pause");//暂停

struct administrator//管理员信息
{
	char name[20];//用户名
	char password[8];//密码
};

typedef struct student//学生信息
{
    char num[20];//学号
	char name[20];//学生姓名
	char sex[10];//性别 
    int birth[3];//生日 
    char dep[16];//系别 
    float score1,score2,score3,score4,score5;//学生成绩 
    struct student* next;//下一个学生的指针
}Stu;

Stu* students;//学生链表

void setxy(int x, int y);  //设置输入，输出的位置，也就是当前光标位置 
void Vexits();//退出程序
int Ireturnmenu();//返回主菜单 
void print();//输出友好界面 
void Vmainmenu();//主菜单
void Vhelp();//版本信息 
void Vstudentmenu();//学生主菜单
void Vtotallist();//学生 总榜菜单
void Vsorttotal();//总分排序
void Vsinglelist();//学生 总榜 单科排名菜单
void Vsorthigh();//高数排序 
void Vsortlogic();//数字逻辑排序 
void Vsortdisperse();//离散排序 
void Vsingleinfor();//查询个人信息
void Vtallest();//最高分查询 
void Voverallsituationmenu();//总体情况菜单
void Voverallsituationtotal();//总人数，总平均分，平均分以上人数，以下人数，各自占比 
void Voverallsituationhigh();//高数平均分，高于平均分人数，低于平均分人数，各自占比，优秀，良好，及格，不及格
void Voverallsituationlogic();//数字逻辑 总体情况  
void Voverallsituationdisperse();//离散数学 总体情况  
void Vadministratorregister();//管理员登录界面 
void Vencrypt(char *pwd);//密码加密
int IcherkUserValid(struct administrator *psu);//检查管理员登录信息是否正确
void Vadministratormenu();//管理员菜单
void Vmodificationmenu();//修改菜单 
void Vmodificationsinglemenu();//修改单个信息菜单 
void Vmodificationsinglename(char *num);//修改姓名
void Vmodificationsinglesex(char *num);//修改性别
void Vmodificationsinglebirth(char *num);//修改生日
void Vmodificationsingledep(char *num);//修改学院
void Vmodificationsinglehigh(char *num);//修改高数成绩
void Vmodificationsinglelogic(char *num);//修改数字逻辑
void Vmodificationsingledisperse(char *num);//修改离散成绩
void Vmodificationall();//修改学生所有信息
void Vcleanall();//清空数据
void Vdeletemenu();//删除菜单
void Vfiletostruct();//将文件中信息读入链表
void Vprintstruct();//将信息输出到屏幕
void Vaddscanf();//增加信息屏幕接收
int Icherknum(char *num);//检查是否有相同的学号
void Vadd(char* num, char* name, char* sex,int *birth,char *dep,float score1,float score2,float score3);//增加信息
void Vdelete(char* num);//删除信息(学号)
void Vdeletename(char * name);//删除信息(姓名)
void VreWrite();//重写进文件
void Vstructtofile(Stu* stu);//将结构体中内容写入文件
int leap (int year);//判断闰年
int datelegal (int year,int month, int day)	;//判断输入日期是否合法函数

void setxy(int x, int y)  //设置输入，输出的位置，也就是当前光标位置
{
   COORD coord = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Vexits()//退出程序
{
	char n[1];
	clean;
	setxy(55,14);
	printf("***** 确定要退出吗?(按y退出，按其他键继续操作) *****");
	setxy(79,15);
	scanf("%s",n);
	if(n[0]=='y'||n[0]=='Y')
	{
		setxy(73,16);
		printf("感谢您的使用!\n");
		Sleep(500);
		setxy(77,17);
		printf("再见!\n");
		Sleep(400);
		exit(0);
	}
}

int Ireturnmenu()//返回主菜单 
{
	char n[1];
	clean;
	setxy(58,14);
	printf("确定要返回主菜单吗?(按y退出，按其他键继续操作)");
	setxy(80,15);
	scanf("%s",n);
	if(n[0]=='y'||n[0]=='Y')
	{
		setxy(75,16);
		printf("即将返回主菜单...\n");
		Sleep(500);
		return 1;
	}
	return 0;
}

void print()//输出友好界面 
{
	setxy(57,8);
	printf("+-----------------------------------------+");
	setxy(57,9);
	printf("|* * * * * * * * * * * * * * * * * * * * *|");
	setxy(57,10);
	printf("|*                                       *|");
	setxy(57,11);
	printf("|*     欢 迎 使 用 学 生 管 理 系 统     *|");
	setxy(57,12);
	printf("|*                                       *|");
	setxy(57,13);
	printf("|* * * * * * * * * * * * * * * * * * * * *|");
	setxy(57,14);
	printf("+-----------------------------------------+");
}

void Vmainmenu()//主菜单
{
	int n;
RR:	clean;
	print();
	Sleep(500);
	setxy(67,16);
	printf("请 选 择 进 入 界 面:");
	setxy(70,18);
	printf("[1] 学 生");
	setxy(70,20);
	printf("[2] 管 理 员");
	setxy(70,22);
	printf("[3] 版 本 说 明");
	setxy(70,24);
	printf("[0] 退 出 程 序");
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
		printf("没有这个选项哦!\n");
		Sleep(1000);
		goto RR;
	}
}

void Vhelp()//版本信息 
{
	clean; 
	print();
	setxy(67,17);
	printf("****** 版本说明 ******");
	setxy(48,19);
	printf("1、使用该软件前，请确认在该软件的同目录下存在'stu.txt'和'register.txt'文件。") ;
	setxy(48,20);
	printf("2、可通过'设置管理员信息'软件修改管理员信息。");
	setxy(48,21);
	printf("3、本软件在VC++和Dev C++上可正常运行，其他编译环境暂无测试。"); 
	setxy(48,22);
	printf("4、欢迎对本软件提出改进意见。");
	setxy(48,24);
	printf("***   制作人:辽宁师范大学 计算机与信息技术学院 师范二班 魏静文   ***");
	setxy(48,26);
	stop;
}

void Vstudentmenu()//学生主菜单
{
	char n[2];
RR:	clean;
	print();
	setxy(63,16);
	printf("请 输 入 您 要 查 询 的 信 息:");
	setxy(71,18);
	printf("[1] 总榜");
	setxy(71,19);
	printf("[2] 个人信息"); 
	setxy(71,20);
	printf("[3] 最高分");
	setxy(71,21);
	printf("[4] 总体成绩情况"); 
	setxy(71,22);
	printf("[#] 返回上一级");
	setxy(71,23);
	printf("[0] 退出程序");
	setxy(71,24);
	scanf("%s",n);

	if(n[1]!='\0')
	{
		setxy(70,26);
		printf("没有这个选项哦!\n");
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
		default:{setxy(70,26);printf("没有这个选项哦!\n");Sleep(500);clean;goto RR;};break;
	}
}

void Vtotallist()//学生 总榜菜单
{
	char n[2];
RR:	clean;
	print();
	setxy(58,16);
	printf("请 输 入 您 想 查 询 的 总 榜 顺 序 类 型:");
	setxy(70,18);
	printf("[1] 默认顺序");//完成 
	setxy(70,19);
	printf("[2] 总分排名顺序");
	setxy(70,20);
	printf("[3] 单科排名顺序");
	setxy(70,21);
	printf("[#] 返回上一级");
	setxy(70,22);
	printf("[*] 返回主菜单");
	setxy(70,23);
	printf("[0] 退出程序");
	setxy(70,24);
	scanf("%s",n);
	if(n[1]!='\0')
	{
		setxy(69,26);
		printf("没有这个选项哦!\n");
		Sleep(500);
		clean;
		goto RR;
	}
	switch(n[0])
	{
		case '1':clean;printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ****学生成绩排榜****\n\n\n");Vprintstruct();stop;goto RR;break;
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
		default:{setxy(69,26);printf("没有这个选项哦!\n");setxy(69,26);Sleep(500);goto RR;};break;
	}
}

void Vsorttotal()//总分排序
{
	Stu * stu=students->next;
	Stu *p=students->next;
	float score[100]={0};
	int i,j,c=0,k=1;
	float temp;
	clean;
	if(stu==NULL)
	{
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t*无相关信息*");
		stop;
		Vtotallist();
	}		
	while(stu!=NULL)
    {
      score[c]=stu->score4;//将所有总成绩输入数组中
      c++;
      stu=stu->next;
    }
    for(i=0;i<c-1;i++)//对数组进行排序
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
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ****学生成绩排榜****\n\n\n");
	printf("序号\t学号\t\t  姓名\t\t性别\t生日\t\t学院\t\t高等数学\t数字逻辑\t离散数学\t总成绩\t\t平均分\n");
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

void Vsinglelist()//学生 总榜 单科排名菜单
{
	char n[2];
RR:	clean;
	print();
	setxy(64,16);
	printf("请 输 入 您 想 查 询 的 科 目:");
	setxy(70,18);
	printf("[1]高等数学");
	setxy(70,19);
	printf("[2]数字逻辑");
	setxy(70,20);
	printf("[3]离散数学");
	setxy(70,21);
	printf("[4]返回学生主菜单");
	setxy(70,22);
	printf("[#]返回上一级");
	setxy(70,23);
	printf("[*]返回主菜单");
	setxy(70,24);
	printf("[0]退出程序");
	setxy(70,25);
	scanf("%s",n);
	if(n[1]!='\0')
	{
		setxy(71,27);
		printf("没有这个选项哦!\n");
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
		default:{setxy(71,27);printf("没有这个选项哦!\n");Sleep(500);goto RR;};break;
	}
}

void Vsorthigh()//高数排序 
{
	Stu * stu=students->next;
	Stu *p=students->next;
	float score[100]={0};
	int i,j,c=0,k=1;
	float temp;
	clean;
	if(stu==NULL)
	{
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t*无相关信息*");
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
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ****学生成绩排榜****\n\n\n");
	printf("序号\t学号\t\t  姓名\t\t性别\t生日\t\t学院\t\t高等数学\t数字逻辑\t离散数学\t总成绩\t\t平均分\n");
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

void Vsortlogic()//数字逻辑排序 
{
	Stu * stu=students->next;
	Stu *p=students->next;
	float score[100]={0};
	int i,j,c=0,k=1;
	float temp;
	clean;
	if(stu==NULL)
	{
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t*无相关信息*");
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
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ****学生成绩排榜****\n\n\n");
	printf("序号\t学号\t\t  姓名\t\t性别\t生日\t\t学院\t\t高等数学\t数字逻辑\t离散数学\t总成绩\t\t平均分\n");
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

void Vsortdisperse()//离散排序 
{
	Stu * stu=students->next;
	Stu *p=students->next;
	float score[100]={0};
	int i,j,c=0,k=1;
	float temp;
	clean;
	if(stu==NULL)
	{
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t*无相关信息*");
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
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ****学生成绩排榜****\n\n\n");
	printf("序号\t学号\t\t  姓名\t\t性别\t生日\t\t学院\t\t高等数学\t数字逻辑\t离散数学\t总成绩\t\t平均分\n");
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

void Vsingleinfor()//查询个人信息
{
	char num[20];
	Stu * stu=students->next;
RR:	clean;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t请输入您想要查询信息的学号:");
	scanf("%s",num);
	if(!Icherknum(num))
	{
		printf("\t\t\t\t\t\t\t     未查找到该学生，请核对信息!");
		Sleep(600);
		goto RR;
	}
	while (strcmp(stu->num,num))
        stu = stu->next;
    printf("\n\t学号\t\t  姓名\t\t性别\t生日\t\t学院\t\t高等数学\t数字逻辑\t离散数学\t总成绩\t\t平均分\n");
    printf("\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n\n\n\t\t\t\t\t\t\t\t",stu->num,stu->name,stu->sex,stu->birth[0],stu->birth[1],stu->birth[2],stu->dep,stu->score1,stu->score2,stu->score3,stu->score4,stu->score5);
    stop;
	
} 

void Vtallest()//最高分查询
{
	Stu * stu=students->next;
	float a[4]={0};
	int i;
	clean;
	if(stu==NULL)      //检查链表是否为空 
    {
    	printf("\n\n\t\t\t\t\t\t\t\t\t*无相关信息*");
    	return;
    }
    else
    	while (stu!=NULL)    //查找最高分并将分数写进数组 
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
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    总分最高分:%.2f  \n\n",a[3]);
    i=1;
	while(stu!=NULL)    //查找到最高分的全部信息并输出 
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
	printf("\t\t\t\t\t\t\t\t\t  高等数学最高分:%.2f\n",a[0]);
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
	printf("\t\t\t\t\t\t\t\t\t  数字逻辑最高分:%.2f\n",a[1]);
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
	printf("\t\t\t\t\t\t\t\t\t  离散数学最高分:%.2f\n",a[2]);
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

void Voverallsituationmenu()//总体情况菜单 
{
	char a[2];
RR:	clean;
	print();
	setxy(64,16);
	printf("请 选 择:");
	setxy(68,18);
	printf("[1]总成绩总体情况");//完成 
	setxy(68,19);
	printf("[2]高等数学成绩总体情况");
	setxy(68,20);
	printf("[3]数字逻辑成绩总体情况");
	setxy(68,21);
	printf("[4]离散数学成绩总体情况");
	setxy(68,22);
	printf("[5]返回学生主菜单");
	setxy(68,23); 
	printf("[#]返回上一级");
	setxy(68,24);
	printf("[0]退出程序");
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
		default:setxy(71,27);printf("没有这个选项哦!\n");Sleep(500);clean;goto RR;break;
	}
} 

void Voverallsituationtotal()  //总人数，总平均分，平均分以上人数，以下人数，各自占比 
{
	Stu* stu=students->next;
	float total=0,ave=0;
	int i=0,j=0;
	float s=0; 
	clean;
	while(stu!=NULL)  //总分 
	{
		total+=stu->score4;
		stu=stu->next;
		i++;
	}
	ave=total/i;  //平均分 
	stu=students->next;
	while(stu!=NULL)  //高于平均分的人数 
	{
		if(stu->score4>=ave)
			j++;
		stu=stu->next;
	}
	s=(float)1.0*j/i*100;  //高于平均分的比例 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t       总人数:%d   总平均分:%.2f\n",i,ave);
	printf("\t\t\t\t\t\t\t     平均分以上人数:%d   占比:%.2f%%\n",j,s);
	printf("\t\t\t\t\t\t\t     平均分以下人数:%d   占比:%.2f%%\n",(i-j),(100-s));
	printf("\n\n\t\t\t\t\t\t\t          ");
	stop;
}

void Voverallsituationhigh()//高数平均分，高于平均分人数，低于平均分人数，各自占比，优秀，良好，及格，不及格 
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
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  高等数学平均分:%.2f\n",ave);
	printf("\t\t\t\t\t\t\t     平均分以上人数:%d   占比:%.2f%%\n",j,s);
	printf("\t\t\t\t\t\t\t     平均分以下人数:%d   占比:%.2f%%\n",(i-j),(100-s));
	printf("\t\t\t\t\t\t\t     优秀人数:%d         占比:%.2f%%\n",a,100.0*a/i);
	printf("\t\t\t\t\t\t\t     良好人数:%d         占比:%.2f%%\n",b,100.0*b/i);
	printf("\t\t\t\t\t\t\t     及格人数:%d         占比:%.2f%%\n",c,100.0*c/i);
	printf("\t\t\t\t\t\t\t     不及格人数:%d       占比:%.2f%%\n",d,100.0*d/i);
	printf("\n\n\t\t\t\t\t\t\t          ");
	stop;
}

void Voverallsituationlogic()//数字逻辑
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
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  数字逻辑平均分:%.2f\n",ave);
	printf("\t\t\t\t\t\t\t     平均分以上人数:%d   占比:%.2f%%\n",j,s);
	printf("\t\t\t\t\t\t\t     平均分以下人数:%d   占比:%.2f%%\n",(i-j),(100-s));
	printf("\t\t\t\t\t\t\t     优秀人数:%d         占比:%.2f%%\n",a,100.0*a/i);
	printf("\t\t\t\t\t\t\t     良好人数:%d         占比:%.2f%%\n",b,100.0*b/i);
	printf("\t\t\t\t\t\t\t     及格人数:%d         占比:%.2f%%\n",c,100.0*c/i);
	printf("\t\t\t\t\t\t\t     不及格人数:%d       占比:%.2f%%\n",d,100.0*d/i);
	printf("\n\n\t\t\t\t\t\t\t          ");
	stop;
}

void Voverallsituationdisperse()//离散数学 
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
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  离散数学平均分:%.2f\n",ave);
	printf("\t\t\t\t\t\t\t     平均分以上人数:%d   占比:%.2f%%\n",j,s);
	printf("\t\t\t\t\t\t\t     平均分以下人数:%d   占比:%.2f%%\n",(i-j),(100-s));
	printf("\t\t\t\t\t\t\t     优秀人数:%d         占比:%.2f%%\n",a,100.0*a/i);
	printf("\t\t\t\t\t\t\t     良好人数:%d         占比:%.2f%%\n",b,100.0*b/i);
	printf("\t\t\t\t\t\t\t     及格人数:%d         占比:%.2f%%\n",c,100.0*c/i);
	printf("\t\t\t\t\t\t\t     不及格人数:%d       占比:%.2f%%\n",d,100.0*d/i);
	printf("\n\n\t\t\t\t\t\t\t          ");
	stop;
}

void Vadministratorregister()//管理员登录界面 
/*管理员密码
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
		printf("请 输 入 登 录 信 息 ( 共 有 3 次 机 会 ，剩 余 %d 次)\n",3-i);
		setxy(70,18);
		printf("用 户 名:");
		scanf("%s",ad.name);
		setxy(70,19);
		printf("密    码:");
		for(j=0;j<100;j++) //将密码遮盖成* 
		{
			ad.password[j]=getch();
			if(ad.password[j]=='\r')
				break;
			printf("*");
		}
		ad.password[j]='\0';
		printf("\n");
		if(IcherkUserValid(&ad)==1)  //检查管理员信息是否正确 
		{
			setxy(70,21);
			printf("登 录 成 功!\n");
			Sleep(1000);
			Vadministratormenu();
		}
		else
		{
			setxy(67,21);
			printf("密码错误或用户不存在!\n"); 
			Sleep(1000);
		}
	}
	setxy(65,23);
	printf("你 的 机 会 用 完 了 哦!");
	Sleep(700);
	setxy(64,25);
	printf("即 将 进 入 学 生 界 面...\n\n");
	Sleep(1500);
	stop;
	Vstudentmenu();
}

void Vencrypt(char *pwd)  //密码加密 
{
	int i,len=strlen(pwd);
	for(i=0;i<len;i++)
		pwd[i]=pwd[i]^15;    //乘15次幂进行加密处理 
}

int IcherkUserValid(struct administrator *psu)  //检查管理员登录信息是否正确 
{
	FILE *fp;
	char usr[30],usr1[30],pwd[10];
	int check=0;
	strcpy(usr,psu->name);
	strcpy(pwd,psu->password);
	Vencrypt(pwd);      //密码加密处理 
	strcat(usr," ");
	strcat(usr,pwd);
	strcat(usr,"\n");
	if((fp=fopen("register.txt","r"))==NULL)
	{
		printf("文件错误!\n");
		exit(0);
	}
	while(!feof(fp))
	{
		fgets(usr1,30,fp);
		if(strcmp(usr,usr1)==0)  //对比信息是否一致 
		{
			check=1;
			break;
		}		
	}
	fclose(fp);
	return check;
}
/*管理员*/
void Vadministratormenu()//管理员菜单
{
	char n[2],a[1]; 
RR:	clean;
	print();//输出友好界面
	
RB:	setxy(63,16);
	printf("请 选 择 您 想 进 行 的 操 作:");
	setxy(68,18);
	printf("[1] 浏览学生信息(自然顺序)");  
	setxy(68,19);
	printf("[2] 增加学生信息"); 
	setxy(68,20);
	printf("[3] 删除学生信息");
	setxy(68,21);
	printf("[4] 修改学生信息");
	setxy(68,22);
	printf("[5] 清除所有学生信息"); 
	setxy(68,23);
	printf("[6] 进入学生界面");
	setxy(68,24);
	printf("[*] 返回主菜单");
	setxy(68,25);
	printf("[0] 退出程序");
	setxy(68,26);
	scanf("%s",n);
	if(n[1]!='\0')
	{
		setxy(67,28);
		printf("没有这个选项哦!\n");
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
					printf("\t\t\t\t\t\t\t\t确认清空所有信息吗？(确定输入y)");
					scanf("%s",a);
					if(a[0]=='y'||a[0]=='Y')
					{
						Vcleanall();
						printf("\t\t\t\t\t\t\t\t\t  清除成功!\n");
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
		default:setxy(67,28);printf("没有这个选项哦!\n");Sleep(500);goto RR;break;
	}
} 

void Vmodificationmenu()//修改菜单 
{
	char a[2];
RR:	clean;
	Vprintstruct();
	setxy(67,16);
	printf("请 选 择:");
	setxy(71,18);
	printf("[1] 修改学生单个信息");
	setxy(71,19);
	printf("[2] 修改学生全部信息");
	setxy(71,20);
	printf("[3] 进入学生界面");
	setxy(71,21);
	printf("[#] 返回上一级");
	setxy(71,22);
	printf("[*] 返回主菜单");
	setxy(71,23);
	printf("[0] 退出程序");
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
		default:setxy(68,26);printf("没有这个选项哦!\n");Sleep(500);clean;goto RR;break;
	} 
}

void Vmodificationsinglemenu()//修改单个信息菜单
{
	char a[2],num[20];
RR:	clean;
	Vprintstruct();
	setxy(64,16);
	printf("请 选 择:");
	setxy(69,18);
	printf("[1] 修改学生姓名信息");
	setxy(69,19);
	printf("[2] 修改学生性别信息"); 
	setxy(69,20);
	printf("[3] 修改学生生日信息");
	setxy(69,21);
	printf("[4] 修改学生学院信息");
	setxy(69,22);
	printf("[5] 修改学生高等数学成绩信息");
	setxy(69,23);
	printf("[6] 修改学生数字逻辑成绩信息");
	setxy(69,24);
	printf("[7] 修改学生离散数学成绩信息");
	setxy(69,25);
	printf("[8] 返回管理员主菜单");
	setxy(69,26);
	printf("[9] 进入学生界面");
	setxy(69,27);
	printf("[#] 返回上一级");
	setxy(69,28);
	printf("[*] 返回主菜单");
	setxy(69,29);
	printf("[0] 退出程序");
	setxy(69,30);
	scanf("%s",a);
	switch(a[0])
	{
		case '1':
				{
RB:					clean;
					Vprintstruct();	
					setxy(59,21);	
					printf("请输入您想修改的学生的学号:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsinglename(num);
					else
					{
						printf("\t\t\t\t\t\t\t\t未查找到该学生，请核对您的信息!\n");
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
					printf("请输入您想修改的学生的学号:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsinglesex(num);
					else
					{
						printf("\t\t\t\t\t\t\t\t未查找到该学生，请核对您的信息!\n");
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
					printf("请输入您想修改的学生的学号:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsinglebirth(num);
					else
					{
						printf("\t\t\t\t\t\t\t\t未查找到该学生，请核对您的信息!\n");
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
					printf("请输入您想修改的学生的学号:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsingledep(num);
					else
					{
						printf("\t\t\t\t\t\t\t\t未查找到该学生，请核对您的信息!\n");
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
					printf("请输入您想修改的学生的学号:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsinglehigh(num);
					else
					{
						printf("\t\t\t\t\t\t\t\t未找到该学生，请核对信息!\n");
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
					printf("请输入您想修改的学生的学号:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsinglelogic(num);
					else
					{
						printf("\t\t\t\t\t\t\t\t未查找到该学生，请核对您的信息!\n");
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
					printf("请输入您想修改的学生的学号:");
					scanf("%s",num);
					if(Icherknum(num))
						Vmodificationsingledisperse(num);
					else
					{
						printf("\t\t\t\t\t\t\t\t未查找到该学生，请核对您的信息!\n");
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
		default:setxy(68,32);printf("没有这个选项哦!\n");Sleep(500);clean;goto RR;break;
	} 
}

void Vmodificationsinglename(char *num)//修改姓名 
{
	Stu* stu = students->next;//当前节点
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t该学生当前姓名为:%s\n",stu->name);
	printf("\t\t\t\t\t\t\t\t输入修改后姓名:");
	scanf("%s",stu->name);
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t修改成功!");
	Sleep(1000);
}

void Vmodificationsinglesex(char *num)//修改性别 
{
	Stu* stu = students->next;//当前节点
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t该学生当前性别为:%s\n",stu->sex);
	printf("\t\t\t\t\t\t\t\t输入修改后性别为:");
	scanf("%s",stu->sex);
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t修改成功!");
	Sleep(1000);
}

void Vmodificationsinglebirth(char *num)  //修改生日
{
	int a,b,c;
	Stu* stu = students->next;  //当前节点
	while (strcmp(stu->num,num))  //找到要修改的位置 
        stu = stu->next;
RR: clean;
	Vprintstruct();  //输出当前结构体信息 
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t该学生当前生日为:%d.%d.%d\n",stu->birth[0],stu->birth[1],stu->birth[2]);
	printf("\t\t\t\t\t\t\t\t输入修改后生日(年月日之间用.间隔):");
	scanf("%d.%d.%d",&a,&b,&c);
	if(datelegal(a,b,c))  //核对生日信息是否合法 
	{
		printf("\t\t\t\t\t\t\t\t输入的生日不合法，请核对信息！\n");
		Sleep(1000);
		goto RR;
	}
	stu->birth[0]=a;
	stu->birth[1]=b;
	stu->birth[2]=c;
	VreWrite();  //将修改后的结构体重新写入文件 
	printf("\t\t\t\t\t\t\t\t\t修改成功!");
	Sleep(1000);
}

void Vmodificationsingledep(char *num)//修改学院 
{
	Stu* stu = students->next;//当前节点
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t该学生当前学院为:%s\n",stu->dep);
	printf("\t\t\t\t\t\t\t\t输入修改后学院:");
	scanf("%s",stu->dep);
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t修改成功!");
	Sleep(1000);
}

void Vmodificationsinglehigh(char *num)//修改高数成绩 
{
	Stu* stu = students->next;//当前节点
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t该学生当前高数成绩为:%.2f\n",stu->score1);
	printf("\t\t\t\t\t\t\t\t输入修改后成绩:");
	scanf("%f",&(stu->score1));
	stu->score4=stu->score1+stu->score2+stu->score3;
	stu->score5=stu->score4/3;
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t修改成功!");
	Sleep(1000);
}

void Vmodificationsinglelogic(char *num)//修改数字逻辑
{
	Stu* stu = students->next;//当前节点
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t该学生当前数字逻辑成绩为:%.2f\n",stu->score2);
	printf("\t\t\t\t\t\t\t\t输入修改后成绩:");
	scanf("%f",&(stu->score2));
	stu->score4=stu->score1+stu->score2+stu->score3;
	stu->score5=stu->score4/3;
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t修改成功!");
	Sleep(1000);
} 

void Vmodificationsingledisperse(char *num)//修改离散成绩 
{
	Stu* stu = students->next;//当前节点
	while (strcmp(stu->num,num))
        stu = stu->next;
	printf("\t\t\t\t\t\t\t\t该学生当前离散成绩成绩为:%.2f\n",stu->score3);
	printf("\t\t\t\t\t\t\t\t输入修改后成绩:");
	scanf("%f",&(stu->score3));
	stu->score4=stu->score1+stu->score2+stu->score3;
	stu->score5=stu->score4/3;
	VreWrite();
	printf("\t\t\t\t\t\t\t\t\t修改成功!");
	Sleep(1000);
} 

void Vmodificationall()//修改学生所有信息 
{
	char num[20],num1[20];	
RB:	clean;
	Vprintstruct();	
	setxy(59,20);	
	printf("请输入您想修改的学生的学号:");
	scanf("%s",num);
	if(!Icherknum(num))
	{
		printf("未查找到该学生，请核对信息!");
		Sleep(1500);
		goto RB;
	}
RR:	clean;
	Vprintstruct();
	if(Icherknum(num))
	{
		Stu* stu = students->next;//当前节点
		while (strcmp(stu->num,num))
        	stu = stu->next;
        printf("\n\n\n\t\t\t学号\t\t  姓名\t\t性别\t生日\t\t学院\t\t高等数学\t数字逻辑\t离散数学\n");
		printf("\t\t\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n",stu->num,stu->name,stu->sex,stu->birth[0],stu->birth[1],stu->birth[2],stu->dep,stu->score1,stu->score2,stu->score3);
		printf("\n\t\t\t\t\t\t\t\t输入修改后信息:\n");
		printf("\t\t\t\t\t\t\t\t\t学号:");
		scanf("%s",num1);
		if(!Icherknum(num1)||strcmp(stu->num,num1)==0)
			strcpy(stu->num,num1);
		else
		{
			printf("\t\t\t\t\t\t\t\t\t此学号已存在，请核对信息！\n");
			Sleep(1500);
			goto RR; 
		}	
		printf("\t\t\t\t\t\t\t\t\t姓名:");
		scanf("%s",stu->name);
		printf("\t\t\t\t\t\t\t\t\t性别(男/女):");
		scanf("%s",stu->sex);
		printf("\t\t\t\t\t\t\t\t\t生日(年月日之间用.间隔):");
		scanf("%d.%d.%d",&(stu->birth[0]),&(stu->birth[1]),&(stu->birth[2]));
		if(datelegal(stu->birth[0],stu->birth[1],stu->birth[2]))
		{
			printf("\t\t\t\t\t\t\t\t输入的生日不合法，请核对信息！");
			Sleep(1000);
			goto RR;
		}
		printf("\t\t\t\t\t\t\t\t\t学院:");
		scanf("%s",stu->dep);
		printf("\t\t\t\t\t\t\t\t\t高数成绩:");
		scanf("%f",&(stu->score1));
		printf("\t\t\t\t\t\t\t\t\t数字逻辑成绩:");
		scanf("%f",&(stu->score2));
		printf("\t\t\t\t\t\t\t\t\t离散成绩:");
		scanf("%f",&(stu->score3));
		stu->score4=stu->score1+stu->score2+stu->score3;
		stu->score5=stu->score4/3;
		VreWrite();
		printf("\t\t\t\t\t\t\t\t\t修改成功!");
		Sleep(1000);
	}
}

void Vcleanall()//清空数据 
{
	FILE* file;
	file=fopen("stu.txt","w");
	fclose(file);
	Vfiletostruct();
} 

void Vdeletemenu()//删除菜单 
{
	char a[2],num[20],name[20];
RR:	clean;
	Vprintstruct();
	setxy(67,16);
	printf("请 选 择:");
	setxy(71,18);
	printf("[1] 按学号删除");
	setxy(71,19);
	printf("[2] 按姓名删除"); 
	setxy(71,20);
	printf("[#] 返回上一级");
	setxy(71,21);
	printf("[*] 返回主菜单");
	setxy(71,22);
	printf("[0] 退出程序");
	setxy(71,23);
	scanf("%s",a);
	switch(a[0])
	{
		case '1':setxy(63,24);printf("请输入想删除的学生的学号:");scanf("%s",num);Vdelete(num);goto RR;break;
		case '2':setxy(63,24);printf("请输入想删除的学生的姓名:");scanf("%s",name);Vdeletename(name);goto RR;break;
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
		default:setxy(68,25);printf("没有这个选项哦!\n");Sleep(500);clean;goto RR;break;
	} 
}



void Vfiletostruct()//将文件中信息读入链表 
{ 
    FILE* file;
	Stu* s;
    students = (Stu*)malloc(sizeof(Stu));//给链表的头节点分配内存
    students->next = NULL;//指向设为空
	s = students;//当前结点
    file = fopen("stu.txt", "r");//打开信息文件
    if (file == NULL)
    {
        printf("打开文件失败!");
        return;
    }
    
    while (1)
    {
        Stu* stu = (Stu*)malloc(sizeof(Stu));
        //从文本读入学生信息，存进stu中
        if (fscanf(file, "%s %s %s %d.%d.%d %s %f %f %f %f %f",stu->num ,stu->name,stu->sex,&(stu->birth[0]),&(stu->birth[1]),&(stu->birth[2]),stu->dep,&(stu->score1),&(stu->score2),&(stu->score3),&(stu->score4),&(stu->score5)) == EOF)
        {
            //如果读入为EOF，也就说为读入为空，那么刚刚新建的stu就不要了，释放分配的内存
            free(stu);
            break;
        }   
        stu->next = NULL;

        s->next = stu;//将当前节点和新建的节点链接起来
        s = stu;//调整当前节点为新节点
    }
    fclose(file);
}

void Vprintstruct()//将信息输出到屏幕 
{
	int i=1;
    Stu* stu = students->next;
    if(stu==NULL)
    	printf("\n\n\t\t\t\t\t\t\t\t\t*无相关信息*");
    else
	{
		printf("序号\t学号\t\t  姓名\t\t性别\t生日\t\t学院\t\t高等数学\t数字逻辑\t离散数学\t总成绩\t\t平均分\n");
    	while (stu!=NULL)
    	{
        	printf("%d\t%s\t  %s\t%s\t%d.%d.%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",i, stu->num,stu->name,stu->sex,stu->birth[0],stu->birth[1],stu->birth[2],stu->dep,stu->score1,stu->score2,stu->score3,stu->score4,stu->score5);
        	stu = stu->next;//指向下一节点
        	i++;
    	}
    }
}

void Vaddscanf()//增加信息屏幕接收
{
	char num[20];//学号
	char name[20];//学生姓名
	char sex[10];//性别 
    int birth[3];//生日 
    char dep[16];//系别 
    float score1,score2,score3; 
    int n,i;
    Vprintstruct();
    setxy(64,20);
    printf("请输入要添加的学生个数:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
RR: 	clean;
    	Vprintstruct();
    	setxy(71,18);
    	printf("*第%d个学生*",i); 
    	setxy(65,19);
    	printf("请输入学号:");
		scanf("%s",num);
		if(Icherknum(num))
		{
			setxy(64,20);
			printf("此学号已存在，请核对信息！");
			Sleep(1500);
			goto RR; 
		}
		setxy(65,20);
		printf("请输入姓名:");
		scanf("%s",name);
		setxy(65,21);
		printf("请输入性别(男/女):");
		scanf("%s",sex);
		setxy(65,22);
		printf("请输入出生年份:");
		scanf("%d",&birth[0]);
		setxy(65,23);
		printf("请输入出生月份:");
		scanf("%d",&birth[1]);
		setxy(65,24);
		printf("请输入出生日:");
		scanf("%d",&birth[2]);
		if(datelegal (birth[0],birth[1],birth[2]))
		{
			setxy(62,25); 
			printf("输入的生日不合法，请核对信息！");
			Sleep(1500);
			goto RR; 
		}
		setxy(65,25);
		printf("请输入学院:");
		scanf("%s",dep);
		setxy(65,26);
		printf("请输入高数成绩:");
		scanf("%f",&score1);
		setxy(65,27);
		printf("请输入数字逻辑:");
		scanf("%f",&score2);
		setxy(65,28);
		printf("请输入离散成绩:");
		scanf("%f",&score3);
		Vadd(num,name,sex,birth,dep,score1,score2,score3);
    }

    
} 

int Icherknum(char *num)//检查是否有相同的学号 
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

int leap (int year)					//判断闰年函数
{
	if((year%4==0 && year%100!=0)||year%400==0)			
		return 1;
	else
		return 0;
}

int datelegal (int year,int month, int day)		//判断输入日期是否合法函数，若合法返回0，不合法返回1
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

void Vadd(char* num, char* name, char* sex,int *birth,char *dep,float score1,float score2,float score3)  //增加信息 
{
    Stu* news = (Stu*)malloc(sizeof(Stu));  //新建一个新节点
	Stu* p = students;
    news->next = NULL;
    //给新节点赋值
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
    
    while (p->next!=NULL)  //调整p到最后一个节点
        p = p->next;
    p->next = news;  //p链接新节点，插入新信息
    Vstructtofile(news);
    printf("\n\t\t\t\t\t\t\t\t\t增加成功！\n");
	Sleep(1000); 
}

void Vdelete(char* num)//删除信息(学号)
{
	char a[1];
    Stu* stu = students->next;//当前节点
    Stu* p = students;
    int flag = 0;//是否找到学生
    while (stu != NULL)
    {
        if (strcmp(stu->num, num) == 0)//判断id是否相同
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
        printf("确定删除吗？(确认输入y)");
        scanf("%s",a);
        if(a[0]=='y'||a[0]=='Y')
        {
			p->next = stu->next;
            free(stu);
            VreWrite();//重写进文件
			printf("\t\t\t\t\t\t\t\t\t删除成功!\n");
			Sleep(1000);
		}
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t   没有找到该学生，请核对信息!\n");
        Sleep(1000);
    }
}

void Vdeletename(char * name)//删除信息(姓名)
{
	Stu* stu = students->next;//当前节点
    Stu* p = students;
    int flag = 0;//是否找到学生
	char a[1];
    while (stu != NULL)
    {
        if (strcmp(stu->name, name) == 0)//判断id是否相同
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
        printf("确定删除吗？(确认输入y)");
        scanf("%s",a);
       	if(a[0]=='y'||a[0]=='Y')
       	{
            p->next = stu->next;
            free(stu);
            VreWrite();//重写进文件
			printf("\t\t\t\t\t\t\t\t\t删除成功!\n");
			Sleep(1000);
		}
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t\t没有找到该学生，请核对信息!\n");
        Sleep(1000);
    }
}

void VreWrite()//重写进文件
{
    Stu* stu = students->next;
    FILE* file = fopen("stu.txt", "w");//清空文件
    fclose(file);
    if (stu == NULL)//这个代表当前没有学生，直接返回
        return;

    while (stu != NULL)
    {   
        Vstructtofile(stu);
        stu = stu->next;
    }
}

void Vstructtofile(Stu* stu)  //将结构体中内容写入文件 
{
    FILE* file;
    file=fopen("stu.txt","a");
    if (file == NULL)  //判断文件是否成功打开 
    {
        printf("文件写入不成功!");
        return;
    }
    fprintf(file, "%s %s %s %d.%d.%d %s %.2f %.2f %.2f %.2f %.2f\n", stu->num,stu->name,stu->sex,stu->birth[0],stu->birth[1],stu->birth[2],stu->dep,stu->score1,stu->score2,stu->score3,stu->score4,stu->score5);
    fclose(file);
}



int main()
{
	char title1[]="欢 迎 进 入 学 生 信 息 管 理 系 统";
	char title2[]="作 者 : 魏 静 文";
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
		Sleep(50);//休眠
	}
	i=0;
	setxy(72,19);
	while(title2[i]!=0)
	{
		printf("%c",title2[i]);
		i++;
		Sleep(50);//休眠
	}
	Sleep(1700); 
	Vmainmenu();

	return 0;
}
