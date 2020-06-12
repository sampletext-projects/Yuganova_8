#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int K;
/**
 * Журнал - последовательность чисел
 * Первое число - количество снимков
 * Далее через пробел 1 - это снимок дачника,
 * 2 - снимок обитателя леса
*/
int* journal;
int n; // длина журнала


void readData()
{
	string journalFileName;

	cout << "Введите данные:\n"
		<< "K (себестоимость снимка) = ";
	cin >> K;

	cout << "Введите имя файла с ценами: \n";
	cin >> journalFileName;

	// Открыть файлы
	ifstream journalFile(journalFileName);
	// Заполнить журнал
	journalFile >> n;
	journal = new int[n];
	for (int i = 0; i < n; i++)
	{
		journalFile >> journal[i];
		cout << journal[i] << " ";
	}
	cout << "\n";
}

int analyze(int* journal, int n)
{
	int outcome = 0; // прибыль (или убыток)
	// Проанализировать журнал
	for (int i = 0; i < n; i++)
	{
		if (journal[i] == 1) // фотография дачника
			outcome += K;
		else // фотография обитателя леса
			outcome -= K;
	}
	return outcome;
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Программу сделала Юганова Лилия Александровна УМЛ-111\n";
	cout << "Программа для расчёта прибылей Шарика\n";

	readData();

	int outcome = analyze(journal, n);

	cout << "Результат: \n";
	if (outcome >= 0)
		cout << "Прибыль " << outcome << " рублей\n";
	else
		cout << "Убыток " << abs(outcome) << " рублей\n";

	system("pause");

	return 0;
}
