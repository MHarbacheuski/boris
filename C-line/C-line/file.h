#pragma once
#include"dioprotective.h"
#include"diopulse.h"
#include"diobridge.h"
#include"stabilitron.h"
#include"FileException.h"
#include"FileException.h"

template <typename T>
void read_from_file(Ring<T>& Ring, const char* filename)
{
	T tmp;
	fstream file;
	file.exceptions(fstream::failbit);
	try
	{
		file.open(filename, fstream::in | fstream::app);
		if (!file.is_open())
			throw(MyException("Error of opening of file", 7));
		if (file.eof())
			throw(MyException("File is empty", 8));
	}
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		ex.code();
		return;
	}
	while (!file.eof())
	{
		file >> tmp;
		Ring.add(tmp);
	}
	file.close();
}

template <typename T>
void write_to_file(Ring<T>& Ring, const char* filename)
{
	Iterator<T> it;
	T tmp;
	fstream file;
	file.exceptions(fstream::failbit);
	try
	{
		file.open(filename, fstream::out);
		if (!file.is_open())
			throw(MyException("Ошибка открытия файла", 7));
	}
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		ex.code();
		return;
	}
	for (it = Ring.begin(); it != Ring.end(); it++)
	{
		file << *it;
	}
	file << *it;
	file.close();
}