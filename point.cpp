#include "point.h"
#include <iostream>

using namespace std;

int Compte::prochainNumeroCompte = 1000;


Client::Client(const string& CIN, const string& nom, const string& prenom, const string& numeroTelephone)
    : CIN(CIN), nom(nom), prenom(prenom), numeroTelephone(numeroTelephone) {}

string Client::getCIN() const { return CIN; }
string Client::getNom() const { return nom; }
string Client::getPrenom() const { return prenom; }
string Client::getNumeroTelephone() const { return numeroTelephone; }

void Client::afficherInfos() const {
    cout << "Client: " << nom << " " << prenom << " (CIN: " << CIN << ", Tel: " << numeroTelephone << ")\n";
}


Compte::Compte(const Client& proprietaire, double soldeInitial)
    : proprietaire(proprietaire), solde(soldeInitial) {
    numeroCompte = prochainNumeroCompte++;
}

int Compte::getNumeroCompte() const { return numeroCompte; }
double Compte::getSolde() const { return solde; }
const Client& Compte::getProprietaire() const { return proprietaire; }

void Compte::crediter(double montant) {
    solde += montant;
    cout << "Le compte " << numeroCompte << " a été crédité de " << montant << " euros. Solde actuel: " << solde << " euros.\n";
}

void Compte::debiter(double montant) {
    if (montant <= solde) {
        solde -= montant;
        cout << "Le compte " << numeroCompte << " a été débité de " << montant << " euros. Solde actuel: " << solde << " euros.\n";
    } else {
        cout << "Solde insuffisant pour débiter " << montant << " euros.\n";
    }
}

void Compte::virement(Compte& autreCompte, double montant) {
    if (montant <= solde) {
        debiter(montant);
        autreCompte.crediter(montant);
        cout << "Virement de " << montant << " euros du compte " << numeroCompte << " vers le compte " << autreCompte.getNumeroCompte() << ".\n";
    } else {
        cout << "Solde insuffisant pour effectuer le virement.\n";
    }
}

void Compte::afficherRIB() const {
    cout << "RIB du compte " << numeroCompte << ":\n"
         << "Propriétaire: " << proprietaire.getNom() << " " << proprietaire.getPrenom() << "\n"
         << "CIN: " << proprietaire.getCIN() << "\n"
         << "Solde: " << solde << " euros\n";
}


void Banque::ajouterCompte(const Compte& compte) {
    comptes[compte.getNumeroCompte()] = compte;
}

Compte* Banque::trouverCompte(int numeroCompte) {
    if (comptes.find(numeroCompte) != comptes.end()) {
        return &comptes[numeroCompte];
    } else {
        cout << "Compte " << numeroCompte << " non trouvé.\n";
        return nullptr;
    }
}

void Banque::afficherComptes() const {
    for (const auto& [numero, compte] : comptes) {
        cout << "Compte #" << numero << " - Solde: " << compte.getSolde() << " euros\n";
    }
}
