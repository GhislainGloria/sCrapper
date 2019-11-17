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
void GetOption(int number, char **option1, char **option2, char **option3, char **option4, char **option5, char *file);
char *checkOption(char *compare, int *numberOption, int number, char **option, char *line);
char *removeEnd(char *temp);
char **getTaskAction(int number, char *fileName);
char ** explodeInC(char separator, char * str );
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
