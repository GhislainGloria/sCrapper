#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <time.h>
#include "parse.h"
#define CHARP_SIZE sizeof(char*)
#define CHAR_SIZE sizeof(char)
/**
int main(int argc, char *argv[])
{
    char * file = "param.sconf";
    char * option1 = malloc(sizeof(char)*50);
    char * option2= malloc(sizeof(char)*50);
    char * option3= malloc(sizeof(char)*50);
    char * option4= malloc(sizeof(char)*50);
    char * option5= malloc(sizeof(char)*50);
    char * testaction1 = malloc(sizeof(char)*55);
    char * testaction2 = malloc(sizeof(char)*55);
    int number = 0;
    GetOption(number, &option1, &option2,  &option3, file );
    printf("%s",option1);
    strcpy(testaction1,option1);
    printf("action1 option 1 : %s",testaction1);
   GetOption(1, &option1, &option2,  &option3, file );
    strcpy(testaction2,option1);
    printf("action2 option 1 : %s",testaction2);


    return 0;
}

**/
