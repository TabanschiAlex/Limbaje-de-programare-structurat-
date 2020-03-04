#include <iostream>
#include <conio.h>
#include <cstdLIB>

using namespace std;

int power(int n);
int Pell(int n);

int main() {
	
	setlocale(LC_ALL, "Russian");
	
	int key, n, a, b, i;
	int cont = 0;
	
	do {
	
	cout << "1. Проверить если число является `сильным`" << endl;
	cout << "2. Вывести все `сильные` числа из интервала [a, b]" << endl;
	cout << "3. Вывести первые n чисела которые являются `сильными`" << endl;
	cout << "4. Вывести все `Ахиллесовы` числа из интервала [a, b]" << endl;
	cout << "5. Вывести самое большое `сильное` число" << endl;
	cout << "0. Выход" << endl;
	cout << "\t\tВыюерите опцию ==> ";
	cin >> key;
	
	switch (key) {
		case 1:
			system("CLS");
			cout << "Введите число которое нужно проверить = ";
			cin >> n;
			if ( power(n) ) cout << "Число " << n << " - `сильное` число" << endl;
				else
					cout << "Число " << n << " не является `сильным` числом" << endl;
		getch ();
		break;
		
		case 2:
			system("CLS");
			cout << "Введите левый предел диапазона: ";
			cin >> a;
			cout << "Введите правый предел диапазона: ";
			cin >> b;
			cout << "`Сильные` числа в заданном диапозоне: " << endl;
			for ( i = a; i <= b; i++) {
				if ( power(i) ) {
					cout << i << "; ";
					cont ++;
				}
			}
			cout << endl;
			if ( cont == 0 ) cout << "В заданном диапозоне нет `сильных` чисел" << endl;
				else
					cout << "В интервале [" << a << ";" << b << "] есть " << cont << " `сильных` чисел" << endl;
		getch ();
		break;
		
		case 3:
			system("CLS");
			cout << "Введите какое количество `сильных` чисел нужно вывести: ";
			cin >> n;
			cout << "Первые " << n << " чисел:" << endl;
			for (i = 1; i <= ((n*2)-1); i++) {
				if ( power(i) ) {
					cout << i << "; ";
				}
			}
		getch ();
		break;
		
		case 4:
			system("CLS");
			cout << "Введите левый предел диапазона: ";
			cin >> a;
			cout << "Введите правый предел диапазона: ";
			cin >> b;
			cout << "`Ахиллесовы` числа в заданном диапозоне: " << endl;
			for ( i = a; i <= b; i++) {
				if ( Pell(i) ) {
					cout << i << "; ";
					cont ++;
				}
			}
			cout << endl;
			if ( cont == 0 ) cout << "В заданном диапозоне нет `Ахиллесовых` чисел" << endl;
				else
					cout << "В интервале [" << a << ";" << b << "] есть " << cont << " `Ахиллесовых` чисел" << endl;
		getch ();
		break;
		
		case 5:
			system("CLS");
			if ( power(INT_MAX) ) {
				cout << "Самое большое `сильное число` = " << INT_MAX << endl;
			}
				else {
					cout << "Самое большое `сильное` число = " << INT_MAX - 1 << endl; 
				}
		getch ();
		break;
	}
	
	}while ( key != 0);
	
	return 0;
}

int Pell ( int n ) {
	if ( n == 0 ) {
		return true;
	}
		else{
			int a = 0;
			int b = 1;
			int c = 2*b+a;
			while ( c < n ) {
				a = b;
				b = c;
				c = 2*b+a;
			}
		return n == c;		
		}
}

int power ( int n ) {
	if ( n%2 == 0 or n == 1 ) return 1;
		else
			return 0;
}

