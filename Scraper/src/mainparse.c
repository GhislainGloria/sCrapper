#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <time.h>
#include "define.h"

int main()
{
    int count = 0;
    char *testurl;
    char *testname;
    testurl = malloc(sizeof(char) * 255);
    testname = malloc(sizeof(char) * 255);
    testname = getAction("name", count);
    testurl = getAction("url", count);
    printf(" \n Url : %s", testurl);
    printf("\n name : %s", testname);
    return 0;
}
