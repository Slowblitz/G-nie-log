#include <string>
#pragma once

using namespace std;

class perso
{
	string nom;
	int PointDeVie,PointDeVieMax,PointDeMana,PointDeManaMax,DmgMin,DmgMax;

	public:
		perso();
		
		string getname();
		int getPointDeVie();
		int getPointDeVieMax();
		int getPointDeMana();
		int getPointDeManaMax();
		int getDmgMin();
		int getDmgMax();

		void setPm(int n);
		void setPmP(int n);
		void setPv(int n);
		void setPvP(int n);

		void resetPm(int n);
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


class monster 
{
	int PointDeVie,PointDeVieMax,DmgMin,DmgMax;

	public:	
		
		monster();
		int AttackBase();
		int getPointDeVie();
		int getPointDeVieMax();
		int getDmgMax();
		int getDmgMin();
		void setPv(int n);
};