#include "Offer.h"
#include <string.h>

Offer* createOffer(int id, char type[], char destination[], int price)
{
	Offer* object = (Offer*)malloc(sizeof(Offer));
	object->id = id;
	object->type = (char*)malloc(sizeof(char) * strlen(type) + 1);
	strcpy(object->type, type);
	object->destination = (char*)malloc(sizeof(char) * strlen(destination) + 1);
	strcpy(object->destination, destination);
	object->price = price;
	return object;
}

void destroyOffer(Offer* offer)
{
	free(offer->type);
	free(offer->destination);
	free(offer);
}

int getID(Offer* offer)
{
	return offer->id;
}

char* getType(Offer* offer)
{
	return offer->type;
}

char* getDestination(Offer* offer)
{
	return offer->destination;
}

int getPrice(Offer* offer)
{
	return offer->price;
}
