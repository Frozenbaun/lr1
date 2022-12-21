#include "BooksP.h"
#include <iostream>
#include <string>
using namespace std;
BooksP::BooksP() {
	setlocale(LC_ALL, "Russian");
	//cout << "Вызов конструктора по умолчанию (ПОЭТЫ)" << endl << endl;
	Familiya = "";
	Imya = "";
	Otchestvo = "";
	godi_alive = "";
}
BooksP::BooksP(const BooksP& other) {
	setlocale(LC_ALL, "Russian");
	//cout << "Вызов конструктора копирования (ПОЭТЫ)" << endl << endl;
	*this = other;
}
BooksP::~BooksP() {
	setlocale(LC_ALL, "Russian");
	//cout << "Вызов деструктора (ПОЭТЫ)" << endl << endl;
}
void BooksP::setVal() {
	cin >> *this;
}
BooksP& BooksP::operator=(const BooksP& other) {
	this->Familiya = other.Familiya;
	this->Imya = other.Imya;
	this->Otchestvo = other.Otchestvo;
	this->godi_alive = other.godi_alive;
	this->Proizvedenie1 = other.Proizvedenie1;
	this->Proizvedenie2 = other.Proizvedenie2;
	this->Proizvedenie3 = other.Proizvedenie3;
	return *this;
}
ofstream& operator<<(ofstream& fout, BooksP& obj) { // Функция записи в файл объекта (Мебель)
	fout << obj.Familiya << " " << endl;
	fout << obj.Imya << " " << endl;
	fout << obj.Otchestvo << " " << endl;
	fout << obj.godi_alive << " " << endl;
	fout << obj.Proizvedenie1 << " " << endl;
	fout << obj.Proizvedenie2 << " " << endl;
	fout << obj.Proizvedenie3 << " " << endl;
	fout << endl;
	return fout;
}
ifstream& operator>>(ifstream& fin, BooksP& obj) { // Функция чтения файла объекта (Мебель)
	fin >> obj.Familiya >> obj.Imya >> obj.Otchestvo >> obj.godi_alive >> obj.Proizvedenie1 >> obj.Proizvedenie2 >> obj.Proizvedenie3;
	return fin;
}
ostream& operator<<(ostream& out, BooksP& obj) { // Функция вывода на экран данных объекта (Мебель)
	setlocale(LC_ALL, "Russian");
	out << "ФИО: " << obj.Familiya << endl;
	out << "Имя: " << obj.Imya << endl;
	out << "Отчество: " << obj.Otchestvo << endl;
	out << "Годы жизни: " << obj.godi_alive << endl;
	out << "Произведения: " << obj.Proizvedenie1 << ", " << obj.Proizvedenie2 << ", " << obj.Proizvedenie3 << endl;
	return out;
}
istream& operator>>(istream& in, BooksP& obj) { // Функция ввода данных объекта (Мебель)
	setlocale(LC_ALL, "Russian");
	cout << "Введите данные:" << endl << endl;
	cout << "Фамилия: " ; 
	cin >> obj.Familiya;
	cout << "Имя: ";
	cin >> obj.Imya;
	cout << "Отчество: " ;
	cin >> obj.Otchestvo;
	cout << "Годы жизни: ";
	cin >> obj.godi_alive;
	cout << "Первое произведение: ";
	cin >> obj.Proizvedenie1;
	cout << "Второе произведение: ";
	cin >> obj.Proizvedenie2;
	cout << "Третье произведение: ";
	cin >> obj.Proizvedenie3;
	return in;
}
