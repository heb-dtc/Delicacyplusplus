#include <stdio.h>
#include <string.h>
#include "simpleLinkedList.h"
#include "simpleNode.h"

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

int main(int argc, char* argv[]) 
{
	//test the reverse string routine
	char input[] = "Hello World!";
	printf("Original string: %s\n", input);
	reverseString(input);
	printf("Reversed string: %s\n", input);

	//test the SimpleLinkedList
	SimpleLinkedList *list = new SimpleLinkedList();
	list->walkThrough();

	SimpleNode *node = new SimpleNode(101);
	list->insertAfter(node, NULL);
	list->walkThrough();

	//cleanup
	delete list;
	delete node;
}