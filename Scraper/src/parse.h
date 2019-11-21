#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <time.h>
#define CHARP_SIZE sizeof(char*)
#define CHAR_SIZE sizeof(char)
typedef int bool;
#define true 1
#define false 0

char *getAction(char *, int, char * );
int countActionOption(int , char * );
void GetOption(int  , char ** , char ** , char **, char *  );
char * removeEnd(char * );
char * checkOption(char * compare, int * numberOption , int number , char ** option, char * line);
char ** explodeInC(char separator, char * str );
char ** getTaskAction(int number, char * fileName);
char *getTaskInfo(char *, int , char *);
bool isInt(char );
bool isTurn(char *);
void writeLogs(char *, char *);
char *removeGuillemets(char *);
char *removeHttps(char *);


    /**
typedef struct Action
{
    char * name;
    char * url;
    int  numberAction;
    char ** action;
}Action;
**/
