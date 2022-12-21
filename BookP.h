#pragma once
#include <fstream>
#include "keeper.h"
#include "BooksOfPoets.h"
using namespace std;
class BooksP : public BooksOfPoets
{
private:
	string godi_alive;
	string Familiya;
	string Imya;
	string Otchestvo;
	string Proizvedenie1;
	string Proizvedenie2;
	string Proizvedenie3;
public:
	BooksP();
	BooksP(const BooksP& other);
	~BooksP();
	void setVal() override;
	friend ofstream& operator << (ofstream& fout, BooksP& obj);
	friend ifstream& operator >> (ifstream& fin, BooksP& obj);
	friend ostream& operator << (ostream& out, BooksP& obj);
	friend istream& operator >> (istream& in, BooksP& obj);
	BooksP& operator =(const BooksP& other);
};
