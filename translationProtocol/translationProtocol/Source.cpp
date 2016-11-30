#pragma comment(lib, "SerialCom.lib") 
#include <iostream>
#include <conio.h>
#include "protocol.h"
#include "Actions.h"
#include "Scenarier.h"
#include "ScenarierList.h"
#include <SerialCom.h>
using namespace std;

int main()
{
	char test[200]={};
	char *a = "!NH12M45NH12M55NH13M15";
	int SIZE = strlen(a);
	SerialCom serialCom;
	ScenarierList scenlist;
	scenlist.addScenarie(a);
try{
	serialCom.open(5, 9600, 8, PARITY_NONE, 1);
}
catch (const char *e)
{
	cout << endl << e;
	_getch();
	exit(1);
}
cout << "COM3 er open og klar til brug." << endl;

try
{
	scenlist.tilCharArray(test,1 );
	serialCom.send(test, scenlist.etScenarie(1).size());
	cout << "information sent" << endl;
}
catch (const char *e)
{
	cout << endl << e;
	_getch();
	exit(1);
}

	return 0;
}