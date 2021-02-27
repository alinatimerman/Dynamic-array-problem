#pragma once
#include "Offer.h"
#include "DynamicallyAllocatedArray.h"

typedef struct {
	DynamicArray* offerList;
	DynamicArray* history;
	int historyIndex;
}Repository;

Repository* createRepository(int capacity);
void destroyOfferList(DynamicArray* offerList);
int findOffer(Repository* repository, int ID);
void destroyHistory(DynamicArray* history);
void appendHistoryList(Repository* repository);
void destroyRepository(Repository* repository);
int addOffer(Repository* repository, Offer* offer );
int updateOffer(Repository* repository, Offer* newOffer);
int deleteOffer(Repository* repository, int ID );
DynamicArray* getOffersList(Repository* repository, int* length);
int undo(Repository* repository);
int redo(Repository* repository);
void deleteAdditionalUndoElements(Repository* repository);
DynamicArray* getCopyOfOfferts(Repository* repo, DynamicArray* offerList);