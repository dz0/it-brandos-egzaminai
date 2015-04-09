#include <fstream>
#include <iomanip>
#include <string>
//#include <iostream>
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
    int k_miest, k_aps=0;
    miestas Miest[104];
    apskiritis Aps[104];
    

// ------- duom skaitymas --------
    ifstream in ("U2.txt");
    in >> k_miest;
    for (int i=1; i<=k_miest; i++)
    {
        in >> Miest[i].pav >> Miest[i].aps >> Miest[i].n; // jei pavadinimas iš dviejų žodžių, reik kitaip, su getline...
    }
    in.close();
    
// --------- skirstymas (pastaba: iš anksto nežinoma, kiek yra apskričių) -------
    for (int i=1; i<=k_miest; i++)
    {
        int kuri=1; // miesto apskrities nr
        for ( ; kuri<=i; kuri++) // peržiūrim, ar jau tokia apsritis buvo informacijoj
        {
            if ( Miest[i].aps == Aps[kuri].pav ) 
               break;    // rei randam, sustojam
        }
        // jei neranda, numeris  padidės iki neužpildytos apskričių masyvo vietos 

        // pildom apskrities duomenis
        if (Miest[i].n < Aps[kuri].n)   
            Aps[kuri].n = Miest[i].n;  // mažiausias miestas
        Aps[kuri].suma += Miest[i].n;  // gyventojų skaičius           
        // jei nauja apskritis, įsidėmim pavadinimą ir padidinam kiekį
        if (kuri==aps+1) { Aps[kuri].pav = Miest[i].pav;      aps++;  }
        
    }
    
//--------- rikiuojam rezultatus ----------
    for (int i=1; i<=aps; i++)
    {
        for (int j=i+1; j<=aps; j++)
        {
           if (Aps[i].n > Aps[j].n)
           {
               swap(Aps[i], Aps[j]); 
               
           }
           else if (Aps[i].n == Aps[j].n)
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
    out << aps << endl;
    for (int i=1; i<=aps; i++)
    {
        out.width(10);
        out.fill(' ');
        out << left << Aps[i].pav;
        out << Aps[i].n << " " << Aps[i].suma << endl;
    }
    
    return 0;
}
