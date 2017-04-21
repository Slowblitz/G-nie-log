#include "Map.h"


Map::Map(int n)
{
	ifstream fichier("map1.txt",ios::in);
    
    if(fichier)
    {

    	string ligne;
    	int nLigne=0;
    	int t;

    	fichier >> t;

    	taille=t;

    	//cerr<<t<<endl;
	
		mp=new Case*[taille];

		if(!fichier.eof())getline(fichier,ligne);

		for (int i=0; i < taille+1; i++)
		{
			if(!fichier.eof())getline(fichier,ligne);
			mp[i]=new Case[taille];

			for (int j=0; j < taille; j++)
			{
				mp[i][j]=Case(i,j,0,ligne[j]);
				//mp[i][j].modifcntnC("B");
			}
		}

	}
	else cerr<<"error";
}

void Map::affichage()
{
	//cerr<<"--TEST--"<<endl;
	for(int i=0; i<taille; i++)
	{	
		
		for(int j=0; j<taille; j++)
		{
			cerr<<""<<mp[i][j].getcntn()<<" ";
		}

		cerr<<endl;
	}
}