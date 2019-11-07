#include "parse.h"

char *getAction(char *paramName, int number, char *fpp)
{
    char line[10000];
    char *param;
    int num = 0;
    FILE *fp = fopen(fpp, "r");
    if (paramName != NULL && fp != NULL)
    {
        param = malloc(CHAR_SIZE * 2550);
        // printf(" name  :  %s \n ", paramName);
        while (fgets(line, 255, fp) != NULL)
        {

            if ((strstr(line, paramName) != NULL) && strchr(line, '>'))
            {
                if (num == number)
                {
                    strcpy(param, (strchr(line, '>') + 2));
                }

                if (num == number)
                {
                    strcpy(param, removeEnd(param));
                    return param;
                }
                num++;
            }
        }
    }
    else
    {
        printf("Fichier de configuration introuvable \n");
        return NULL;
    }
    free(param);
    fclose(fp);
    return NULL;
}

int countActionOption(int number, char *fpp)
{
    char line[255];
    int numberAction = 0;
    int totalOption = 0;
    char *temp;
    char *currentLine = malloc(CHAR_SIZE * 500);
    FILE *fp = fopen(fpp, "r");
    if (fp != NULL && temp != NULL)
    {
        while (fgets(line, 255, fp) != NULL)
        {
            if (strstr(line, "+"))
            {
                if (numberAction == number)
                {

                    currentLine = fgets(line, 255, fp);
                    while (strchr(currentLine, '=') == NULL && strchr(currentLine, '+') == NULL)

                    {
                        totalOption++;
                        printf("total : %d \n ", totalOption);

                        currentLine = fgets(line, 255, fp);
                    }
                }

                numberAction++;
            }
        }
    }
    else
    {
        return 0;
    }
    return totalOption;
}
void GetOption(int number, char **option1, char **option2, char **option3, char **option4, char **option5, char *file)
{
    char line[1000];
    int numberOption = 0;
    FILE *fp = fopen(file, "r");
    // printf("ici");
    if (fp != NULL)
    {
        while (fgets(line, 500, fp) != NULL)
        {
            checkOption("option1", &numberOption, number, option1, line);
            checkOption("option2", &numberOption, number, option2, line);
            checkOption("option3", &numberOption, number, option3, line);
            checkOption("option4", &numberOption, number, option4, line);
            checkOption("option5", &numberOption, number, option5, line);
        }
    }
    strcpy(*option1, removeEnd(*option1));
    strcpy(*option2, removeEnd(*option2));
    strcpy(*option3, removeEnd(*option3));
    strcpy(*option4, removeEnd(*option4));
    strcpy(*option5, removeEnd(*option5));
}
char **checkOption(char *compare, int *numberOption, int number, char **option, char *line)
{
    if (strstr(line, compare))
    {
        if (*numberOption == number)
        {
            *option = malloc(CHAR_SIZE * 50);
            if (*option != NULL)
            {
                strcpy(*option, strchr(line, '>') + 1);
            }
        }

        (*numberOption)++;
        return option;
    }
    return NULL;
}
char *removeEnd(char *temp)
{
    char *finalStr = malloc(CHAR_SIZE * strlen(temp));
    int end = 1;
    int i = 0;
    while (end)
    {
        if (temp[i] == '}' || i == strlen(temp))
        {
            finalStr[i] = '\0';
            end = 0;
        }
        else
        {
            finalStr[i] = temp[i];
        }
        i++;
    }
    return finalStr;
}
char *getTaskInfo(char * paramName, int number, char * fileName)
{
    char line[1000];
    int count = 0;
    char * myParam;
    myParam = malloc(CHAR_SIZE*255);
    FILE * fp = fopen(fileName,"r");
    if(fp != NULL && paramName != NULL && myParam != NULL)
    {
        while (fgets(line,255,fp)!= NULL)
        {
            if( line[0] == '=' && line[1] == '=')
            {
                if(count == number )
                {
                    while (strchr(line,'+') == NULL && strchr(line,'=') == NULL)  
                    {
                        if(strstr(line,paramName) != NULL)
                        {   
                            strcpy(myParam,strchr(line,'>')+1);
                        }
                        fgets(line,255,fp);
                    }
                    return removeEnd(myParam);
                }

                count++;
            }
        }
        
    }
    else
    {
        printf("Problème de mémoire.");
        return NULL;
    }
    return NULL;
}
char ** explodeInC(char separator, char * str )
{
    char *tmp = (char*) malloc(strlen(str));
    tmp = strcpy(tmp,str);
    char **finalStr = (char**)malloc(CHARP_SIZE);
    finalStr[0] = *tmp;
    int actualSize = 1;
    int i = 0;
    while(*tmp!='\0')
    {
        if(*tmp == separator)
        {   //printf("%d \n", ++i);
            finalStr = (char**)realloc(finalStr,(++actualSize)*CHARP_SIZE);
            finalStr[actualSize-1] = tmp+1;
           *tmp = 0;  
        }
        tmp++;
    }
    return finalStr;

}
char ** getTaskAction(int number, char * fileName)
{
    char ** actionTab;
    int count=0;
    actionTab = malloc(sizeof(char)*255);

}
/**
char** explode1(const char delimiter, const char* str) {
	char *p = strcpy((char*)malloc(strlen(str)),str);
	unsigned int cp_size = sizeof(char*);
	char **r = (char**)malloc(cp_size);
	unsigned long j = 1;
	r[0] = p;
	while(*p){
		if(*p == delimiter){
			r = (char**)realloc(r,(++j)*cp_size);
			r[j-1] = p+1;
			*p = 0;
		}
		p++;
	}
	return r;
}**/

