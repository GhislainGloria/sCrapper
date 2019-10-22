/*
 * critere.c
 *
 *  Created on: 17 oct. 2019
 *      Author: hejar
 */
#include <stdio.h>
#include <stdlib.h>
#include "critere.h"




Criterion *initCriterion(){
	Criterion *criterion = malloc(sizeof(Criterion));
	if(criterion == NULL){
		printf("Problem to malloc Criterion");
		exit(1);
	}
	criterion->hour = 0;
	criterion->minute = 0;
	criterion->second = 0;
	return criterion;
}


int addHour(Criterion *criterion, int hour){
	if(criterion == NULL){
		printf("No criterion ");
		exit(1);
	}
	if(hour < 0){
		printf("Negative hour");
		exit(1);
	}
	criterion->hour = hour;
	return 0;

}




int addMinute(Criterion *criterion, int minute){
	if(criterion == NULL){
		printf("No criterion ");
		exit(1);
	}
	if(minute < 0){
		printf("Negative minute");
		exit(1);
	}
	if(minute >= 60){
		addHour(criterion, criterion->hour+(minute/60));
		criterion->minute = minute%60;
	}else{
		criterion->minute = minute;
	}
	return 0;

}




int addSecond(Criterion *criterion, int second){
	if(criterion == NULL){
		printf("No criterion ");
		exit(1);
	}
	if(second < 0){
		printf("Negative second");
		exit(1);
	}
	if(second >= 60){
		addMinute(criterion,criterion->minute+(second/60));
		criterion->second = second%60;
	}else{
		criterion->second = second;
	}
	return 0;

}


void delCriterion(Criterion *c){
	free(c);
}

/*

int main(int argc, char* argv[]){
	Criterion *c = initCriterion();
	addHour(c,9);
	addMinute(c,58);
	addSecond(c,120);
	printf("Heure : %d\n",c->hour);
	printf("Minute : %d\n",c->minute);
	printf("Seconde : %d\n",c->second);

	delCriterion(c);

	return EXIT_SUCCESS;
}

*/
