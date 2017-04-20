#include"Perso.h"
 #include<cstdlib>
#include <fstream>
#include <iostream>
using namespace std;



perso::perso()
{

ifstream fichier("Perso.dat", ios::in);  // on ouvre le fichier en lecture
 	
        if(fichier)  // si l'ouverture a réussi
        {       
           
		string name;  // déclaration d'une chaîne qui contiendra la ligne lue
		int PointDeVie,PointDeMana,DmgMin,DmgMax;
               	fichier >> name >> PointDeVie >> PointDeMana >> DmgMin >> DmgMax;
                fichier.close();  // on ferme le fichier
		this->nom=name;
		this->PointDeVie=PointDeVie;
		this->PointDeMana=PointDeMana;
		this-> DmgMin= DmgMin;
		this-> DmgMax= DmgMax;
	
        }
        else  
                cerr << "Impossible d'ouvrir le fichier !" << endl;
 
      
}
////////////////////////////////////////////////////////////////////////
string perso::getname()
{
	return this->nom;
}
////////////////////////////////////////////////////////////////////////
int perso::getPointDeVie()
{
	return this->PointDeVie;
}
////////////////////////////////////////////////////////////////////////
int perso::getPointDeMana()
{
	return this->PointDeMana;
}
////////////////////////////////////////////////////////////////////////
int perso::getDmgMax()
{
	return this->DmgMax;
}
////////////////////////////////////////////////////////////////////////
int perso::getDmgMin()
{
	return this->DmgMin;
}







int guerrier::AttackBase()
{
	int dmg;
	srand (time(NULL));

	dmg = rand() % 10 + 1;/* generate secret number between 1 and 10: */
	dmg+=2;
	return dmg;

}

int perso::setPm(int n)
{
	this->PointDeMana=this->PointDeMana-n;
}

int guerrier::CompD()
{	this->setPm(20);
	int dmg=24;
	return dmg;

}

int guerrier::CompDef1()
{

this->AttackBase();
this->AttackBase();

}







int main(){

guerrier p;
cout<<p.CompD()<<endl;
cout<<p.getPointDeMana()<<endl;
return 0;

}
