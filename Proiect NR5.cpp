#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void writeTextFile ( string &phrase, string &file );
void readTextFile( string &file );
int checkWordCount ( string &phrase, int option );
void showVocals ( string &phrase, int option );
bool findVocals ( char word, string &tmp );
void deleteVocalsWord ( string &phrase );
void deleteVocalsWordFile ( string &file );

int main() {
	
	setlocale(LC_ALL, "Russian");
	
	char functionKey;
	string file = "text.txt";
	string phrase, newPhrase;
	
	cout << "������� �����������: ";
	getline( cin, phrase );
	writeTextFile( phrase, file );
	
	do {
	    cout << "1.���������� ���������� ���� � �����������." << endl;
		cout << "2.�������� ����� �� �����������, ������� �������� ������� 2 ������� �����." << endl;
		cout << "3.������� ����� �� �����������, ������� �������� ������� 2 ������� �����." << endl;
		cout << "4.���������� ���������� ���� �� �����." << endl;
		cout << "5.�������� � ���� ����� � ���� �����������, ������� �������� ������� 2 ������� �����." << endl;
	    cout << "6.������� ����� �� �����, ������� �������� ������� 2 ������� �����." << endl;
	    cout << "7.���������� ���������� ���� �� �����, ������� �������� ������ 2 ������� ����." << endl;
	    cout << "0.�����" << endl;
	    functionKey = getch();
	    system("CLS");
	    
	    switch(functionKey) {
	    	
	    	case '1':
	    		
	    		cout << "�����������: " << endl;
	    		cout << phrase << "\n" << endl;
	    		cout << checkWordCount( phrase, 0 ) << " ����(�) � �����������" << endl;
	    		cout << "\n\t( 'Enter' - ��������� � ���� )" << endl;
				getch();
				system("CLS");
	    		break;
	    		
	    	case '2':
	    		
	    		cout << "�����������: " << endl;
	    		cout << phrase << "\n" << endl;
	    		cout << "����� ������� �������� ������� 2 �������:" << endl;
	    		showVocals( phrase, 0 );
	    		cout << "\n\t( 'Enter' - ��������� � ���� )" << endl;
				getch();
				system("CLS");
	    		break;
	    		
	    	case '3':
	    		
	    		cout << "�����������: " << endl;
	    		cout << phrase << "\n" << endl;
	    		cout << "����� �����������:" << endl;
	    		deleteVocalsWord ( phrase );
	    		cout << "\n\t( 'Enter' - ��������� � ���� )" << endl;
				getch();
				system("CLS");
	    		break;
	    		
	    	case '4':
	    		
	    		cout << "�����������: " << endl;
	    		cout << phrase << "\n" << endl;
	    		cout << checkWordCount( file, 1 ) << " ����(�) � �����" << endl;
	    		cout << "\t( 'Enter' - ��������� � ���� )" << endl;
				getch();
				system("CLS");
	    		break;
	    		
	    	case '5':
	    		
	    		cout << "������� ����������� � ����:" << endl;
	    		showVocals( phrase, 1 );
	    		cout << "\t( 'Enter' - ��������� � ���� )" << endl;
				getch();
				system("CLS");
	    		break;
	    		
	    	case '6':
	    		
	    		cout << "������� ����� � �����, ������� �������� ������� 2 ������� �����" << endl;
	    		deleteVocalsWordFile ( file );
	    		cout << "\t( 'Enter' - ��������� � ���� )" << endl;
				getch();
				system("CLS");
	    		break;
	    		
	    	case '7':
	    		cout << "����� ������� �������� ������� 2 �������:" << endl;
	    		showVocals( phrase, 2 );
	    		cout << "\t( 'Enter' - ��������� � ���� )" << endl;
				getch();
				system("CLS");
	    		break;
	    	
			case '0':
				cout << "�������� ����� �� ���������" << endl;
				break;
				
	    	default:
	    		cout << "����������� �������. ��������� ��� ���!" << endl;
                break;
		}
	    
	} while ( functionKey != '0' );
}

void writeTextFile ( string &phrase, string &file ) {
	ofstream writeFile("text.txt");
	writeFile << phrase << " ";
	writeFile.close();
}

int checkWordCount ( string &phrase, int option ) {
	int count = 0;
	string tmp;
	
	if ( option == 0 ) {
		istringstream text(phrase);
		text >> tmp;
		
		while ( text and !tmp.empty() ) {
	        count++;
	        text >> tmp;
		}
		return count;
		
	} else if ( option == 1 ) {
		ifstream text("text.txt");
		text >> tmp;
		
		while ( text and !tmp.empty() ) {
	        count++;
	        text >> tmp;
		}
	
		text.close();
		return count;
	}
	
}

void showVocals ( string &phrase, int option ) {
	string tmp;
	int count;
	istringstream text(phrase);
	text >> tmp;
	
	while ( text and !tmp.empty() ) {
		count = 0;
		
		for ( int i = 0; i < tmp.length(); i++) {
			if ( findVocals( tmp[i], tmp ) ) {
				count++;
			}
		}		
		
		if ( count >= 2 ) {
			if ( option == 0 ) {
				cout << count << " � �����: " << tmp << endl;
			} else if ( option == 1 ) {
				ofstream vocals("vocals.txt", ios::app);
				vocals << tmp << " ";
				vocals.close();
			}
			
		} else if ( ( count < 2 ) and ( option == 2 ) ) {
			cout << count << " � �����: " << tmp << endl;
		}
	
		text >> tmp;
	}
}

bool findVocals ( char word, string &tmp ) {
 	string vocals = "AaEeIiJjOoUuYy";
 	
  	for (int i = 0; i < vocals.length(); i++) {
    	if (word == vocals[i]) {
    		return true;
    	}
	}

    return false;
}

void deleteVocalsWord ( string &phrase ) {
	string tmp;
	string newPhrase;
	int count;
	istringstream text(phrase);
	text >> tmp;
	while ( text and !tmp.empty() ) {	
		count = 0;
		
		for ( int i = 0; i < tmp.length(); i++ ) {
			
			if ( findVocals( tmp[i], tmp ) ) {
				count++;
			}
		}
		if ( count < 2 ) {
			newPhrase =  newPhrase + " " + tmp;
		} 

		text >> tmp;
	}
	cout << newPhrase;
}

void deleteVocalsWordFile ( string &file ) {
	string tmp;
	string newPhrase;
	int count;
	ifstream text("text.txt");
	text >> tmp;
	while ( text and !tmp.empty() ) {	
		count = 0;
		
		for ( int i = 0; i < tmp.length(); i++ ) {
			
			if ( findVocals( tmp[i], tmp ) ) {
				count++;
			}
		}
		if ( count < 2 ) {
			ofstream text("result.txt", ios::app);
			text << tmp << " ";
			text.close();
		} 

		text >> tmp;
	}
}

