#include <stdio.h>

void save_ida (int id)
{
    FILE *fp;
    fp = fopen("DataBase\\id.txt","w");
    fprintf(fp,"%d",id);
    fclose(fp);
}


