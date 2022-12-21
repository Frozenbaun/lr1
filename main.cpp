#include <iostream>
#include "keeper.h" //keeper.h
#include "BooksOfPoets.h" //BooksOfPoets.h
#include "BooksP.h" // fyrniture
#include "fan.h"
#include "menu.h"
#include "worker.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	Keeper <BooksP> BooksP;
	Keeper <fan> fan;
	Keeper <Worker> worker;
	int button;
	bool flag = true; // Для проверки логических условий (флаг состояний), как выключатель - ВКЛ и ВЫКЛ
	while (flag) {
		system("cls"); // Ждет ввода, чтобы окно консоли не закрылось
		cout << "Главное Меню: " << endl << endl;
		cout << "[1] Книги поэтов" << endl;
		cout << "[2] Книги романтистов" << endl;
		cout << "[3] Книги фантастов" << endl;
		cout << "[4] Выход " << endl << endl;
		cout << "->: ";
		cin >> button;
		if (cin.fail()) { // Проверка на правильный ввод
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1:
			menu(BooksP, "BooksOfPoets.txt"); // Factory
			break;
		case 2:
			menu(worker, "Worker.txt"); // Вызов меню (Работник)
			break;
		case 3:
			menu(fan, "fan.txt"); // Вызов меню (Машина)
			break;
		case 4:
			flag = false; // Выход из программы
			cout << "\nКонец" << endl;
			break;
		default:
			cout << endl << "Некорректные данные, введите заново!" << endl << endl; // Проверка на правильный ввод
			system("pause");
			break;
		}
	}
	return 0;
}}
