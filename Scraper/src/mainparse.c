#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>
#include <time.h>
#include "parse.h"
#include "option.h"
#include "action.h"
#include "critere.h"
#include "task.h"
#include "controllerTask.h"
#include "scraper.h"




Action **createActions(char *fpp, int numberOfAction){
	Action **tab;
	tab = malloc(sizeof(CHARP_SIZE)*50);

	for(int i = 0; i<numberOfAction; i++){
		Action *action = initAction();

		char *nameAction = malloc(sizeof(char) * 255);
		char *urlAction = malloc(sizeof(char) * 255);
		char * o1 = malloc(sizeof(char)*50);
		char * o2= malloc(sizeof(char)*50);;
		char * o3= malloc(sizeof(char)*50);;



		nameAction = getAction("name", i,"files/param.sconf");
		urlAction = getAction("url", i,"files/param.sconf");

		Option *opt1 = initOption();
		Option *opt2 = initOption();
		Option *opt3 = initOption();
		Option *opt4 = initOption();
		Option *opt5 = initOption();

		addKey(opt1,"option1");
		addKey(opt2,"option2");
		addKey(opt3,"option3");
		addKey(opt4,"option4");
		addKey(opt5,"option5");


		if(countActionOption(i,fpp) > 0){
			GetOption(i, &o1, &o2,  &o3, fpp );

			addValue(opt1,o1);
			addValue(opt2,o2);
			addValue(opt3,o3);


		}else{
			addValue(opt1,NULL);
			addValue(opt2,NULL);
			addValue(opt3,NULL);

		}


		addNameAction(action,nameAction);
		addUrl(action,urlAction);
		addOption(action,opt1);
		addOption(action,opt2);
		addOption(action,opt3);




		tab[i] = action;
	}
	return tab;

}




Task **createTasks(char *fpp,int numberOfTask){
	Task **tabl;
	tabl = malloc(sizeof(CHARP_SIZE)*50);
	for(int i = 0;i<numberOfTask;i++){
		Task *task = initTask();

		char *nameTask = malloc(sizeof(char) * 255);
		char * h =  malloc(sizeof(char) * 255);
		char * m = malloc(sizeof(char) * 255);
		char * s =  malloc(sizeof(char) * 255);

 		nameTask = getTaskInfo("name",i,"files/param.sconf");
 		h = getTaskInfo("hour",i,"files/param.sconf");
 		m = getTaskInfo("minute",i,"files/param.sconf");
 		s = getTaskInfo("second",i,"files/param.sconf");

 		char ** t ;//= malloc(sizeof(char*)*255);
 		t = getTaskAction(i,"files/param.sconf");
 		addActionTempName(task,t[0]);

 		Criterion *criterion = initCriterion();
 		addHour(criterion,(int)h);
 		addMinute(criterion,(int)m);
 		addSecond(criterion,(int)s);

		addNameTask(task,nameTask);
		addCriterion(task,criterion);

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





void delTabAllTask(Task **tab,int tabLength){
	if(tab == NULL){
			printf("No tab to free");
		}
	for(int i = 0; i<tabLength;i++){
		delTask(tab[i]);
	}
}





int main(){

	char *fileName = "files/param.sconf";
	int countTotalAction = 0;
	int countTotalTask = 0;

//A      C      T      I      O       N
	countTotalAction = countAllAction(fileName);
	printf("Il y a %d actions au total\n",	countTotalAction);
	printf("\n");



	Action **tabAllAction = malloc(sizeof(Action*)*	countTotalAction);
	tabAllAction = createActions(fileName,	countTotalAction);


	for(int i = 0; i<countTotalAction;i++){
		printf("%s\n",tabAllAction[i]->name);
		printf("%s\n",tabAllAction[i]->url);
		//printf("L'action a %d options\n",countActionOption(i,fileName));
		//printf(" %s\n",tabAllAction[i]->tabOption[0]->value[tabAllAction[i]->tabOption[0]->nbreCurrentValue -1]);
		scrap(tabAllAction[i]->url,",", tabAllAction[i]->name);
		printf("\n");
	}




//T      A      S      K
	countTotalTask = countAllTask(fileName);
	printf("Il y a %d tâches au total\n",	countTotalTask);
	printf("\n");


	Task **tabAllTask = malloc(sizeof(Task*)* countTotalTask);
	tabAllTask = createTasks(fileName, countTotalTask);


	for(int i = 0; i<countTotalTask;i++){
			//addAction(tabAllTask[i], searchInTabOFAction(t, tabAllAction, countTotalAction));

			printf("Cette tâche s'appelle %s\n",tabAllTask[i]->name);

			printf(" Les critères de la taches sont\n");
			//printf("  Heure : %s",tabAllTask[i]->criterion->hour);
			//printf("  Minute : %s",tabAllTask[i]->criterion->minute);
			//printf("  Second : %s",tabAllTask[i]->criterion->second);
			printf("Les pseudo-actions sont %s\n",tabAllTask[i]->actionNameTemp);
			printf("\n");
	}


//F      R      E      E

	delTabAllAction(tabAllAction,countTotalAction);
	//delTabAllTask(tabAllTask, countTotalTask);
	return 0;
}







