#include "dynamikArray.h"
#include <cstring>

//Extend the capacity of the internal Array with the new capacity provided:
//	- allocate some new memory
//  - copy the values from the internal array to the new array
//	- clean up old memory
//  - make the internal array points to the newly allocated memory
void DynamikArray::setCapacity(int newCapacity)
{
	int *extendedArray =  new int[newCapacity];
	memcpy(extendedArray, mArray, sizeof(int) * mSize);
	mCapacity = newCapacity;
	delete[] mArray;
	mArray = extendedArray;
}

// Make sure the internal array capacity is gt the minCapacity provided.
// if not, the internal array is extended.
void DynamikArray::ensureCapacity(int minCapacity)
{
	if(minCapacity > mCapacity)
	{
		//compute new capacity (1.5 factor)
		int newCapacity = mCapacity*1.5;
		if(newCapacity < minCapacity) 
			//if still not enough, the minCapacity is used
			newCapacity = minCapacity;
		setCapacity(newCapacity);
	}
}

// Reduce the capacity of the internal array if the size is less than 
// half of the capacity. This is done to avoid having a lot of allocated
// memory not being used.
void DynamikArray::pack()
{
	if(mSize <= mCapacity/2)
	{
		int newCapacity = mSize / 1.5;
		setCapacity(newCapacity);
	}
}

// Reduce capacity of the internal array to fit exactly the amount 
// of items in the array.
void DynamikArray::trim()
{
	int newCapacity = mSize;
	setCapacity(newCapacity);
}

// Check that the index provided is within the bounds of the internal array.
void DynamikArray::rangeCheck(int idx)
{
	if(idx < 0 || idx >= mSize)
		throw "Index out of bounds!";
}

// Set the value provided at the index provided.
void DynamikArray::set(int idx, int value)
{
	rangeCheck(idx);
	mArray[idx] = value;
}

// Return the value set at the provided index.
int DynamikArray::get(int idx)
{
	rangeCheck(idx);
	return mArray[idx];
}

// Insert the new value at the given index.
// Make sure the internal capacity of the array is enough.
// Take care of moving all the element of the array to make space for the new value;
void DynamikArray::insert(int idx, int value)
{
	if(idx < 0 || idx > mSize)
		throw "Index out of bounds!";

	ensureCapacity(mSize+1);

	int moveNr = mSize - idx;
	if(moveNr > 0)
		memmove(mArray + idx + 1, mArray + idx, sizeof(int) * moveNr);
	mArray[idx] = value;
	mSize++;
}

// Delete the value at the given index.
// Take care of moving all the element of the array to fill the space for the new value;
void DynamikArray::deleteAt(int idx)
{
	rangeCheck(idx);
	int moveNr = mSize - idx - 1;
	if(moveNr > 0)
		memmove(mArray + idx, mArray + (idx + 1), sizeof(int) * moveNr);
	mSize--;
	pack();
}