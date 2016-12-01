#pragma once

#include <string>

class PCControl {
public:
	PCControl();
	
	void pcOn();
	void pcOff();
	void pcLogic();
	void pcPrintScenarieNames();

private:
	int chooseProgram = -1;
};