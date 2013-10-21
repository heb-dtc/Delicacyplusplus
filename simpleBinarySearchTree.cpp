#include "simpleBinarySearchTree.h"

bool SimpleBinarySearchTree::add(int value)
{
	if(mRoot == NULL)
	{
		mRoot = new BinaryTreeNode(value);
		return true;
	}
	return mRoot->add(value);
}

bool SimpleBinarySearchTree::search(int value)
{
	if(mRoot == NULL)
		return false;
	return mRoot->search(value);
}

bool SimpleBinarySearchTree::remove(int value)
{
	if(mRoot == NULL)
		return false;
	else
	{
		if(mRoot->mValue == value)
		{
			BinaryTreeNode tmpNode(0);
			tmpNode.mLeftNode = mRoot;
			BinaryTreeNode *removedNode = mRoot->remove(value, &tmpNode);
			mRoot = tmpNode.mLeftNode;
			if(removedNode != NULL)
			{
				delete removedNode;
				return true;
			}
			else
				return false;
		}
		else
		{
			BinaryTreeNode *removedNode = mRoot->remove(value, NULL);
			if(removedNode != NULL)
			{
				delete removedNode;
				return true;
			}
			else
				return false;
		}
	}
}