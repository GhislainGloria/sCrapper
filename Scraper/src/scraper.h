#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <curl/easy.h>

size_t write_data(void *, size_t , size_t , FILE *);
void scrap(char* , char* , char * );
