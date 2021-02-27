#pragma once
#include "Service.h"

typedef struct {
	Service* offerService;
}OffersUI;

OffersUI* createUI(Service* service);
void destroyUI(OffersUI* offersUI);
void uiStart(OffersUI* offersUI);

void uiAddOffer(OffersUI* offersUI);
void uiUpdateOffer(OffersUI* offersUI);
void uiDeleteOffer(OffersUI* offersUI);
void uiListOffers(OffersUI* offersUI);

void uiUndo(OffersUI* offersUI);
void uiRedo(OffersUI* offersUI);