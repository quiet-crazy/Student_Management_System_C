#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sysuser
{
	char username[20];
	char password[8];
} ;
void encrypt(char *pwd)
{
	int i;
	for(i=0;i<strlen(pwd);i++)
		pwd[i]=pwd[i]^15;
}
int main()
{
	FILE *fp;
	int i,n;
	struct sysuser su;
	printf("用户数量:");
	scanf("%d",&n);
	if((fp=fopen("register.txt","w"))==NULL)
	{
		printf("文件打开错误!\n");
		exit(0);
	}
	for(i=1;i<=n;i++)
	{
		printf("第%d个\n用户名:",i);
		scanf("%s",su.username);
		printf("密码:");
		scanf("%s",su.password);
		encrypt(su.password);
		fprintf(fp,"%s %s\n",su.username,su.password);
	}
	fclose(fp);
	
	return 0;
}
