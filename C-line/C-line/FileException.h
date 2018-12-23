#pragma once
#include "MyException.h"
class FileException :
	public MyException
{
public:

	FileException(const char* str, int code);
	FileException();
	~FileException();
	bool file_clear()
	{}
};

