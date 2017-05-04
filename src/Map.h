#include "Case.h"
#include "Perso.h"


class Map
{
	Case ** mp;
	int taille;
	

public:

	Map(string s);

	void affichage();
	void affichageWM();
	bool cmptM();
/*	bool trouveJ(string s, guerrier &p, monster m);
	bool trouveJ(string s, mage &p, monster m);
	bool trouveJ(string s, guerriseur &p, monster m);
*/
	bool trouveJ(string s, perso& p, monster m);
	bool combat(perso &p, monster &m);

	
/*	bool combat(guerrier &p, monster &m);
	bool combat(mage &p, monster &m);
	bool combat(guerriseur &p, monster &m);
*/

	friend class Case;

	//friend bool combat(guerrier &p, monster m);
	
};

//bool combat(guerrier &p, monster m);
