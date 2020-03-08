#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#define limit  100

using namespace std;

int generateVector ( int array[], int n );
void showVector ( int array[], int n );
int Minimum ( int array[], int n );
int Maximum ( int array[], int n );
double averageValue ( int array[], int n );

int main(){

	setlocale(LC_ALL, "Russian");

    int key, n;
    int array[limit];


  do {
        system("CLS");
    cout << "1.���������� ����������� � ������������ �������� � ������� �����" <<endl;
    cout << "2.���������� ������� �������������� � ������� �����" <<endl;
    cout << "3.������� �� ����� ������� ����� � ������� ����������� ��� � �������" <<endl;
    cout << "4.De efectuat rotirea la st�nga (variantele impare) sau la dreapta (variantele pare) a elementelor tabelului de k ori" <<endl;
    cout << "5.�������� ������ � ������� �����" <<endl;
    cout << "6.������� ������ �� ������� �����" <<endl;
    cout << "7.De calculat o caracteristica, referitoare la datele concrete" <<endl;
    cout << "\t\t�������� ������� ==> ";
    cin  >> key;
    switch (key){
        case 1:
            system("CLS");
            cout << "������� ������ ������� = ";
            cin >> n;
            generateVector( array, n );
            cout << "������� : ";
            showVector( array, n );
            cout << "����������� �������� = " << Minimum( array, n ) << endl;
            cout << "������������ �������� = " << Maximum( array, n ) << endl;
        getch();
        break;
       case 2:
            system("CLS");
            cout << "������� ������ ������� = ";
            cin >> n;
            generateVector( array, n );
            cout << "������� : ";
            showVector( array, n );
            cout << "������� �������������� = " << averageValue( array, n );
        getch();
        break;
        case 3:
            system("CLS");
            cout << "������� ������ ������� = ";
            cin >> n;
            generateVector( array, n );
            cout << "�������: ";
            showVector( array, n );
            cout << "������� � ������� �����������: ";
            sortingIncrease( array, n );
            cout << "������� � ������� ��������: ";
            sortingDecrease( array, n );
        getch();
        break;
        case 4:
        getch();
        break;
        case 5:
        getch();
        break;
        case 6:
        getch();
        break;
        case 7:
        getch();
        break;

    }
  } while(key !=0);
  
  return 1;
  
}

int generateVector (int array[], int n ) {
	for ( int i = 0; i < n; i++ ) {
		array[i] = rand() % 100;
	}
		
		return 1;
		
}

void showVector ( int array[], int n ){
	for(int i=0; i < n; i++) {
		cout << setw(6) << array[i];
	}	
	cout << endl;	
}

int Minimum ( int array[], int n ) {
	int min = array[0];
	for ( int i = 1; i < n; i++ ) {
		if ( array[i] < min ) {
			min = array[i];
		}
	}
	
	return min;
	
}

int Maximum ( int array[], int n ) {
	int max = array[0];
	for ( int i = 1; i < n; i++ ) {
		if ( array[i] > max ) {
			max = array[i];
		}
	}
	
	return max;
	
}

double averageValue ( int array[], int n ) {
	int average, i;
	for ( i = 0; i < n; i++ ) {
		average += array[i]; 
	}
	
	return (double)average/n;
	
}

int sortingIncrease ( int array[], int n ) {
	
}

int sortingDecrease ( int array[], int n ){
	
}
