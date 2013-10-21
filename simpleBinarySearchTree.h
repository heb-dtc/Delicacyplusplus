#include "BinaryTreeNode.h"

class SimpleBinarySearchTree
{
private:
	BinaryTreeNode *mRoot;

public:
	SimpleBinarySearchTree()
	{
		mRoot = NULL;
	}

	bool add(int value);
	bool search(int value);
	bool remove(int value);
};