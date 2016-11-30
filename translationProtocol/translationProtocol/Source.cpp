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
	auto i = 0;
	char test[200] = {};
	
	SerialCom serialCom;
	ScenarierList scenlist;
	while (1) {
		i++;
		scenlist.opretScenarie();
		try {
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

			scenlist.tilCharArray(test, i);
			serialCom.send(test, scenlist.etScenarie(i).size());
			cout << "information sent" << endl;
		}
		catch (const char *e)
		{
			cout << endl << e;
			_getch();
			exit(1);
		}
		try
		{
			serialCom.close();
		}
		catch (const char *e)
		{
			cout << endl << e;
			_getch();
			exit(1);
		}
		memset(test, 0, 200);
	}
	return 0;
}