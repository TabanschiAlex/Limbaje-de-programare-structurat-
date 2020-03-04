#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int terrain, min, max, distance, difference, average = 0, small = 0, more = 0, equally = 0, near;
    min = 999999999;
    max = 0;
    near = 1;

    cout << "Введите количество местностей (от 1 до 20): " << endl;
    cin >> terrain;
    if (terrain < 1) exit(0);
        else
            if (terrain > 20) exit (0);
        for (int i = 1; i <= terrain; i++) {
            cout << "Введите расстояние относительно начальной местности: " << i << " = ";
            cin >> distance;

       // Максимальное и минимальное значение

        if (distance < min)
            min = distance;
        if (distance > max)
            max = distance;

        // Среднее значение расстояния

        average += distance;

        // Значения, равное, меньше или больше.

        if (distance < 50) small++;
            else
                if (distance > 50) more++;
                    else
                        if (distance = 50) equally++;

        }

    // Количество местностей расположенных рядом друг с другом

    near += terrain;
    if (near % 2 > 0) near - 1;

    cout << "Наименьшее расстояние относительно начальной местности = " << min << " км." << endl;
    cout << "Наибольшее расстояние относительно начальной местности = " << max << " км." << endl;
    cout << "Разница между самой дальней и самой ближней местностью = " << max - min << " км." << endl;
    cout << "Среднее растояние от начальной местности = " << (float)average/terrain << " км." << endl;
    cout << "Количество местностей с расстоянием меньшим чем 50 км = " << small << endl;
    cout << "Количество местностей с расстоянием большим чем 50 км = " << more << endl;
    cout << "Количество местностей с расстоянием равным 50 км = " << equally << endl;
    cout << "Количество местностей расположенных рядом друг с другом = " << (near/2)+1 << endl;

    return 0;
}
