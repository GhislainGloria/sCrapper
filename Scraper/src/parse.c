#include "parse.h"


//COMPTE LE NOMBRE TOTAL D'ACTION DANS LE FICHIER DE CONFIG
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


//COMPTE LE NOMBRE TOTAL DE TACHE DANS LE FICHIER DE CONFIG
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
    char indic = NULL;
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
    char *temp;
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
void GetOption(int number, char **option1, char **option2, char **option3, char **option4, char **option5, char *file){
    char line[1000];
    int numberOption = 0;
    FILE *fp = fopen(file, "r");
    if (fp != NULL){
        while (fgets(line, 500, fp) != NULL){
            if(checkOption("option1", &numberOption, number, option1, line)!= NULL){
                strcpy(*option1,checkOption("option1", &numberOption, number, option1, line));
            }
            else if(checkOption("option2", &numberOption, number, option2, line)!= NULL ){
                strcpy(*option2,checkOption("option2", &numberOption, number, option2, line));
            }
            else if(checkOption("option3", &numberOption, number, option3, line)!= NULL ){
                strcpy(*option3,checkOption("option3", &numberOption, number, option3, line));
            }
            else if(checkOption("option4", &numberOption, number, option4, line)!= NULL ){
                strcpy(*option4,checkOption("option4", &numberOption, number, option4, line));
            }
            else if(checkOption("option5", &numberOption, number, option5, line)!= NULL){
                strcpy(*option5,checkOption("option5", &numberOption, number, option5, line));
            }
        }
    }
    // Ici on peut mettre notre attribution des options (structure etc.. )
    /**
     * En gros on on crée nos options ici comme ça c'est plus simple pour toi
     * Sinon il suffit juste de les recup apres la sortie de getOption ctoi qu vois comment tu geres ça !
     * */
    if(*option1){
        strcpy(*option1, removeEnd(*option1));
    }
    else if (*option2){
        strcpy(*option2, removeEnd(*option2));
    }
    else if (*option3){
        strcpy(*option3, removeEnd(*option3));
    }
    else if (*option4){
        strcpy(*option4, removeEnd(*option4));
    }
    else if(*option5){
        strcpy(*option5, removeEnd(*option5));
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
