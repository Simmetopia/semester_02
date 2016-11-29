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
	char test = 'a';
	char *a = "!NH12M45NH12M55NH13M15";
	char *b = "!NH12M45NH12M55";
	int SIZE = strlen(a);
	SerialCom serialCom;
	ScenarierList scenlist;
	scenlist.addScenarie(a);
	scenlist.opretScenarie();
	int size, *ports;
try{
	serialCom.open(3, 9600, 8, PARITY_NONE, 1);
}
catch (const char *e)
{
	cout << endl << e;
	_getch();
	exit(1);
}
cout << "COM3 er open og klar til brug." << endl;
//scenlist.tilCharArray(scenlist.etScenarie(2)), scenlist.etScenarie(2).size()
try
{
	serialCom.send(scenlist.tilCharArray(scenlist.etScenarie(2)), scenlist.etScenarie(2).size()+1);
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