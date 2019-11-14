#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <time.h>
#define CHARP_SIZE sizeof(char*)
#define CHAR_SIZE sizeof(char)

int countAllAction(char *fpp);
int countAllTask(char *fpp);

int countActionOption(int , char * );
int countTaskCriterion(int number, char *fpp);
char *getTaskInfo(char *paramName, int number, char *fileName);
char *getAction(char *, int, char * );
char * removeEnd(char * );


/*
char ** explodeInC(char separator, char * str );
char ** getTaskAction(int number, char * fileName);
*/


/**
typedef struct Action
{
    char * name;
    char * url;
    int  numberAction;
    char ** action;
}Action;
**/
