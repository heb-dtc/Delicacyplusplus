class DynamikArray
{
private:
	int mSize; //size actually occupied by the data
	int mCapacity; //total capacity of the array

	int *mArray; //array holding the data 

public:
	DynamikArray(int initialCapacity)
	{
		mCapacity = initialCapacity;
		mSize = 0;
		mArray = new int[capacity];
	}

	~DynamikArray()
	{
		delete[] mArray;
	}

	int getSize()
	{
		return mSize;
	}
};