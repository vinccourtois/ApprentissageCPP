

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string nomDuFichier;
    cout << "Entrer le nom du fichier à lire : ";
    cin >> nomDuFichier;
    ifstream leFichier(nomDuFichier.c_str());
    if (!leFichier.is_open())
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    else
    {
        string pays;
        int nbOr;
        int nbArgent;
        int nbBronze;
        cout <<"+"<< setw(21)<< setfill('-') <<"+" << setw(6)<<setfill('-')<< "+" << setw(6)<<setfill('-')<<"+" << setw(6)<<setfill('-')<<"+" <<endl ;
        do
        {
            leFichier >> pays >> nbOr >> nbArgent >> nbBronze;
            if (leFichier.good())
            {
                cout << setfill(' ')<< "|" << setw(20)<< left << pays << setfill(' ') <<"|"
                     << setw(5) <<right << nbOr <<"|"
                     <<setw(5) << right <<nbArgent<<"|"
                     <<setw(5) << right<< nbBronze  << "|" << endl ;
            }
        } while (!leFichier.eof());
        cout <<"+"<< setw(21)<< setfill('-') <<"+" << setw(6)<<setfill('-')<< "+" << setw(6)<<setfill('-')<<"+" << setw(6)<<setfill('-')<<"+" <<endl ;
    }
    return 0;
}