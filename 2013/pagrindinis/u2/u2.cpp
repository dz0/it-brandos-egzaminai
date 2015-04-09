#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct miestas{
    string pav, aps;
    int n;
};
struct apskiritis{
    string pav="";
    int n=600001, suma=0;
};

int main()
{
    int k_miest, k_aps=0;  //miestų ir apskričių kiekiai
    miestas Miest[103];
    apskiritis Aps[103];


// ------- duom skaitymas --------
    ifstream in ("U2.txt");
    in >> k_miest;
    for (int i=0; i<k_miest; i++)
    {
        in >> Miest[i].pav >> Miest[i].aps >> Miest[i].n; // jei pavadinimas iš dviejų žodžių, reik kitaip, su getline...
        // cout << Miest[i].pav << " " <<  Miest[i].aps << " " <<  Miest[i].n << endl;
    }
    in.close();

// --------- skirstymas (pastaba: iš anksto nežinoma, kiek yra apskričių) -------
    for (int i=0; i<k_miest; i++)
    {
        int kuri=0; // apskrities nr miestui
        for ( ; kuri < i; kuri++) // peržiūrim, ar jau tokia apsritis buvo informacijoj
        {
            if ( Miest[i].aps == Aps[kuri].pav )
            {
               break;    // rei randam, sustojam
            }
        }

        // jei nauja apskritis, įsidėmim pavadinimą ir padidinam kiekį
        if (kuri==k_aps) { Aps[kuri].pav = Miest[i].aps;      k_aps++;  }
        // pildom apskrities duomenis
        if (Miest[i].n < Aps[kuri].n)
            Aps[kuri].n = Miest[i].n;  // mažiausias miestas
        Aps[kuri].suma += Miest[i].n;  // gyventojų skaičius

    }

//--------- rikiuojam rezultatus ----------
    for (int i=0; i<k_aps; i++)
    {
        for (int j=i+1; j<k_aps; j++)
        {
           if (Aps[i].n > Aps[j].n )
           {
               swap(Aps[i], Aps[j]);

           }
           else if (Aps[i].n == Aps[j].n)  // jei mažiausių miestų skaičiai sutampa
           {
               if (Aps[i].pav > Aps[j].pav)
               {
                    swap(Aps[i], Aps[j]);
               }

           }
        }
    }

// ------- rez rašymas --------
    ofstream out("U2rez.txt");
    out << k_aps << endl;
    for (int i=0; i<k_aps; i++)
    {
        out.width(10);
        out.fill(' ');
        out << left << Aps[i].pav;
        out << Aps[i].n << " " << Aps[i].suma << endl;
    }

    return 0;
}
