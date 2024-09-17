#ifndef POINT_H
#define POINT_H

#include <string>
#include <unordered_map>

using namespace std;

// Classe Client
class Client {
private:
    string CIN;
    string nom;
    string prenom;
    string numeroTelephone;

public:
    // Constructeur
    Client(const string& CIN, const string& nom, const string& prenom, const string& numeroTelephone);

    // Accesseurs
    string getCIN() const;
    string getNom() const;
    string getPrenom() const;
    string getNumeroTelephone() const;

    // Méthode d'affichage des informations du client
    void afficherInfos() const;
};

// Classe Compte
class Compte {
private:
    static int prochainNumeroCompte;
    int numeroCompte;
    double solde;
    Client proprietaire;

public:
    // Constructeur
    Compte(const Client& proprietaire, double soldeInitial = 0.0);

    // Accesseurs
    int getNumeroCompte() const;
    double getSolde() const;
    const Client& getProprietaire() const;

    // Méthodes pour les opérations bancaires
    void crediter(double montant);
    void debiter(double montant);
    void virement(Compte& autreCompte, double montant);
    void afficherRIB() const;
};

// Classe Banque
class Banque {
private:
    unordered_map<int, Compte> comptes;

public:
    void ajouterCompte(const Compte& compte);
    Compte* trouverCompte(int numeroCompte);
    void afficherComptes() const;
};

#endif
