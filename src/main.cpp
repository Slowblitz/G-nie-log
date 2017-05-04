#include "Map.h"
#include "Perso.h"

int main(int argc, char const *argv[])
{
	int n=0,m=0;


	perso *player;
	Map *map;

	cout<<"Bienvenu dans notre jeu E-gam"<<endl;
	cout<<"choisissez une carte:   1 -> map1 (10*10)"<<endl;
	cout<<"                        2 -> map2 (25*25)"<<endl;
	cout<<"                        3 -> map3 (50*50)"<<endl;
	cin>>n;

	if(n==1) map=new Map("map1.dat");
	else if(n==2) map=new Map("map1.dat");
	else if(n==3) map=new Map("map1.dat");

	cout<<"choisissez une classe:   1 -> guerrier"<<endl;
	cout<<"                         2 -> mage"<<endl;
	cout<<"                         3 -> guerriseur"<<endl;
	cin>>m;

	if(m==1) player=new guerrier();
	else if(m==2) player=new mage();
	else if(m==3) player=new guerriseur();

	monster monster;
//player = new guerrier();
	map->affichageWM();


	string s;
	bool cdn;

	

	do
	{
		do
		{
			cout<<"choisissez une direction (haut -> h ou z / bas -> b ou s / gauche -> g ou q / droite -> d)"<<endl;
			cin>>s;

			system("clear");

			cdn=map->trouveJ(s,*player,monster);

		}while(!cdn && player->getPointDeVie()>0);

		if(player->getPointDeVie()<=0)
		{
			system("clear");
			cout<<"GAME OVER!!!"<<endl;

			exit(1);
		}

		else if(map->cmptM())
		{
			system("clear");
			cout<<"Vous Avez Gagner!!!"<<endl;

			exit(1);
		}

		system("clear");
		map->affichageWM();



	}while(1);


	return 0;

}