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

		}while(!cdn && p.getPointDeVie()>0);

		if(p.getPointDeVie()<=0)
		{
			system("clear");
			cout<<"GAME OVER!!!"<<endl;

			exit(1);
		}

		else if(map.cmptM())
		{
			system("clear");
			cout<<"Vous Avez Gagnez!!!"<<endl;

			exit(1);
		}

		system("clear");
		map.affichage();



	}while(1); 

	return 0;

}