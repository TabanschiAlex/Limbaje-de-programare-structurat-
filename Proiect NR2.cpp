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
	
	cout << "1. ��������� ���� ����� �������� `�������`" << endl;
	cout << "2. ������� ��� `�������` ����� �� ��������� [a, b]" << endl;
	cout << "3. ������� ������ n ������ ������� �������� `��������`" << endl;
	cout << "4. ������� ��� `����������` ����� �� ��������� [a, b]" << endl;
	cout << "5. ������� ����� ������� `�������` �����" << endl;
	cout << "0. �����" << endl;
	cout << "\t\t�������� ����� ==> ";
	cin >> key;
	
	switch (key) {
		case 1:
			system("CLS");
			cout << "������� ����� ������� ����� ��������� = ";
			cin >> n;
			if ( power(n) ) cout << "����� " << n << " - `�������` �����" << endl;
				else
					cout << "����� " << n << " �� �������� `�������` ������" << endl;
		getch ();
		break;
		
		case 2:
			system("CLS");
			cout << "������� ����� ������ ���������: ";
			cin >> a;
			cout << "������� ������ ������ ���������: ";
			cin >> b;
			cout << "`�������` ����� � �������� ���������: " << endl;
			for ( i = a; i <= b; i++) {
				if ( power(i) ) {
					cout << i << "; ";
					cont ++;
				}
			}
			cout << endl;
			if ( cont == 0 ) cout << "� �������� ��������� ��� `�������` �����" << endl;
				else
					cout << "� ��������� [" << a << ";" << b << "] ���� " << cont << " `�������` �����" << endl;
		getch ();
		break;
		
		case 3:
			system("CLS");
			cout << "������� ����� ���������� `�������` ����� ����� �������: ";
			cin >> n;
			cout << "������ " << n << " �����:" << endl;
			for (i = 1; i <= ((n*2)-1); i++) {
				if ( power(i) ) {
					cout << i << "; ";
				}
			}
		getch ();
		break;
		
		case 4:
			system("CLS");
			cout << "������� ����� ������ ���������: ";
			cin >> a;
			cout << "������� ������ ������ ���������: ";
			cin >> b;
			cout << "`����������` ����� � �������� ���������: " << endl;
			for ( i = a; i <= b; i++) {
				if ( Pell(i) ) {
					cout << i << "; ";
					cont ++;
				}
			}
			cout << endl;
			if ( cont == 0 ) cout << "� �������� ��������� ��� `�����������` �����" << endl;
				else
					cout << "� ��������� [" << a << ";" << b << "] ���� " << cont << " `�����������` �����" << endl;
		getch ();
		break;
		
		case 5:
			system("CLS");
			if ( power(INT_MAX) ) {
				cout << "����� ������� `������� �����` = " << INT_MAX << endl;
			}
				else {
					cout << "����� ������� `�������` ����� = " << INT_MAX - 1 << endl; 
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

