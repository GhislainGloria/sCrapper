/*
 * task.c
 *
 *  Created on: 19 oct. 2019
 *      Author: hejar
 */


#include <stdio.h>
#include <stdlib.h>
#include "option.h"
#include "action.h"
#include "critere.h"
#include "task.h"

Task *initTask(){
	Task *task = malloc(sizeof(Task));
	if(task == NULL){
		printf("Problem to malloc Task");
		exit(1);
	}
	task->criterion = malloc(sizeof(Criterion));
	task->nbrCurrentAction = 0;
	task->tabActionLength = 5;
	task->actionNameTemp = malloc(sizeof(char)*255);
	task->tabAction = malloc(sizeof(Action*)*task->tabActionLength);
	return task;
}



int addNameTask(Task* task, char* name){
	if(task == NULL){
		printf("No task");
		exit(1);
	}
	task->name = name;
	return 0;
}


int addCriterion(Task *task, Criterion *criterion){
	if(task == NULL){
		printf("No task");
		exit(1);
	}
	if(criterion == NULL){
		printf("No criterion to add");
		exit(1);
	}
	task->criterion = criterion;
	return 0;
}

int addActionTempName(Task *task, char *name){
	if(task == NULL){
			printf("No task");
			exit(1);
	}
	task->actionNameTemp = name;
	return 0;
}

int addAction(Task *task, Action *action){
	if(task == NULL){
		printf("No task");
		exit(1);
	}
	if(action == NULL){
		printf("No action to add");
		exit(1);
	}
	if(task->nbrCurrentAction >= task->tabActionLength){
		printf("So much Action");
		exit(1);
	}
	task->tabAction[task->nbrCurrentAction] = action;
	task->nbrCurrentAction++;
	return 0;
}



void delTask(Task *task){
	if(task == NULL){
		printf("Nothing to free");
		exit(1);
	}
	if(task->nbrCurrentAction > 0){
		for(int i = 0; i<task->nbrCurrentAction;i++){
			free(task->tabAction[i]);
		}
	}
	free(task->criterion);
	free(task->tabAction);
	free(task);
}

/*

int main(int argc, char* argv[]){

	Criterion* c1 = initCriterion();
	addHour(c1, 15);
	addSecond(c1, 30);

	Action* a1 = initAction();
	addNameAction(a1,"Mon action");


	Action* a2 = initAction();
	addNameAction(a2,"Mon bobo");



	Task *t1 = initTask();
	addNameTask(t1,"Ma Super Tâlklkche");
	addCriterion(t1,c1);
	addAction(t1,a1);
	addAction(t1,a2);


	printf("==\n");
	printf("name -> %s\n",t1->name);
	printf("Hour -> %d\n",t1->criterion->hour);
	printf("Minute -> %d\n",t1->criterion->minute);
	printf("Second -> %d\n",t1->criterion->second);
	printf("+\n");
	printf("(");

	for(int i = 0; i<t1->nbrCurrentAction;i++){
		printf("%s,",t1->tabAction[i]->name);
	}
	printf(")");


	delTask(t1);

	return EXIT_SUCCESS;
}

*/

