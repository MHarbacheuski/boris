#include "diopulse.h"

diopulse::diopulse()
{
	capacity = 0;
}

diopulse::diopulse(int id, string creator, string model, int coast, string corps, double maxreversvolt, double maxforwardcurrent, double capacity):
specifications(id, coast, creator, model, maxreversvolt,maxforwardcurrent), capacity(capacity)
{
	setcorps(corps);
}

diopulse::~diopulse()
{
}

void diopulse::setcapacity(double n)
{
	capacity = n;
}

double diopulse::getcapacity()
{
	return capacity;
}

void diopulse::toStream(ostream& os)
{
	specifications::toStream(os);
	os << capacity;
}

ostream& operator << (ostream& os, diopulse& wt)
{
	wt.toStream(os);
	return os;
}

istream& operator >> (istream& is, diopulse& dt)
{
	is >> (dynamic_cast<specifications&>(dt));
	dt.capacity = checkNumber<double>("Enter Capacity(1 to 50): ",1,50);
	dt.setcorps("Enter corps: ");
	return is;
}

void diopulse::table()
{
	specifications::table();
	cout << "Capacity,pF" << setw(15);
}

diopulse& diopulse::operator= (diopulse &sem)
{
	this->specifications::operator= (dynamic_cast<specifications&>(sem));
	this->capacity = sem.capacity;
	this->setcorps(sem.getcorps());
	return *this;
}

bool diopulse::operator== (diopulse &sem)
{
	if (this->specifications::operator== (dynamic_cast<specifications&>(sem)) && (this->capacity==sem.capacity ||sem.capacity==0))
		return true;
	return false;
}

fstream& operator >> (fstream& is, diopulse& dt)
{
	is >> (dynamic_cast<specifications&>(dt));
	string cap;
	is >> dt.capacity;
	dt.setcorps(cap);
	return is;
}

fstream& operator << (fstream& os, diopulse& wt)
{
	wt.tofStream(os);
	return os;
}

void diopulse::tofStream(ostream& os)
{
	specifications::tofStream(os);
	os <<capacity;
}

void diopulse::inp()
{
	specifications::inp();
	int ch;
	cout << "Do you want to find by corps?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setcorps(checkString("Enter corps: "));
	}

	cout << "Do you want to find by capacity?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setcapacity(checkNumber<int>("Enter capacity: ", 1, 2000));
	}
}