/*
 * controllerTask.c
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
#include "controllerTask.h"




ControllerTask *initController(){
	ControllerTask *controllerTask = malloc(sizeof(ControllerTask));
	if( controllerTask == NULL){
		printf("Problem to malloc controllerTask");
		exit(1);
	}
	controllerTask->nbreCurrentTask = 0;
	controllerTask->tabTaskLength = 5;
	controllerTask->tabTask = malloc(sizeof(Task)*controllerTask->tabTaskLength);
	return controllerTask;
}



int addTask(ControllerTask *controllerTask, Task *task){
	if(controllerTask == NULL){
		printf("No controllerTask");
		exit(1);
	}
	if(task == NULL){
		printf("No task to add");
		exit(1);
	}
	if(controllerTask->nbreCurrentTask >= controllerTask->tabTaskLength){
		printf("So much task");
		exit(1);
	}
	controllerTask->tabTask[controllerTask->nbreCurrentTask] = task;
	controllerTask->nbreCurrentTask++;
	return 0;
}






void delControllerTask(ControllerTask *controllerTask){
	if(controllerTask == NULL){
		printf("Nothing to free");
		exit(1);
	}
	for(int i = 0; i<controllerTask->nbreCurrentTask;i++){
		free(controllerTask->tabTask[i]);
	}
	free(controllerTask->tabTask);
	free(controllerTask);

}



void parse(char *fname){
	FILE *f = fopen(fname, "r");
	if(f != NULL){
		fseek(f,0,SEEK_SET);

		char c = fgetc(f);
		while(c != EOF){

			//si c est un = alors j'initialise une action vide
			//si c est un ...

		}


		fclose(f);

	}else{
		printf("Can't open file");
		exit(1);
	}
}




int main(int argc, char* argv[]){
	char *fname = "files/fconfig.sconf";
	parse(fname);
	return EXIT_SUCCESS;
}

/*

int main(int argc, char* argv[]){

		Task *t1 = initTask();
		addNameTask(t1,"Tâche 1");

		Task *t2 = initTask();
		addNameTask(t2,"Tâche 2");

		Task *t3 = initTask();
		addNameTask(t3,"Tâche 3");

		Task *t4 = initTask();
		addNameTask(t4,"Tâche 4");

		Task *t5 = initTask();
		addNameTask(t5,"Tâche 5");



		ControllerTask *ct = initController();
		addTask(ct,t1);
		addTask(ct,t2);
		addTask(ct,t3);
		addTask(ct,t4);
		addTask(ct,t5);



		printf("CONTROLLEUR TACHE\n");
		for(int i = 0; i<ct->nbreCurrentTask;i++){
			printf("  %s\n",ct->tabTask[i]->name);
		}

		delControllerTask(ct);
		return EXIT_SUCCESS;
}
*/
