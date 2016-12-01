#pragma once

#include <string>

class PCControl {
public:
	PCControl();
	
	void pcOn();
	void pcOff();
	void pcLogic();

private:
	int chooseProgram = -1;
};