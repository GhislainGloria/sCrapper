/*
 * task.h
 *
 *  Created on: 19 oct. 2019
 *      Author: hejar
 */

#ifndef TASK_H_
#define TASK_H_


typedef struct{
	char *name;
	Criterion *criterion;
	int nbrCurrentAction;
	int tabActionLength;
	char *actionNameTemp;   //Will be compared with all of Actions
 	Action **tabAction;
}Task;


Task *initTask();

int addNameTask(Task* task, char* name);

int addCriterion(Task *task, Criterion *criterion);

int addActionTempName(Task *task, char *name);

int addAction(Task *task, Action *action);

void delTask(Task *task);

#endif /* TASK_H_ */
