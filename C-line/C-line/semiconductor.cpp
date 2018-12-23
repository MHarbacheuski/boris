#include "semiconductor.h"



semiconductor::semiconductor()
{
	id = 0;
	creator = "";
	model = "";
	coast = 0;
}

semiconductor::semiconductor(int num, int yea, string creator, string model) : id(num), coast(yea), creator(creator), model(model)
{
}

semiconductor::~semiconductor()
{
}

void semiconductor::setId(int n)
{
	id = n;
}

int semiconductor::getId()
{
	return id;
}

bool semiconductor::operator== (semiconductor &sem)
{
	if ((sem.id == this->id || sem.id == 0) && (sem.coast == this->coast || sem.coast == 0) && (this->creator == sem.creator || sem.creator == "")
		&& (this->model == sem.model || sem.model == ""))
		return true;
	return false;
}

void semiconductor::setCreator(string n)
{
	creator = n;
}

string semiconductor::getCreator()
{
	return creator;
}

void semiconductor::setModel(string n)
{
	model = n;
}

string semiconductor::getModel()
{
	return model;
}

void semiconductor::setcoast(int n)
{
	coast = n;
}

int semiconductor::getcoast()
{
	return coast;
}

void semiconductor::toStream(ostream& os)
{
	os << setw(15) << id << setw(25) << creator << setw(25) << model << setw(25) << coast << setw(25);//25
}

ostream& operator<< (ostream& os, semiconductor& wt)
{
	wt.toStream(os);
	return os;
}

istream& operator>> (istream& is, semiconductor& dt)
{
	
	dt.creator = checkString("Enter creator: ");
	dt.coast = checkNumber<int>("Enter coast(from 0 to 2500): ", 0, 2500);
	dt.model = checkString("Enter model: ");
    dt.id = checkNumber<int>("Enter id(from 0 to 9999999): ", 0, 999999);
	return is;
}

semiconductor& semiconductor::operator= (semiconductor &str)
{
	this->coast = str.coast;
	this->creator = str.creator;
	this->id = str.id;
	this->model = str.model;
	return *this;
}

void semiconductor::table()
{
	cout << setw(15) << "Id" << setw(25) << "Creator" << setw(25) << "Model" << setw(25) << "Coast" << setw(25);//25
}

fstream& operator >> (fstream& is, semiconductor& dt)
{
	is >> dt.id;
	is >> dt.coast;
	is >> dt.creator;
	is >> dt.model;
	return is;
}

fstream& operator<< (fstream& os, semiconductor& wt)
{
	wt.tofStream(os);
	return os;
}

void semiconductor::tofStream(ostream& os)
{
	os << " " << id << " " << coast << " " << creator << " " << model << " ";
}

void semiconductor::inp()
{
	int ch;
	cout << "Do you want to find by id?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setId(checkNumber<int>("Enter id(from 0 to 9999999): ", 0, 999999));
	}

	cout << "Do you want to find by coast?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setcoast(checkNumber<int>("Enter coast(from 0 to 2500): ", 0, 2500));
	}

	cout << "Do you want to find by creator?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setCreator(checkString("Enter creator: "));
	}

	cout << "Do you want to find by model?" << endl << "1-yes" << endl << "2-no" << endl;
	ch = checkNumber<int>("Your choice: ", 1, 2);
	if (ch == 1)
	{
		setModel(checkString("Enter model: "));
	}
}
