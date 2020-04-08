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
void sortingIncrease ( int array[], int n );
void sortingDecrease ( int array[], int n );
void editArray ( int array[], int s, int value );
void rotateElements ( int array[], int n, int value );
void addArray ( int array[], int n, int value, int s );
void deleteArray ( int array[], int n, int value );

int main(){

	setlocale(LC_ALL, "Russian");

    int key, n, s, r, value;
    int array[limit];


  do {
        system("CLS");
    cout << "1.Определить минимальное и максимальное значения в таблице чисел" <<endl;
    cout << "2.Определить среднее орифметическое в таблице чисел" <<endl;
    cout << "3.Вывести на экран таблицу чисел в порядке возрастания и в порядке убывания" <<endl;
    cout << "4.Передвинуть таблицу влево на k шагов" <<endl;
    cout << "5.Изменить данные в таблице чисел" <<endl;
    cout << "6.Добавить данные в таблицу чисел" <<endl;
    cout << "7.Удалить данные из таблицы чисел" <<endl;
    cout << "8.De calculat o caracteristica, referitoare la datele concrete" <<endl;
    cout << "\t\tВыберите функцию ==> ";
    cin  >> key;
    switch (key){
        case 1:
            system("CLS");
            cout << "Введите размер вектора = ";
            cin >> n;
            generateVector( array, n );
            cout << "Таблица : ";
            showVector( array, n );
            cout << "Минимальное значение = " << Minimum( array, n ) << endl;
            cout << "Максимальное значение = " << Maximum( array, n ) << endl;
        getch();
        break;
       case 2:
            system("CLS");
            cout << "Введите размер вектора = ";
            cin >> n;
            generateVector( array, n );
            cout << "Таблица : ";
            showVector( array, n );
            cout << "Среднее арифметическое = " << averageValue( array, n );
        getch();
        break;
        case 3:
            system("CLS");
            cout << "Введите размер вектора = ";
            cin >> n;
            generateVector( array, n );
            cout << "Таблица: ";
            showVector( array, n );
            cout << "Таблица в порядке возрастания: ";
            cout << "Таблица в порядке убывания: ";
            sortingDecrease( array, n );
        getch();
        break;
        case 4:
        	system("CLS");
        	cout << "Введите размер вектора = ";
            cin >> n;
            generateVector( array, n );
            cout << "Таблица: ";
            showVector ( array, n );
            cout << "Введите сколько элементов нужно сдвинуть влево = ";
            cin >> value;
            rotateElements ( array, n, value );
            cout << "Результат: ";
            showVector ( array, n );
        getch();
        break;
        case 5:
        	system("CLS");
        	cout << "Введите размер вектора = ";
            cin >> n;
            generateVector( array, n );
            cout << "Таблица: ";
			showVector( array, n );
            do {
        	cout << "Введите адрес массива который хотите изменить ( от 0 до " << n - 1 << " ):";
        	cin >> s;
        	cout << "Введите число на которое нужно поменять значение: ";
        	cin >> value;
        	editArray( array, s , value );
        	cout << "Продолжить редактирование? (0 - Нет, 1 - Да) ";
        	cin >> r;
        	} while ( r != 0 );
        	cout << "Таблица: ";
			showVector( array, n );
        getch();
        break;
        case 6:
        	system("CLS");
        	cout << "Введите размер вектора = ";
            cin >> n;
            generateVector( array, n );
            cout << "Таблица: ";
			showVector( array, n );
			cout << "Сколько нужно добавить элементов?: ";
			cin >> value;
			r = value;
			while ( value != 0 ) {
				cout << "Введите число: ";
				cin >> s;
				addArray( array, n, value, s);
				value--;
			}
			cout << "Таблица: ";
			showVector( array, n + r );
        getch();
        break;
        case 7:
        	system("CLS");
        	cout << "Введите размер вектора = ";
            cin >> n;
            generateVector( array, n );
            cout << "Таблица: ";
			showVector( array, n );
			cout << "Какой элемент массива нужно удалить?: ";
			cin >> value;
			cout << "Таблица: ";
			deleteArray( array, n, value );
			
        getch();
        break;
        case 8:
        	
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

void sortingIncrease ( int array[], int n ) {
	for ( int i = 0; i < n; i++) {
		for ( int j = i+1; j < n; j++) {
			if ( array[j] < array[i] ) {
				int tmp = array[j];
				array [j] = array [i];
				array [i] = tmp;
			}
		}
	cout << setw(6) << array[i];
	}
cout << endl;	
}

void sortingDecrease ( int array[], int n ){
	for ( int i = 0; i < n; i++) {
		for ( int j = i+1; j < n; j++) {
			if ( array[j] > array[i] ) {
				int tmp = array[j];
				array [j] = array [i];
				array [i] = tmp;
			}
		}
	cout << setw(6) << array[i];
	}
cout << endl;	
}

void rotateElements ( int array[], int n, int value ) {
	int tmp, j = 0, s;
	s = value;
		while ( j < value ) {
			tmp = array[j];
			array[j] = array[n-s];
			array[n-s] = tmp;
			j++;
			s--;	
		}
}

void editArray ( int array[], int s, int value ) {
	array[s] = value;
}

void addArray ( int array[], int n, int value, int s ) {
	int i;
	i = n + value - 1;
	array[i] = s;
}
void deleteArray ( int array[], int n, int value ) {
	value--;
	for ( int i = value; i < n-1; i++) {
		array[i] = array[i+1];
	}
	n--;
	showVector( array, n );
}
