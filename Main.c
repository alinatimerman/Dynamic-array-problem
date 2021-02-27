#include <stdio.h>
#include "UI.h"
#include "Tests.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
//#define _CRT_SECURE_NO_WARNINGS


int main() {
	Repository* repository = createRepository(20);
	Service* service = createService(repository);
	OffersUI* ui = createUI(service);
	//_CrtDumpMemoryLeaks();
	runTests();
	uiStart(ui);
	return 0;
}