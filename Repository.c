#pragma once
#include "Repository.h"
#include "DynamicallyAllocatedArray.h"
#include <stdio.h>
Repository* createRepository(int capacity)
{
	Repository* repository = (Repository*)malloc(sizeof(Repository));
	repository->history = createDynamicArray(2);
	repository->historyIndex = -1;
	repository->offerList = createDynamicArray(capacity);
	return repository;
}

void destroyOfferList(DynamicArray* offerList)
{
	if (sizeOfArray(offerList) > 0)
		for (int i = 0; i < sizeOfArray(offerList); ++i)
			destroyOffer(offerList->elements[i]);
}

void destroyHistory(DynamicArray* history)
{
	DynamicArray* listOfOfferts;
	for (int i = 0; i < sizeOfArray(history); ++i)
	{
		listOfOfferts = getElementByIndex(history, i);
		destroyOfferList(listOfOfferts);
		destroyDynamicArray(&listOfOfferts);
	}
}

void destroyRepository(Repository* repository)
{
	destroyOfferList(repository->offerList);
	destroyDynamicArray(&(repository->offerList));
	destroyHistory(repository->history);
	destroyDynamicArray(&(repository->history));
	free(repository);
}

int findOffer(Repository* repository, int ID)
{
	Offer* currentOfferObject;
	for (int i = 0; i < sizeOfArray(repository->offerList); ++i)
	{
		currentOfferObject = getElementByIndex(repository->offerList, i);
		if (currentOfferObject->id == ID)
			return i;
	}
	return -1;
}

void appendHistoryList(Repository* repository)
{
	DynamicArray* copyOfOfferts = getCopyOfOfferts(repository, repository->offerList);
	appendArray(repository->history, copyOfOfferts);
	repository->historyIndex++;
}


int addOffer(Repository* repository, Offer* offer)
{
	if (findOffer(repository, offer->id) != -1)
	{
		destroyOffer(offer);
		return -1;
	}

	deleteAdditionalUndoElements(repository);
	appendArray(repository->offerList, offer);
	appendHistoryList(repository);
	return 1;
}

int deleteOffer(Repository* repository, int ID)
{
	int foundOfferIndex = findOffer(repository, ID);
	if (foundOfferIndex == -1)
		return -1;

	deleteAdditionalUndoElements(repository);
	destroyOffer(getElementByIndex(repository->offerList, foundOfferIndex));
	deleteArrayElementByIndex(repository->offerList, foundOfferIndex);
	appendHistoryList(repository);
	return 1;
}

int updateOffer(Repository* repository, Offer* newOffer)
{
	int foundOfferIndex = findOffer(repository, newOffer->id);
	if (foundOfferIndex == -1)
	{
		destroyOffer(newOffer);
		return -1;
	}

	deleteAdditionalUndoElements(repository);
	updateArrayElementByIndex(repository->offerList, foundOfferIndex, newOffer);
	appendHistoryList(repository);
	return 1;
}

DynamicArray* getOffersList(Repository* repository, int* length)
{
	*length = sizeOfArray(repository->offerList);
	return repository->offerList;
}

int undo(Repository* repository)
{
	//printf("%d", repository->historyIndex);
	if (repository->historyIndex == -1)
		return -1;

	destroyOfferList(repository->offerList);
	destroyDynamicArray(&repository->offerList); 
	if (repository->historyIndex == 0)
		repository->offerList = createDynamicArray(2);
	else
		repository->offerList = getCopyOfOfferts(repository, (DynamicArray*)getElementByIndex(repository->history, repository->historyIndex - 1));
	repository->historyIndex--;
	//printf("%d", sizeOfArray(repository->offerList));
	return 1; 
}

int redo(Repository* repository)
{
	if (repository->historyIndex == sizeOfArray ( repository->history ) - 1)
		return -1;
	destroyOfferList(repository->offerList);
	destroyDynamicArray(&repository->offerList);
	repository->offerList = getCopyOfOfferts(repository, (DynamicArray*)getElementByIndex(repository->history, repository->historyIndex + 1));
	repository->historyIndex++;
	return 1;
}

void deleteAdditionalUndoElements(Repository* repository)
{
	if (repository->historyIndex < sizeOfArray(repository->history) - 1)
	{
		DynamicArray* additionalElement;
		while (repository->historyIndex < sizeOfArray(repository->history) - 1) 
		{
			additionalElement = (DynamicArray*)getElementByIndex(repository->history, sizeOfArray(repository->history) - 1);
			destroyOfferList(additionalElement);
			destroyDynamicArray(&additionalElement);
			deleteArrayElementByIndex(repository->history, sizeOfArray(repository->history) - 1);
		}
	}
}

DynamicArray* getCopyOfOfferts(Repository* repo, DynamicArray* offerList)
{
	DynamicArray* copyOfOfferts = createDynamicArray(sizeOfArray(offerList));
	Offer* offerToBeAppended;
	Offer* appendedOffert;
	for (int i = 0; i < sizeOfArray(offerList); ++i)
	{
		appendedOffert = getElementByIndex(offerList, i); 
		offerToBeAppended = createOffer(appendedOffert->id, appendedOffert->type, appendedOffert->destination, appendedOffert->price);
		appendArray(copyOfOfferts, offerToBeAppended);
	}
	return copyOfOfferts;
}
