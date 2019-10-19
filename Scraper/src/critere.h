/*
 * critere.h
 *
 *  Created on: 18 oct. 2019
 *      Author: hejar
 */

#ifndef CRITERE_H_
#define CRITERE_H_


typedef struct{
	int hour;
	int minute;
	int second;
}Criterion;


Criterion *initCriterion();

int addHour(Criterion *criterion, int hour);

int addMinute(Criterion *criterion, int minute);

int addSecond(Criterion *criterion, int second);

void delCriterion(Criterion *c);




#endif /* CRITERE_H_ */
