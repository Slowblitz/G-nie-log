#include <string>
#pragma once

using namespace std;

class perso
{
	string nom;
	int PointDeVie,PointDeMana,DmgMin,DmgMax;
	public:
		perso();
		bool deplacement();
		int AttackBase();
		string getname();
		int getPointDeVie();
		int getPointDeMana();
		int getDmgMin();
		int getDmgMax();
		int CompD(int, int);
		int CompDef1(int);
		int CompDef2(int);
		int CompDef3(int);
		int setPm(int n);

};


class guerrier : public perso
{
	int PointDeVie,PointDeMana,DmgMin,DmgMax;
	
	public:


		int AttackBase();
		int CompD();
		int CompDef1();
};



class mage : public perso
{
	int PointDeVie,PointDeMana,DmgMin,DmgMax;

	public:

		int AttackBase();
		int CompD();
		int CompDef1();
};



class guerriseur : public perso
{
	int PointDeVie,PointDeMana,DmgMin,DmgMax;

	public:

		int AttackBase();
		int CompD();
		int CompDef1();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class monster 
{
	int PointDeVie,DmgMin,DmgMax;

	public:	
		
		monster();
		int AttackBase();
		int getPointDeVie();
		int getDmgMax();
		int getDmgMin();
		void setPv(int n);

};