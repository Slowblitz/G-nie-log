#include "Case.h"


/**
 * @brief [constructeur]
 * @details [constructeur sans arguments]
 */
Case::Case()
{
	x=0;
	y=0;
	cntn="0";
}


/**
 * @brief [constructeur]
 * @details [constructeur avec arguments avec char]
 * 
 * @param a [coordonnee x]
 * @param b [coordonnee y]
 * @param s [caractere pour initialiser la case de la map]
 */
Case::Case(int a, int b, char s)
{
	x=a;
	y=b;
	cntn=s;
}


/**
 * @brief [retourne contenu]
 * @details [retourne contenu]
 * @return [retourne contenu]
 */
string Case::getcntn()
{ return cntn; }


/**
 * @brief [modifie le contenu]
 * @details [modifie le contenu par le parametre s]
 * 
 * @param s [caractere]
 */
void Case::modifcntnC(string s)
{ cntn=s; }