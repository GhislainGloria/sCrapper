/*
 * option.h
 *
 *  Created on: 18 oct. 2019
 *      Author: hejar
 */

#ifndef OPTION_H_
#define OPTION_H_





typedef struct{
	char* key;
	int nbreCurrentValue;
	int valueTabLength;
	char **value;
}Option;


Option *initOption();

int addKey(Option *option, char *key );

int addValue(Option *option, char *value);

void delOption(Option *option);

#endif /* OPTION_H_ */
