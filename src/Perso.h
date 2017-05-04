#include <string>
#pragma once

using namespace std;

class perso
{
	string nom;
	int PointDeVie,PointDeVieMax,PointDeMana,PointDeManaMax,DmgMin,DmgMax;
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
		void setPm(int n);
		void setPmP(int n);
		void resetPm(int n);
		void setPv(int n);
		void setPvP(int n);
		void resetPv(int n);

		virtual int choiceCmp() = 0;
};


class guerrier : public perso
{
	int PointDeVie,PointDeMana,DmgMin,DmgMax;
	
	public:


		int AttackBase();
		int CompD();
		int CompDp();
		virtual int choiceCmp();
};



class mage : public perso
{
	int PointDeVie,PointDeMana,DmgMin,DmgMax;

	public:

		int AttackBase();
		int CompD();
		int CompDef1();
		virtual int choiceCmp();
};



class guerriseur : public perso
{
	int PointDeVie,PointDeMana,DmgMin,DmgMax;

	public:

		int AttackBase();
		int CompD();
		int CompDef1();
		virtual int choiceCmp();
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