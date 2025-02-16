﻿#include <iostream>
#include <Wibdows.h>
#include <cstdlib>
#include <iomanip>


using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	std::cout << "\t\t Игра счасливое число" << endl; std::cout << endl;
	std::cout << "Счастливым считается шестизначное число, у которого сумма первых 3 цифр равна сумме вторых трех цифр." << endl; cout << endl;

	int number, a, numberDigits, temp;
	char yesNo = 'N';
	int halfNumber1, halfNumber2,
		sum1 = 0,
		sum2 = 0;

	do
	{
		std::cout << "Введите 6-ти значное число: "; std::cin >> number; std::cout << endl;

		numberDigits = 1;
		a = number;

		while ((a /= 10) > 0) // Кол-во цифр в числе
		{
			numberDigits++;
		}
		if (numberDigits > 6 || numberDigits < 6) // Проверка введеного числа
		{
			cout << "Вы ввели не 6-ти значное число. Повторите ввод" << endl;
			continue;
		}

		halfNumber1 = number / 1000;
		halfNumber2 = number % 1000;

		for (int i = 1; i <= numberDigits / 2; i++) // Сумма 3х цифр правой части часла 
		{
			sum2 += halfNumber1 % 10;
			halfNumber1 /= 10;
		}

		for (int i = 1; i <= numberDigits / 2; i++) // Сумма 3х цифр левой части часла
		{
			sum1 += halfNumber2 % 10;
			halfNumber2 /= 10;
		}

		if (sum1 == sum2)  // Вывод результата
		{
			std::cout << "\tВаше число СЧАСЛИВОЕ!" << endl; std::cout << endl;
		}
		else
		{
			std::cout << "\tВаше число НЕ СЧАСЛИВОЕ!" << endl; std::cout << endl;
		}

		std::cout << "Веведите 'Y' если хотите повторить игру счасливое число: "; std::cin >> yesNo; std::cout << endl;
	} while (yesNo == 'Y' || yesNo == 'y');

	system("pause");
}