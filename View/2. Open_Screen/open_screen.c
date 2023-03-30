#include <stdio.h>
#include <conio.h>

void open_screen ()
{
    screen();
    char c;
    FILE *fp,*fp1;
    fp = fopen ("View\\2. Open_Screen\\open_window.txt","r");

    printf("\n\n");
    while ( (c=fgetc(fp)) != EOF)
    {
        if (c == '\n')
        {
            printf("\n\t\t\t\t\t\t\t\t\t\t");
        }
        else
        {
            printf ("%c",c);
        }
    }

    fclose(fp);

}
