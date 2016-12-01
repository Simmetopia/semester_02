
#include "PCControl.h"
#include "ScenarierList.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <SerialCom.h>

ScenarierList scenlist;

PCControl::PCControl() {
	std::cout << "Vil du gerne taende for PC'en? Tast 'j' for ja." << std::endl;

	while (_getch() != 'j')
		std::cout << "Forkert task, Proev igen." << std::endl;
}

void PCControl::pcOn() {
	for (auto i = 0; i < 3; i++) {
		std::cout << "----------------------------------------" << std::endl;
		Sleep(100);
	}
	std::cout << "Velkommen til Smart Morning System!" << std::endl;
	for (auto i = 0; i < 3; i++) {
		std::cout << "----------------------------------------" << std::endl;
		Sleep(100);
	}
}

void PCControl::pcOff() {
	std::cout << "Lukker computeren." << std::endl;
	for (auto i = 0; i <= 3; i++) {
		std::cout << "**" << std::endl;
		Sleep(500);
	}
	exit(0);
}

void PCControl::pcLogic() {


	std::cout << "---------- Vaelge en af foelgende genskaber, efterfulgt af Enter ----------" << std::endl;
	std::cout << "(1) Opret scenarie ";
	std::cout << "(2) Liste af scenarier ";
	std::cout << "(3) Luk computer" << std::endl;

	int _temp = -1;
	ScenarierList scenlist;
	while (_temp != 999) {
		std::cin >> chooseProgram;
		switch (chooseProgram) {

		case 1:
			scenlist.opretScenarie();
			break;

		case 2:
			break;

		case 3:
			pcOff();
			break;

		default:
			std::cout << "Egenskab findes ikke. Prøv igen" << std::endl;
			continue;
		}
		break;
	}

	char test[200] = {};
	auto i = 0;
	SerialCom serialCom;

	i++;

	try {
		serialCom.open(4, 9600, 8, PARITY_NONE, 1);
	}
	catch (const char *e)
	{
		std::cout << std::endl << e;
		_getch();
		exit(1);
	}
	std::cout << "COM3 er open og klar til brug." << std::endl;

	try
	{

		scenlist.tilCharArray(test, i);
		serialCom.send(test, scenlist.etScenarie(i).size());
		std::cout << "information sent" << std::endl;
	}
	catch (const char *e)
	{
		std::cout << std::endl << e;
		_getch();
		exit(1);
	}
	try
	{
		serialCom.close();
	}
	catch (const char *e)
	{
		std::cout << std::endl << e;
		_getch();
		exit(1);
	}
	memset(test, 0, 200);
}




