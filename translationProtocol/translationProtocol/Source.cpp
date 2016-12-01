#pragma comment(lib, "SerialCom.lib") 
#include <iostream>
#include <conio.h>
#include "protocol.h"
#include "Actions.h"
#include "Scenarier.h"
#include "ScenarierList.h"
#include "PCControl.h"
#include <SerialCom.h>
using namespace std;

int main()
{	

	PCControl p1;

	p1.pcOn();

	while (1) {
		p1.pcLogic();
	}
	return 0;
}