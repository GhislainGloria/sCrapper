#include "parse.h"

char *getAction(char *param_name, int number, char *fpp)
{
    char line[10000];
    char *param;
    char param_temp[25];
    int i = 0;
    int end = 1;
    int num = 0;
    FILE *fp = fopen(fpp, "r");
    if (param_name != NULL && fp != NULL)
    {
        param = malloc(sizeof(char) * 2550);
        // printf(" name  :  %s \n ", param_name);
        while (fgets(line, 255, fp) != NULL)
        {

            if ((strstr(line, param_name) != NULL) && strchr(line, '>'))
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
    char *currentLine = malloc(sizeof(char) * 500);
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
            checkOption("{option1", &numberOption, number, option1, line);
            checkOption("{option2", &numberOption, number, option2, line);
            checkOption("{option3", &numberOption, number, option3, line);
            checkOption("{option4", &numberOption, number, option4, line);
            checkOption("{option5", &numberOption, number, option5, line);
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
            *option = malloc(sizeof(char) * 50);
            if (*option != NULL)
            {
                strcpy(*option, strchr(line, '>') + 1);
            }
        }
        printf(" ici :  %s \n ", *option);

        (*numberOption)++;
        return option;
    }
    return NULL;
}
char *removeEnd(char *temp)
{
    char *finalStr = malloc(sizeof(char) * strlen(temp));
    int end = 1;
    int i = 0;
    while (end)
    {
        if (temp[i] == '}')
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