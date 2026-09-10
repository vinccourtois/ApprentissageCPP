
#include <algorithm>
#include <limits>
#include "menu.h"

Menu::Menu(const string &_nom)
    :nom(_nom)
    , longueurMax(0)
{
    ifstream fichier(nom.c_str());
    if (!fichier.is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
        nbOptions=0;
    }
    else
    {

        nbOptions = static_cast<int>(count(istreambuf_iterator<char>(fichier),istreambuf_iterator<char>(),'\n'));
        cout << "nbOptions : " << nbOptions << endl;
        fichier.seekg(0,ios::beg);

        char ligne[50];
        options = new string [nbOptions];
        for (int var = 0; var < nbOptions; ++var) {
            fichier.getline(ligne,50 );
            options[var] = string(ligne);
            cout << options[var] << endl;

        }
        if(options[var].length>nbOptions)
        {
            nbOptions=options[var].length;
        }
        fichier.close();
    }


    // ouvrir le fichier
    // Si il y a une erreur
    // alors Afficher un message indiquant une erreur de lecture
    // et mettre nbOptions à 0
    // Sinon calculer nbOptions, le nombre d’options dans le fichier
    // allouer dynamiquement le tableau options en fonction de nbOptions
    // Pour chaque option dans le fichier
    // Lire l’option et l’affecter dans le tableau options
    // Si la taille de l’option est plus grande que longueurMax
    // alors longueurMax reçoit la taille de l’option
    // FinSi
    // FinPour
    // FinSi
}
Menu::~Menu()
{
    delete [] options;
}

int Menu::Afficher()
{
    if(!(cin>>choix))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        choix = -1;
         system("clear");
    }
}

void Menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout << endl << "appuyer sur la touche Entrée pour continuer...";
    getline(cin,uneChaine);
    cin.ignore( std::numeric_limits<streamsize>::max(), '\n' );
    system("clear");
}
