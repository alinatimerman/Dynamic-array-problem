#pragma once

typedef struct {
	int id;
	char* type;
	char* destination;
	int price;
}Offer;

Offer* createOffer(int id, char type[], char destination[], int price);

void destroyOffer( Offer* offer );
int getID(Offer* offer);
char* getType(Offer* offer);
char* getDestination(Offer* offer);
int getPrice(Offer* offer);
