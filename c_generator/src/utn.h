/*
 * utn.h
 *
 *  Created on: Oct 6, 2020
 *      Author: toty
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getFloat(char*, char*, float*, int);
int utn_getFloatConMinMax(char*, char*, float*, float, float, int);
int utn_getInt(char*, char*, int*, int);
int utn_getIntConMinMax(char*, char*, int*, int, int, int);
int utn_isIntNumber(char*);
int utn_isFloatNumber(char *);
int utn_isAlphabetic(char*);
int utn_isNumeric(char*);
int utn_isAlphanumeric(char*);
int utn_getString(char*, char*, char*, int, int);
int utn_getStringWithNumbers(char*, char*, char*, int, int);
int utn_getStringWithOnlyNumbers(char*, char*, char*, int, int);
int utn_getStringWithNumbersAndSymbols(char*, char*, char*, int, int);
int myGets(char*, int);


#endif /* UTN_H_ */
