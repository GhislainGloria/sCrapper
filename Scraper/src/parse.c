#include "parse.h"



int countAllAction(char *fpp){
	char line[255];
	int count = 0;
	FILE * fp = fopen(fpp,"r");
	fseek(fp,0,SEEK_SET);
	char* parcours = fgetc(fp);
	    if (fp != NULL){
	    	while(parcours != EOF){
	    		if(parcours == '='){
	    			parcours = fgetc(fp);
	    			if(parcours != '='){
	    			count++;
	    			}
	    		}
	    		parcours = fgetc(fp);
	    	}
	    }
	fclose(fp);
	return count;
}



int countAllTask(char *fpp){
	char line[255];
	int count = 0;
	FILE * fp = fopen(fpp,"r");
	fseek(fp,0,SEEK_SET);
	char* parcours = fgetc(fp);
	    if (fp != NULL){
	    	while(parcours != EOF){
	    		if(parcours == '='){
	    			parcours = fgetc(fp);
	    			if(parcours == '='){
	    			count++;
	    			}
	    		}
	    		parcours = fgetc(fp);
	    	}
	    }
	fclose(fp);
	return count;
}


char *getAction(char *param_name, int number, char * fpp)
{
    char line[10000];
    char *param;
    char param_temp[25];
    int i = 0;
    int end = 1;
    int num = 0;
    FILE * fp = fopen(fpp,"r");
    fseek(fp,0,SEEK_SET);
    if (param_name != NULL && fp != NULL)
    {
        param = malloc(sizeof(char) * 2550);
       // printf(" name  :  %s \n ", param_name);
        while (fgets(line, 255, fp) != NULL)
        {

            if ((strstr(line, param_name) != NULL) && strchr(line, '>'))
            {
                //printf(" num =   %d \n ", num);
                //printf(" num =   %d \n ", num);

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
                    //printf(" param : %s \n ", param);
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
    fseek(fp,0,SEEK_SET);
    if (fp != NULL && temp != NULL)
    {
        while (fgets(line, 255, fp) != NULL )
        {
        	if (strstr(line, "+"))
            {
                if (numberAction == number)
                {

                    currentLine = fgets(line, 255, fp);
                    while (strchr(currentLine, '=') == NULL && strchr(currentLine, '+') == NULL && currentLine[1] != NULL )
                    {

                        totalOption++;
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
    fclose(fp);
    return totalOption;
}



char *removeEnd(char *temp)
{
    char *removedStr = malloc(CHAR_SIZE * strlen(temp));
    int end = 1;
    int i = 0;
    while (end)
    {
        if (temp[i] == '}' || i == strlen(temp))
        {
            removedStr[i] = '\0';
            end = 0;
        }
        else
        {
            removedStr[i] = temp[i];
        }
        i++;
    }
    return removedStr;
}


char *getTaskInfo(char *paramNameT, int number, char *fileName)
{
    char line[1000];
    int count = 0;
    char *myParam;
    myParam = malloc(CHAR_SIZE * 255);
    FILE *fp = fopen(fileName, "r");
    if (fp != NULL && paramNameT != NULL && myParam != NULL)
    {
        while (fgets(line, 255, fp) != NULL)
        {
            if (line[0] == '=' && line[1] == '=')
            {
                if (count == number)
                {

                    while (strchr(line, '+') == NULL )//&& strchr(line, '=') == NULL)
                    {

                        if (strstr(line, paramNameT) != NULL)
                        {
                        	strcpy(myParam, strchr(line, '>') + 1);
                        }
                        fgets(line, 255, fp);
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



