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
		bool trouveJ(string s, perso &p, monster m, int n);
		bool combat(perso &p, monster &m);

		void bougeM();

		bool save(int n);
		void appelSave(int n);

		friend class Case;	
};

bool verifEntree(string s,int &n);