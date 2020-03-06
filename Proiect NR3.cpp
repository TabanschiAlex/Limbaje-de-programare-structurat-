#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
#define nmax  50
using namespace std;

int creare_vector(int v[], int n);
int generare_vector(int v[], int n);
void afisare_vector(int v[], int n);
int Minimum(int v[], int n );
int Maximum(int v[], int n );
double media(int v[], int n);
int Sortare_bubble_optimizata(int v[], int n );
int Sortare_insertiei(int v[], int n );
int Rotire_Dreapta(int v[],int n);

int main(){

    int key, n;
    int v[nmax];


  do {
        system("CLS");
    cout << "1.De determinat într-un tabel de numere valorile minima si maxima " <<endl;
    cout << "2.De determinat într-un tabel de numere media aritmetica " <<endl;
    cout << "3.De aranjat un tabel de numere în ordine crescatoare sau descrescatoare, utilizând una dintre metodele de sortare " <<endl;
    cout << "4.De efectuat rotirea la stânga (variantele impare) sau la dreapta (variantele pare) a elementelor tabelului de k ori" <<endl;
    cout << "5.De adaugat date în tabelul de numerele " <<endl;
    cout << "6.De ?ters date din tabelul de numerele." <<endl;
    cout << "7.De calculat o caracteristica, referitoare la datele concrete" <<endl;
    cout << "\t\tSelecteaza o optiune ==> ";
    cin  >> key;
    switch (key){
        case 1:
            system("CLS");
            cout << "Introduceti dimensiunea vectorului = ";
            cin >> n;
            //creare_vector(v, n);
            generare_vector(v, n);
            cout << "Tabelul : ";
            afisare_vector(v, n);
            cout<<"Valoarea minima este = "<<Minimum(v, n)<<endl;
            cout<<"Valoarea maxima este = "<<Maximum(v, n)<<endl;
        getch();
        break;
        case 2:
            system("CLS");
            cout << "Introduceti dimensiunea vectorului = ";
            cin >> n;
            //creare_vector(v, n);
            generare_vector(v, n);
            cout << "Tabelul : ";
            afisare_vector(v, n);
            cout << "Media elementelor este = "<<media(v, n);
        getch();
        break;
        case 3:
            system("CLS");
            cout << "Introduceti dimensiunea vectorului = ";
            cin >> n;
            //creare_vector(v, n);
            generare_vector(v, n);
            cout << "Tabelul initial: ";
            afisare_vector(v, n);
            cout << "Tabelul sortat crescator: ";
            Sortare_insertiei(v, n);
            cout << "Tabelul sortat descrescator: ";
            Sortare_bubble_optimizata(v, n);

        getch();
        break;
        case 4:
            system("CLS");
            cout << "Introduceti dimensiunea vectorului = ";
            cin >> n;
            generare_vector(v, n);
            cout << "Tabelul initial: ";
            afisare_vector(v, n);
            cout << "Rotirea la dreapta: ";
            Rotire_Dreapta( v,  n);

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
  }while(key !=0);
  return 1;
}
int creare_vector(int v[], int n)
{
     cout << "Dati elementele tabelului \n";
for(int i=0; i<n; i++){
        cout << "V[ "<<i+1<<" ] = ";
        cin >> v[i];
        }


 return 1;
}
int generare_vector(int v[], int n)
{

for(int i=0; i<n; i++)
    v[i] =  rand()%  -10 +10;


   return 1;
}
void afisare_vector(int v[], int n){

for(int i=0; i<n; i++)
cout << setw(8) << v[i];
        cout << endl;
}

int Minimum(int v[], int n )
{
int i, min;
min = v[0];
for(i=1; i<n; i++)
if(v[i]<min)
min = v[i];
return min;
}

int Maximum(int v[], int n )
{
int i, max;
max = v[0];
for(i=1; i<n; i++)
if(v[i]>max)
max = v[i];
return max;
}

double media(int v[], int n){
    int i, media= 0;
    for(i=0; i<n; i++){
        media+=v[i];
    }
    return (double)media/n;
}
int Sortare_bubble_optimizata(int v[], int n ) {
int i, j=0, m, aux;
do
{
m = 0; j++;
for(i=0; i<n-j; i++)
if(v[i]<v[i+1]) {
aux = v[i];
v[i] = v[i+1];
v[i+1] = aux;
m = 1;
}
} while(m);
afisare_vector(v, n);
return 1;
}
int Sortare_insertiei(int v[], int n ) {
 int key, j;
   for(int i = 1; i<n; i++) {
      key = v[i];
      j = i;
      while(j > 0 && v[j-1]>key) {
         v[j] = v[j-1];
         j--;
      }
     v[j] = key;
   }
 afisare_vector(v, n);
return 1;
}
int Rotire_Dreapta(int v[], int n)
{
int i, aux;
if(n==0) return 0;
else {

aux = v[n-1];
for(i=n-1; i>0; i--)
v[i] = v[i-1];
v[0] = aux;
}
 afisare_vector(v, n);
return 1;
}
