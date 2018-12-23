#include"Check_Inp.h"

string checkString(string ms)
{
	string input;
	bool flag = false;
	bool check = true;
	while (1)
	{
		try
		{
			check = false;
			cout << ms;
			cin >> input;
			for (int i = 0; i < input.size(); i++)
			{
				if ((input[i] < 'A' || input[i] > 'Z') && (input[i] < 'a' || input[i] > 'z') &&  (input[i] < '0' || input[i] > '9'))
					throw MyException("Wrong input of string", 1);
					
			}
		
			if (cin.get() != '\n')
				throw MyException("Wrong input of string", 1);

			if (input.size() > 25)
			{
				throw InputException("Wrong input of string", 4);
			}
			
				
		}
		catch (InputException& ex)
		{
			cout << ex.what() << endl;
			ex.code();
			ex.StringLenthEx();
			check = true;
			cin.clear();
		}
		catch (MyException& ex)
		{
			cout << ex.what() << endl;
			ex.code();
			check = true;
			cin.clear();
		}
		if (!check)
			break;
	}
	return input;
}

