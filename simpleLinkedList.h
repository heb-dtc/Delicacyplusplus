#include "simpleNode.h"

class SimpleLinkedList
{
public:
	SimpleNode *mHead;
	SimpleNode *mTail;

	SimpleLinkedList()
	{
		mHead = NULL;
		mTail = NULL;
	}

	void insertAfter(SimpleNode *newElem, SimpleNode *previous);
	void addHead(SimpleNode *newElem);
	void addTail(SimpleNode *newElem);
	void removeFirst();
	void removeLast();
	void removeNext(SimpleNode *previous);
	void walkThrough();
};