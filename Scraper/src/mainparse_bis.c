#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <time.h>
#include "parse.h"
#define CHARP_SIZE sizeof(char*)
#define CHAR_SIZE sizeof(char)

int main(int argc, char *argv[])
{
    char * file = "param.sconf";
    char * option1 = malloc(sizeof(char)*50);
    char * option2= malloc(sizeof(char)*50);;
    char * option3= malloc(sizeof(char)*50);;
    char * option4= malloc(sizeof(char)*50);;
    char * option5= malloc(sizeof(char)*50);;
    int number = 0;
    GetOption(number, option1, option2,  option3, option4, option5, file );
    return 0;
}


