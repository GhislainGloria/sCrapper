/*
 * controllerTask.h
 *
 *  Created on: 19 oct. 2019
 *      Author: hejar
 */

#ifndef CONTROLLERTASK_H_
#define CONTROLLERTASK_H_


typedef struct{
	int nbreCurrentTask;
	int tabTaskLength;
	Task **tabTask;
}ControllerTask;



ControllerTask *initController();

int addTask(ControllerTask *controllerTask, Task *task);

void delControllerTask(ControllerTask *controllerTask);


#endif /* CONTROLLERTASK_H_ */
