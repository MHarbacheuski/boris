#include "InputException.h"

InputException::InputException(const char* str, int code): MyException(str, code)
{
}

InputException::InputException()
{
}

InputException::~InputException()
{
}

void InputException::StringLenthEx()
{
	cout << "Your input too long, try again to 20 characters" << endl;
}

void InputException::ambitEx(int l, int r)
{
	cout << "Your number is not from " << l << " to " << r << endl;
}