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
	ScenarierList scenlist;
	scenlist.addScenarie();
	scenlist.addScenarie();
	scenlist.AntalElementer();
	int a=0;
	cout << "antal scen i hvilket nr?" << endl;
	cin >> a;
	scenlist.AntalaktionerIScenarie(a);


	/*char *a = "f \n";
	int SIZE = strlen(a);
	SerialCom serialCom;    
	int size, *ports;
	try
	{
		ports = serialCom.getPorts(serialCom.ALL, size);
	}
	catch (const char *e)
	{
		cout << endl << e;
		_getch();
		exit(1);
	}
	for (size_t i = 0; i < size; i++)
	{
		cout << "COM" << ports[i] << endl;
	}
	try
	{
		serialCom.open(5, 9600, 8, PARITY_NONE, 1);
	}  

	catch (const char *e)    
	{        
		cout << endl << e; 
		_getch();
		exit(1);   
	}    
	cout <<"COM5 er open og klar til brug."<< endl;

	try
	{
		serialCom.send(a, SIZE);
		cout << "information sent" << endl;
	}
	catch(const char *e)
	{
		cout << endl << e;
		_getch();
		exit(1);
	}
	try
	{
		serialCom.close();
		cout << "closed" << endl;
	} 
	catch (const char *e)
	{
		cout << endl << e;
		_getch();
		exit(1);
	}*/
	return 0;
}