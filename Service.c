#include "Service.h"
#define _CRT_SECURE_NO_WARNINGS
Service* createService(Repository* repository)
{
	Service* service = (Service*)malloc(sizeof(Service));
	service->repository = repository;
	return service;
}

void destroyService(Service* service)
{
	destroyRepository(service->repository);
	free(service); 
}

int findOfferService(Service* service, int id)
{
	return findOffer(service->repository, id);
}

int addOfferService(Service* service, int id, char type[], char destination[], int price)
{
	Offer* offer = createOffer(id, type, destination, price);
	return addOffer(service->repository, offer);
}

int deleteOfferService(Service* service, int id)
{
	return deleteOffer(service->repository, id);
}

int updateOfferService(Service* service, int id, char type[], char destination[], int price)
{
	Offer* newOffer = createOffer(id, type, destination, price);
	return updateOffer(service->repository, newOffer);
}

DynamicArray* getOffersListService(Service* service, int* length)
{
	return getOffersList(service->repository, length);
}

int undoService(Service* service)
{
	return undo(service->repository);
}

int redoService(Service* service)
{
	return redo(service->repository); 
}
