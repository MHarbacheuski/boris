#include "diobridge.h"

diobridge::diobridge()
{
	numberofphases = 0;
	mountmethod = "";
}

diobridge::diobridge(int id, int coast, string creator, string model, string corps, string mountmethod, int numberofphases, double maxreversvolt, double maxforwardcurrent) :
	specifications(id, coast, creator, model, maxreversvolt, maxforwardcurrent), numberofphases(numberofphases), mountmethod(mountmethod)
{
	setcorps(corps);
}

diobridge::~diobridge()
{
}

void diobridge::setmountmethod(string tmp)
{
	mountmethod = tmp;
}

string diobridge::getmountmethod()
{
	return mountmethod;
}

void diobridge::setnumberofphases(int tmp)
{
	numberofphases = tmp;
}

int diobridge::getnumberofphases()
{
	return numberofphases;
}

diobridge& diobridge::operator= (diobridge &sem)
{
	this->specifications::operator= (dynamic_cast<specifications&>(sem));
	this->mountmethod =sem.mountmethod;
	this->numberofphases = sem.numberofphases;
	this->setcorps(sem.getcorps());
	return *this;
}

void diobridge::toStream(ostream& os)
{
	specifications::toStream(os);
	os << getcorps() << setw(20) << mountmethod << setw(15) << numberofphases /*<< setw(20)*/;
}

ostream& operator << (ostream& os, diobridge& wt)
{
	wt.toStream(os);
	return os;
}

istream& operator >> (istream& is, diobridge& dt)
{
	is >> (dynamic_cast<specifications&>(dt));

	dt.mountmethod = checkString("Mounting method: ");
	dt.numberofphases = checkNumber<int>("Enter number of phases(from 1 to 50): ", 1, 50);
	dt.setcorps("Enter corps: ");
	return is;
}

void diobridge::table()
{
	specifications::table();
	cout << "Corps" << setw(20)  << "MountingMethod" << setw(20) << "NumberOfPhases" << setw(20);
}

bool diobridge::operator== (diobridge &sem)
{
	if ((this->getcorps() == sem.getcorps() || sem.getcorps() == "" )  && this->specifications::operator== (dynamic_cast<specifications&>(sem)))
		if ((this->numberofphases == sem.numberofphases || sem.numberofphases ==0) && (this->mountmethod == sem.mountmethod ||sem.mountmethod == "" ))
			return true;
	return false;
}

fstream& operator >> (fstream& is, diobridge& dt)
{
	is >> (dynamic_cast<specifications&>(dt));
	string cap;
	
	is >> dt.mountmethod;
	is >> dt.numberofphases;
	is >> cap;
	
	dt.setcorps(cap);
	
	return is;
}

fstream& operator << (fstream& os, diobridge& wt)
{
	wt.tofStream(os);
	return os;
}

void diobridge::tofStream(ostream& os)
{
	specifications::tofStream(os);
	os << mountmethod << " " << numberofphases << " " << getcorps();
}

void diobridge::inp()
{
	specifications::inp();
	int ch;
	cout << "Do you want to find by corps?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setcorps(checkString("Enter corps: "));
	}

	cout << "Do you want to find by number of phases?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setnumberofphases(checkNumber<int>("Enter number of phases(from 1 to 50): ", 1, 50));
	}

	cout << "Do you want to find by mountmethod?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setmountmethod(checkString("Enter Mounting method: "));
	}
}