#include "worker.h"
#include <iostream>
#include <string>
using namespace std;
Worker::Worker() {
	setlocale(LC_ALL, "Russian");
	//cout << "Вызов конструктора по умолчанию (Работник)" << endl << endl;
	FamiliyaR = "";
	ImyaR = "";
	OtchestvoR = "";
	Godi_aliveR = "";
	ProizvedenieR1 = ProizvedenieR2 = ProizvedenieR3 = "";
	Biographiya = "";
}
Worker::Worker(const Worker& other) {
	setlocale(LC_ALL, "Russian");
//	cout << "Вызов конструктора копирования (Работник)" << endl << endl;
	*this = other;
}
Worker::~Worker() {
	setlocale(LC_ALL, "Russian");
//	cout << "Вызов деструктора (Работник)" << endl << endl;
}
void Worker::setVal() {
	cin >> *this;
}
Worker& Worker::operator=(const Worker& other) {
	this->FamiliyaR = other.FamiliyaR;
	this->ImyaR = other.ImyaR;
	this->OtchestvoR = other.OtchestvoR;
	this->Godi_aliveR = other.Godi_aliveR;
	this->ProizvedenieR1 = other.ProizvedenieR1;
	this->ProizvedenieR2 = other.ProizvedenieR2;
	this->ProizvedenieR3 = other.ProizvedenieR3;
	this->Biographiya = other.Biographiya;
	return *this;
}
ofstream& operator<<(ofstream& fout, Worker& obj) { // Функция записи в файл объекта (Работник)
	fout << obj.FamiliyaR << " " << endl;
	fout << obj.ImyaR << " " << endl;
	fout << obj.OtchestvoR << " " << endl;
	fout << obj.Godi_aliveR << " " << endl;
	fout << obj.ProizvedenieR1 << " " << endl;
	fout << obj.ProizvedenieR2 << " " << endl;
	fout << obj.ProizvedenieR3 << " " << endl;
	fout << obj.Biographiya << " " << endl;
	fout << endl;
	return fout;
}
ifstream& operator>>(ifstream& fin, Worker& obj) { // Функция чтения файла объекта (Работник)
	fin >> obj.FamiliyaR >> obj.ImyaR >> obj.OtchestvoR >> obj.Godi_aliveR >> obj.ProizvedenieR1 >> obj.ProizvedenieR2 >> obj.ProizvedenieR3 >> obj.Biographiya;
	return fin;
}
ostream& operator<<(ostream& out, Worker& obj) { // Функция вывода на экран данных объекта (Работник)
	setlocale(LC_ALL, "Russian");
	out << "Фамилия: " << obj.FamiliyaR << endl;
	out << "Имя: " << obj.ImyaR << endl;
	out << "Отчетсво: " << obj.OtchestvoR << endl;
	out << "Годы жизни: " << obj.Godi_aliveR << endl;
	out << "Произведения: " << obj.ProizvedenieR1 << obj.ProizvedenieR2 << obj.ProizvedenieR3 << endl;
	out << "Краткая биография: " << obj.Biographiya << endl;
	return out;
}
istream& operator>>(istream& in, Worker& obj) { // Функция ввода данных объекта (Работник)
	setlocale(LC_ALL, "Russian");
	cout << "Введите данные:" << endl << endl;
	cout << "Фамилия: ";
	cin >> obj.FamiliyaR;
	cout << "Имя: ";
	cin >> obj.ImyaR;
	cout << "Отчество: ";
	cin >> obj.OtchestvoR;
	cout << "Годы жизни: ";
	cin >> obj.Godi_aliveR;
	cout << "Первое произведение: ";
	cin >> obj.ProizvedenieR1;
	cout << "Второе произведение: ";
	cin >> obj.ProizvedenieR2;
	cout << "Третье произведение: " ;
	cin >> obj.ProizvedenieR3;
	cout << "\nПримечание. Вместо пробелма, используейте символ '_' " << endl << endl;
	cout << "Краткая биография: ";
	cin >> obj.Biographiya;
	return in;
}
