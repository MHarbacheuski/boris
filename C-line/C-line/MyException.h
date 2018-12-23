#pragma once
#include <iostream>
#include <exception>
#include "String"

using namespace std;

class MyException :
	public exception
{
	int code_error;
public:
	MyException();
	MyException(const char* str,int code);
	void code();
	~MyException();
};

