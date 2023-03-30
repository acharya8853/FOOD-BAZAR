#include <stdio.h>
#include <windows.h>

void screen()
{
    system("cls");
    char current_time[20];

    times(current_time);

    printf("\n\nFOOD BAZAR\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t %s\n\n\n",current_time);
    printf("Type the first letter of the option to use it and 'e' to exit\n\n\n\n\n");
}
