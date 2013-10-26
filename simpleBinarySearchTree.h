#include "binaryTreeNode.h"

class SimpleBinarySearchTree
{
private:
	BinaryTreeNode *mRoot;

public:
	SimpleBinarySearchTree();

	bool add(int value);
	bool search(int value);
	bool remove(int value);
};