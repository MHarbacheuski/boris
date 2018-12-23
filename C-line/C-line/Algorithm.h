#pragma once
#include<iostream>
#include <functional>
#include"Ring.h"
#include"specifications.h"
#include"diopulse.h"
#include"dioprotective.h"
#include"stabilitron.h"
#include"semiconductor.h"

using namespace std;

template <class T>
void swapt(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template< class RandomIt, typename Compare>
void sort_bubble(RandomIt first, RandomIt last, Compare comp)
{
	for (RandomIt j = first; j != last; j++)
	{
		for (RandomIt i = first; i != last; i++)
		{
			RandomIt tmp = i;
			tmp++;
			if (comp(*i, *tmp) && tmp != first)
			{
				swapt(*i, *tmp);
			}
		}
	}
}

template <class T>
bool comp_id(T& a, T& b)
{
	if (a.getId() > b.getId())
		return true;
	return false;
}

template <class T>
bool comp_creator(T& a, T& b)
{
	if (a.getCreator() > b.getCreator())
		return true;
	return false;
}

template <class T>
bool comp_coast(T& a, T& b)
{
	if (a.getcoast() > b.getcoast())
		return true;
	return false;
}

template <class T>
bool comp_model(T& a, T& b)
{
	if (a.getModel() > b.getModel())
		return true;
	return false;
}

template< class RandomIt, class Compare>
void compare(RandomIt first, RandomIt last, Compare T)
{
	bool flag = false;
	RandomIt j = first;
	for (; j != last; j++)
	{
		if (*j == T)
		{
		cout << *j << endl;
		flag = true;
		}
	}
	if (*j == T)
	{
		cout << *j << endl;
		flag = true;
	}
	if(!flag)
	cout << "Sorry, we not found this device" << endl;
}
