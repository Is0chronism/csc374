//header.h

/*-------------------------------------------------------------------------*
 *---									---*
 *---		header.h						---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 January 2		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

extern void countWithList();
extern void countWithTree();
extern int getNextNumber();


#define		MAX_LINE	256

#define		RANGE_LOWEST	0

#define		RANGE_HIGHEST	32767

#define		MIN_NUM_NUMBERS	0

#define		MAX_NUM_NUMBERS	0x40000000