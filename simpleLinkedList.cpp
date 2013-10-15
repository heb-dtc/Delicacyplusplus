#include "simpleLinkedList.h"

void SimpleLinkedList::insertAfter(SimpleNode *newElem, SimpleNode *previous)
{
	if(newElem == NULL)
			return;

	if(previous == NULL) //no previous, newElem is Head
	{
		addHead(newElem);
	}
	else if(previous == mTail)//previous is Tail, new elem becomes new Tail
	{
		addTail(newElem);
	}
	else
	{
		newElem->mNext = previous->mNext;
		previous->mNext = newElem;
	}
}

// Add a node in first position
void SimpleLinkedList::addHead(SimpleNode *newElem)
{
	if(newElem == NULL)
			return;

	if(mHead == NULL) //if there is no head, it means the list is empty
	{
		//newElem is now the one and only node of the list
		newElem->mNext = NULL;
		mHead = newElem;
		mTail = newElem;
	}
	else //there is a head
	{
		//mNext node of newElem is the current Head
		newElem->mNext = mHead;
		//newElem becomes Head
		mHead = newElem;
	}
}

// Add a node in last position
void SimpleLinkedList::addTail(SimpleNode *newElem)
{
	if(newElem == NULL)
			return;

	//newElem is in last position, no mNext
	newElem->mNext = NULL; 

	if(mHead == NULL) //if there is no Head, it means the list is empty
	{
		mHead = newElem;
		mTail = newElem;
	}
	else
	{
		//mNext node of the current Tail is newElem
		mTail->mNext = newElem;
		//newELem becomes the new Tail
		mTail = newElem;
	}
}

void SimpleLinkedList::removeLast()
{
	if(mTail == NULL) //if Tail is NULL, the list is empty, nothing to do
		return;
	else
	{
		if(mHead == mTail) //HEAD and TAIL are the same, the list has one elem. only
		{
			mHead = NULL;
			mTail = NULL;
		}
		else //the list has several elements
		{ 
			SimpleNode *elem = mHead; 

			//loop over the list to get the node right before the TAIL
			while(elem->mNext != mTail)
				elem = elem->mNext;

			//set the new TAIL
			mTail = elem;
			mTail->mNext = NULL;
		}
	}
}

void SimpleLinkedList::removeFirst()
{
	if(mHead == NULL) //if Head is NULL, the list is empty, nothing to do
		return;
	else
	{
		if(mHead == mTail) //HEAD and TAIL are the same, the list has one elem. only
		{
			mHead = NULL;
			mTail = NULL;
		}
		else //the list has several elements, the new Head is the next node of the curennt Head
		{ 
			mHead = mHead->mNext;
		}
	}
}

void SimpleLinkedList::removeNext(SimpleNode *previous)
{
	if(previous == NULL) //previosu is NULL, remove the HEAD
		removeFirst();
	else if(previous->mNext == mTail) //new elem. of previous is Tail, remove Tail
		removeLast();
	else if(previous == mTail) //if previous is Tail, there is no next
		return;
	else
	{
		//make the new link
		previous->mNext = previous->mNext->mNext;
	}
}

void SimpleLinkedList::walkThrough()
{
	SimpleNode *node = mHead;
	int counter = 0;
	int sum = 0;

	while(node != NULL)
	{
		sum += node->mValue;

		printf("%d: ", counter);
		node->printNode();
		node = node->mNext;
	}

	printf("Total: %d\n", sum);
}