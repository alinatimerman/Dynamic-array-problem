#pragma once
#include "Repository.h"

typedef struct {
	Repository* repository;
}Service;

Service* createService(Repository* repository);
void destroyService(Service* service);

int findOfferService(Service* service, int id);
int addOfferService(Service* service, int id, char type[], char destination[], int price);
int deleteOfferService(Service* service, int id );
int updateOfferService(Service* service, int id, char type[], char destination[], int price);

DynamicArray* getOffersListService(Service* service, int* length); 

int undoService(Service* service);
int redoService(Service* service);