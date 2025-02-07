#include <iostream>
#include "livre.h"
using namespace std;

int main () {

  int choix, id = 0, size = 0;
  Livre *tab_livres = nullptr;
  

  cout << "------------------------------------------------------------------------------- " << "\n";
  cout << "------------------------------------------------------------------------------- " << "\n";
  cout << "----------------------------  GESTION BIBLIOTHEQUE ---------------------------- " << "\n";
  cout << "------------------------------------------------------------------------------- " << "\n";
  cout << "------------------------------------------------------------------------------- " << "\n";

  cout << "Afficher livres (taper 0) : " << "\n";
  cout << "Afficher un livre (taper 1) : " << "\n";
  cout << "Ajouter un livre (taper 2) : " << "\n";
  cout << "Modifier une information d'un livre (taper 3) : " << "\n";
  cout << "Modifier un livre complet (taper 4) : " << "\n";
  cout << "Supprimer un livre (taper 5) : " << "\n";
  cout << "Supprimer tout les livres (taper 6) : " << "\n";
  cout << "------------------------------------------------- " << "\n";
  cout << "=> votre choix : ";
  cin >> choix;


  switch (choix)
  {
  case 2:
    if(AjouterLivre(tab_livres, size, id)){
      cout << "Ajout avec succes !" << "\n";
    };
    break;
  default:
    cout << "veuiller chosir !";
    break;
  }

}