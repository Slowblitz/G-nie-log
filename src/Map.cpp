#include "Map.h"

/**
 * @brief [constrcteur]
 * @details [construction de la map en utilisant un fichier .dat]
 * 
 * @param n []
 */
Map::Map(int n)
{
	ifstream fichier("map1.dat",ios::in);
    
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
				mp[i][j]=Case(i,j,ligne[j]);
				//mp[i][j].modifcntnC("B");
			}
		}

	}
	else cerr<<"erreur";
}

/**
 * @brief [affichage]
 * @details [affichage avec monstres en parcourant le tableau ,pour les besoins du dev]
 */
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

/**
 * @brief [affichage]
 * @details [affichage sans monstres en parcourant le tableau]
 */
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

/**
 * @brief [compteur de monstre]
 * @details [compte les monstres restant sur la map]
 * @return [retourne true s'il ne reste aucun monstre sinon false]
 */
bool Map::cmptM()
{
	int n=0;

	for(int i=0; i<taille; i++)
	{	
		
		for(int j=0; j<taille; j++)
		{
			if(mp[i][j].getcntn()=="M") n++;
		}
	}

	if(n==0) return true;

	else return false;
}

/**
 * @brief [trouve le joueur, le déplace si possible et lance un combat si un monstre est trouvé]
 * @details [trouve le joueur, le déplace si possible et lance un combat si un monstre est trouvé]
 * 
 * @param s [chaine de caractere pour la direction]
 * @param p [joueur]
 * @param m [monstre]
 * @return [retourne true si le déplacement est réalisé et si est tué sinon false si impossible de se déplacer ou si le joueur meurt]
 */
bool Map::trouveJ(string s, guerrier &p, monster m)
{
	for (int i=0; i < taille+1; i++)
	{
		for (int j=0; j < taille; j++)
		{
			if(mp[i][j].getcntn()=="J")
			{
				if(s=="h" || s=="z")
				{
					if(i>0 && i<taille)
					{
						if(mp[i-1][j].getcntn()=="*" || mp[i-1][j].getcntn()=="^" || mp[i-1][j].getcntn()=="~") return false;

						else if(mp[i-1][j].getcntn()=="M")
						{
							bool o=this->combat(p,m);

							if(o)
							{
								mp[i-1][j].modifcntnC("J");
								mp[i][j].modifcntnC(" ");

								return true;
							}

							else return false;
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

				else if(s=="b" || s=="s")
				{
					if(i>=0 && i<taille-1)
					{
						if(mp[i+1][j].getcntn()=="*" || mp[i+1][j].getcntn()=="^" || mp[i+1][j].getcntn()=="~") return false;

						else if(mp[i+1][j].getcntn()=="M")
						{
							bool o=this->combat(p,m);

							if(o)
							{
								mp[i+1][j].modifcntnC("J");
								mp[i][j].modifcntnC(" ");

								return true;
							}

							else return false;
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

				else if(s=="g" || s=="q")
				{
					if(j>0 && j<taille)
					{
						if(mp[i][j-1].getcntn()=="*" || mp[i][j-1].getcntn()=="^" || mp[i][j-1].getcntn()=="~") return false;

						else if(mp[i][j-1].getcntn()=="M")
						{
							bool o=this->combat(p,m);

							if(o)
							{
								mp[i][j-1].modifcntnC("J");
								mp[i][j].modifcntnC(" ");

								return true;
							}

							else return false;
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

				else if(s=="d")
				{
					if(j>=0 && j<taille-1)
					{
						if(mp[i][j+1].getcntn()=="*" || mp[i][j+1].getcntn()=="^" || mp[i][j+1].getcntn()=="~") return false;

						else if(mp[i][j+1].getcntn()=="M")
						{
							bool o=this->combat(p,m);

							if(o)
							{
								mp[i][j+1].modifcntnC("J");
								mp[i][j].modifcntnC(" ");

								return true;
							}

							else return false;
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

/**
 * @brief [lance un combat entre le joueur et un monstre]
 * @details [lance un combat entre le joueur et un monstre, il y a un random pour choisir qui commence]
 * 
 * @param p [joueur]
 * @param m [monstre]
 * 
 * @return [retourne true si le joueur gagne sinon false]
 */
bool Map::combat(guerrier &p, monster &m)
{
	srand (time(NULL));
	int rnd=rand() % 2 + 1;

	while(p.getPointDeVie()>0 && m.getPointDeVie()>0)
	{		
		if(rnd==1)	//le joueur joue
		{
			cout<<"A vous de jouez\n"<<endl;

			m.setPv(p.choiceCmp());

			if(m.getPointDeVie()>=0) cout<<"\nPV Monstre: "<<m.getPointDeVie()<<"\n"<<endl;

			rnd=2;

			
		}

		else if(rnd==2)	//le monstre joue
		{
			cout<<"le monstre joue\n"<<endl;

			p.setPv(m.AttackBase());		//le monstre joue et enleve les points de vie au joueur

			if(p.getPointDeVie()>=0) cout<<"PV Joueur: "<<p.getPointDeVie()<<" \nPM joueur: "<<p.getPointDeMana()<<"\n"<<endl;

			rnd=1;
		}
	}

	if(m.getPointDeVie()<=0)
	{
		p.resetPv(100);
		p.resetPm(100);
		
		return true;	
	} 

	else if(p.getPointDeVie()<=0) return false;
}


bool Map::trouveJ(string s, mage &p, monster m)
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

bool Map::trouveJ(string s, guerriseur &p, monster m)
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




