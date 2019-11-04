#include "parse.h"

char *getAction(char *param_name, int number, char * fpp)
char *getAction(char *param_name, int number, FILE * fp)
{
    char line[10000];
    char *param;
    char param_temp[25];
    int i = 0;
    int end = 1;
    int num = 0;
    FILE * fp = fopen(fpp,"r");
    if (param_name != NULL && fp != NULL)
    {
        param = malloc(sizeof(char) * 2550);
       // printf(" name  :  %s \n ", param_name);
        while (fgets(line, 255, fp) != NULL)
        {

            if ((strstr(line, param_name) != NULL) && strchr(line, '>'))
            {
                //printf(" num =   %d \n ", num);
                printf(" num =   %d \n ", num);

                if (num == number)
                {
                    strcpy(param, (strchr(line, '>') + 2));
                }

                if (strchr(param, '}') && num == number)
                {
                    while (end)
                    {
                        if (param[i] == '}')
                        {
                            param_temp[i] = '\0';
                            end = 0;
                        }
                        else
                        {
                            param_temp[i] = param[i];
                        }
                        i++;
                    }
                }
                if (num == number)
                {
                    free(param);
                    char *param;
                    param = malloc(sizeof(char) * (strlen(param_temp) + 2));
                    strcpy(param, param_temp);
                    //printf(" param : %s \n ", param);
                    printf(" param : %s \n ", param);
                    return param;
                }
                num++;
            }
        }
    }
    else
    {
        //printf("Fichier de configuration introuvable \n");
        return NULL;
    }
    free(param);
    fclose(fp);
    return NULL;
}

int countActionOption(int number, char * fpp)
        printf("Fichier de configuration introuvable \n");
        return NULL;
    }
    free(param);
    free(name);
    fclose(fp);
}

int countActionOption(int number, FILE * fp)
{
    char line[255];
    int numberAction = 0;
    int totalOption = 0;
    char *temp;
    char *currentLine = malloc(sizeof(char) * 500);
    temp = malloc(sizeof(char) * 255);
     FILE * fp = fopen(fpp,"r");
    if (fp != NULL && temp != NULL)
    {
        while (fgets(line, 255, fp) != NULL)
        {
            temp = strchr(line, '=');
            // printf("%d", temp);
            if (strchr(line, '=') != NULL && strchr(temp, '='))
            {
                if (numberAction == number)
                {
                    currentLine = fgets(line, 255, fp);
                    while (strchr(currentLine, '=') == NULL && strchr(currentLine, '+') == NULL)

                    {
                        totalOption++;
                        currentLine = fgets(line, 255, fp);
                    }
                }
                numberAction++;
            }
    char * temp;
    char * currentLine = malloc(sizeof(char)*500);
    temp = malloc(sizeof(char)*255);
    if(fp != NULL && temp != NULl )
    {
        while (fgets(line, 255, fp) != NULL)
        {
            temp = strchr(line,'=');
            if(strchr(line,'=') != NULL && temp[1] == '=')
            {
               if(numberAction == number)
               {
                    currentLine = fgets(line,255,fp);
                    while(strchr(currentLine,'=') == NULL && strchr(currentLine,'+') == NULL)
                    {
                        totalOption++;
                    }
               }
                numberAction++;
            }

        }
    }
    else
    {
        return NULL;
    }
    free(temp);
    free(currentLine);
    fclose(fp);
    return totalOption;
}
