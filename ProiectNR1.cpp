#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int terrain, min, max, distance, difference, average = 0, small = 0, more = 0, equally = 0, near;
    min = 999999999;
    max = 0;
    near = 1;

    cout << "������� ���������� ���������� (�� 1 �� 20): " << endl;
    cin >> terrain;
    if (terrain < 1) exit(0);
        else
            if (terrain > 20) exit (0);
        for (int i = 1; i <= terrain; i++) {
            cout << "������� ���������� ������������ ��������� ���������: " << i << " = ";
            cin >> distance;

       // ������������ � ����������� ��������

        if (distance < min)
            min = distance;
        if (distance > max)
            max = distance;

        // ������� �������� ����������

        average += distance;

        // ��������, ������, ������ ��� ������.

        if (distance < 50) small++;
            else
                if (distance > 50) more++;
                    else
                        if (distance = 50) equally++;

        }

    // ���������� ���������� ������������� ����� ���� � ������

    near += terrain;
    if (near % 2 > 0) near - 1;

    cout << "���������� ���������� ������������ ��������� ��������� = " << min << " ��." << endl;
    cout << "���������� ���������� ������������ ��������� ��������� = " << max << " ��." << endl;
    cout << "������� ����� ����� ������� � ����� ������� ���������� = " << max - min << " ��." << endl;
    cout << "������� ��������� �� ��������� ��������� = " << (float)average/terrain << " ��." << endl;
    cout << "���������� ���������� � ����������� ������� ��� 50 �� = " << small << endl;
    cout << "���������� ���������� � ����������� ������� ��� 50 �� = " << more << endl;
    cout << "���������� ���������� � ����������� ������ 50 �� = " << equally << endl;
    cout << "���������� ���������� ������������� ����� ���� � ������ = " << (near/2)+1 << endl;

    return 0;
}
