#pragma once
#include "diod.h"
#include "specifications.h"//deelte videocard!!!!
class diobridge :
	public diod, public specifications
{
	string mountmethod;
	int numberofphases;
public:
	diobridge(int id, int coast, string creator, string model, string corps, string mountmethod, int numberphases, double maxreversvolt, double maxforwardcurrent);
	diobridge();
	~diobridge();
	void setmountmethod(string tmp);
	string getmountmethod();
	void setnumberofphases(int tmp);
	int getnumberofphases();
	diobridge& operator= (diobridge &sem);
	virtual void toStream(ostream& os);
	virtual void tofStream(ostream& os);
	friend fstream& operator << (fstream& os, diobridge& wt);
	friend ostream& operator << (ostream& os, diobridge& wt);
	friend istream& operator >> (istream& is, diobridge& dt);
	friend fstream& operator >> (fstream& is, diobridge& dt);
	void table();
	bool operator== (diobridge &sem);
	void inp();
};