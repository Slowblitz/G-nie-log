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
	else cerr<<"erreur";
}

void Map::affichage()
{
	for(int o=0; o<taille+1; o++)
	{
		if(o==taille-1)cerr<<"-";
		else cerr<<"--";
	}
		cerr<<endl;
	
	for(int i=0; i<taille; i++)
	{	
		
		for(int j=0; j<taille; j++)
		{
			if(j==0)cerr<<"|"<<mp[i][j].getcntn()<<" ";
			else if(j==taille-1)cerr<<""<<mp[i][j].getcntn();
			else cerr<<""<<mp[i][j].getcntn()<<" ";
		}

		cerr<<"|"<<endl;
	}
	for(int o=0; o<taille+1; o++)
	{
		if(o==taille-1)cerr<<"-";
		else cerr<<"--";
	}
		cerr<<endl;
}


void Map::affichageWM()
{
	for(int o=0; o<taille+1; o++)
	{
		if(o==taille-1)cerr<<"-";
		else cerr<<"--";
	}
		cerr<<endl;
	
	for(int i=0; i<taille; i++)
	{	
		
		for(int j=0; j<taille; j++)
		{
			if(j==0)
			{
				if(mp[i][j].getcntn()=="M")cerr<<"|"<<" "<<" ";
				else cerr<<"|"<<mp[i][j].getcntn()<<" ";
			}

			else if(j==taille-1)
			{
				if(mp[i][j].getcntn()=="M")cerr<<" ";
				else cerr<<mp[i][j].getcntn();
			}

			else 
			{
				if(mp[i][j].getcntn()=="M")cerr<<" "<<" ";
				else cerr<<mp[i][j].getcntn()<<" ";
			}
		}

		cerr<<"|"<<endl;
	}
	for(int o=0; o<taille+1; o++)
	{
		if(o==taille-1)cerr<<"-";
		else cerr<<"--";
	}
		cerr<<endl;
}

bool Map::trouveJ(string s, guerrier &p, monster &m)
{
	for (int i=0; i < taille+1; i++)
	{
		for (int j=0; j < taille; j++)
		{
			if(mp[i][j].getcntn()=="J")
			{
				if(s=="h" || s=="^[[A")
				{
					if(i>0 && i<taille)
					{
						if(mp[i-1][j].getcntn()=="*" || mp[i-1][j].getcntn()=="^" || mp[i-1][j].getcntn()=="~") return false;

						else if(mp[i-1][j].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i-1][j].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else if(s=="b" || s=="^[[B")
				{
					if(i>=0 && i<taille-1)
					{
						if(mp[i+1][j].getcntn()=="*" || mp[i+1][j].getcntn()=="^" || mp[i+1][j].getcntn()=="~") return false;

						else if(mp[i+1][j].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i+1][j].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else if(s=="g" || s=="^[[D")
				{
					if(j>0 && j<taille)
					{
						if(mp[i][j-1].getcntn()=="*" || mp[i][j-1].getcntn()=="^" || mp[i][j-1].getcntn()=="~") return false;

						else if(mp[i][j-1].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i][j-1].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else if(s=="d" || s=="^[[C")
				{
					if(j>=0 && j<taille-1)
					{
						if(mp[i][j+1].getcntn()=="*" || mp[i][j+1].getcntn()=="^" || mp[i][j+1].getcntn()=="~") return false;

						else if(mp[i][j+1].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i][j+1].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else return false;
			}
			//mp[i][j].modifcntnC("B");
		}
	}
}

bool Map::trouveJ(string s, mage &p, monster &m)
{
	for (int i=0; i < taille+1; i++)
	{
		for (int j=0; j < taille; j++)
		{
			if(mp[i][j].getcntn()=="J")
			{
				if(s=="h" || s=="^[[A")
				{
					if(i>0 && i<taille)
					{
						if(mp[i-1][j].getcntn()=="*" || mp[i-1][j].getcntn()=="^" || mp[i-1][j].getcntn()=="~") return false;

						else if(mp[i-1][j].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i-1][j].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else if(s=="b" || s=="^[[B")
				{
					if(i>=0 && i<taille-1)
					{
						if(mp[i+1][j].getcntn()=="*" || mp[i+1][j].getcntn()=="^" || mp[i+1][j].getcntn()=="~") return false;

						else if(mp[i+1][j].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i+1][j].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else if(s=="g" || s=="^[[D")
				{
					if(j>0 && j<taille)
					{
						if(mp[i][j-1].getcntn()=="*" || mp[i][j-1].getcntn()=="^" || mp[i][j-1].getcntn()=="~") return false;

						else if(mp[i][j-1].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i][j-1].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else if(s=="d" || s=="^[[C")
				{
					if(j>=0 && j<taille-1)
					{
						if(mp[i][j+1].getcntn()=="*" || mp[i][j+1].getcntn()=="^" || mp[i][j+1].getcntn()=="~") return false;

						else if(mp[i][j+1].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i][j+1].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else return false;
			}
			//mp[i][j].modifcntnC("B");
		}
	}
}

bool Map::trouveJ(string s, guerriseur &p, monster &m)
{
	for (int i=0; i < taille+1; i++)
	{
		for (int j=0; j < taille; j++)
		{
			if(mp[i][j].getcntn()=="J")
			{
				if(s=="h" || s=="^[[A")
				{
					if(i>0 && i<taille)
					{
						if(mp[i-1][j].getcntn()=="*" || mp[i-1][j].getcntn()=="^" || mp[i-1][j].getcntn()=="~") return false;

						else if(mp[i-1][j].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i-1][j].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else if(s=="b" || s=="^[[B")
				{
					if(i>=0 && i<taille-1)
					{
						if(mp[i+1][j].getcntn()=="*" || mp[i+1][j].getcntn()=="^" || mp[i+1][j].getcntn()=="~") return false;

						else if(mp[i+1][j].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i+1][j].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else if(s=="g" || s=="^[[D")
				{
					if(j>0 && j<taille)
					{
						if(mp[i][j-1].getcntn()=="*" || mp[i][j-1].getcntn()=="^" || mp[i][j-1].getcntn()=="~") return false;

						else if(mp[i][j-1].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i][j-1].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else if(s=="d" || s=="^[[C")
				{
					if(j>=0 && j<taille-1)
					{
						if(mp[i][j+1].getcntn()=="*" || mp[i][j+1].getcntn()=="^" || mp[i][j+1].getcntn()=="~") return false;

						else if(mp[i][j+1].getcntn()=="M")
						{

						}
						
						else
						{
							mp[i][j+1].modifcntnC("J");
							mp[i][j].modifcntnC(" ");

							return true;
						}
					}

					else return false;
				}

				else return false;
			}
			//mp[i][j].modifcntnC("B");
		}
	}
}

bool Map::combat(guerrier &p, monster &m)
{
	while(p.getPointDeVie()!=0 && m.getPointDeVie()!=0)
	{
		
	}
}


