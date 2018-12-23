#include "MyException.h"

MyException::MyException()
{
}

MyException::MyException( const char* str,int code) : 
	exception(str), code_error(code)
{
}

void MyException::code()
{
	cout << "Code of error: " <<code_error << endl;
}

MyException::~MyException()
{
}
