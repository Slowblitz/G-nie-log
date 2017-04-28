#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#pragma once

using namespace std;


class Case
{
	int x, y,ini;
	string cntn;		//contenu de la case

public:

	Case();
	Case(int a, int b);
	Case(int a, int b, int i, char s);

	int getx();
	int gety();
	string getcntn();

	void modifcntnC(string s);

	friend class Plateau;

};