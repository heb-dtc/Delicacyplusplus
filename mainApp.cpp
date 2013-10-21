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

//reursive routine to compute the factorial of a given number
int fact(int value)
{
	if(value <= 1)
		return value;

	return value * fact(value - 1);
}

// Compute and print multiplication tables up to the provided max value.
void printMultTable(int max)
{
	for(int i=1 ; i <= max ; i++)
	{
		for(int y=1 ; y <=max ; y++)
		{
			printf("%d  ", i*y);
		}
		printf("\n");
	}
}

// Print out odd numbers from 1 till the max provided
void printOdds(int max)
{
	for(int i=0 ; i <= max ; i++)
	{
		if(i%2 != 0)
			printf("%d \n", i);
	}

}

// Merge the two arrays provided (A, B) into a third one(C)
// Both A and B need to be sorted. 
// Result in C is also sorted
void mergeSortedArrays(int sizeA, int sizeB, int *a, int *b, int *c)
{
	int i = 0;
	int j = 0;
	int k = 0;

	//Merge the two until we reach the end of A or B
	while(i<sizeA && j<sizeB)
	{
		if(a[i] < b[j])
		{
			c[k] = a[i];
			i++;
		}
		else 
		{
			c[k] = b[j];
			j++;
		}
		k++;
	}

	//the while is over, the end of one array was reached
	//the rest of the remaining array will now be copied over in C
	if(i<sizeA) //is it A
	{
		for(int p=i ; p<sizeA ;p++)
		{
			c[k] = a[p];
			k++;
		}
	}
	else //or is it B
	{
		for(int p=i ; p<sizeB ;p++)
		{
			c[k] = b[p];
			k++;
		}
	}
}

void testMergeSortedArrays()
{
	int sizeA = 5;
	int sizeB = 9;

	int sizeC = 5+9;

	int *a = new int[sizeA];
	int *b = new int[sizeB];
	int *c = new int[sizeC];

	a[0] = 5;
	a[1] = 8;
	a[2] = 15;
	a[3] = 22;
	a[4] = 42;

	b[0] = 3;
	b[1] = 6;
	b[2] = 17;
	b[3] = 21;
	b[4] = 32;
	b[5] = 39;
	b[6] = 50;
	b[7] = 65;
	b[8] = 72;

	mergeSortedArrays(sizeA, sizeB, a, b, c);

	for(int i=0 ; i<sizeC ; i++)
	{
		printf("%d ", c[i]);
	}

	//clean up
	delete[] a;
	delete[] b;
	delete[] c;
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

	int res = fact(10);
	printf("10! = %d\n", res);

	res = fact(5);
	printf("5! = %d\n", res);

	//printMultTable(12);

	//printOdds(99);

	testMergeSortedArrays();
}