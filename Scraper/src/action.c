/*
 * action.c
 *
 *  Created on: 18 oct. 2019
 *      Author: hejar
 */

#include <stdio.h>
#include <stdlib.h>
#include "option.h"
#include "action.h"


Action *initAction(){
	Action *action = malloc(sizeof(Action));
	if(action == NULL){
		printf("Problem to malloc Action");
		exit(1);
	}
	action->nbrCurrentOption = 0;
	action->tabOptionLenght = 5;
	action->tabOption = malloc(sizeof(Option*)* action->tabOptionLenght);

	return action;
}



int addNameAction(Action *action, char *name){
	if(action == NULL){
		printf("No action");
		exit(1);
	}
	action->name = name;
	return 0;
}




int addUrl(Action *action, char *url){
	if(action == NULL){
			printf("No action");
			exit(1);
		}
	action->url = url;
	return 0;
}


int addOption(Action *action, Option *option){
	if(action == NULL){
		printf("No action");
		exit(1);
	}
	if(option == NULL){
		printf("No option to add");
		exit(1);
	}

	if(action->nbrCurrentOption >= action->tabOptionLenght){
			printf("So much Option");
			exit(1);
	}
	action->tabOption[action->nbrCurrentOption] = option;
	action->nbrCurrentOption++;
	return 0;

}




void delAction(Action *action){
	if(action == NULL){
		printf("Nothing to free");
		exit(1);
	}
	free(action->name);
	free(action->url);
	for(int i = 0; i<action->nbrCurrentOption; i++){
		delOption(action->tabOption[i]);
	}
	free(action->tabOption);
	free(action);
}





/*

int main(int argc, char* argv[]){
	Option *o = initOption();
	addKey(o,"Key1");
	addValue(o,"V1");
	addValue(o,"V2");
	addValue(o,"V3");
	addValue(o,"V4lklk");
	addValue(o,"V5lklkkl");

	Option *o2 = initOption();
	addKey(o2,"Key2");
	addValue(o2,"AA");
	addValue(o2,"ZZ");
	addValue(o2,"12");
	addValue(o2,"AZklk");
	addValue(o2,"VAZl");




	Action *a = initAction();
	addNameAction(a, "firstAction");
	addUrl(a, "http://www.google.fr");
	addOption(a,o);
	addOption(a,o2);



	printf("=\n");
	printf("{Name -> %s}\n",a->name);
	printf("{Url -> %s}\n",a->url);
	printf("+\n");

	for(int i = 0; i < a->nbrCurrentOption; i++){
		printf("{ %s",a->tabOption[i]->key);
		printf(" ->");
		for(int j = 0; j<a->tabOption[i]->nbreCurrentValue;j++){
			printf(" %s ",a->tabOption[i]->value[j]);
		}
		printf("}\n");
	}


	delAction(a);
	return EXIT_SUCCESS;
}

*/



