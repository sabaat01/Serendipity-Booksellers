#define _CRT_SECURE_NO_WARNINGS
#ifndef REPORTINGMODULE_H
#define REPORTINGMODULE_H
#include "InventoryModule.h"
#include "Module.h"

using namespace std;

class ReportingModule : public Module
{
protected:
	InventoryModule *inventory;
public:
	ReportingModule(InventoryModule *inv);
	void driver();
	int displayRepenu();
};
#endif
