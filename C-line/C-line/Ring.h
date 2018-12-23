#pragma once
#include<iostream>
#include"NodeRing.h" 

template <class T>
class Iterator
{
	NodeRing<T>* cur;
public:
	Iterator();
	Iterator(NodeRing<T>*  el);
	~Iterator();
	Iterator<T>& operator++ ();
	Iterator<T>& operator++ (int n);
	Iterator<T>& operator-- ();
	Iterator<T>& operator-- (int n);
	bool operator== (Iterator<T> tmp);
	bool operator!= (Iterator<T> tmp);
	T& operator* ();
	T& operator-> ();
	Iterator<T>& operator= (Iterator<T> a);
};

template <typename T>
class Ring
{
	NodeRing <T> *current;
	int count;
public:
	friend class Iterator<T>;
	Ring();
	~Ring();
	bool add(T item);
	bool delete_n(T item);
	bool find(T item);
	int getcount();
	void show();
	Iterator<T> begin();
	Iterator<T> end();
	void clear();
	bool isEmpty() const
	{
		if (current == nullptr)
			return true;
		return false;
	}
};


template <typename T>
Iterator<T>::Iterator()
{
	cur = nullptr;
}

template <typename T>
Iterator<T>::Iterator(NodeRing<T>* el) :cur(el)
{
}

template <typename T>
Iterator<T>::~Iterator()
{
}

template <typename T>
Iterator<T>& Iterator<T>::operator++ ()
{
	cur = cur->next;
	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++ (int n)
{
	cur = cur->next;
	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator-- ()
{
	cur = cur->prev;
	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator-- (int n)
{
	cur = cur->prev;
	return *this;
}

template <typename T>
T& Iterator<T>::operator* ()
{
	return cur->data;
}

template <typename T>
Iterator<T>& Iterator<T>::operator= (Iterator<T> ptr)
{
	this->cur = ptr.cur;
	return *this;
}

template <typename T>
bool Iterator<T>::operator== (Iterator<T> tmp)
{
	if (this->cur == tmp.cur)
		return true;
	return false;
}

template <typename T>
bool Iterator<T>::operator!= (Iterator<T> tmp)
{
	if (this->cur != tmp.cur)
		return true;
	return false;
}

template <typename T>
T& Iterator<T>::operator-> ()
{
	return cur;
}

template <typename T>
Ring<T>::Ring()
{
	current = nullptr;
	count = 0;
}

template <typename T>
Ring<T>::~Ring()
{
	clear();
}

template <typename T>
bool Ring<T>::add(T item)
{
	if (isEmpty() || count == 0) {
		NodeRing<T> *newNode = new NodeRing<T>;
		newNode->data = item;
		current->next = current->prev = current = newNode;
		count++;
	}
	else {
		NodeRing<T> *newNode = new NodeRing<T>;
		newNode->data = item;
		current->prev->next = newNode;
		newNode->prev = current->prev;
		newNode->next = current;
		current->prev = newNode;
		count++;
	}
	count++;
	return true;
}

template<class T>
int Ring<T>::getcount()
{
	return count;
}

template<class T>
void Ring<T>::show() {
	NodeRing<T>* tmp = current;
	if (isEmpty())
		cout << "Ring is empty" << endl;
	else
	{
		do
		{
			cout << tmp->data << endl;
			tmp = tmp->next;
		} while (current != tmp);
	}
}

template<class T>
Iterator<T>  Ring<T>::begin()
{
	return Iterator<T>(current);
}

template<class T>
Iterator<T>  Ring<T>::end()
{
	return Iterator<T>(current->prev);
}


template <typename T>
void Ring<T>::clear()
{
	if (isEmpty())
	{
		cout << "Ring is empty" << endl;
		return;
	}
	else
	{
		NodeRing<T>* tmp;
		current->prev->next = nullptr;
		while (current)
		{
			tmp = current;
			current = current->next;
			delete tmp;
		}
	}
}

template <typename T>
bool Ring<T>::delete_n(T item)
{
	if (isEmpty())
	{
		cout << "Error of deleting" << endl;
		return false;
	}
	NodeRing<T>* tmp = current;
	NodeRing<T>* prev = current;
	current = current->next;
	if (current == prev && item == current->data)
	{
		delete current;
		current = nullptr;
		return true;
	}
	while (1)
	{
		if (item == current->data)
		{
			prev->next = current->next;
			delete current;
			count--;
			current = prev;
			return true;
		}
		prev = current;
		if (current == tmp)
		{
			break;
		}
		current = current->next;
	}
	return false;
}

template <typename T>
bool Ring<T>::find(T item)
{
	NodeRing<T>* tmp = current;
	if (isEmpty())
		cout << "Ring is empty" << endl;
	else
	{
		do
		{
			if (item == current->data)
				return true;
			current = current->next;
		} while (current != tmp);

	}
	return false;
}