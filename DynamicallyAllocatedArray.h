	#pragma once 
#include <stdlib.h>

typedef void* TElem;

typedef struct {
	int length;
	int capacity;
	TElem* elements;
}DynamicArray;

DynamicArray* createDynamicArray(int capacity);
void destroyDynamicArray(DynamicArray** dynamicArrayPointer);
int sizeOfArray(DynamicArray* dynamicArray);
void resizeArray(DynamicArray* dynamicArray);
void appendArray(DynamicArray* dynamicArray, TElem element);
int deleteArrayElementByIndex(DynamicArray* dynamicArray, int index);
int updateArrayElementByIndex(DynamicArray* dynamicArray, int index, TElem newElement);
TElem getElementByIndex(DynamicArray* dynamicArray, int index);