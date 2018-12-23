#pragma once

#include<iostream>

using namespace std;

template<class T>
class NodeRing
{
public:
	NodeRing * next;
	NodeRing * prev;
	T data;
};