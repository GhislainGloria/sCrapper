/*
 * action.h
 *
 *  Created on: 18 oct. 2019
 *      Author: hejar
 */

#ifndef ACTION_H_
#define ACTION_H_



typedef struct{
	char* name;
	char* url;
	int nbrCurrentOption;
	int tabOptionLenght;
	Option **tabOption; //tableau de pointeur d'option
}Action;


Action *initAction();

int addNameAction(Action *action, char *name);

int addUrl(Action *action, char *url);

int addOption(Action *action, Option *option);

void delAction(Action *action);
int countAllAction(char *);



#endif /* ACTION_H_ */
