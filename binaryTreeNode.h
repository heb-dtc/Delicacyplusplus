class BinaryTreeNode
{
private:
	int mValue;
	BinaryTreeNode *mLeftNode;
	BinaryTreeNode *mRightNode;
public:
	BinaryTreeNode(int value)
	{
		mValue = value;
		mLeftNode = NULL;
		mRightNode = NULL;
	}

	bool add(int value);
	bool search(int value);
	int getMinValue();
	BinaryTreeNode *remove(int value, BinaryTreeNode *parent);
};