#include <stdio.h>

class SimpleNode
{
public:
	int mValue;
	SimpleNode *mNext;

	SimpleNode(int val)
	{
		mValue = val;
		mNext = NULL;
	}

	void printNode()
	{
		printf("Node value: %d\n", mValue);
	}
};