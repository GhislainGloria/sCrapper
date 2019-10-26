#include "parse.h"
/**
 Fonction pour r�cuperer les action c'est a dire le nom de l'action et son url.
 number = permet de recuperer le num�ro de l'action
 param_name permet de savoir ce que vont r�cuperer ,c'est a dire le nom de l'action ou l'url.

 **/
char * getAction(char *param_name, int number)
{
    FILE *fp = fopen("files/param.sconf", "r");
    char line[10000];
    char *name = malloc(sizeof(char) * 255);
    char * param;
    char param_temp[25];
    int i = 0;
    int end = 1;
    int num = 0;
    if (name != NULL && fp != NULL)
    {
        param = malloc(sizeof(char) * 2550);
        name = param_name;
        printf(" name  :  %s \n ", name);

        while (fgets(line, 255, fp) != NULL)
        {

            if ((strstr(line, name) != NULL) && strchr(line, '>'))
            {
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
                    printf(" param : %s \n ", param);
                    return param;
                }
                num++;
            }
        }
    }
    else
    {
        printf("\n \n Fichier de configuration introuvable");
        return NULL;
    }
    free(param);
    free(name);
    fclose(fp);
}
int numberAction()
{
    FILE * fp;
}
