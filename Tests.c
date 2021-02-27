#include "Tests.h"

void runTests()
{
	testOffert();
	testDynamicallyAllocatedArray();
	testRepository();
	testService();
}

void testOffert()
{
	CreateOffert_AnyOffert_OffertCreated();
	DestroyOffert_ExistingOffert_OffertDestroyed();
	GetID_ExistingOffert_OffertID();
	GetType_ExistingOffert_OffertType();
	GetDestination_ExistingOffert_OffertDestination();
	GetPrice_ExistingOffert_OffertPrice();
}

void CreateOffert_AnyOffert_OffertCreated()
{
	Offer* testedOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	assert(getID(testedOffert) == 1);
	assert(strcmp(getType(testedOffert), "Holiday") == 0);
	assert(strcmp(getDestination(testedOffert), "Bahamas") == 0);
	assert(getPrice(testedOffert) == 1900);
	destroyOffer(testedOffert);
}

void DestroyOffert_ExistingOffert_OffertDestroyed()
{
	Offer* testedOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	destroyOffer(testedOffert);
}

void GetID_ExistingOffert_OffertID()
{
	Offer* testedOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	assert(getID(testedOffert) == 1);
	destroyOffer(testedOffert);
}

void GetType_ExistingOffert_OffertType()
{
	Offer* testedOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	assert(strcmp(getType(testedOffert), "Holiday") == 0 );
	destroyOffer(testedOffert);
}

void GetDestination_ExistingOffert_OffertDestination()
{
	Offer* testedOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	assert(strcmp(getDestination(testedOffert), "Bahamas") == 0);
	destroyOffer(testedOffert);
}

void GetPrice_ExistingOffert_OffertPrice()
{
	Offer* testedOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	assert(getPrice(testedOffert) == 1900);
	destroyOffer(testedOffert);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void testDynamicallyAllocatedArray()
{
	CreateDynamicArray_AnyArray_DynamicArrayCreated();
	DestroyDynamicArray_ExistingDynamicArray_DynamicArrayDestroyed();
	SizeOfDynamicArray_ExistingDynamicArray_SizeOfDynamicArray();
	ResizeDynamicArray_ExistingDynamicArray_DynamicArrayResized();
	AppendNewElement_AnyElement_ElementAppended();
	DeleteElementByIndex_ValidIndex_ElementDeleted();
	DeleteElementByIndex_InvalidIndex_ReturnsFalse();
	UpdateElementByIndex_ValidIndex_ElementUpdated();
	UpdateElementByIndex_InvalidIndex_ReturnsFalse();
	GetElementByIndex_AnyValidIndex_ReturnsElementFromGivenIndex();
}

void CreateDynamicArray_AnyArray_DynamicArrayCreated()
{
	DynamicArray* testedDynamicArray = createDynamicArray(25);
	assert(testedDynamicArray->length == 0);
	assert(testedDynamicArray->capacity == 25);
	destroyDynamicArray(&testedDynamicArray);
}

void DestroyDynamicArray_ExistingDynamicArray_DynamicArrayDestroyed()
{
	DynamicArray* testedDynamicArray = createDynamicArray(25);
	destroyDynamicArray(&testedDynamicArray);
}

void SizeOfDynamicArray_ExistingDynamicArray_SizeOfDynamicArray()
{
	DynamicArray* testedDynamicArray = createDynamicArray(25);
	assert(sizeOfArray(testedDynamicArray) == 0);
	for (int i = 0; i < 5; ++i)
	{
		appendArray(testedDynamicArray, i);
		assert(sizeOfArray(testedDynamicArray) == i + 1);
	}
	destroyDynamicArray(&testedDynamicArray);
}

void ResizeDynamicArray_ExistingDynamicArray_DynamicArrayResized()
{
	DynamicArray* testedDynamicArray = createDynamicArray(25);
	assert(testedDynamicArray->capacity == 25);
	resizeArray(testedDynamicArray);
	assert(testedDynamicArray->capacity == 50);
	destroyDynamicArray(&testedDynamicArray);
}

void AppendNewElement_AnyElement_ElementAppended()
{
	DynamicArray* testedDynamicArray = createDynamicArray(25);
	assert(sizeOfArray(testedDynamicArray) == 0);
	for (int i = 0; i < 5; ++i)
	{
		appendArray(testedDynamicArray, i);
		assert(sizeOfArray(testedDynamicArray) == i + 1);
	}
	destroyDynamicArray(&testedDynamicArray);
}

void DeleteElementByIndex_ValidIndex_ElementDeleted()
{
	DynamicArray* testedDynamicArray = createDynamicArray(25);
	appendArray(testedDynamicArray, 25);
	assert(sizeOfArray(testedDynamicArray) == 1);
	deleteArrayElementByIndex(testedDynamicArray, 0);
	assert(sizeOfArray(testedDynamicArray) == 0);
	destroyDynamicArray(&testedDynamicArray);
}

void DeleteElementByIndex_InvalidIndex_ReturnsFalse()
{
	DynamicArray* testedDynamicArray = createDynamicArray(25);
	assert(deleteArrayElementByIndex(testedDynamicArray, 2) == -1);
	destroyDynamicArray(&testedDynamicArray);
}

void UpdateElementByIndex_ValidIndex_ElementUpdated()
{
	DynamicArray* testedDynamicArray = createDynamicArray(25);
	appendArray(testedDynamicArray, 15);
	updateArrayElementByIndex(testedDynamicArray, 0, 20);
	assert(getElementByIndex(testedDynamicArray, 0) == 20);
	destroyDynamicArray(&testedDynamicArray);
}

void UpdateElementByIndex_InvalidIndex_ReturnsFalse()
{
	DynamicArray* testedDynamicArray = createDynamicArray(25);
	appendArray(testedDynamicArray, 15);
	assert(updateArrayElementByIndex(testedDynamicArray, 2, 20) == -1);
	destroyDynamicArray(&testedDynamicArray);
}

void GetElementByIndex_AnyValidIndex_ReturnsElementFromGivenIndex()
{
	DynamicArray* testedDynamicArray = createDynamicArray(25);
	appendArray(testedDynamicArray, 15);
	assert(getElementByIndex(testedDynamicArray, 0) == 15);
	destroyDynamicArray(&testedDynamicArray);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void testRepository()
{
	CreateRepository_AnyRepository_RepositoryCreated();
	DestroyOffertsList_ExistingOffertsList_OffertsListDestroyed();
	DestroyHistoryList_CurrentHistoryList_HistoryDestroyed();
	FindOffert_ElementInList_ReturnsOffertIndex();
	FindOffert_ElementNotInList_ReturnsFalse();
	AppendHistoryList_AnyRepository_AppendsHistory();
	AddOffert_NewOffert_ReturnsTrue();
	AddOffert_ExistingOffert_ReturnsFalse();
	DeleteOffert_OffertInList_ReturnsTrue();
	DeleteOffert_OffertNotInList_ReturnFalse();
	UpdateOffert_OffertInList_ReturnsTrue();
	UpdateOffert_OffertNotInList_ReturnFalse();
	GetOffertsList_AnyRepository_ReturnsOffertsList();
	Undo_AnyRepositoryWithAvailableUndo_ReturnsTrue();
	Undo_AnyRepositoryWithUnavailableUndo_ReturnsFalse();
	Redo_AnyRepositoryWithAvailableRedo_ReturnsTrue();
	Redo_AnyRepositoryWithUnavailableRedo_ReturnsFalse();
	DeleteAdditionalUndos_AnyRepository_DeletesAdditionalUndos();
	GetCopyOfOfferts_ExistingListOfOfferts_ReturnsCopyOfOffertsList();
}

void CreateRepository_AnyRepository_RepositoryCreated()
{
	Repository* testedRepository = createRepository(25);
	assert(sizeOfArray(testedRepository->offerList) == 0);
	destroyRepository(testedRepository);
}

void DestroyOffertsList_ExistingOffertsList_OffertsListDestroyed()
{
	Repository* testedRepository = createRepository(25);
	destroyOfferList(testedRepository->offerList);
	destroyRepository(testedRepository);
}

void DestroyHistoryList_CurrentHistoryList_HistoryDestroyed()
{
	Repository* testedRepository = createRepository(25);
	destroyOfferList(testedRepository->offerList);
	destroyRepository(testedRepository);
}

void DestroyRepository_AnyRepository_RepositoryDestroyed()
{
	Repository* testedRepository = createRepository(25);
	destroyRepository(testedRepository);
}

void FindOffert_ElementInList_ReturnsOffertIndex()
{
	Repository* testedRepository = createRepository(25);
	Offer* exampleOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	addOffer(testedRepository, exampleOffert);
	assert(findOffer(testedRepository, 1) == 0);
	destroyRepository(testedRepository);
}

void FindOffert_ElementNotInList_ReturnsFalse()
{
	Repository* testedRepository = createRepository(25);
	Offer* exampleOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	addOffer(testedRepository, exampleOffert);
	assert(findOffer(testedRepository, 2) == -1);
	destroyRepository(testedRepository);
}

void AppendHistoryList_AnyRepository_AppendsHistory()
{
	Repository* testedRepository = createRepository(25);
	Offer* exampleOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	addOffer(testedRepository, exampleOffert);
	destroyRepository(testedRepository);
}

void AddOffert_NewOffert_ReturnsTrue()
{
	Repository* testedRepository = createRepository(25);
	Offer* exampleOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	assert(addOffer(testedRepository, exampleOffert) == 1);
	destroyRepository(testedRepository);
}

void AddOffert_ExistingOffert_ReturnsFalse()
{
	Repository* testedRepository = createRepository(25);
	Offer* exampleOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	addOffer(testedRepository, exampleOffert);
	Offer* existingOffert = createOffer(1, "Business", "Romania", 250);
	assert(addOffer(testedRepository, existingOffert) == -1);
	destroyRepository(testedRepository);
}

void DeleteOffert_OffertInList_ReturnsTrue()
{
	Repository* testedRepository = createRepository(25);
	Offer* exampleOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	addOffer(testedRepository, exampleOffert);
	assert(deleteOffer(testedRepository, 1) == 1);
	destroyRepository(testedRepository);
}

void DeleteOffert_OffertNotInList_ReturnFalse()
{
	Repository* testedRepository = createRepository(25);
	Offer* exampleOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	addOffer(testedRepository, exampleOffert);
	Offer* deletedOffert = createOffer(2, "Business", "Romania", 250);
	assert(deleteOffer(testedRepository, deletedOffert) == -1);
	destroyOffer(deletedOffert);
	destroyRepository(testedRepository);
}

void UpdateOffert_OffertInList_ReturnsTrue()
{
	Repository* testedRepository = createRepository(25);
	Offer* exampleOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	addOffer(testedRepository, exampleOffert);
	Offer* updatedOffert = createOffer(1, "Business", "Romania", 250);
	assert(updateOffer(testedRepository, updatedOffert) == 1);
	destroyRepository(testedRepository);
}

void UpdateOffert_OffertNotInList_ReturnFalse()
{
	Repository* testedRepository = createRepository(25);
	Offer* exampleOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	addOffer(testedRepository, exampleOffert);
	Offer* updatedOffert = createOffer(2, "Business", "Romania", 250);
	assert(updateOffer(testedRepository, updatedOffert) == -1);
	destroyRepository(testedRepository);
}

void GetOffertsList_AnyRepository_ReturnsOffertsList()
{
	Repository* testedRepository = createRepository(25);
	Offer* exampleOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	addOffer(testedRepository, exampleOffert);
	Offer* secondExampleOffert = createOffer(2, "Business", "Romania", 250);
	addOffer(testedRepository, secondExampleOffert);
	int length = 0;
	DynamicArray* returnedList = getOffersList(testedRepository, &length);
	assert(length == 2);
	destroyRepository(testedRepository);
}

void Undo_AnyRepositoryWithAvailableUndo_ReturnsTrue()
{
	Repository* testedRepository = createRepository(25);
	Offer* firstOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	Offer* secondOffert = createOffer(2, "Business", "Romania", 250);
	addOffer(testedRepository, firstOffert);
	addOffer(testedRepository, secondOffert);
	assert(undo(testedRepository) == 1);
	assert(sizeOfArray(testedRepository->offerList) == 1);
	assert(undo(testedRepository) == 1);
	assert(sizeOfArray(testedRepository->offerList) == 0);
	destroyRepository(testedRepository);
}

void Undo_AnyRepositoryWithUnavailableUndo_ReturnsFalse()
{
	Repository* testedRepository = createRepository(25);
	Offer* firstOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	Offer* secondOffert = createOffer(2, "Business", "Romania", 250);
	addOffer(testedRepository, firstOffert);
	addOffer(testedRepository, secondOffert);
	assert(undo(testedRepository) == 1);
	assert(sizeOfArray(testedRepository->offerList) == 1);
	assert(undo(testedRepository) == 1);
	assert(sizeOfArray(testedRepository->offerList) == 0);
	assert(undo(testedRepository) == -1);
	destroyRepository(testedRepository);
}

void Redo_AnyRepositoryWithAvailableRedo_ReturnsTrue()
{
	Repository* testedRepository = createRepository(25);
	Offer* firstOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	Offer* secondOffert = createOffer(2, "Business", "Romania", 250);
	addOffer(testedRepository, firstOffert);
	addOffer(testedRepository, secondOffert);
	assert(undo(testedRepository) == 1);
	assert(sizeOfArray(testedRepository->offerList) == 1);
	assert(redo(testedRepository) == 1);
	assert(sizeOfArray(testedRepository->offerList) == 2);
	destroyRepository(testedRepository);
}

void Redo_AnyRepositoryWithUnavailableRedo_ReturnsFalse()
{
	Repository* testedRepository = createRepository(25);
	Offer* firstOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	Offer* secondOffert = createOffer(2, "Business", "Romania", 250);
	addOffer(testedRepository, firstOffert);
	addOffer(testedRepository, secondOffert);
	assert(undo(testedRepository) == 1);
	assert(sizeOfArray(testedRepository->offerList) == 1);
	assert(redo(testedRepository) == 1);
	assert(sizeOfArray(testedRepository->offerList) == 2);
	assert(redo(testedRepository) == -1);
	destroyRepository(testedRepository);
}

void DeleteAdditionalUndos_AnyRepository_DeletesAdditionalUndos()
{
	Repository* testedRepository = createRepository(25);
	Offer* firstOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	Offer* secondOffert = createOffer(2, "Business", "Romania", 250);
	destroyRepository(testedRepository);
}

void GetCopyOfOfferts_ExistingListOfOfferts_ReturnsCopyOfOffertsList()
{
	Repository* testedRepository = createRepository(25);
	Offer* firstOffert = createOffer(1, "Holiday", "Bahamas", 1900);
	Offer* secondOffert = createOffer(2, "Business", "Romania", 250);
	addOffer(testedRepository, firstOffert);
	addOffer(testedRepository, secondOffert);
	destroyRepository(testedRepository);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void testService()
{
	CreateService_AnyService_ServiceCreated();
	DestroyService_ExistingService_ServiceDestroyed();
	FindOffertService_OffertsID_ReturnsOffert();
	AddOffertService_NewOffert_ReturnsTrue();
	AddOffertService_ExistingOfferts_ReturnsFalse();
	DeleteOffertService_OffertInList_ReturnsTrue();
	DeleteOffertService_OffertNotInList_ReturnsFalse();
	UpdateOffertService_OffertInList_ReturnsTrue();
	UpdateOffertService_OffertNotInList_ReturnsFalse();
	GetOffertsListService_AnyService_ReturnsOffertsList();
	UndoService_AnyServiceWithAvailableUndo_ReturnsTrue();
	UndoService_AnyServiceWithUnavailableUndo_ReturnsFalse();
	RedoService_AnyServiceWithAvailableRedo_ReturnsTrue();
	RedoService_AnyServiceWithUnavailableRedo_ReturnsFalse();

}

void CreateService_AnyService_ServiceCreated()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	int offertListLength = sizeOfArray(testedService->repository->offerList);
	assert(offertListLength == 0);
	destroyService(testedService);
}

void DestroyService_ExistingService_ServiceDestroyed()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	destroyService(testedService);
}

void FindOffertService_OffertsID_ReturnsOffert()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	assert(findOfferService(testedService, 1) == 0);
	destroyService(testedService);
}

void AddOffertService_NewOffert_ReturnsTrue()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	assert(sizeOfArray(testedService->repository->offerList) == 0);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	assert(sizeOfArray(testedService->repository->offerList) == 1);
	destroyService(testedService);
}

void AddOffertService_ExistingOfferts_ReturnsFalse()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	assert(addOfferService(testedService, 1, "Business", "Romania", 250) == -1);
	destroyService(testedService);
}

void DeleteOffertService_OffertInList_ReturnsTrue()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	assert(sizeOfArray(testedService->repository->offerList) == 1);
	deleteOfferService(testedService, 1);
	assert(sizeOfArray(testedService->repository->offerList) == 0);
	destroyService(testedService);
}

void DeleteOffertService_OffertNotInList_ReturnsFalse()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	assert(deleteOfferService(testedService, 2) == -1);
	destroyService(testedService);
}

void UpdateOffertService_OffertInList_ReturnsTrue()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	updateOfferService(testedService, 1, "Business", "Romania", 250);
	Offer* randomOffert = getElementByIndex(testedService->repository->offerList, 0);
	Offer* testedOffert = createOffer(randomOffert->id, randomOffert->type, randomOffert->destination, randomOffert->price);
	assert(strcmp(testedOffert->type, "Business") == 0);
	assert(strcmp(testedOffert->destination, "Romania") == 0);
	assert(testedOffert->price == 250);
	destroyService(testedService);
}

void UpdateOffertService_OffertNotInList_ReturnsFalse()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	assert(updateOfferService(testedService, 2, "Business", "Romania", 250) == -1);
	destroyService(testedService);
}

void GetOffertsListService_AnyService_ReturnsOffertsList()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	addOfferService(testedService, 2, "Business", "Romania", 250);
	int length = 0;
	DynamicArray* returnedList = getOffersListService(testedService, &length);
	assert(length == 2);
	destroyService(testedService);
}

void UndoService_AnyServiceWithAvailableUndo_ReturnsTrue()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	addOfferService(testedService, 2, "Business", "Romania", 250);
	assert(undoService(testedService) == 1);
	assert(sizeOfArray(testedService->repository->offerList) == 1);
	assert(undoService(testedService) == 1);
	assert(sizeOfArray(testedService->repository->offerList) == 0);
	destroyService(testedService);
}

void UndoService_AnyServiceWithUnavailableUndo_ReturnsFalse()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	addOfferService(testedService, 2, "Business", "Romania", 250);
	assert(undoService(testedService) == 1);
	assert(sizeOfArray(testedService->repository->offerList) == 1);
	assert(undoService(testedService) == 1);
	assert(sizeOfArray(testedService->repository->offerList) == 0);
	assert(undoService(testedService) == -1);
	destroyService(testedService);
}

void RedoService_AnyServiceWithAvailableRedo_ReturnsTrue()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	addOfferService(testedService, 2, "Business", "Romania", 250);
	assert(undoService(testedService) == 1);
	assert(sizeOfArray(testedService->repository->offerList) == 1);
	assert(redoService(testedService) == 1);
	assert(sizeOfArray(testedService->repository->offerList) == 2);
	destroyService(testedService);
}

void RedoService_AnyServiceWithUnavailableRedo_ReturnsFalse()
{
	Repository* testedRepository = createRepository(25);
	Service* testedService = createService(testedRepository);
	addOfferService(testedService, 1, "Holiday", "Bahamas", 1900);
	addOfferService(testedService, 2, "Business", "Romania", 250);
	assert(undoService(testedService) == 1);
	assert(sizeOfArray(testedService->repository->offerList) == 1);
	assert(redoService(testedService) == 1);
	assert(sizeOfArray(testedService->repository->offerList) == 2);
	assert(redoService(testedService) == -1);
	destroyService(testedService);
}
