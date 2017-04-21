#include "Map.h"
#include "Perso.h"

int main(int argc, char const *argv[])
{
	Map map(2);

	//m.modifMap();

	map.affichage();

	guerrier p;
	monster m;

	cout<<"PointDeMana avant utilisation de la CompD : "<<p.getPointDeMana()<<endl;
	cout<<"degat CompD du guerrier : "<<p.CompD()<<endl;
	cout<<"PointDeMana apres utilisation de la CompD : "<<p.getPointDeMana()<<endl;

	cout<<"PointDeVie du monstre : "<<m.getPointDeVie()<<endl;

	m.setPv(p.CompD());

	cout<<"PointDeVie du monstre : "<<m.getPointDeVie()<<endl;

	map.affichageWM();

	return 0;

}