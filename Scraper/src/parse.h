#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <time.h>
#define CHARP_SIZE sizeof(char*)
#define CHAR_SIZE sizeof(char)

char *getAction(char *, int, char * );
int countActionOption(int , char * );
void GetOption(int  , char ** , char ** , char **, char ** , char **, char *  );
char * removeEnd(char * );
char * checkOption(char * compare, int * numberOption , int number , char ** option, char * line);
char ** explodeInC(char separator, char * str );
char ** getTaskAction(int number, char * fileName);
/**
typedef struct Action
{
    char * name;
    char * url;
    int  numberAction;
    char ** action;
}Action;
**/
