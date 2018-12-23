#include "stabilitron.h"

stabilitron::stabilitron()
{
	voltagestabil=0;
	maxcurrentstabil=0;
}

stabilitron::stabilitron(int id, int coast, string creator, string model, string corps, double voltagest, double maxcurst):
 diod(id, coast, creator, model, corps), voltagestabil(voltagestabil), maxcurrentstabil(maxcurrentstabil)
{	
}

stabilitron::~stabilitron()
{
}

void stabilitron::setVoltagestabil(double n)
{
	voltagestabil = n;
}

double stabilitron::getVoltagestabil()
{
	return voltagestabil;
}

void stabilitron::setMaxcurrentstabil(double n)
{
	maxcurrentstabil = n;
}

double stabilitron::getMaxcurrentstabil()
{
	return maxcurrentstabil;
}

void stabilitron::toStream(ostream& os)
{
	diod::toStream(os);
	os<< voltagestabil << setw(25) << maxcurrentstabil/*<<setw(25)*/;
}

 ostream& operator << (ostream& os, stabilitron& wt)
{
	 wt.toStream(os);
	 return os;
}

istream& operator >> (istream& is, stabilitron& dt)
{
	is >> (dynamic_cast<diod&>(dt));
	dt.maxcurrentstabil = checkNumber<double>("Enter Max current stabil(from 1 to 1000): ", 1,1000);
	dt.voltagestabil = checkNumber<double>("Enter Voltage stabilization(from 1 to 1000): ", 1, 1000);
	return is;
}

void stabilitron::table()
{
	diod::table();
	cout << "VoltageStabilization,W" << setw(25) << "MaxCurrentStabil,I" /*<< setw(25)*/;
}

stabilitron& stabilitron::operator= (stabilitron &dev)
{
	this->diod::operator= (dynamic_cast<diod&>(dev));
	this->maxcurrentstabil = dev.maxcurrentstabil;
	this->voltagestabil = dev.voltagestabil;

	return *this;
}

bool stabilitron::operator== (stabilitron &dev)
{
	if (this->diod::operator== (dynamic_cast<diod&>(dev)) && (this->maxcurrentstabil == dev.maxcurrentstabil|| dev.maxcurrentstabil == 0) 
		&& (this->voltagestabil == dev.voltagestabil|| dev.voltagestabil ==0))
		return true;
	return false;
}

fstream& operator >> (fstream& is, stabilitron& dt)
{
	is >> (dynamic_cast<diod&>(dt));
	is >> dt.maxcurrentstabil;
	is >> dt.voltagestabil;
	return is;
}

fstream& operator << (fstream& os, stabilitron& wt)
{
	wt.tofStream(os);
	return os;
}

void stabilitron::tofStream(ostream& os)
{
	diod::tofStream(os);
	os << maxcurrentstabil << " " << voltagestabil;
}

void stabilitron::inp()
{
	diod::inp();
	int ch;
	cout << "Do you want to find by Voltage stabilizatio?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setVoltagestabil(checkNumber<double>("Enter Voltage stabilizatio(from 1 to 1000): ", 1, 1000));
	}

	cout << "Do you want to find by Max current stabil?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setMaxcurrentstabil(checkNumber<double>("Enter Max current stabil(from 1 to 1000): ", 1,1000));
	}
}