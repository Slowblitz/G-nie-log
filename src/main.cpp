#include "Map.h"


int main(int argc, char const *argv[])
{
	int n=0,m=0;

	string nn,mm;

	bool bn=true,bm=true;

	Map *map;
	perso *player;	

	system("clear");

	do
	{
		if(!bn) cout<<"\033[1;37;41mimpossible entrez 1 ou 2 ou 3\033[0m"<<endl;

		cout<<"Bienvenu dans notre jeu E-gam"<<endl;
		cout<<"choisissez une carte:   1 -> map1 (10*10) -- 5 monstres"<<endl;
		cout<<"                        2 -> map2 (20*20) -- 10 monstres"<<endl;
		cout<<"                        3 -> map3 (30*30) -- 15 monstres"<<endl;
		cin>>nn;
		bn=verifEntree(nn,n);

	}while(!bn);


	if(n==1) map=new Map("map1.dat");
	else if(n==2) map=new Map("map2.dat");
	else if(n==3) map=new Map("map3.dat");


	do
	{
		if(!bm) cout<<"\033[1;37;41mimpossible entrez 1 ou 2 ou 3\033[0m"<<endl;

		cout<<"choisissez une classe:   1 -> guerrier"<<endl;
		cout<<"                         2 -> mage"<<endl;
		cout<<"                         3 -> guerriseur"<<endl;
		cin>>mm;
		bm=verifEntree(mm,m);

	}while(!bm);


	if(m==1) player=new guerrier();
	else if(m==2) player=new mage();
	else if(m==3) player=new guerriseur();


	monster monster;

	system("clear");
	map->affichageWM();

	string s="z";
	bool cdn=true;

	do
	{
		do
		{
			if(s != "z" && s != "Z" && s != "s" && s != "S" && s != "q" && s != "Q" && s != "d" && s != "D" && s != "e")
			{ 
				system("clear");
				map->affichageWM();
				cerr<<"\033[1;37;41mimpossible entrez [z|q|s|d] pour les directions, [e] pour quitter\033[0m"<<endl;
			}

			if(!cdn)
			{
				system("clear");
				map->affichageWM();
				cerr<<"\033[1;37;41mimpossible vous rencontrez un obstacle\033[0m"<<endl;
			}

			cout<<"choisissez une direction (haut -> z|Z / bas -> s|S / gauche -> q|Q / droite -> d|D)"<<endl;
			cout<<"\033[1;37;42mvous pouvez aussi quitter la partie -> e \033[0m"<<endl;
			cin>>s;

			if(s=="e")
			{
				system("clear");
				cout<<"vous avez quitté la partie, à bientôt"<<endl;
				exit(1);
			}

			system("clear");

			if(s == "z" || s == "Z" || s == "s" || s == "S" || s == "q" || s == "Q" || s == "d" || s == "D") cdn=map->trouveJ(s,*player,monster);

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