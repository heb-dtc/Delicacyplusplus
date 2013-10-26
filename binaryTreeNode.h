class BinaryTreeNode
{
public:
	int mValue;
	BinaryTreeNode *mLeftNode;
	BinaryTreeNode *mRightNode;

	BinaryTreeNode(int value);

	bool add(int value);
	bool search(int value);
	int getMinValue();
	BinaryTreeNode *remove(int value, BinaryTreeNode *parent);
};