#include "DynamicallyAllocatedArray.h"

DynamicArray* createDynamicArray (int capacity)
{
	DynamicArray* dynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));
	dynamicArray->length = 0;
	dynamicArray->capacity = capacity;
	dynamicArray->elements = (TElem*)malloc(sizeof(TElem) * capacity);
	return dynamicArray;
}

void destroyDynamicArray(DynamicArray** dynamicArrayPointer)
{
	free((*dynamicArrayPointer)->elements);
	free(*dynamicArrayPointer); 
}

int sizeOfArray(DynamicArray* dynamicArray)
{
	return dynamicArray->length;
}

void resizeArray(DynamicArray* dynamicArray)
{
	TElem* resizedArray = (TElem*)malloc(sizeof(TElem) * dynamicArray->capacity * 2);
	for (int i = 0; i < dynamicArray->length; ++i)
		resizedArray[i] = dynamicArray->elements[i];
	free(dynamicArray->elements);
	dynamicArray->capacity *= 2;
	dynamicArray->elements = resizedArray;
}

void appendArray(DynamicArray* dynamicArray, TElem element)
{
	if (dynamicArray->length == dynamicArray->capacity)
		resizeArray(dynamicArray);
	dynamicArray->elements[dynamicArray->length] = element;
	dynamicArray->length++;
}

int deleteArrayElementByIndex(DynamicArray* dynamicArray, int index)
{
	if (index < 0 || index > dynamicArray->length - 1 || dynamicArray->length == 0)
		return -1;
	for (int i = index; i < dynamicArray->length; ++i)
		dynamicArray->elements[i] = dynamicArray->elements[i + 1];
	dynamicArray->length--;
	return 1;
}

int updateArrayElementByIndex(DynamicArray* dynamicArray, int index, TElem newElement)
{
	if (index < 0 || index > dynamicArray->length - 1 || dynamicArray->length == 0)
		return -1;
	dynamicArray->elements[index] = newElement;
	return 1;
}

TElem getElementByIndex(DynamicArray* dynamicArray, int index)
{
	return dynamicArray->elements[index]; 
}
