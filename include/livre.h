#ifndef LIVRE_H
#define LIVRE_H

#include <string>

struct Livre
{
  int id, annee;
  std::string titre;
  std::string auteur;
  bool estDisponible;
};


int Menu(int &choix);
bool AjouterLivre(Livre **tab_livres, int &sizee, int &idd);
// bool ModifierLivre(Livre *tab_livres, int &size, std::string const& membre);
// bool ModifierLivreComplet(Livre *tab_livres, int &size);
// bool SupprimerLivre(Livre *tab_livres, int &size, std::string const& membre);
// bool SupprimerLivres(Livre *tab_livres);
// bool AfficherLivre(Livre *tab_livres, std::string const& membre);
// bool AfficherLivres(Livre *tab_livres, int &size);



#endif