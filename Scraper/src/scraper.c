#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <time.h>
#include "scraper.h"
#include "parse.h"
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
    return written;
}

void scrap(char* URL, char* type, char * name)
{
    char * nameHtml = malloc(sizeof(char)*50);
    char * date = malloc(sizeof(char)*50);
    char * error = malloc(sizeof(char)*50);
    time_t t = time(NULL);
    curl_global_init( CURL_GLOBAL_ALL );
    CURL * myHandle = curl_easy_init ( );
    CURLcode result; // We’ll store the result of CURL’s webpage retrieval, for simple error checking
    myHandle = curl_easy_init ( ) ;
    char *content_type = (char *)malloc(sizeof(char) * 100);
    char * newUrl = (char * ) malloc(sizeof(char)*100);
    newUrl = removeGuillemets(URL);
    // Set up a couple initial paramaters that we will not need to modify later.otice the lack of major error checking, for brevity */
    curl_easy_setopt(myHandle, CURLOPT_URL, (char *) newUrl);
    curl_easy_setopt(myHandle, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(myHandle, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(myHandle, CURLOPT_WRITEFUNCTION, write_data); // Passing the function pointer to LC
    curl_easy_setopt(myHandle, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(myHandle, CURLOPT_VERBOSE, 0);
    if(strchr(newUrl,'/')!= NULL)
    {
        nameHtml = removeHttps(strchr(newUrl,'/')+2);
    }
    else{
        sprintf(nameHtml,"%s",name);
    }
    sprintf(nameHtml,"%s.html",nameHtml);
    sprintf(date,"%s \n",ctime(&t));
    writeLogs(date,"history.txt");
    writeLogs("\n","history.txt");
    writeLogs(nameHtml,"history.txt");
    writeLogs("\n","history.txt");
    FILE* scrapFile = fopen(nameHtml, "wb");
    if (scrapFile){
        curl_easy_setopt(myHandle, CURLOPT_WRITEDATA, scrapFile);
        result = curl_easy_perform( myHandle );
        fclose(scrapFile);
        if (result == CURLE_OK){
            curl_easy_getinfo(myHandle, CURLINFO_CONTENT_TYPE, &content_type);
        } else {
            fprintf(stderr, " Error : %s\n",
                    curl_easy_strerror(result));
                    sprintf(error, "Error : %s \n ", curl_easy_strerror(result));
                    writeLogs(error,"errors.log");
                    printf("Cannot download url\n");
        }

    } else {
        printf("Cannot create file\n");
    }


    curl_easy_cleanup( myHandle );
    curl_global_cleanup();
}
