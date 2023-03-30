#include <stdio.h>
#include <conio.h>
#include <windows.h>


void welcome_screen ()
{
	FILE *fp;

	fp = fopen ("View\\1. Welcome and Ending\\welcome.txt","r");

	char c;
	system("cls");

 	while ( (c=fgetc(fp)) != EOF)
    {
		if(c =='9')
		{
			Sleep(175);
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}
		else if (c=='\n')
        {
            printf("\n\t\t");
        }
		else
        {
			printf("%c",c);
		}
	}
	fclose(fp);
	getch();

}
