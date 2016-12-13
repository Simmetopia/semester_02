// Projekt		øvelser 2. semester
//
// Fil			CircularBuffer-int.h
//
// Beskrivelse	Interface til klassen CircularBuffer
//
// Forfatter	NVJ
//
// Version		1.0 - 120905 - oprindelig version

#pragma once


class CircularBuffer
{
public:
	CircularBuffer( int=10 );
	CircularBuffer &insert( int );
	double meanValue( ) const;
	void print( ) const;
	~CircularBuffer();
private:
	int *arrayPtr_;
	int size_;
	int newestIndex_;
};