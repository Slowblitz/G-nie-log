#include "Case.h"

Case::Case()
{
	x=0;
	y=0;
	ini=0;
	cntn="0";
}

Case::Case(int a, int b)
{
	x=a;
	y=b;
	ini=0;
	cntn="0";
}

Case::Case(int a, int b, int i, char s)
{
	x=a;
	y=b;
	ini=i;
	cntn=s;
}

int Case::getx()
{ return x; }

int Case::gety()
{ return y; }

string Case::getcntn()
{ return cntn; }

void Case::modifcntnC(string s)
{ cntn=s; }
