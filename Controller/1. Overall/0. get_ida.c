#include <stdio.h>

int get_ida ()
{
    int id;
    FILE *fp;
    fp = fopen("DataBase\\id.txt","r");
    fscanf(fp,"%d",&id);
    fclose(fp);
    return id;
}

