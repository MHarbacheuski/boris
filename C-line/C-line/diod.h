#pragma once
#include "semiconductor.h"
class diod :
	virtual public semiconductor//memorydiv delete
{
	string corps;
public:
	diod();
	diod(int id, int coast, string creator, string model, string corps);
	~diod();
	void setcorps(string tmp);
	string getcorps();
	bool operator== (diod &sem);
	diod& operator= (diod &sem);
	virtual void toStream(ostream& os);
	virtual void tofStream(ostream& os);
	friend fstream& operator << (fstream& os, diod& wt);
	friend ostream& operator << (ostream& os, diod& wt);
	friend istream& operator >> (istream& is, diod& dt);
	friend fstream& operator >> (fstream& is, diod& dt);
	void table();
	virtual void inp();
};

