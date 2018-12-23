#pragma once
#include "diod.h"//ne trogai delete CPU
class stabilitron :
	public diod
{
	double voltagestabil;
	double maxcurrentstabil;
public:
	stabilitron();
	stabilitron(int id, int coast, string creator, string model,string corps, double voltagest, double maxcurst);
	void setVoltagestabil(double n);
	double getVoltagestabil();
	void setMaxcurrentstabil(double n);
	double getMaxcurrentstabil();
	~stabilitron();
	virtual void toStream(ostream& os);
	virtual void tofStream(ostream& os);
	friend fstream& operator << (fstream& os, stabilitron& wt);
	friend ostream& operator << (ostream& os, stabilitron& wt);
	friend istream& operator >> (istream& is, stabilitron& dt);
	friend fstream& operator >> (fstream& is, stabilitron& dt);
	void table();
	stabilitron& operator= (stabilitron &str);
	bool operator== (stabilitron &sem);
	void inp();
};

