#include "diod.h"



diod::diod()
{
	
	corps = "";
}

diod::diod(int id, int coast, string creator, string model, string corps):
	semiconductor(id, coast, creator, model),  corps(corps)//semiconductor delete
{

}

diod::~diod()
{
}



void diod::setcorps(string n)
{
	corps = n;
}

string diod::getcorps()
{
	return corps;
}

bool diod::operator== (diod &sem)
{
	if (this->semiconductor::operator== (dynamic_cast<semiconductor&>(sem)) && (corps == sem.corps|| sem.corps == ""))
		return true;
	return false;
}

diod& diod::operator= (diod &sem)
{
	this->semiconductor::operator= (dynamic_cast<semiconductor&>(sem));
	this->corps = sem.corps;
	return *this;
}

void diod::toStream(ostream& os)
{
	semiconductor::toStream(os);
	os << corps << setw(30);
}

ostream& operator << (ostream& os, diod& wt)
{
	wt.toStream(os);
	return os;
}

istream& operator >> (istream& is, diod& dt)
{
	is >> (dynamic_cast<semiconductor&>(dt));
	dt.corps = checkString("Enter Corps: ");
	return is;
}

void diod::table()
{
	semiconductor::table();
	cout <<"Corps"<< setw(30);
}

fstream& operator >> (fstream& is, diod& dt)
{
	is >> (dynamic_cast<semiconductor&>(dt));
	is >> dt.corps;
	return is;
}

fstream& operator << (fstream& os, diod& wt)
{
	wt.tofStream(os);
	return os;
}

void diod::tofStream(ostream& os)
{
	semiconductor::tofStream(os);
	os <<corps << " ";
}

void diod::inp()
{
	semiconductor::inp();
	int ch;
	cout << "Do you want to find by corps?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setcorps(checkString("Enter corps: "));
	}
}