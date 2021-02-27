#include "UI.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

OffersUI* createUI(Service* service)
{
	OffersUI* ui = (OffersUI*)malloc(sizeof(OffersUI));
	ui->offerService = service;
	return ui;
}

void destroyUI(OffersUI* offersUI)
{
	destroyService(offersUI->offerService);
	free(offersUI);
}

void uiStart(OffersUI* offersUI)
{
	char userInput[100];
	while (1)
	{
		printf("Give input : ");
		scanf("%s", userInput);
		if (strcmp(userInput, "exit") == 0)
		{
			destroyUI(offersUI);
			break;
		}
		else if (strcmp(userInput, "add") == 0)
			uiAddOffer(offersUI);
		else if (strcmp(userInput, "delete") == 0)
			uiDeleteOffer(offersUI);
		else if (strcmp(userInput, "update") == 0)
			uiUpdateOffer(offersUI);
		else if (strcmp(userInput, "list") == 0)
			uiListOffers(offersUI);
		else if (strcmp(userInput, "undo") == 0)
			uiUndo(offersUI);
		else if (strcmp(userInput, "redo") == 0)
			uiRedo(offersUI);
		else
			printf("Invalid command!\n");
	}
}

void uiAddOffer(OffersUI* offersUI)
{
	int id, price;
	char type[100], destination[100]; 
	scanf("%d, ", &id);
	scanf("%s, ", type);
	scanf("%s, ", destination);
	scanf("%d ", &price);
	type[strlen(type) - 1] = '\0';
	destination[strlen(destination) - 1] = '\0';
	int working = addOfferService(offersUI->offerService, id, type, destination, price);
	if (working == -1)
		printf("No!\n");
	/*if (addOfferService(offersUI->offerService,id, type, destination, price) == -1)
		printf("No!\n");*/
}

void uiUpdateOffer(OffersUI* offersUI)
{
	int id, price;
	char type[100], destination[100];
	scanf("%d, ", &id);
	scanf("%s, ", type);
	scanf("%s, ", destination);
	scanf("%d ", &price);
	type[strlen(type) - 1] = '\0';
	destination[strlen(destination) - 1] = '\0';
	int working = updateOfferService(offersUI->offerService, id, type, destination, price);
	if (working == -1)
		printf("No!\n");
	/*if (updateOfferService(offersUI->offerService,id, type, destination, price) == -1)
		printf("No!\n");*/
}

void uiDeleteOffer(OffersUI* offersUI)
{
	int id;
	scanf("%d", &id);

	int working = deleteOfferService(offersUI->offerService, id);
	if (working == -1)
		printf("No!\n");
	//if (deleteOfferService(offersUI->offerService,id) == -1)
	//	printf("No!\n");
}

void uiListOffers(OffersUI* offersUI)
{
	char givenDestination[100];	
	int givenMaxQuantity = 0;
	gets(givenDestination);
	if ( strlen (givenDestination) != 0 )
		strcpy(givenDestination, givenDestination + 1);
	if (givenDestination[0] >= '0' && givenDestination[0] <= '9')
		for (int i = 0; i < strlen(givenDestination); ++i)
			givenMaxQuantity = 10 * givenMaxQuantity + (givenDestination[i] - '0');
	int length, sortedListOfOffertsLength = 0;
	Offer* offertsBelowMaxPriceSortedAscendinglyByType[20005];
	Offer* offersList = getOffersListService ( offersUI->offerService, &length); 
	Offer* currentOffert;
	Offer* auxiliarySwapOffert;

	//printf("%s: %d\n", givenDestination, strlen(givenDestination));
	//printf("%d : %s", offersList[0].id, offersList[0].type);
	//printf("%d - %d", sizeOfArray (offersList), offersUI->offerService->repository->offerList->length);

	if (givenMaxQuantity != 0)
	{
		for (int i = 0; i < length; ++i)
		{
			currentOffert = getElementByIndex(offersList, i);
			if (currentOffert->price < givenMaxQuantity)
			{
				offertsBelowMaxPriceSortedAscendinglyByType[sortedListOfOffertsLength] = currentOffert;
				sortedListOfOffertsLength++;
			}
		}
		for (int i = 0; i < sortedListOfOffertsLength; ++i)
		{
			for (int j = i + 1; j < sortedListOfOffertsLength; ++j)
				if (strcmp(offertsBelowMaxPriceSortedAscendinglyByType[i]->type, offertsBelowMaxPriceSortedAscendinglyByType[j]->type) > 0)
				{
					auxiliarySwapOffert = offertsBelowMaxPriceSortedAscendinglyByType[i];
					offertsBelowMaxPriceSortedAscendinglyByType[i] = offertsBelowMaxPriceSortedAscendinglyByType[j];
					offertsBelowMaxPriceSortedAscendinglyByType[j] = auxiliarySwapOffert;
				}
			printf("ID: %d, Type: %s, Destination: %s, Price: %d \n", offertsBelowMaxPriceSortedAscendinglyByType[i]->id, offertsBelowMaxPriceSortedAscendinglyByType[i]->type, offertsBelowMaxPriceSortedAscendinglyByType[i]->destination, offertsBelowMaxPriceSortedAscendinglyByType[i]->price);
		}
	}
	else if (strlen(givenDestination) == 0 || strlen(givenDestination) == '0')
	{
		for (int i = 0; i < length; ++i)
		{
			currentOffert = getElementByIndex(offersList, i);
			printf("ID: %d, Type: %s, Destination: %s, Price: %d \n", currentOffert->id, currentOffert->type, currentOffert->destination, currentOffert->price);
		}
	} 
	else
	{
		for (int i = 0; i < length; ++i)
		{
			currentOffert = getElementByIndex(offersList, i);
			if (strcmp(currentOffert->destination, givenDestination) == 0)
				printf("ID: %d, Type: %s, Destination: %s, Price: %d \n", currentOffert->id, currentOffert->type, currentOffert->destination, currentOffert->price);
		}
	}
}

void uiUndo(OffersUI* offersUI)
{
	int isWorking = undoService(offersUI->offerService);
	if (isWorking == -1)
		printf("No more undos available!\n");

}

void uiRedo(OffersUI* offersUI)
{
	//printf("%d", offersUI->offerService->repository->historyIndex); 
	int isWorking = redoService(offersUI->offerService);
	if (isWorking == -1)
		printf("No more redos available!\n");
}
