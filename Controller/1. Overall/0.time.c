#include <time.h>
#include <stdio.h>
#include <string.h>

void times(char *ptr)
{
    time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';

    *ptr=time_str[8];
    *(ptr+1)=time_str[9];
    *(ptr+2)='/';
    *(ptr+3)=time_str[4];
    *(ptr+4)=time_str[5];
    *(ptr+5)=time_str[6];
    *(ptr+6)='/';
    *(ptr+7)=time_str[20];
    *(ptr+8)=time_str[21];
    *(ptr+9)=time_str[22];
    *(ptr+10)=time_str[23];
    *(ptr+11)='\0';
}
