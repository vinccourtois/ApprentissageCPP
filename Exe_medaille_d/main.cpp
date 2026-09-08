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

        string nomFichierSortie;
        cout << "Entrer le nom du fichier de sortie (ex: resultat.txt) : ";
        cin >> nomFichierSortie;

        ofstream fichierSortie(nomFichierSortie.c_str());
        if (!fichierSortie.is_open()) {
            cerr << "Erreur lors de l'ouverture du fichier en écriture" << endl;
            leFichier.close();
        }


        string pays;
        int nbOr;
        int nbArgent;
        int nbBronze;


        fichierSortie << "+" << setw(21) << setfill('-') << "+" << setw(6) << setfill('-') << "+" << setw(6) << setfill('-') << "+" << setw(6) << setfill('-') << "+" << endl;

        do
        {

            leFichier >> pays >> nbOr >> nbArgent >> nbBronze;

            if (leFichier.good())
            {

                fichierSortie << setfill(' ') << "|" << setw(20) << left << pays << setfill(' ') << "|"
                              << setw(5) << right << nbOr << "|"
                              << setw(5) << right << nbArgent << "|"
                              << setw(5) << right << nbBronze << "|" << endl;
            }
        } while (!leFichier.eof());
        fichierSortie << "+" << setw(21) << setfill('-') << "+" << setw(6) << setfill('-') << "+" << setw(6) << setfill('-') << "+" << setw(6) << setfill('-') << "+" << endl;
        fichierSortie.close();
        leFichier.close();

        cout << "Le tableau a été généré avec succès dans le fichier : " << nomFichierSortie << endl;
    }
    return 0;
}
