#include"dioprotective.h"
#include"diopulse.h"
#include"diobridge.h"
#include"stabilitron.h"
#include"Algorithm.h"
#include"file.h"
#include <cstdlib>
#include<vector>


const char* dioprotect = "dioprotective.txt";
const char* diobridg = "diobridge.txt";
const char* stabilitr = "stabilitron.txt";
const char* diopuls = "diopulse.txt";

template <typename T>
void menu(T obj, Ring<T>* Watch, const char* filename)
{
	vector<T> undo;
	typename vector<T>::iterator vecit;
	Iterator<T> it;
	int fl=0;
	while (1)
	{
		int ch;
		T tmp;
		cout << endl << "1) Add record" << endl << "2) Delete record" << endl << "3) Find record" << endl << "4) Edit record" << endl;
		cout << "5) Show records" << endl << "6) Sort records" << endl << "7) Undo last action " << endl << "8) Choose enother detail" << endl;
		ch = checkNumber<int>("Your choice: ", 1, 10);
		switch (ch)
		{
		case 1:
			cin >> obj;
			Watch->add(obj);
			system("CLS");
			undo.clear();
			undo.push_back(obj);
			fl = 1;
			break;
		case 2:
			if (!Watch->isEmpty())
			{
				cin >> obj;
				system("CLS");
				if(!Watch->delete_n(obj))
					cout << "This detail not found" << endl;
				else
				{
					fl = 2;
					undo.clear();
					undo.push_back(obj);
				}
			}
			else
				cout << "Ring is empty" << endl;
			break;
		case 3:
			tmp.inp();
			compare(Watch->begin(), Watch->end(), tmp); 
			break;
		case 4:

			if (!Watch->isEmpty())
			{
				cout << "Enter the detail, that you want to edit" << endl;
				cin >> obj;
				if (Watch->find(obj))
				{
					Watch->delete_n(obj);
					cout << "Enter new fields of detail" << endl;
					undo.clear();
					undo.push_back(obj);
					cin >> obj;
					Watch->add(obj);
					undo.push_back(obj);
					fl = 3;
				}
				else
					cout << "This detail not found" << endl;
			}
			break;
		case 5:
			system("CLS");
			if (!Watch->isEmpty())
			{
				obj.table();
				cout << endl;
				Watch->show();
			}
			else 				
				cout << "Ring is empty" << endl;
			break;
		case 6:
			system("CLS");
			cout << "By what field u want to sort?" << endl;
			cout << "1) By Id" << endl;
			cout << "2) By Creator" << endl;
			cout << "3) By Coast" << endl;
			cout << "4) By Model" << endl;
			int cch;
			cch = checkNumber<int>("Your choice: ", 1, 4);
			switch (cch)
			{
			case 1:
				sort_bubble(Watch->begin(), Watch->end(), comp_id<T>);
				break;
			case 2:
				sort_bubble(Watch->begin(), Watch->end(), comp_creator<T>);
				break;
			case 3:
				sort_bubble(Watch->begin(), Watch->end(), comp_coast<T>);
				break;
			case 4:
				sort_bubble(Watch->begin(), Watch->end(), comp_model<T>);
				break;
			}
			break;
		case 7:

			switch(fl)
			{
		case 1:
			fl = 0;
			vecit = undo.begin();
			Watch->delete_n(*vecit);
			undo.clear();
			break;
		case 2:
			fl = 0;
			vecit = undo.begin();
			Watch->add(*vecit);
			undo.clear();
			break;
		case 3:
			fl = 0;
			vecit = undo.begin();
			Watch->add(*vecit);
			vecit++;
			Watch->delete_n(*vecit);
			undo.clear();
			break;
		default :
			cout << "There is'n last action" << endl;
			break;
			}
			break;
		case 8:
			write_to_file(*Watch, filename);
			Watch->clear();
			return;
		}
	}
}

int main()
{
	system("color F0");
	dioprotective protect;
	Ring<dioprotective> dioprRing;
	diopulse pulse;
	Ring<diopulse> dioplRing;
	stabilitron stab;
	Ring<stabilitron> stabilRing;
	diobridge bridge;
	Ring<diobridge>diobrRing;
	system("chcp 1251");
	while (1)
	{
		system("CLS");
		cout << "...........::::MENU::::............" << endl;
		cout << "-----------------------------------" << endl;
		cout << "What radio detail you want to show?" << endl;
		cout << "1) Diod protective" << endl << "2) Diod Impulse" << endl << "3) Stabilitron" << endl << "4) Diod bridge" << endl << "5) Exit" << endl;
		cout << "-----------------------------------" << endl;
		int ch;
		ch = checkNumber<int>("Your choice: ", 1, 5);
		switch (ch)
		{
		case 1:
			read_from_file(dioprRing, dioprotect);
			menu(protect, &dioprRing, dioprotect);
			break;
		case 2:
			read_from_file(dioplRing, diopuls);
			menu(pulse, &dioplRing, diopuls);
			break;
		case 3:
			read_from_file(stabilRing, stabilitr);
			menu(stab, &stabilRing, stabilitr);
			break;
		case 4:
			read_from_file(diobrRing, diobridg);
			menu(bridge, &diobrRing, diobridg);
			break;
		case 5: 
			return 0;
		}
	}
	system("pause");
	return 0;
}