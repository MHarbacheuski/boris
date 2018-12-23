#include "dioprotective.h"

dioprotective::dioprotective()
{
	polarity = "";
	power = 0;	
}

dioprotective::dioprotective(int id, int coast, string creator, string model, string corps,double maxreversvolt, double maxforwardcurrent,string plr, int power) :
	specifications(id, coast, creator, model, maxreversvolt, maxforwardcurrent), polarity(polarity), power(power)
{
	setcorps(corps);
}

//dioprotective::dioprotective(const dioprotective &clone)
//{
//	
//
//}

dioprotective::~dioprotective()
{
}

void dioprotective::setpolarity(string n)
{
	polarity = n;
}

string dioprotective::getpolarity()
{
	return polarity;
}

void dioprotective::setpower(int n)
{
	power = n;
}

int dioprotective::getpower()
{
	return power;
}

dioprotective& dioprotective::operator = (dioprotective & sem)
{
	this->specifications::operator= (dynamic_cast<specifications&>(sem));
	this->polarity = sem.polarity;
	this->power = sem.power;
	this->setcorps(sem.getcorps());
	return *this;
}

void dioprotective::toStream(ostream& os)
{
	specifications::toStream(os);
	os << getcorps() << setw(20) << polarity << setw(15) << power;
}

ostream& operator << (ostream& os, dioprotective& wt)
{
	wt.toStream(os);
	return os;
}

istream& operator >> (istream& is, dioprotective& dt)
{
	is >> (dynamic_cast<specifications&>(dt));

	dt.polarity = checkString("Enter polarity: ");
	dt.power = checkNumber<int>("Enter power: ",1,10000);
	dt.setcorps(checkString("Enter corps: "));
	return is;
}


void dioprotective::table()
{
	specifications::table();
	cout << "Corps" << setw(20) << "Polarity" << setw(15) << "Power,W" << setw(15);
}

bool dioprotective::operator== (dioprotective &sem)
{
	if ((this->getcorps() == sem.getcorps() || sem.getcorps() == "")
		&& this->specifications::operator== (dynamic_cast<specifications&>(sem)))
		if ((this->polarity == sem.polarity || sem.polarity == "") && (this->power == sem.power || sem.power == 0))
			return true;
	return false;
}

fstream& operator >> (fstream& is, dioprotective& dt)
{
	is >> (dynamic_cast<specifications&>(dt));
	string cap;
	is >> cap;
	dt.setcorps(cap);
	
	is >> dt.polarity;
	is >> dt.power;
	return is;
}

fstream& operator << (fstream& os, dioprotective& wt)
{
	wt.tofStream(os);
	return os;
}

void dioprotective::tofStream(ostream& os)
{
	specifications::tofStream(os);
	os << getcorps() << " " << polarity << " " << power;
}

void dioprotective::inp()
{
	specifications::inp();
	int ch;
	cout << "Do you want to find by corps?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setcorps("Enter corps: ");
	}

	cout << "Do you want to find by polarity?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setpolarity(checkString("Enter polarity: "));
	}

	cout << "Do you want to find by power?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setpower(checkNumber<int>("Enter power: ", 1 ,10000));
	}
}