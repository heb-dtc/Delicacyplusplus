#include <stdio.h>
#include <string.h>
#include "simpleLinkedList.h"

//take a string in input and reverse it
void reverseString(char input[])
{
	int length = strlen(input);
	int lastPos = length-1;

	for(int i=0 ; i < length/2 ; i++)
	{
		char c = input[i];
		input[i] = input[lastPos];
		input[lastPos] = c;

		lastPos--;
	}
}

void testSimpleLinkedList()
{
	SimpleLinkedList *list = new SimpleLinkedList();
	list->walkThrough();

	SimpleNode *nodeA = new SimpleNode(101);
	SimpleNode *nodeB = new SimpleNode(102);
	SimpleNode *nodeC = new SimpleNode(103);
	SimpleNode *nodeD = new SimpleNode(104);
	SimpleNode *nodeE = new SimpleNode(105);

	list->insertAfter(nodeA, NULL);
	list->walkThrough();

	list->insertAfter(nodeB, nodeA);
	list->insertAfter(nodeC, nodeB);
	list->walkThrough();

	list->addHead(nodeD);
	list->walkThrough();

	list->addTail(nodeE);
	list->walkThrough();

	list->removeNext(nodeA);
	list->walkThrough();

	list->removeNext(nodeD);
	list->walkThrough();

	//cleanup
	delete nodeA;
	delete nodeB;
	delete nodeC;
	delete nodeD;
	delete nodeE;	
	delete list;
}

int main(int argc, char* argv[]) 
{
	//test the reverse string routine
	char input[] = "Hello World!";
	printf("Original string: %s\n", input);
	reverseString(input);
	printf("Reversed string: %s\n", input);

	//test the SimpleLinkedList
	testSimpleLinkedList();
}