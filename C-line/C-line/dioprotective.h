#pragma once
#include "diod.h"
#include "specifications.h"
#include "Ring.h"
//delte motherboard
class dioprotective :
	public diod, public specifications
{
	string polarity;
	int power;
public:
	dioprotective(int id, int coast, string creator, string model, string corps,double maxreversvolt, double maxforwardcurrent, string plr, int power);
	dioprotective();
	//dioprotective(const dioprotective& clone);
	~dioprotective();
	void setpolarity(string n);
	string getpolarity();
	void setpower(int n);
	int getpower();
	dioprotective& operator= (dioprotective& sem);
	virtual void toStream(ostream& os);
	virtual void tofStream(ostream& os);
	friend fstream& operator << (fstream& os, dioprotective& wt);
	friend ostream& operator << (ostream& os, dioprotective& wt);
	friend istream& operator >> (istream& is, dioprotective& dt);
	friend fstream& operator >> (fstream& is, dioprotective& dt);
	void table();
	bool operator== (dioprotective &sem);
	void inp();
};

