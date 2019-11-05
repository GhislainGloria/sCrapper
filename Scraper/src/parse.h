#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <time.h>
char *getAction(char *, int, char * );
int countActionOption(int , char * );
void GetOption(int  , char ** , char ** , char **, char ** , char **, char *  );
char * removeEnd(char * );
char ** checkOption(char * compare, int * numberOption , int number , char ** option, char * line);
/**
typedef struct Action
{
    char * name;
    char * url;
    int  numberAction;
    char ** action;
}Action;
**/
