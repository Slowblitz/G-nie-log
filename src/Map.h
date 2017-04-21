#include "Case.h"
//#include "Joueur.h"



class Map
{
	Case ** mp;
	int taille;
	

public:

	Map(int n);

	void affichage();
	void affichageWM();
	/*bool coupjoue(int x, int y, Joueur J);
	int getnbTotalCase();
	bool MapPlein(int n);
	int getRayon();*/

	friend class Case;
	
};

/*void ClearScreen();
bool verifChaine(string c);
bool verifTailleMap(int n);*/