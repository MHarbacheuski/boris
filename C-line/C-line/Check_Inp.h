#pragma once
#include"InputException.h"
#include <iostream>
using namespace std;

string checkString(string ms);

template<typename T>
T checkNumber(string ms, int l, int r)
{
	T input;
	bool flag = false;
	while (1)
	{
		try
		{
			cout << ms;
			cin >> input;
			if (cin.fail() || cin.bad() || cin.get()!='\n')
				throw MyException("Wrong input of number", 2);
			if (input < l || input > r)
				throw InputException("Wrong input of number", 3);
			rewind(stdin);
			flag = true;
		}
		catch (InputException& ex)
		{
			cout << ex.what() << endl;
			ex.code();
			ex.ambitEx(l, r);
			cin.clear();
			rewind(stdin);
		}
		catch (MyException& ex)
		{
			cout << ex.what() << endl;
			ex.code();
			cin.clear();
			rewind(stdin);
		}
		if (flag)
			break;
	}
	return input;
}