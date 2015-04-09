//#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  // abs funkcijai
using namespace std;

// Duomenys
int n;          //Ámoniu skaicius
int m;          //Kilometru limitas dienai
int X[50];  // X koordinates
int Y[50];  // Y koordinates
string pavadinimai[50];

// Rezultatai
int aptarnauta=0;     //Aptarnautu imoniu skaicius
int kilometrai=0;   //Per darbo diena nuvaziuoti km
string paskutine;

void Skaitymas ()
{
    ifstream informacija ("U1.txt");
    informacija >> n;
    informacija >> m;
    //informacija.ignore(80, '\n');
    for(int i = 0; i < n; i++)
    {
        informacija >> pavadinimai[i]  >> X[i] >> Y[i];

    }
    informacija.close();
}

void Rezultatai ()
{
    ofstream rezultatai ("U1rez.txt");
    rezultatai << aptarnauta << " " << kilometrai << " " << paskutine;
    rezultatai.close();
}

int kelias_firmai(int i)
{
   return 2*(abs(X[i])+abs(Y[i]))
}

int main()
{
    Skaitymas();
    for (int i=0; i<n; i++)
    {
        if (kilometrai+kelias_firmai(i) < m){
            kilometrai+=kelias_firmai(i);
            aptarnauta=i+1;
            paskutine=pavadinimai[i];
        }
    }
    Rezultatai();

    return 0;
}
