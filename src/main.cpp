#include <iostream>
#include "livre.h"

using namespace std;

int main() {
    int choix, id = 0, size = 0;
    Livre* tab_livres = nullptr;
    bool actif = true;

    cout << "------------------------------------------------------------------------------- " << "\n";
    cout << "------------------------------------------------------------------------------- " << "\n";
    cout << "----------------------------  GESTION BIBLIOTHEQUE ---------------------------- " << "\n";
    cout << "------------------------------------------------------------------------------- " << "\n";
    cout << "------------------------------------------------------------------------------- " << "\n";

    do {
      if(Menu(choix) == 0){
          switch (choix) {
            case 2:
              if (AjouterLivre(&tab_livres, size, id)) {
                cout << "Ajout avec succes !\n";
              } else {
                cout << "Erreur lors de l'ajout du livre !\n";
              }
              break; 
            case 7:
              cout << "Good night !\n";
              actif = false;
              break;
            default:
              cout << "Veuillez choisir une option valide !\n";
              break;
          }
        }
    } while (actif);

    // Nettoyage mémoire (si tab_livres a été alloué)
    delete[] tab_livres;

    return 0;
}
