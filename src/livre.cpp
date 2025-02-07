#include "livre.h"
#include <iostream>


bool AjouterLivre(Livre *tab_livres, int &sizee, int &idd){
  int annee;
  std::string disponible, titre, auteur;
  bool estAjoute = false;
  idd++;
  Livre livre;
  livre.id = idd;


  do {
    std::cout << "Veuillez saisir le titre du livre : " << "\n";
    std::getline(std::cin, titre);
  } while (titre.empty());

  std::cout << "\n";

  do{
    std::cout << "Veuillez saisir l'auteur du livre : " << "\n";
    std::getline(std::cin, auteur);
  } while (auteur.empty());
    
  std::cout << "\n";

  do{
    std::cout << "Veuillez saisir l'annee du livre : " << "\n";
    std::cin >> (annee);
  } while (annee <= 0);
  
  std::cin.ignore(); // Vider le buffer pour éviter que std::getline lise une entrée vide
  std::cout << "\n";

  do{
    std::cout << "Est ce qu'il est disponible ? (oui / non) : " << "\n";
    std::getline(std::cin, disponible);  
  } while (disponible.empty());

  livre.titre = titre;
  livre.auteur = auteur;
  livre.annee = annee;
  if (disponible == "oui") {
    livre.estDisponible = true;
  } else {
    livre.estDisponible = false;
  }

  sizee++;
  Livre *temp = new Livre[sizee];
  for (int i = 0; i < sizee-1; ++i) {
      temp[i] = tab_livres[i];
  }
  temp[sizee-1] = livre;
  delete[] tab_livres;
  tab_livres = temp;
  estAjoute = true;

  return estAjoute;

};



// bool AfficherLivres(Livre *tab_livres, int &size){


// };



// bool ModifierLivre(Livre *tab_livres, int &size, std::string const& membre){

// };


// bool ModifierLivreComplet(Livre *tab_livres, int &size){

// };


// bool SupprimerLivre(Livre *tab_livres, int &size, std::string const& membre){


// };


// bool SupprimerLivres(Livre *tab_livres){


// };


// bool AfficherLivre(Livre *tab_livres, std::string const& membre){


// };

