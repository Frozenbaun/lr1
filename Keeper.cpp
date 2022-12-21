#include "Keeper.h"

Keeper::Keeper()
{
	this->data = nullptr;
	this->size = 0;
}

Keeper::~Keeper()
{
	delete[] data;
}

int Keeper::getSize()
{
	return size;
}

void Keeper::add()
{
	int type; 
	try
	{
		cout << "Choose the class: " << endl
			<< "[1] Udar" << endl
			<< "[2] Strun" << endl
			<< "[3] duh" << endl
			<< "Ваш выбор: ";
		cin >> type;
		if (type > 3 || type < 1)
		{
			throw (string)"Error class";
		}
		ork** tmp = new ork * [size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		switch (type)
		{
		case 1:
			tmp[size] = new udar;
			break;
		case 2:
			tmp[size] = new strun;
			break;
		case 3:
			tmp[size] = new duh;
			break;
		default:
			break;
		}
		if (tmp[size]->isError())
		{
			cout << "Not add error" << endl;
			system("pause");
			return;
		}
		size++;
		if (data)
			delete[] data;
		data = tmp;
		cout << "Element added" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}

void Keeper::add(int _type, ifstream &fin)
{
	ork** tmp = new ork * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = data[i];
	}
	switch (_type)
	{
	case 1:
		tmp[size] = new udar(fin);
		break;
	case 2:
		tmp[size] = new strun(fin);
		break;
	case 3:
		tmp[size] = new duh(fin);
		break;
	default:
		break;
	}
	size++;
	if (data)
		delete[] data;
	data = tmp;
}

void Keeper::edit()
{
	int index;
	if (!size)
	{
		cout << "Nothing" << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i << "] ";
			switch (data[i]->getType())
			{
			case 1:
				cout << "Udar" << endl;
				break;
			case 2:
				cout << "Strun" << endl;
				break;
			case 3:
				cout << "Duh" << endl;
				break;
			default:
				break;
			}
		}
		cout << "Choose element ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"Elemnt not exist";
		data[index]->edit();
		if (data[index]->isError())
		{
			cout << "Error" << endl;
		}
		else
		{
			cout << "Element edited" << endl;
		}
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}

void Keeper::del()
{
	int index;
	if (!size)
	{
		cout << "Nothing" << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i << "] ";
			switch (data[i]->getType())
			{
			case 1:
				cout << "Udar" << endl;
				break;
			case 2:
				cout << "Strun" << endl;
				break;
			case 3:
				cout << "Duh" << endl;
				break;
			default:
				break;
			}
		}
		cout << "What delete ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"Not exist";
		if (size == 1)
		{
			delete[] data;
			data = nullptr;
			cout << "Deleted" << endl;
			size--;
			system("pause");
			return;
		}
		ork** tmp = new ork * [size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (index == i)
				continue;
			tmp[j] = data[i];
			j++;
		}
		delete[] data;
		data = tmp;
		size--;
		cout << "Deleted" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}

void Keeper::save()
{
	ofstream fout("output.txt");
	for (int i = 0; i < size; i++)
	{
		data[i]->save(fout);
	}
	fout.close();
	cout << "Saved" << endl;
	system("pause");
}

void Keeper::load()
{
	ifstream fin("output.txt");
	if(fin.fail())
	{
		cout << "Nothing" << endl;
		system("pause");
		return;
	}
	int type = 0;
	while (fin)
	{
		fin >> type;
		if (fin.peek() == -1)
		{
			break;
		}
		add(type, fin);
	}
	fin.close();
	cout << "Loaded" << endl;
	system("pause");
}

ostream& operator<<(ostream& out, Keeper& obj)
{
	if (!obj.size)
	{
		cout << "Nothing" << endl;
		system("pause");
		return out;
	}
	for (int i = 0; i < obj.size; i++)
	{
		obj.data[i]->print(out);
	}
	system("pause");
	return out;
}
