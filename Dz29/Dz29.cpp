#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool overwrite(string& path, string word);

int main() {
	setlocale(LC_ALL, "Russian");

	//������ 1
	cout << "������ 1\n";
	string str;
	ofstream out;
	out.open("file.txt", ios::app);
	if (out.is_open()) {
		cout << "���� ������ ��� ������.\n";
		do {
			cout << "������ ������: ";
			getline(cin, str);
			out << str << endl;
		} while (str != "end");
	}
	else
		cerr << "��������� ������ �������� �����.\n";
	out.close();
	ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		cout << "���� ������ ��� ������.\n";
		while (!in.eof()) {
			string str2;
			getline(in, str2);
			cout << str2 << endl;
		}
	}
	else
		cerr << "������ ������ �����.\n";
	in.close();
	if (remove("file.txt") == 0)
		cout << "���� ������.\n\n";
	else
		cerr << "������ ��������.\n\n";

	//������ 2
	cout << "������ 2\n������� ���� � �����:\n";
	string path, word;
	getline(cin, path);
	cout << "������� ������ ��� ������ � ����:\n";
	getline(cin, word);
	if (overwrite(path, word))
		cout << "true" << "\n\n";
	else
		cout << "false" << "\n\n";

	return 0;
}

//������ 2
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