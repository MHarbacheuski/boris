#pragma once
#include "MyException.h"
#include "cctype"
class InputException :
	public MyException
{
public:
	InputException();
	InputException(const char* str, int code);
	void ambitEx(int l, int r);
	void StringLenthEx();
	~InputException();
};

