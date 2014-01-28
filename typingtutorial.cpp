#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char ch,a[200];
	int correct=0,wrong=0;
	FILE *in;
	clrscr();
	printf("Press W to write String or any key to continue\n");
	switch(getch())
	{
	default:
		in=fopen("C:\\in.txt","r+");
		fscanf(in,"%[^\n]",a); break;
	case 'W':
	case 'w':
		gotoxy(2,6);
		printf("Enter String:: ");
		gets(a);
		break;
	}
	clrscr();textcolor(6);
	gotoxy(60,2);
	cprintf("Press Esc to exit");
	gotoxy(6,8);
	printf(a);
	gotoxy(4,2);
	cprintf("Correct:: %d",correct);
	gotoxy(25,2);
	cprintf("Wrong:: %d",wrong);
	for(int i=0;a[i]!='\0';i++)
	{
	repeat:
	gotoxy(6+i,10);
	ch=getche();
	if(ch=='\n'||ch=='\t'||ch=='\r')goto repeat;
	else if(ch==27) break;
	else if(ch==a[i])
	{
	gotoxy(6+i,6);
	cprintf("%c",3);
	gotoxy(14,2);
	cprintf("%d",++correct);
	}
	else
	{
	gotoxy(6+i,6);
	cprintf("%c",2);
	gotoxy(33,2);
	cprintf("%d",++wrong);
	}
	}
	gotoxy(20,15);
	printf("Your Score is %d\/%d",correct,correct+wrong);
	getch();
}
