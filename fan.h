#pragma once
#include <fstream>
#include "BooksOfPoets.h"
#include "keeper.h"
using namespace std;
class fan : public BooksOfPoets {
private:
	string FamiliyaF;
	string Imya;
	string Otchestvo;
	string ProizvedenieF1;
	string danet1;
	string ProizvedenieF2;
	string danet2;
	string ProizvedenieF3;
	string danet3;
	string state_number;
public:
	fan();
	~fan();
	fan(const fan&);
	void setVal() override;
	friend ofstream& operator << (ofstream& fout, fan& obj);
	friend ifstream& operator >> (ifstream& fin, fan& obj);
	friend ostream& operator << (ostream& out, fan& obj);
	friend istream& operator >> (istream& in, fan& obj);
	fan& operator =(const fan& other);
}; 
