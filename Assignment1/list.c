list.c

/*-------------------------------------------------------------------------*
 *---									---*
 *---		list.c							---*
 *---									---*
 *---	    This file defines struct(s) and functions for counting	---*
 *---	randomly-generated integers in a linked list.			---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 January 2		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/

#include	"header.h"

//  PURPOSE:  To hold elements of a linked list that holds counts of integers.
struct		ListElement
{
  int			item_;
  int			count_;
  struct ListElement*	nextPtr_;
};


//  PURPOSE:  To count the occurrence of 'numNums' numbers generated by
//	'getNextNumber()'.  Returns linked list with counts.
struct ListElement*
		generateList	(int	numNums
				)
{
  struct ListElement*	toReturn	= NULL;
  struct ListElement*	prev;
  struct ListElement*	run;
  int	 		i;

  for  (i = 0;  i < numNums;  i++)
  {
    int	nextNum	= getNextNumber();

    for  (prev=NULL, run=toReturn;  run!=NULL;  prev=run, run=run->nextPtr_)
      if  (run->item_ == nextNum)
      {
	run->count_++;
        break;
      }

    if  (run == NULL)
    {
      struct ListElement* newItemPtr = (struct ListElement*)
      	     		  	       malloc(sizeof(struct ListElement));

      newItemPtr->item_		= nextNum;
      newItemPtr->count_	= 1;
      newItemPtr->nextPtr_	= NULL;

      if  (prev == NULL)
        toReturn	= newItemPtr;
      else
	prev->nextPtr_	= newItemPtr;
    }

  }

  return(toReturn);
}


//  PURPOSE:  To print the list of counts pointed to by 'listPtr'.  No return
//	value.
void		printList	(struct ListElement*	listPtr
				)
{
  while  (listPtr != NULL)
  {
    printf("%d: %d time(s)\n",listPtr->item_,listPtr->count_);
    listPtr = listPtr->nextPtr_;
  }
}


//  PURPOSE:  To free the list pointed to by 'listPtr'.  No return value.
void		freeList	(struct ListElement*	listPtr
				)
{
  struct ListElement*	next;

  while  (listPtr != NULL)
  {
    next	= listPtr->nextPtr_;
    free(listPtr);
    listPtr	= next;
  }

}


//  PURPOSE:  To count the occurrence of 'numNums' numbers generated by
//	'getNextNumber()' and put the counts in a linked-list.  Prints this
//	list, and then free()s it.  No return value.
void		countWithList	(int	numNums
				)
{
  struct ListElement*	listPtr	= generateList(numNums);

  printList(listPtr);
  freeList (listPtr);
}