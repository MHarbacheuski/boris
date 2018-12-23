#include "specifications.h"//videocard!!



specifications::specifications()
{
	maxreversvolt = 0;
	maxforwardcurrent = 0;
}

specifications::specifications(int id, int coast, string creator, string model, double maxreversvolt, double maxforwardcurrent) :
	semiconductor(id, coast, creator, model), maxreversvolt(maxreversvolt), maxforwardcurrent(maxforwardcurrent)
{
}

specifications::~specifications()
{
}

void specifications::setmaxreversvolt(double n)
{
	maxreversvolt = n;
}

double specifications::getmaxreversvolt()
{
	return maxreversvolt;
}

void specifications::setmaxforwardcurrent(double n)
{
	maxforwardcurrent = n;
}

double specifications::getmaxforwardcurrent()
{
	return maxforwardcurrent;
}


bool specifications::operator== (specifications &sem)
{
	if (this->semiconductor::operator== (dynamic_cast<semiconductor&>(sem)) && (maxreversvolt == sem.maxreversvolt ||sem.maxreversvolt == 0)
		&&(maxforwardcurrent == sem.maxforwardcurrent || sem.maxforwardcurrent == 0))
			return true;
	return false;
}

specifications& specifications::operator= (specifications &sem)
{
	this->semiconductor::operator= (dynamic_cast<semiconductor&>(sem));
	this->maxreversvolt = sem.maxreversvolt;
	this->maxforwardcurrent = sem.maxforwardcurrent;
	return *this;
}

void specifications::toStream(ostream& os)
{
	semiconductor::toStream(os);
	os<< maxreversvolt << setw(30) << maxforwardcurrent << setw(20);//mxr 25
}

ostream& operator << (ostream& os, specifications& wt)
{
	wt.toStream(os);
	return os;
}

istream& operator >> (istream& is, specifications& dt)
{
	is >> (dynamic_cast<semiconductor&>(dt));

	dt.maxreversvolt = checkNumber<double>("Enter Max revers voltage(from 1 to 10): ", 1, 1000);
	dt.maxforwardcurrent = checkNumber<double>("Enter Max forward current(from 1 to 10): ", 1, 1000);
	return is;
}

void specifications::table()
{
	semiconductor::table();
	cout << "Maxreversvolt,W" << setw(30) << "Maxforwardcurrent,I" << setw(20);//mxr25
}

fstream& operator >> (fstream& is, specifications& dt)
{
	is >> (dynamic_cast<semiconductor&>(dt));
	is >> dt.maxreversvolt;
	is >> dt.maxforwardcurrent;
	return is;
}

fstream& operator << (fstream& os, specifications& wt)
{
	wt.tofStream(os);
	return os;
}

void specifications::tofStream(ostream& os)
{
	semiconductor::tofStream(os);
	os << maxreversvolt << " " << maxforwardcurrent << " ";
}

void specifications::inp()
{
	semiconductor::inp();
	int ch;
	cout << "Do you want to find by Max revers voltage?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setmaxreversvolt(checkNumber<double>("Enter Max revers voltage(from 0 to 100): ", 1, 100));
	}

	cout << "Do you want to find by Max forward current?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setmaxforwardcurrent(checkNumber<double>("Enter Max forward current(from 0 to 100): ", 1, 100));
	}
}