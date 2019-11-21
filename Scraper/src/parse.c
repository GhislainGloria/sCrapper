#include "parse.h"


//COMPTE LE NOMBRE TOTAL D'ACTION DANS LE FICHIER DE CONFIG
int countAllAction(char *fpp){
	char line[255];
	int count = 0;
	FILE * fp = fopen(fpp,"r");
	fseek(fp,0,SEEK_SET);
	char* parcours = (char*)fgetc(fp);
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


//COMPTE LE NOMBRE TOTAL DE TACHE DANS LE FICHIER DE CONFIG
int countAllTask(char *fpp){
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


//RECUPERE LA VALEUR DE L'ACTION SELON SON KEY ET SON NUMERO
//KEY = name et url
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




//COMPTE LE NOMBRE D'OPTION POUR UNE ACTION
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




//RECUPERE LA VALEUR DE LA TACHE SELON SON KEY ET SON NUMERO
//KEY = name et hour et minute et second
char *getTaskInfo(char *paramNameT, int number, char *fileName)
{
    //int total = countTaskCriterion(number,fileName);
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




//COMPTE LE NOMBRE DE CRITERE DANS UNE TACHE
int countTaskCriterion(int number, char *fpp)
{
    int totalAct = countAllAction(fpp);
	char line[255];
    int numberTask = 0;
    int numberAct = 0;
    int totalOption = 0;
    char *temp = malloc(sizeof(char)*255);
    char *currentLine = malloc(CHAR_SIZE * 500);
    FILE *fp = fopen(fpp, "r");
    if (fp != NULL && temp != NULL)
    {
        while (fgets(line, 255, fp) != NULL)
        {
            if (strstr(line, "name"))
            {
            	numberAct++;
            	if(numberAct > totalAct){
							if (numberTask == number)
							{

								currentLine = fgets(line, 255, fp);
								while (/*strchr(currentLine, '=') == NULL &&*/ strchr(currentLine, '+') == NULL)

								{
									totalOption++;
									//printf("total : %d \n ", totalOption);

									currentLine = fgets(line, 255, fp);
								}
							}

							numberTask++;
            	}
            }
        }
    }
    else
    {
        return 0;
    }
    return totalOption;
}





//RECUPERE LES OPTIONS D'UNE ACTION SELON SON NUMERO

void GetOption(int number, char **option1, char **option2, char **option3, char *file)
{
    char line[1000];
    int numberOption1 = 0;
    int numberOption2 = 0;
    int numberOption3 = 0;
    FILE *fp = fopen(file, "r");
    if (fp != NULL)
    {
        while (fgets(line, 500, fp) != NULL)
        {

            if (checkOption("option1", &numberOption1, number, option1, line) != NULL)
            {
                //max-depth
                strcpy(*option1, checkOption("option1", &numberOption1, number, option1, line));
                numberOption1++;
                if (!isInt(*option1[0]))
                {
                    writeLogs("Valeur de max-depth incorrecte \n", "erreur.logs");
                }
            }
            else if (checkOption("versioning", &numberOption2, number, option2, line) != NULL)
            {
                //Versioning
                strcpy(*option2, checkOption("option2", &numberOption2, number, option2, line));
                numberOption2++;

                if (isTurn(*option2))
                {
                    writeLogs("Valeur de l'option versioning incorrecte", "erreur.logs");
                }
            }
            // Type
            else if (checkOption("type", &numberOption3, number, option3, line) != NULL)
            {
                strcpy(*option3, checkOption("option3", &numberOption3, number, option3, line));
                numberOption3++;
            }
        }
    }
    if (*option1)
    {
        strcpy(*option1, removeEnd(*option1));
    }
    if (*option2)
    {
        strcpy(*option2, removeEnd(*option2));
    }
    else if (*option3)
    {
        strcpy(*option3, removeEnd(*option3));
    }
}

char *checkOption(char *compare, int *numberOption, int number, char **option, char *line){
    if (strstr(line, compare)){
        if (*numberOption == number){
            option = malloc(CHAR_SIZE * 50);
            *option = malloc(CHAR_SIZE * 50);
            if (*option != NULL){
                strcpy(*option, strchr(line, '>') + 1);
                return *option;
            }
        }
        (*numberOption)++;
    }
    return NULL;
}


char *removeEnd(char *temp){
    char *removedStr = malloc(sizeof(char) * strlen(temp));
    int end = 1;
    int i = 0;
    while (end){
        if (temp[i] == '}' || i == strlen(temp)){
            removedStr[i] = '\0';
            end = 0;
        }
        else{
            removedStr[i] = temp[i];
        }
        i++;
    }
    return removedStr;
}

void getTask(int number, char **name, char **hours, char **minutes, char **seconds, char *file)
{
    char line[1000];
    int numberName = 0;
    int numberHours = 0;
    int numberMinutes = 0;
    int numberSeconds = 0;
    bool isUnder = false;

    FILE *fp = fopen(file, "r");
    if (fp != NULL)
    {
        while (fgets(line, 500, fp) != NULL)
        {
            if (line[0] == '=' && line[1] == '=')
            {
                isUnder = true;
            }
            if (line == '=' && line[1] != '=')
            {
                isUnder = false;
            }
            if (isUnder)
            {
                if (checkOption("name", &numberName, number, name, line) != NULL)
                {
                    strcpy(*name, checkOption("name", &numberName, number, name, line));
                    numberName++;
                }
                if (checkOption("hours", &numberHours, number, hours, line) != NULL)
                {
                    strcpy(*hours, checkOption("hours", &numberHours, number, hours, line));
                    numberHours++;
                }
                if (checkOption("minutes", &numberMinutes, number, minutes, line) != NULL)
                {
                    strcpy(*minutes, checkOption("minutes", &numberMinutes, number, minutes, line));
                    numberMinutes++;
                }
                if (checkOption("secondes", &numberSeconds, number, seconds, line) != NULL)
                {
                    strcpy(*seconds, checkOption("secondes", &numberSeconds, number, seconds, line));
                    numberSeconds++;
                }
            }
        }
        if (*name)
        {
            strcpy(*name, removeEnd(*name));
        }
        else
        {
            *name = NULL;
        }
        if (*hours)
        {
            strcpy(*hours, removeEnd(*hours));
        }
        else
        {
            *hours = NULL;
        }
        if (*minutes)
        {
            strcpy(*minutes, removeEnd(*minutes));
        }
        else
        {
            *minutes = NULL;
        }
        if (*seconds)
        {
            strcpy(*seconds, removeEnd(*seconds));
        }
        else
        {
            *seconds = NULL;
        }
    }
}

//RECUPERE UN TABLEAU DE CHAR* CONTENANT LE NOM DES ACTION SPOUR CHAQUE TACHE
char **getTaskAction(int number, char *fileName){
	char **actionTab;
    int count = 0;
    int isUnder = 0;
    char line[1000];
    FILE *fp = fopen(fileName, "r");
    if (fp != NULL){
        while (fgets(line, 255, fp)){
            if (line[0] == '=' && line[1] == '='){
                isUnder = 1;
            }
            if (line == '=' && line[1] != '='){
                isUnder = 0;
            }
            if (isUnder == 1 && strchr(line, '+') != NULL){
                fgets(line, 255, fp);
                if (number == count){
                    if (strchr(line, '(') != NULL){
                        actionTab = explodeInC(',', line);
                        return actionTab;
                    }
                }
                count++;
            }
        }
    }
    return NULL;
}


char ** explodeInC(char separator, char * str )
{
    char *tmp = malloc(strlen(str));
    strcpy(tmp,str);
    char **finalStr = malloc(CHAR_SIZE);
    int actualSize = 1;
    finalStr[0] = tmp;
    while(*tmp){
        if(*tmp == separator){
            finalStr = realloc(finalStr,actualSize*CHAR_SIZE);
            actualSize++;
            finalStr[actualSize-1] =tmp+1;
            *tmp = '\0';
        }
        tmp++;
    }
    return finalStr;
}
bool isTurn(char *string)
{
    return (strstr(string, 'on') != NULL || strstr(string, 'off') != NULL);
}
void writeLogs(char *string, char *fileName)
{
    FILE *fp;
    char *logs = malloc(CHAR_SIZE * strlen(string) + 1);
    logs = strcpy(logs, string);
    if (logs[strlen(logs) - 1] == '\0')
    {
        logs[strlen(logs) - 1] = '\n';
        logs[strlen(logs)] = '\0';
    }
    fp = fopen(fileName, "a+t");
    if (fp != NULL)
    {
        fputs(logs, fp);
    }
    else
    {
        fp = fopen(fileName, "w+t");
        fputs(logs, fileName);
    }
    fclose(fp);
    free(logs);
}
bool isInt(char value)
{
    return (value > 47 && value < 58);
}
char *removeGuillemets(char *content)
{
    char *newContent = malloc(strlen(content));
    if(newContent!= NULL)
    {
        strcpy(newContent,content + 1);
        newContent[strlen(newContent) - 1] = (char) '\0';
    }
    return newContent;
}
char *removeHttps(char *temp)
{
    char *removedStr = malloc(sizeof(char) * strlen(temp));
    int end = 1;
    int i = 0;
    if(removedStr)
    {


    while (end){
        if (temp[i] == '/' || i == strlen(temp)){
            removedStr[i] = '\0';
            end = 0;
        }
        else{
            removedStr[i] = temp[i];
        }
        i++;
    }
    return removedStr;
}

}
