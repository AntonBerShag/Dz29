#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool overwrite(string& path, string word);

int main() {
	setlocale(LC_ALL, "Russian");

	//Задача 1
	cout << "Задача 1\n";
	string str;
	ofstream out;
	out.open("file.txt", ios::app);
	if (out.is_open()) {
		cout << "Файл открыт для записи.\n";
		do {
			cout << "Начата запись: ";
			getline(cin, str);
			out << str << endl;
		} while (str != "end");
	}
	else
		cerr << "Произошла ошибка открытия файла.\n";
	out.close();
	ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		cout << "Файл открыт для чтения.\n";
		while (!in.eof()) {
			string str2;
			getline(in, str2);
			cout << str2 << endl;
		}
	}
	else
		cerr << "Ошибка чтения файла.\n";
	in.close();
	if (remove("file.txt") == 0)
		cout << "Файл удален.\n\n";
	else
		cerr << "Ошибка удаления.\n\n";

	//Задача 2
	cout << "Задача 2\nВведите путь к файлу:\n";
	string path, word;
	getline(cin, path);
	cout << "Введите строку для записи в файл:\n";
	getline(cin, word);
	if (overwrite(path, word))
		cout << "true" << "\n\n";
	else
		cout << "false" << "\n\n";

	return 0;
}

//Задача 2
bool overwrite(string& path, string word) {
	ofstream out;
	out.open(path, ios::out);
	if (out.is_open()) {
		out << word << endl;
		out.close();
		return true;
	}
	out.close();
	return false;
}