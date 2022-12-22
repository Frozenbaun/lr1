#include "fan.h"
#include <iostream>
#include <string>
using namespace std;
fan::fan() {
	setlocale(LC_ALL, "Russian");
	//cout << "Вызов конструктора по умолчанию (Машина)" << endl << endl;
	FamiliyaF =Imya=Otchestvo= "";
	ProizvedenieF1 = "";
	ProizvedenieF2 = "";
	ProizvedenieF3 = "";
	danet1 = danet2 = danet3 = "";
}
fan::fan(const fan& other) {
	setlocale(LC_ALL, "Russian");
	//cout << "Вызов конструктора копирования (Машина)" << endl << endl;
	*this = other;
}
fan::~fan() {
	setlocale(LC_ALL, "Russian");
	//cout << "Вызов деструктора (Машина)" << endl << endl;
}
void fan::setVal() {
	cin >> *this;
}
fan& fan::operator=(const fan& other) {
	this->FamiliyaF = other.FamiliyaF;
	this->Imya = other.Imya;
	this->Otchestvo = other.Otchestvo;
	this->ProizvedenieF1 = other.ProizvedenieF1;
	this->danet1 = other.danet1;
	this->ProizvedenieF2 = other.ProizvedenieF2;
	this->danet2 = other.danet2;
	this->ProizvedenieF3 = other.ProizvedenieF3;
	this->danet3 = other.danet3;
	return *this;
}
ofstream& operator<<(ofstream& fout, fan& obj) { // Функция записи в файл объекта (Машина)
	fout << obj.FamiliyaF << " " << endl;
	fout << obj.Imya << " " << endl;
	fout << obj.Otchestvo << " " << endl;
	fout << obj.ProizvedenieF1 << " " << endl;
	fout << obj.danet1 << " " << endl;
	fout << obj.ProizvedenieF2 << " " << endl;
	fout << obj.danet2 << " " << endl;
	fout << obj.ProizvedenieF3 << " " << endl;
	fout << obj.danet3 << " " << endl;
	fout << endl;
	return fout;
}
ifstream& operator>>(ifstream& fin, fan& obj) { // Функция чтения файла объекта (Машина)
	fin >> obj.FamiliyaF >> obj.Imya >> obj.Otchestvo >> obj.ProizvedenieF1 >> obj.ProizvedenieF2 >> obj.ProizvedenieF3 >> obj.danet1 >> obj.danet2 >> obj.danet3;
	return fin;
}
ostream& operator<<(ostream& out, fan& obj) { // Функция вывода на экран данных объекта (Машина)
	setlocale(LC_ALL, "Russian");
	out << "Фамилия: " << obj.FamiliyaF << endl;
	out << "Имя: " << obj.Imya << endl;
	out << "Отчество: " << obj.Otchestvo << endl;
	out << "\nПервое произведение: " << obj.ProizvedenieF1 << endl;
	out << "\tБыл ли записан фильм по произведению " << obj.ProizvedenieF1 <<"? " << obj.danet1 << endl;
	out << "\nВторое произведение: " << obj.ProizvedenieF2 << endl;
	out << "\tБыл ли записан фильм по произведению " << obj.ProizvedenieF2 << "? " << obj.danet2 << endl;
	out << "\nТретье произведение: " << obj.ProizvedenieF3 << endl;
	out << "\tБыл ли записан фильм по произведению " << obj.ProizvedenieF3 << "? " << obj.danet3 << endl;
	return out;
}
istream& operator>>(istream& in, fan& obj) { // Функция ввода данных объекта (Машина)
	setlocale(LC_ALL, "Russian");
	cout << "Введите данные:" << endl << endl;
	cout << "Фамилия: ";
	cin >> obj.FamiliyaF;
	cout << "Имя: ";
	cin >> obj.Imya;
	cout << "Отчество: ";
	cin >> obj.Otchestvo;
	cout << "\nПервое произведение: ";
	cin >> obj.ProizvedenieF1;
	cout << "Был записан фильм по произведению? ";
	cin >> obj.danet1;
	cout << "\nВторое произведение: ";
	cin >> obj.ProizvedenieF2;
	cout << "Был записан фильм по произведению? ";
	cin >> obj.danet2;
	cout << "\nТретье произведение: ";
	cin >> obj.ProizvedenieF3;
	cout << "Был записан фильм по произведению? ";
	cin >> obj.danet3;
	return in;
} 
