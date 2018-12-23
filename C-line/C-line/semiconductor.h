#pragma once

#include"iostream"
#include"string"
#include"Check_Inp.h"
#include"InputException.h"
#include<fstream>
#include <String>
#include <iomanip>


using namespace std;

class semiconductor
{
	int id;
	string creator;
	string model;
	int coast;
public:
	semiconductor();
	semiconductor(int num, int coast, string creator, string model);
	virtual ~semiconductor();
	void setId(int n);
	int getId();
	void setcoast(int n);
	int getcoast();
	void setCreator(string n);
	string getCreator();
	void setModel(string n);
	string getModel();
	bool operator== (semiconductor &dev);
	virtual void toStream(ostream& os);
	virtual void tofStream(ostream& os);
	friend ostream& operator << (ostream& os, semiconductor& wt);
	friend fstream& operator << (fstream& os, semiconductor& wt);
	friend istream& operator >> (istream& is, semiconductor& dt);
	friend fstream& operator >> (fstream& is, semiconductor& dt);
	void table();
	semiconductor& operator= (semiconductor &str);
	virtual void inp();
};