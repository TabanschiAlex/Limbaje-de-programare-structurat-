#include "Header.h"


int main() {
    string rate = "rate.txt";
    string binary = "binary.txt";
    vector<Rates> totalRate;
    char function;
    int deletePosition;

    setlocale(LC_ALL, "Russian");

    readTextFile(totalRate, rate);
    do {
        cout << "Выберите функцию: " << endl;
        cout << "1. Сортировать по городу: " << endl;
        cout << "2. Сортировать по тарифу: " << endl;
        cout << "3. Добавить новый тариф: " << endl;
        cout << "4. Удалить тариф: " << endl;
        cout << "5. Изменить тариф: " << endl;
        cout << "6. Показать дорогие тарифы: " << endl;
        cout << "7. Записать данные в двоичный файл: " << endl;
        cout << "8. Вывести данные из двоичного файла: " << endl;
        cout << "0. Exit" << endl;
        cin >> function;
        system("CLS");

        switch (function) {
        case '1':
            cout << "Сортировка по городам: " << endl;
            sortByLocation(totalRate);
            break;

        case '2':
            cout << "Сортировка по тарифу: " << endl;
            sortByRate(totalRate);
            break;
            
        case '3':
            addElement(totalRate);
            break;
            
        case '4':
            cout << "Ввелите Id который нужно удалить: ";
            cin >> deletePosition;
            deleteElement(totalRate, deletePosition);
            break;

        case '5':
            changeElement(totalRate);
            break;

        case '6':
            getExpensiveRates(totalRate);
            break;

        case '7':
            writeBinaryFile(totalRate, binary);
            cout << "Двоичный файл записан!" << endl;
            break;

        case '8':
            cout << "Данные из двоичного файла: " << endl;
            readBinaryFile(totalRate, binary);
            break;

        case '0':
            cout << "Успешный выход из программы!" << endl;
            break;

        default:
            cout << "Функции не существует, попробуйте еще раз!" << endl;
            break;
        }

    } while (function != '0');

    return 0;
}