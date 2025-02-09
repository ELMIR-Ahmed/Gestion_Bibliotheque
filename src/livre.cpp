#include "livre.h"
#include <iostream>
#include <limits> // Pour gérer les erreurs d'entrée
#include <typeinfo>



int Menu(int &choix){


  std::cout << "Afficher livres (taper 0) \n";
  std::cout << "Afficher un livre (taper 1) \n";
  std::cout << "Ajouter un livre (taper 2) \n";
  std::cout << "Modifier une information d'un livre (taper 3) \n";
  std::cout << "Modifier un livre complet (taper 4) \n";
  std::cout << "Supprimer un livre (taper 5) \n";
  std::cout << "Supprimer tous les livres (taper 6) \n";
  std::cout << "Quitter le programme [-> (taper 7) \n";
  std::cout << "---------------------------------------------------------------- \n";
  std::cout << "=> Votre choix : ";

  std::cin >> choix;

  std::cout << "---------------------------------------------------------------- \n";

  // Vérifier si l'entrée est invalide
  if (std::cin.fail() || choix < 0 || choix > 7) {
      std::cin.clear();  // Réinitialiser l'état de cin
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer l'entrée invalide
      std::cout << "Entrée invalide ! Veuillez entrer un chiffre entre 0 et 7.\n";
      return -1; // Réinitialiser choix pour éviter d'exécuter un mauvais cas
  } else {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Nettoyer le buffer
  }

  return 0;

};


bool AjouterLivre(Livre **tab_livres, int &sizee, int &idd){
  std::string disponible, titre, auteur; 
  int annee;
  bool estAjoute = false;
  idd++;
  Livre livre;
  livre.id = idd;

  // Saisie du titre avec contrôle
  do {
    std::cout << "Veuillez saisir le titre du livre : ";
    std::getline(std::cin, titre);
    if (titre.empty()) {
      std::cout << "Titre invalide, veuillez saisir un titre non vide !:\n";
    }
  } while (titre.empty());

// Saisie de l'auteur avec contrôle
do {
    std::cout << "Veuillez saisir l'auteur du livre : ";
    std::getline(std::cin, auteur);
} while (auteur.empty());

do {
  std::cout << "Veuillez saisir l'annee du livre (min = 1900) : ";
  std::cin >> annee;

  if (std::cin.fail() || annee < 1900) { 
      std::cin.clear();  // Réinitialiser cin pour éviter l'état d'erreur
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Vider le buffer
      std::cout << "Entree invalide ! Veuillez entrer une annee valide (< 1900).\n";
      annee = -1; // Valeur invalide pour forcer la boucle à recommencer
  }

} while (annee < 1900);

std::cin.ignore();

// Saisie de la disponibilité avec vérification
do {
    std::cout << "Est-ce qu'il est disponible ? (oui / non) : ";
    std::getline(std::cin, disponible);
} while (disponible != "oui" && disponible != "non");

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
      temp[i] = (*tab_livres)[i];
  }
  temp[sizee-1] = livre;
  
  delete[] *tab_livres;
  *tab_livres = temp;

  if (sizee > sizee - 1){
    estAjoute = true;
  } else {
    estAjoute = false;
  }

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

