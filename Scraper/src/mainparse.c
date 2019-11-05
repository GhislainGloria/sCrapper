#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <time.h>
#include "parse.h"

int main(int argc, char *argv[])
{   
    // Test GetOption
    int count = 0;
    char *testurl;
    char *testname;
    char * file = "files/param.sconf";
    char * option1;
    char * option2; 
    char * option3;
    char * option4;
    char * option5;
    int number = 0;

   /* testurl = malloc(sizeof(char) * 255);
    testname = malloc(sizeof(char) * 255);
    testname = getAction("name", count);
    testurl = getAction("url", count);*/
  /*  printf(" \n Url : %s", testurl);
    printf("\n name : %s", testname); */
    GetOption(number , option1, option2 ,  option3, option4 , option5, file );
    printf("Option 1  =  %s", option1);
    return 0;
}
void GetOption(int number , char * option1, char * option2 , char * option3, char * option4 , char * option5, char * file )
{
    char line[1000];
    int numberOption;
    FILE * fp = fopen(file,"r");
    printf("ici");
    if(fp != NULL)
    {
        while(fgets(line,500,fp) != NULL)
        {
            printf("While");
            if(strstr(line,"option1"))
            {
                printf("ici0");
                option1 = malloc(sizeof(char)*50);
                if(option1 != NULL)
                {
                    strcpy(option1,strchr(line,'>'));
                    printf(" ici :  %s",option1);
                }
            }

        }

    }

}