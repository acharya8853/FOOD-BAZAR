#include <stdio.h>

void save_idf (int id)
{
    FILE *fp;
    fp = fopen("DataBase\\idf.txt","w");
    fprintf(fp,"%d",id);
    fclose(fp);
}


