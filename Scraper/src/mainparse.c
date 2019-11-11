#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <time.h>
#include "parse.h"
#include "option.h"
#include "action.h"
#include "critere.h"
#include "task.h"
#include "controllerTask.h"




Action **createActions(char *fpp, int numberOfAction){
	Action **tab;
	for(int i = 0; i<numberOfAction; i++){
		Action *action = initAction();

		char *name = malloc(sizeof(char) * 255);
		char *url = malloc(sizeof(char) * 255);

		name = getAction("name", i,"files/param.sconf");
		url = getAction("url", i,"files/param.sconf");

		addNameAction(action,name);
		addUrl(action,url);
		tab[i] = action;
	}
	return tab;

}




void delTabAllAction(Action **tab, int tabLength){
	if(tab == NULL){
		printf("No tab to free");
	}
	for(int i = 0; i<tabLength;i++){
		delAction(tab[i]);
	}
}






int main(){
	char *fileName = "files/param.sconf";

	int countAction = countAllAction(fileName);
	printf("Il y a %d actions\n",countAction);
	printf("\n");


	Action **tabAllAction = malloc(sizeof(Action*)*countAction);
	tabAllAction = createActions(fileName,countAction);


	for(int i = 0; i<countAction;i++){
		printf("Cette action s'appelle%s\n",tabAllAction[i]->name);
		printf("Son url est %s\n",tabAllAction[i]->url);
		printf("L'action a %d options\n",countActionOption(i,fileName));
		printf("\n");
	}


	delTabAllAction(tabAllAction,countAction);
	printf("FINISH");
	return 0;
}







