#ifndef DBOPERATION_C
#define DBOPERATION_C

#include<stdio.h>
#include<stdlib.h>

#define ROWLIMIT 100
#define COLUMNLIMIT 20

typedef struct yymmddhhmmss
{
    int yea;
    int mon;
    int day;
    int hou;
    int min;
    int sec;
} time;

typedef struct tableinfo
{
    int intNum;
    int strNum;
    int timNum;
    int floNum;
    int tblNum;
    int rowNum;
    
} tblinfo; // 

typedef struct tablerow
{
    int *pint; // by default, pint[0] is internal ID, pint[1] is valid tag.
    char **pstr;
    time *ptim;
    float *pflo;
    tbl *ptbl;
    int *keyID; //in this programe, key must be a int number.
} tblrow;

typedef struct tablecolumn
{
    int **phint; // pointer to the head of a list of int, all the same.
    char ***phstr;
    time **phtim;
    float **phflo;
    tbl **phtbl;
    int **phkeyID;// note the correspondence of tbl and keyID is complicated in column mode
} tblclm;

typedef struct table
{
    int recordMode; // -1 : abandon; 0 : empty; 1 : row; 2 : column
    char *name;
    // int keyIDColumn; as key must be a int, the key will always be stored in front of the record. 1st
    tblinfo info; 
    int *defaultMap;
    int locatedRowNum;
    tblrow *prow;
    //tblclm clm;
} tbl;

tblrow *loca_row(int n)
{
    return (tblrow *)malloc(n * sizeof(tblrow));
}
tbl *loca_table(int n)
{
    return (tbl *)malloc(n * sizeof(tbl));
}

void free_row(tblrow *rowHead)
{
    if(rowHead != NULL)
    {
        free(rowHead);
    }
}
void free_table(tbl *tblHead)
{

}

void read_table(FILE *pfile, tbl *target)
{
    if(checkhead(readhead(pfile), ))
    {
        for()
        {
            readrow();
        }
    }
    else
    {
        printf("fatal error, storage wrong.\n");
    }
    
}
void write_table(FILE *pfile, tbl source)
{
    writehead();
    for()
    {
        writerow(); 
    }
}


void init_row(tblrow *pdirty_row)
{
    pdirty_row -> pint = NULL;
    pdirty_row -> pstr = NULL;
    pdirty_row -> ptim = NULL;
    pdirty_row -> pflo = NULL;
    pdirty_row -> ptbl = NULL;
    pdirty_row -> key = -1;
}
void init_info(tblinfo *pinfo)
{
    pinfo -> intNum = 0;
    pinfo -> strNum = 0;
    pinfo -> timNum = 0;
    pinfo -> floNum = 0;
    pinfo -> tblNum = 0;
    pinfo -> rowNum = 0;
}
void init_table(tbl *pdirty_table)
{
    pdirty_table->recordMode = 0;
    pdirty_table->name = NULL;
    init_info(&pdirty_table->info);
    pdirty_table->prow = loca_row(ROWLIMIT);
    if(pdirty_table->prow == NULL)
    {
        pdirty_table->locatedRowNum = 0;
    }
    else
    {
        pdirty_table->locatedRowNum = ROWLIMIT;
        for(int i = 0; i < ROWLIMIT; i++)
        {
            init_row(&pdirty_table->prow[i]); 
        }
    }
    pdirty_table->defaultMap = NULL;
}

tbl *expand_table(tbl * )


void set_table(tbl *table, char *name, int keyIDColumn, int intNum, int strNum, int tblNum, int rowNum);
int* calc_size(tbl tblInfo);
void pack_row(tbl *resource, int *size, int *pint, char **pstr, time *ptime, float *pflo, tbl *ptbl, int *tblcolumn);

#endif