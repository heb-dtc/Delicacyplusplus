#include "binaryTreeNode.h"

bool BinaryTreeNode::add(int value)
{
	if(value == mValue)
		return false;
	else if(value < mValue)
	{
		if(mLeftNode == NULL)
		{
			mLeftNode = new BinaryTreeNode(value);
			return true;
		}
		else
			return mLeftNode->add(value);
	}
	else if(value > mValue)
	{
		if(mRightNode == NULL)
		{
			mRightNode = new BinaryTreeNode(value);
			return true;
		}
		else
			return mRightNode->add(value);
	}
	return false;
}

bool BinaryTreeNode::search(int value)
{
	if(value == mValue)
		return true;
	else if(value < mValue)
	{
		if(mLeftNode == NULL)
			return false;
		else
			return mLeftNode->search(value);
	}
	else if(value > mValue)
	{
		if(mRightNode == NULL)
			return false;
		else
			return mRightNode->search(value);
	}
	return false;
}

int BinaryTreeNode::getMinValue()
{
	if(mLeft == NULL)
		return mValue;
	return mLeft->getMinValue();
}

BinaryTreeNode *BinaryTreeNode::remove(int value, BinaryTreeNode *parent)
{
	
}