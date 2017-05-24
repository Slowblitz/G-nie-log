#include "Map.h"


int main(int argc, char const *argv[])
{
	int n=0,m=0;

	string nn,mm;

	bool bn=true,bm=true;

	Map *map;
	perso *player;	

	system("clear");

	cout<<"Bienvenu dans notre jeu E-gam"<<endl;

	string b="n";

	do
	{
		if(b != "n" && b != "o") cout<<"\033[1;37;41mimpossible entrez [o/n]\033[0m"<<endl;
		cout<<"voulez vous charger une partie? [o/n]"<<endl;
		cin>>b;

	}while(b != "n" && b != "o");

	if(b == "o")
	{
		int nj;

		map=new Map("save.dat");

		ifstream fichierJ("saveJ.dat",ios::in);

		fichierJ>>nj;

		fichierJ.close();

		if(nj==1) player=new guerrier();
		else if(nj==2) player=new mage();
		else if(nj==3) player=new guerisseur();

		system("clear");
	}


	else if(b == "n")
	{
		system("clear");

		do
		{
			if(!bn) cout<<"\033[1;37;41mimpossible entrez 1 ou 2 ou 3\033[0m"<<endl;

			cout<<"choisissez une carte:   1 -> map1 (10*10) -- 5 monstres"<<endl;
			cout<<"                        2 -> map2 (20*20) -- 10 monstres"<<endl;
			cout<<"                        3 -> map3 (40*40) -- 20 monstres"<<endl;
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
		else if(m==3) player=new guerisseur();

	}

	string dif="n";

	do
	{
		if(dif != "n" && dif != "o") cout<<"\033[1;37;41mimpossible entrez [o/n]\033[0m"<<endl;
		cout<<"voulez vous que les monstres bouges? [o/n]"<<endl;
		cin>>dif;

	}while(dif != "n" && dif != "o");


	monster monster;

	system("clear");
	map->affichage();

	string s="z";
	bool cdn=true;

	do
	{
		do
		{
			if(s != "z" && s != "Z" && s != "s" && s != "S" && s != "q" && s != "Q" && s != "d" && s != "D" && s != "e")
			{ 
				system("clear");
				map->affichage();
				cout<<"\033[1;37;41mimpossible entrez [z|q|s|d] pour les directions, [e] pour quitter\033[0m"<<endl;
			}

			if(!cdn)
			{
				system("clear");
				map->affichage();
				cout<<"\033[1;37;41mimpossible vous rencontrez un obstacle\033[0m"<<endl;
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

			if(s == "z" || s == "Z" || s == "s" || s == "S" || s == "q" || s == "Q" || s == "d" || s == "D") 
			{
				cdn=map->trouveJ(s,*player,monster,m);
				if(dif == "o") map->bougeM();
			}

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
		map->affichage();

	}while(1);

	return 0;
}