#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <time.h>
#define CHARP_SIZE sizeof(char*)
#define CHAR_SIZE sizeof(char)

int countAllAction(char *fpp);
int countAllTask(char *fpp);
char *getAction(char *, int, char * );
int countActionOption(int , char * );
char * removeEnd(char * );
char *getTaskInfo(char *paramName, int number, char *fileName);
/**
typedef struct Action
{
    char * name;
    char * url;
    int  numberAction;
    char ** action;
}Action;
**/
