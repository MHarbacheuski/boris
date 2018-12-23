#pragma once
#include "semiconductor.h"//sizedivece
class specifications :
	virtual public semiconductor
{
	double maxreversvolt;
	double maxforwardcurrent;
public:
	specifications();
	specifications(int id, int coast, string creator, string model, double maxreversvolt, double maxforwardcurrent);
	~specifications();
	void setmaxreversvolt(double n);
	double getmaxreversvolt();
	void setmaxforwardcurrent(double n);
	double getmaxforwardcurrent();
	bool operator== (specifications &sem);
	specifications& operator= (specifications &sem);
	virtual void toStream(ostream& os);
	virtual void tofStream(ostream& os);
	friend ostream& operator << (ostream& os, specifications& wt);
	friend fstream& operator << (fstream& os, specifications& wt);
	friend istream& operator >> (istream& is, specifications& dt);
	friend fstream& operator >> (fstream& is, specifications& dt);
	void table();
	virtual void inp();
};

