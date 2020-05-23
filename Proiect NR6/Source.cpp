#include "Header.h"

Rates writeVector(vector<Rates> &array, string &line) {
    Rates temp;
    int element = 0;
    string word;

    istringstream buffer(line);
    while (buffer) {
        buffer >> word;

        switch (element) {
        case 0:
            temp.id = stoi(word);
            break;
        case 1:
            temp.location = word;
            break;
        case 2:
            temp.gas = stoi(word);
            break;
        case 3:
            temp.electricity = stoi(word);
            break;
        case 4:
            temp.phone = stoi(word);
            break;
        case 5:
            temp.thermalEnergy = stoi(word);
            break;
        case 6:
            temp.water = stoi(word);
            break;
        }
        element++;
    }
    return temp;
}

void readTextFile(vector<Rates> &array, string &file) {
	string line;
	ifstream readFile(file);

	while (getline(readFile, line)) {
		array.push_back(writeVector(array, line));
	}
	readFile.close();
}

void writeBinaryFile(vector<Rates> &array, string &file) {
    ofstream writeFile(file, ios::binary);

    for (int i = 0; i < array.size(); i++) {
        writeFile.write((char*)&array[i], sizeof(Rates));
    }

    writeFile.close();
}

void readBinaryFile(vector<Rates> &array, string &file) {
    Rates temp;
    vector <Rates> arr;

    ifstream readFile(file, ios::binary);
    while (readFile.read((char*)&temp, sizeof(Rates))) {
        arr.push_back(temp);
    }

    readFile.close();
    writeElements(arr);
}

void writeElements(vector<Rates> &array) {
    for (int i = 0; i < array.size(); i++) {
        cout << "Id: " << array[i].id << endl;
        cout << " Locality: " << array[i].location << endl;
        cout << " Gas: " << array[i].gas << endl;
        cout << " Electricity: " << array[i].electricity << endl;
        cout << " Telephone: " << array[i].phone << endl;
        cout << " Thermal Energy: " << array[i].thermalEnergy << endl;
        cout << " Water: " << array[i].water << endl;
    }
}

Rates createRate() {
    Rates rate;
    cout << "Id: ";
    cin >> rate.id;
    cout << "Раположение: ";
    cin >> rate.location;
    cout << "Тариф на газ: ";
    cin >> rate.gas;
    cout << "Тариф на электричество: ";
    cin >> rate.electricity;
    cout << "Тариф на телефон: ";
    cin >> rate.phone;
    cout << "Тариф на тепловую энергию: ";
    cin >> rate.thermalEnergy;
    cout << "Тариф на воду: ";
    cin >> rate.water;

    return rate;
}

void sortByLocation(vector<Rates> &array) {
    int key;
    Rates count;

    for (int i = 0; i < array.size() - 1; i++) {
        count = array[i];
        key = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j].location < array[key].location) {
                key = j;
            }
        }

        if (key != i) {
            array[i] = array[key];
            array[key] = count;
        }
    }
    writeElements(array);
}

void sortByRate(vector<Rates> &array) {
    int key;
    Rates count;

    for (int i = 0; i < array.size() - 1; i++) {
        count = array[i];
        key = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j].gas < array[key].gas) {
                key = j;
            }
            if (array[j].gas == array[key].gas) {
                if (array[j].electricity < array[key].electricity) {
                    key = j;
                }
                if (array[j].electricity == array[key].electricity) {
                    if (array[j].phone < array[key].phone) {
                        key = j;
                    }
                }
            }
        }

        if (key != i) {
            array[i] = array[key];
            array[key] = count;
        }
    }
    writeElements(array);
}

void addElement(vector<Rates> &array) {
    array.push_back(createRate());
    writeElements(array);
}

//void deleteElement(vector<Rates> &array, int position) {
//    if ((position < array.size()) or (position > 0)) {
//        array.erase(array.begin() + position);
//        writeElements(array);
//    }
//    else {
//        cout << "Id не существует";
//    }
//}

int deleteElement(vector<Rates>& array, int id) {
    Rates count;
    int flag = 0;

        for (int i = 0; i < array.size(); i++) {
            if (id == array[i].id) {
                array.erase(array.begin() + i);
                flag = 1;
            }
        }

    if (flag == 0) {
        cout << "Id не существует" << endl;
        return 0;
    }

    writeElements(array);
    return 1;
}

int changeElement(vector<Rates> &array) {
    Rates temp = createRate();
    int flag = 0;

        for (int i = 0; i < array.size(); i++)
        {
            if (temp.id == array[i].id) {
                array[i].id = temp.id;
                array[i].location = temp.location;
                array[i].gas = temp.gas;
                array[i].electricity = temp.electricity;
                array[i].phone = temp.phone;
                array[i].thermalEnergy = temp.thermalEnergy;
                array[i].water = temp.water;
                flag = 1;
            }
        }

    if (flag == 0) {
        cout << "Id не существует" << endl;
        return 0;
    }

    writeElements(array);
    return 1;
}

float getAverage(Rates& temp) {
    int sum = temp.phone + temp.water + temp.thermalEnergy + temp.electricity + temp.gas;
    return (float)sum / 5;
}

void getExpensiveRates(vector<Rates> &array) {
    float average;
    int expensiveRates;

    for (auto &i : array) {
        expensiveRates = 0;
        average = getAverage(i);

        if ((float)i.gas > average) {
            expensiveRates++;
        }
        if ((float)i.phone > average) {
            expensiveRates++;
        }
        if ((float)i.water > average) {
            expensiveRates++;
        }
        if ((float)i.thermalEnergy > average) {
            expensiveRates++;
        }
        if ((float)i.electricity > average) {
            expensiveRates++;
        }

        cout << i.location << " имеет " << expensiveRates << " дорогих тарифа" << endl;
    }
}