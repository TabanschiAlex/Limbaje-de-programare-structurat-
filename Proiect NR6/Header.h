#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

struct Rates {
    int id;
    string location;
    int gas;
    int electricity;
    int phone;
    int thermalEnergy;
    int water;
};

Rates writeVector(vector<Rates> &array, string &line);
void readTextFile(vector<Rates> &array, string &file);
void writeBinaryFile(vector<Rates> &array, string &file);
void readBinaryFile(vector<Rates> &array, string &file);
void writeElements(vector<Rates> &array);
void sortByLocation(vector<Rates> &array);
void sortByRate(vector<Rates> &array);
void addElement(vector<Rates> &array);
int deleteElement(vector<Rates> &array, int position);
int changeElement(vector<Rates> &array);
void getExpensiveRates(vector<Rates> &array);

