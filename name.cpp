#include "point.h"
#include <iostream>

using namespace std;

int main() {
    // Création de clients
    Client client1("CIN123456", "Drame", "Samba", "0600000000");
    Client client2("CIN789101", "Chetouani", "Haythem", "0700000000");

    // Création de comptes
    Compte compte1(client1, 500);  // Compte de Jean Dupont avec 500 euros
    Compte compte2(client2, 1000); // Compte de Sophie Martin avec 1000 euros

    // Création de la banque (base de données fictive)
    Banque banque;
    banque.ajouterCompte(compte1);
    banque.ajouterCompte(compte2);

    // Affichage des comptes
    cout << "Liste des comptes:\n";
    banque.afficherComptes();

    // Opérations bancaires
    cout << "\nOpérations sur le compte 1:\n";
    compte1.crediter(200);
    compte1.debiter(100);
    compte1.afficherRIB();

    // Virement du compte 1 vers le compte 2
    cout << "\nVirement du compte 1 vers le compte 2:\n";
    compte1.virement(compte2, 150);

    // Affichage final des comptes après les opérations
    cout << "\nListe des comptes après opérations:\n";
    banque.afficherComptes();

    return 0;
}
