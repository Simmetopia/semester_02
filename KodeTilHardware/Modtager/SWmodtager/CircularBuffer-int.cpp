#include <iostream>

using namespace std;

#include "CircularBuffer-int.h"


CircularBuffer::CircularBuffer( int s )
{
	size_ = ( s>0 ? s : 8);

		arrayPtr_ = new int[size_];  // This will not initialize integers


	// Initialize
	for( int i=0; i<size_; i++ )
		arrayPtr_[i] = 0;

	newestIndex_ = -1;
}


CircularBuffer &CircularBuffer::insert( int element )
{
	(++newestIndex_) %= size_;
	arrayPtr_[newestIndex_] = element;
	return *this;
}


double CircularBuffer::meanValue( ) const
{
	int sum = 0;

	for(int j=0; j<size_; j++ )
		sum += arrayPtr_[j];
	
	return ( (double) sum/size_ );
}


CircularBuffer::~CircularBuffer()
{
	delete [] arrayPtr_;
}
