#pragma once
#include"diod.h"
#include "specifications.h"//cooller
class diopulse :
	public diod,public specifications
{
	double capacity;
public:
	diopulse();
	diopulse(int id, string creation, string model, int coast, string corps, double maxreversvolt, double maxforwardcurrent,double capasity);
	~diopulse();
	void setcapacity(double n);
	double getcapacity();
	virtual void toStream(ostream& os);
	virtual void tofStream(ostream& os);
	friend ostream& operator << (ostream& os, diopulse& wt);
	friend fstream& operator << (fstream& os, diopulse& wt);
	friend istream& operator >> (istream& is, diopulse& dt);
	friend fstream& operator >> (fstream& is, diopulse& dt);
	void table();
	diopulse& operator= (diopulse &str);
	bool operator== (diopulse &dev);
	void inp();
};

