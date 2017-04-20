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

    	this->taille=t;

    	//cerr<<t<<endl;
	
		mp=new Case*[taille];

		for (int i=0; i < taille; i++)
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
	else cerr<<"dkjkhgf";
}

void Map::affichage()
{
	for(int i=0; i<taille; i++)
	{	
		for(int j=0; j<taille; j++)
		{
			cout<<""<<mp[i][j].getcntn()<<" ";//PlaPla[i][j].getclr();
		}

		cerr<<endl;
	}
}