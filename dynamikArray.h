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
		mArray = new int[mCapacity];
	}

	~DynamikArray()
	{
		delete[] mArray;
	}

	int getSize()
	{
		return mSize;
	}

	void setCapacity(int newCapacity);
	void ensureCapacity(int minCapacity);
	void pack();
	void trim();
	void rangeCheck(int idx);
	void set(int idx, int value);
	int get(int idx);
	void insert(int idx, int value);
	void deleteAt(int idx);
};