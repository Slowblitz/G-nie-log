#include "Perso.h"
#include "Map.h"


/**
 * @brief [constructeur]
 * @details [constructeur en fonction du perso.dat]
 */
perso::perso()
{
	ifstream fichier("Perso.dat", ios::in);  // on ouvre le fichier en lecture
 	
        if(fichier)  // si l'ouverture a réussi
        {           
			string name;  // déclaration d'une chaîne qui contiendra la ligne lue
			int PointDeVie,PointDeMana,DmgMin,DmgMax;
               	
            fichier >> name >> PointDeVie >> PointDeMana >> DmgMin >> DmgMax;
            fichier.close();  // on ferme le fichier
			
			this->nom=name;
			this->PointDeVie=PointDeVie;
			this->PointDeVieMax=PointDeVie;
			this->PointDeMana=PointDeMana;
			this->PointDeManaMax=PointDeMana;
			this->DmgMin=DmgMin;
			this->DmgMax=DmgMax;	
        }

        else 	cerr << "Impossible d'ouvrir le fichier !" << endl;      
}


/**
 * @brief [retourne nom]
 * @details [retourne le nom du perso aka joueur]
 * @return [retourne un string]
 */
string perso::getname()
{ return this->nom; }


/**
 * @brief [retourne les points de vie]
 * @details [retourne les points de vie du perso aka joueur]
 * @return [retourne un entier]
 */
int perso::getPointDeVie()
{ return this->PointDeVie; }


/**
 * @brief [retourne les points de vie]
 * @details [retourne les points de vie du perso aka joueur]
 * @return [retourne un entier]
 */
int perso::getPointDeVieMax()
{ return this->PointDeVieMax; }


/**
 * @brief [retourne les points de mana maximum]
 * @details [retourne les points de mana maximum du perso aka joueur]
 * @return [retourne un entier]
 */
int perso::getPointDeMana()
{ return this->PointDeMana; }


/**
 * @brief [retourne les points de mana maximum]
 * @details [retourne les points de mana maximum du perso aka joueur]
 * @return [retourne un entier]
 */
int perso::getPointDeManaMax()
{ return this->PointDeManaMax; }


/**
 * @brief [retourne les degats maximum]
 * @details [retourne les degats maximum du perso aka joueur]
 * @return [retourne un entier]
 */
int perso::getDmgMax()
{ return this->DmgMax; }


/**
 * @brief [retourne les degats minimum]
 * @details [retourne les degats minimum du perso aka joueur]
 * @return [retourne un entier]
 */
int perso::getDmgMin()
{ return this->DmgMin; }


/**
 * @brief [modifie les points de mana]
 * @details [modifie les points de mana du perso aka joueur a partir des couts d'une attaque]
 * 
 * @param n [entier, cout en mana d'un attaque]
 */
void perso::setPm(int n)
{ this->PointDeMana-=n; }


/**
 * @brief [modifie les points de mana]
 * @details [modifie les points de mana du perso aka joueur a partir d'une competence de def du joueur (ajout mana)]
 * 
 * @param n [entier, compt def joueur ]
 */
void perso::setPmP(int n)
{
	if(this->PointDeMana+n > this->PointDeManaMax) this->PointDeMana=this->PointDeManaMax;

	else this->PointDeMana+=n;
}


/**
 * @brief [modifie les points de vie]
 * @details [modifie les points de vie du perso aka joueur a partir des degats fait par un monstre]
 * 
 * @param n [entier, degats fait par un monstre]
 */
void perso::setPv(int n)
{
	if(this->PointDeVie<=0) this->PointDeVie=0;

	else if(this->PointDeVie>0) this->PointDeVie=this->PointDeVie-n;
}


/**
 * @brief [modifie les points de vie]
 * @details [modifie les points de vie du perso aka joueur a partir d'une competence defence du joueur (ajout vie)]
 * 
 * @param n [entier, compt def joueur]
 */
void perso::setPvP(int n)
{
	if(this->PointDeVie+n > this->PointDeVieMax) this->PointDeVie=this->PointDeVieMax;

	else this->PointDeVie+=n;
}


/**
 * @brief [reset points de mana]
 * @details [reset points de mana du perso aka joueur après un combat]
 * 
 * @param n [entier, point de mana du perso en debut de partie]
 */
void perso::resetPm(int n)
{ this->PointDeMana=n; }


/**
 * @brief [reset points de vie]
 * @details [reset points de vie du perso aka joueur après un combat]
 * 
 * @param n [entier, point de vie du perso en debut de partie]
 */
void perso::resetPv(int n)
{ this->PointDeVie=n; }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief [attaque de base]
 * @details [attaque de base du guerrier en fonction d'un random entre les degats minimumet maximum]
 * 
 * @param time [pour le random en fonction du temps]
 * @return [entier, points de degats de la competence]
 */
int guerrier::AttackBase()
{
	srand (time(NULL));

	int dmg = rand() % this->getDmgMax() + this->getDmgMin();/* generate secret number between 1 and 10: */
	dmg+=2;

	cout<<"\n\033[1;32mVos dmg: "<<dmg<<"\033[0m"<<endl;

	return dmg;
}


/**
 * @brief [competence degat 1]
 * @details [competence degat 1 du guerrier, elle utilise du mana]
 * @return [entier, points de degats de la competence]
 */
int guerrier::CompD()
{	this->setPm(35);
	int dmg=24;

	cout<<"\n\033[1;32mVos dmg: "<<dmg<<"\033[0m"<<endl;

	return dmg;
}


/**
 * @brief [competence degat plus]
 * @details [competence degat, deuxieme du nom du guerrier, elle utilise aussi du MANA]
 * @return [et elle retourne deux attaques de base]
 */
int guerrier::CompDp()
{
	this->setPm(20);
	int a=this->AttackBase();
	int b=this->AttackBase();

	return a+b;
}


/**
 * @brief [choix d'une competence]
 * @details [choix d'une competence de la classe guerrier]
 * @return [un entier en fonction de l'attaque choisie]
 */
int guerrier::choiceCmp()
{	
	srand(time(NULL));

	int rnd = rand() % 3 + 1;

	int n=0;
	string nn;
	bool bn=true;

	do
	{
		if(!bn) cout<<"\033[1;37;41mimpossible entrez 1 ou 2 ou 3\033[0m"<<endl;

		cout<<"choisir une compétence:  1 - AttackBase   (degats["<<this->getDmgMin()<<"/"<<this->getDmgMax()<<"]+2 -> 0 mana)"<<endl;
		cout<<"                         2 - Competence 1 (degats[20] -> 35 mana)"<<endl;
		cout<<"                         3 - Competence 2 (2xAttackBase -> 20 mana)"<<endl;
		
		cin>>nn;
		bn=verifEntree(nn,n);

	}while(!bn);

	if(n==1)
	{ 
		cout<<"\033[1;36m0 PM utilisé\033[0m"<<endl;
		return AttackBase();
	}

	else if(n==2 && this->getPointDeMana()>=35)
	{ 
		cout<<"\033[1;36m35 PM utilisé\033[0m"<<endl;
		return CompD();
	}

	else if(n==3 && this->getPointDeMana()>=20)
	{ 
		cout<<"\033[1;36m20 PM utilisé\033[0m"<<endl;
		return CompDp();
	}

	else
	{ 
		if(rnd==1) cout<<"\n\033[1;37;41mpas assez de mana!!!\033[0m"<<endl; 
		else if(rnd==2) cout<<"\n\033[1;37;41mil me faut plus de mana!!!\033[0m"<<endl;
		else if(rnd==3) cout<<"\n\033[1;37;41mAllo Huston, nous avons un probleme, j'ai plus de MANA!!!\033[0m"<<endl;
		cout<<"PM du joueur: "<<this->getPointDeMana()<<"\n"<<endl;
		return choiceCmp();
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief [attaque de base]
 * @details [attaque de base du guerrier en fonction d'un random entre les degats minimumet maximum]
 * 
 * @param time [pour le random en fonction du temps]
 * @return [entier, points de degats de la competence]
 */
int mage::AttackBase()
{
	srand (time(NULL));

	int dmg = rand() % this->getDmgMax() + this->getDmgMin();/* generate secret number between 1 and 10: */

	cout<<"\033[1;32mVos dmg: "<<dmg<<"\033[0m"<<endl;

	return dmg;
}


/**
 * @brief [competence degat 1]
 * @details [competence degat 1 du guerrier, elle utilise du mana]
 * @return [entier, points de degats de la competence]
 */
int mage::CompD()
{	
	srand (time(NULL));

	this->setPm(70);

	int dmg = rand() % this->getDmgMax()*4 + this->getDmgMax()*4;

	cout<<"\033[1;32mVos dmg: "<<dmg<<"\033[0m"<<endl;
	
	return dmg;
}


/**
 * @brief [competence degat plus]
 * @details [competence degat, deuxieme du nom du guerrier, elle utilise aussi du MANA]
 * @return [et elle retourne deux attaques de base]
 */
int mage::CompDef1()
{
	srand (time(NULL));

	this->setPm(15);

	int manaP = rand() % (this->getDmgMax()*5) + (this->getDmgMax()/2);

	cout<<"\033[1;32mPM ajouté: "<<manaP<<"\033[0m"<<endl;
	
	this->setPmP(manaP);

	return 0;
}


/**
 * @brief [choix d'une competence]
 * @details [choix d'une competence de la classe guerrier]
 * @return [un entier en fonction de l'attaque choisie]
 */
int mage::choiceCmp()
{	
	srand (time(NULL));

	int rnd = rand() % 3 + 1;

	int n=0;
	string nn;
	bool bn=true;

	do
	{
		if(!bn) cout<<"\033[1;37;41mimpossible entrez 1 ou 2 ou 3\033[0m"<<endl;

		cout<<"choisir une compétence:  1 - AttackBase   (degats["<<this->getDmgMin()<<"/"<<this->getDmgMax()<<"] -> 0 mana)"<<endl;
		cout<<"                         2 - Competence 1 (degats["<<this->getDmgMax()*4<<"/"<<this->getDmgMax()*8<<"] -> 70 mana)"<<endl;
		cout<<"                         3 - Competence 2 (ajout PM["<<this->getDmgMax()/2<<"/"<<this->getDmgMax()*5<<"]  -> 15 mana)"<<endl;
		
		cin>>nn;
		bn=verifEntree(nn,n);

	}while(!bn);

	if(n==1)
	{ 
		cout<<"\033[1;36m0 PM utilisé\033[0m"<<endl;
		return AttackBase();
	}

	else if(n==2 && this->getPointDeMana()>=70)
	{ 
		cout<<"\033[1;36m70 PM utilisé\033[0m"<<endl;
		return CompD();
	}

	else if(n==3 && this->getPointDeMana()>=15)
	{
		cout<<"\033[1;36m15 PM utilisé\033[0m"<<endl;
		return CompDef1();
	}

	else
	{ 
		if(rnd==1) cout<<"\n\033[1;37;41mpas assez de mana!!!\033[0m"<<endl; 
		else if(rnd==2) cout<<"\n\033[1;37;41mil me faut plus de mana!!!\033[0m"<<endl;
		else if(rnd==3) cout<<"\n\033[1;37;41mAllo Huston, nous avons un probleme, j'ai plus de MANA!!!\033[0m"<<endl;
		cout<<"PM du joueur: "<<this->getPointDeMana()<<"\n"<<endl;
		return choiceCmp();
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief [attaque de base]
 * @details [attaque de base du guerrier en fonction d'un random entre les degats minimumet maximum]
 * 
 * @param time [pour le random en fonction du temps]
 * @return [entier, points de degats de la competence]
 */
int guerriseur::AttackBase()
{
	srand (time(NULL));

	int dmg = rand() % this->getDmgMax() + this->getDmgMin();/* generate secret number between 1 and 10: */

	cout<<"\033[1;32mVos dmg: "<<dmg<<"\033[0m"<<endl;

	return dmg;
}


/**
 * @brief [competence degat 1]
 * @details [competence degat 1 du guerrier, elle utilise du mana]
 * @return [entier, points de degats de la competence]
 */
int guerriseur::CompD()
{	
	srand (time(NULL));

	this->setPm(35);

	int dmg = rand() % this->getDmgMax()*2 + this->getDmgMax()*2;

	cout<<"\033[1;32mVos dmg: "<<dmg<<"\033[0m"<<endl;
	
	return dmg;
}


/**
 * @brief [competence degat plus]
 * @details [competence degat, deuxieme du nom du guerrier, elle utilise aussi du MANA]
 * @return [et elle retourne deux attaques de base]
 */
int guerriseur::CompDef1()
{
	srand (time(NULL));

	this->setPm(10);

	int vieP = rand() % (this->getDmgMax()*2) + this->getDmgMax();

	cout<<"\033[1;32mPV ajouté: "<<vieP<<"\033[0m"<<endl;
	
	this->setPvP(vieP);

	return 0;
}


/**
 * @brief [choix d'une competence]
 * @details [choix d'une competence de la classe guerrier]
 * @return [un entier en fonction de l'attaque choisie]
 */
int guerriseur::choiceCmp()
{	
	srand (time(NULL));

	int rnd = rand() % 3 + 1;

	int n=0;
	string nn;
	bool bn=true;

	do
	{
		if(!bn) cout<<"\033[1;37;41mimpossible entrez 1 ou 2 ou 3\033[0m"<<endl;

		cout<<"choisir une compétence:  1 - AttackBase   (degats["<<this->getDmgMin()<<"/"<<this->getDmgMax()<<"] -> 0 mana)"<<endl;
		cout<<"                         2 - Competence 1 (degats["<<this->getDmgMax()*2<<"/"<<this->getDmgMax()*4<<"] -> 35 mana)"<<endl;
		cout<<"                         3 - Competence 2 (ajout PV["<<this->getDmgMax()<<"/"<<this->getDmgMax()*3<<"]  -> 10 mana)"<<endl;
		
		cin>>nn;
		bn=verifEntree(nn,n);

	}while(!bn);

	if(n==1)
	{ 
		cout<<"\033[1;36m0 PM utilisé\033[0m"<<endl;
		return AttackBase();
	}

	else if(n==2 && this->getPointDeMana()>=35)
	{ 
		cout<<"\033[1;36m35 PM utilisé\033[0m"<<endl;
		return CompD();
	}

	else if(n==3 && this->getPointDeMana()>=10)
	{ 
		cout<<"\033[1;36m10 PM utilisé\033[0m"<<endl;
		return CompDef1();
	}
	else
	{ 
		if(rnd==1) cout<<"\n\033[1;37;41mpas assez de mana!!!\033[0m"<<endl; 
		else if(rnd==2) cout<<"\n\033[1;37;41mil me faut plus de mana!!!\033[0m"<<endl;
		else if(rnd==3) cout<<"\n\033[1;37;41mAllo Huston, nous avons un probleme, j'ai plus de MANA!!!\033[0m"<<endl;
		cout<<"PM du joueur: "<<this->getPointDeMana()<<"\n"<<endl;
		return choiceCmp();
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief [constructeur]
 * @details [constructeur d'un monstre en fonction du fichier Monster.dat]
 */
monster::monster()
{
	ifstream fichier("Monster.dat", ios::in);  // on ouvre le fichier en lecture
 	
        if(fichier)  // si l'ouverture a réussi
        {           
			string name;  // déclaration d'une chaîne qui contiendra la ligne lue
			int PointDeVie,DmgMin,DmgMax;
            
            fichier >> PointDeVie >>  DmgMin >> DmgMax;
            fichier.close();  // on ferme le fichier
			
			this->PointDeVie=PointDeVie;
			this->PointDeVieMax=PointDeVie;
			this-> DmgMin= DmgMin;
			this-> DmgMax= DmgMax;	
        }
        
        else  cerr << "Impossible d'ouvrir le fichier !" << endl;      
}


/**
 * @brief [attaque de base]
 * @details [attaque de base du monstre, c'est d'ailleurs sa seul attaque]
 * 
 * @param time [description]
 * @return [entier, degat en fonction d'un random entre ses degats minimum et maximum]
 */
int monster::AttackBase()
{
	srand (time(NULL));

	int  dmg = rand() % this->getDmgMax() + this->getDmgMin();/* generate secret number between 1 and 10: */

	cout<<"\033[1;31mdmg fait par le monstre: "<<dmg<<"\033[0m"<<endl;
	
	return dmg;
}


/**
 * @brief [retourne les points de vie du monstre]
 * @details [retourne les points de vie du monstre]
 * @return [entier]
 */
int monster::getPointDeVie()
{ return this->PointDeVie; } 


/**
 * @brief [retourne les points de vie maximum du monstre]
 * @details [retourne les points de vie maximum du monstre]
 * @return [entier]
 */
int monster::getPointDeVieMax()
{ return this->PointDeVieMax; }


/**
 * @brief [retourne les degats max]
 * @details [retourne les degats max du monstre]
 * @return [entier]
 */int monster::getDmgMax()
{ return this->DmgMax; }


/**
 * @brief [retourne les degats min]
 * @details [retourne les degats min du monstre]
 * @return [entier]
 */
int monster::getDmgMin()
{ return this->DmgMin; }


/**
 * @brief [modifie les points de vie]
 * @details [modifie les points de vie du monstre]
 * 
 * @param n [entier, issue d'une attaque du joueur]
 */
void monster::setPv(int n)
{
	if(this->PointDeVie<=0) this->PointDeVie=0;

	else if(this->PointDeVie>0) this->PointDeVie=this->PointDeVie-n;
}