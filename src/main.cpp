#include "Map.h"
#include "Perso.h"

int main(int argc, char const *argv[])
{
	Map map(2);

	guerrier p;
	monster m;

	map.affichage();


	string s;
	bool cdn;

	
	do
	{
		do
		{
			cout<<"choisissez une direction (haut -> h ou z / bas -> b ou s / gauche -> g ou q / droite -> d)"<<endl;
			cin>>s;

			system("clear");

			cdn=map.trouveJ(s,p,m);

		}while((!cdn && p.getPointDeVie()>0) /*|| !cdn*/);

		if(p.getPointDeVie()<=0)
		{
			cout<<"GAME OVER!!!"<<endl;

			exit(1);
		}

		else if(map.cmptM())
		{
			cout<<"Vous Avez Gagnez!!!"<<endl;

			exit(1);
		}

		map.affichage();



	}while(1); /////  faire fonction nb monstre 

	return 0;

}