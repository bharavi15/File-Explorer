#include <dirent.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char ch[50]="C:\\";
void chrdir()
{
    printf("Enter root directory::");
	scanf("%s",&ch);
	strcat(ch,":\\");
}

void list(char ch[])
{
    DIR *d;int count=0;
    struct dirent *dir;
    d = opendir(ch);
	 if (d)
	 {
	  while ((dir = readdir(d)) != NULL)
	  {
        printf("%d. %s\n", ++count, dir->d_name);
	  }
	  closedir(d);
    }
}
void prevdir(char ch[])
{
    int x,i,y;
    for(x=1,i=strlen(ch);i>0&&x!=3;i--)
    {
        y=ch[i];
		if(y==92)
		x++;
		else
		ch[i]='\0';
    }
}
void chngdir()
{
    char ch1[20];
    printf("Enter Name of Folder::");
	scanf("%s",&ch1);
	strcat(ch,ch1);
	strcat(ch,"\\");
	DIR *d;
	d=opendir(ch);
	if(!d)
    {
        printf("CANNOT OPEN FOLDER!!\n");
        prevdir(ch);
    }
     closedir(d);
}
void opfile()
{

    char ch5[100]="start \"\" \"";
    int fn,count=1,flag=0;
    strcat(ch5,ch);
    printf("Enter File No. from List::");
    scanf("%d",&fn);
    DIR *d;
    struct dirent *dir;
    d = opendir(ch);
	 if (d)
	 {
	  while ((dir = readdir(d)) != NULL)
	  {
        if(fn==count)
        {strcat(ch5,dir->d_name);
        strcat(ch5,"\"");printf("%s",ch5);
         system(ch5);flag=1;
        break;
        }
        else
        count++;
	  }
	  if(flag==0)
        printf("FILE NOT FOUND\n");
	  closedir(d);
    }
}
int main()
{
	 int a;
     do
	 {
	 printf("\nCurrent Directory:%s\n",ch);
	 printf("1.Change Root Directory\n2.List items\n3.Change Directory\n4.Go back to Previous Directory\n5.Open File\n6.Exit\nEnter Your Choice::");
     scanf("%d",&a);
     switch(a)
	 {
	 case 1:chrdir();
	 break;
	 case 2:list(ch);
	 break;
	 case 3:chngdir();
	 break;
	 case 4:prevdir(ch);
	 break;
	 case 5:opfile();
	 break;
	 case 6:break;
	 default:printf("\nWRONG CHOICE\n");
	 }
	 }while(a!=6);
	 return(0);
}
