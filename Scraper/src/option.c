/*
 * option.c
 *
 *  Created on: 17 oct. 2019
 *      Author: hejar
 */

#include <stdio.h>
#include <stdlib.h>
#include "option.h"


Option *initOption(){
	Option *option = malloc(sizeof(Option));
	if(option == NULL){
		printf("Problem to malloc Option");
		exit(1);
	}
	option->nbreCurrentValue = 0;
	option->valueTabLength = 5;
	option->value = malloc(sizeof(char*)* option->valueTabLength);

	return option;
}




int addKey(Option *option, char *key ){
	if(option == NULL){
		printf("No option");
		exit(1);
	}
	option->key = key;
	return 0;
}





int addValue(Option *option, char *value){

	if(option == NULL){
			printf("No option");
			exit(1);
	}
	if(option->nbreCurrentValue >= option->valueTabLength){
		printf("So much value");
		exit(1);
	}
	option->value[option->nbreCurrentValue] = value;
	option->nbreCurrentValue++;
	return 0;
}





void delOption(Option *option){
	if(option == NULL){
		printf("Nothing to free");
		exit(1);
	}
	free(option->value);
	free(option);
}


/*

int main(int argc, char* argv[]){
	Option *o = initOption();
	addKey(o,"Key1");
	addValue(o,"V1");
	addValue(o,"V2");
	addValue(o,"V3");
	addValue(o,"V4");
	addValue(o,"V5");

	printf("(%s ",o->key);
	printf("->");
	for(int i = 0; i< o->nbreElement;i++){
		printf(" %s",o->value[i]);
	}
	printf(")\n");

	Option *o2 = initOption();
	addKey(o2,"Key1");
	addValue(o2,"V7");
	addValue(o2,"V8");
	addValue(o2,"V9");
	addValue(o2,"V12");
	addValue(o2,"V14");
	addValue(o2,"V14");
	addValue(o2,"V14");
	addValue(o2,"V14");
	addValue(o2,"V14");
	addValue(o2,"V14");

	printf("(%s ",o2->key);
	printf("->");
	for(int i = 0; i< o2->nbreElement;i++){
		printf(" %s",o2->value[i]);
	}
	printf(")");



	delOption(o);
	delOption(o2);
	return EXIT_SUCCESS;
}
*/



