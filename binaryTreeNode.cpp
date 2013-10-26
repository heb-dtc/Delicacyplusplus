#include "binaryTreeNode.h"
#include <cstring>

BinaryTreeNode::BinaryTreeNode(int value)
{
	mValue = value;
	mLeftNode = NULL;
	mRightNode = NULL;
}

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
	if(mLeftNode == NULL)
		return mValue;
	return mLeftNode->getMinValue();
}

BinaryTreeNode *BinaryTreeNode::remove(int value, BinaryTreeNode *parent)
{
	if(value < mValue)
	{
		if(mLeftNode != NULL)
		{
			return mLeftNode->remove(value, this);
		}
		else 
			return NULL;
	}
	else if(value > mValue)
	{
		if(mRightNode != NULL)
		{
			return mRightNode->remove(value, this);
		}
			else 
				return NULL;
	}
	else
	{
		if(mLeftNode != NULL && mRightNode != NULL)
		{
			mValue = mRightNode->getMinValue();
			return mRightNode->remove(mValue, this);
		}
		else if(parent->mLeftNode == this)
		{
			parent->mLeftNode = (mLeftNode != NULL) ? mLeftNode : mRightNode;
            return this;
        } 
        else if (parent->mRightNode == this) {
                  parent->mRightNode = (mLeftNode != NULL) ? mLeftNode : mRightNode;
                  return this;
            }
	}
}