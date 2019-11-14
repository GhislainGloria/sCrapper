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

		char *nameAction = malloc(sizeof(char) * 255);
		char *urlAction = malloc(sizeof(char) * 255);

		nameAction = getAction("name", i,"files/param.sconf");
		urlAction = getAction("url", i,"files/param.sconf");

		addNameAction(action,nameAction);
		addUrl(action,urlAction);
		tab[i] = action;
	}
	return tab;

}




Task **createTasks(char *fpp,int numberOfTask){
	Task **tabl;
	for(int i = 0;i<numberOfTask;i++){
		Task *task = initTask();

		char *nameTask = malloc(sizeof(char) * 255);
		//char * h =  malloc(sizeof(char) * 255);
		//char * m = malloc(sizeof(char) * 255);
		//char * s =  malloc(sizeof(char) * 255);
 		nameTask = getTaskInfo("name",i,"files/param.sconf");
 		//h = getTaskInfo("hour",i,"files/param.sconf");
 		//m = getTaskInfo("minute",i,"files/param.sconf");
 		//s = getTaskInfo("second",i,"files/param.sconf");

 		//Criterion *criterion = initCriterion();
 		//addHour(criterion,h);
 		//addMinute(criterion,m);
 		//addSecond(criterion,s);

		addNameTask(task,nameTask);
		//addCriterion(task,criterion);

		tabl[i] = task;
	}
	return tabl;
}









void delTabAllAction(Action **tab, int tabLength){
	if(tab == NULL){
		printf("No tab to free");
	}
	for(int i = 0; i<tabLength;i++){
		delAction(tab[i]);
	}
}





void delTabAllTask(Task **tab){
	if(tab == NULL){
		printf("No tab to free");
	}
	free(tab);

}





int main(){

	char *fileName = "files/param.sconf";
	int countTotalAction = 0;
	int countTotalTask = 0;

//A   C   T   I   O    N
	countTotalAction = countAllAction(fileName);
	printf("Il y a %d actions au total\n",	countTotalAction);
	printf("\n");



	Action **tabAllAction = malloc(sizeof(Action*)*	countTotalAction);
	tabAllAction = createActions(fileName,	countTotalAction);


	for(int i = 0; i<countTotalAction;i++){
		printf("Cette action s'appelle %s\n",tabAllAction[i]->name);
		printf("Son url est %s\n",tabAllAction[i]->url);
		printf("L'action a %d options\n",countActionOption(i,fileName));
		printf("\n");
	}


//T   A   S   K
	countTotalTask = countAllTask(fileName);
	printf("Il y a %d tâches au total\n",	countTotalTask);
	printf("\n");


	Task **tabAllTask = malloc(sizeof(Task*)* countTotalTask);
	tabAllTask = createTasks(fileName, countTotalTask);

	for(int i = 0; i<countTotalTask;i++){
			printf("Cette tâche s'appelle %s\n",tabAllTask[i]->name);
			printf(" Les critères de la taches sont\n");
			//printf("  Heure : %s",tabAllTask[i]->criterion->hour);
			//printf("  Minute : %s",tabAllTask[i]->criterion->minute);
			//printf("  Second : %s",tabAllTask[i]->criterion->second);
			printf("\n");
	}


//F   R   E   E

	delTabAllAction(tabAllAction,countTotalAction);
	delTabAllTask(tabAllTask);
	return 0;
}







