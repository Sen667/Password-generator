#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <fstream> 
#include <ctime>
#include <algorithm>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

using namespace std;

struct Password {
    vector<int> numbers;
    string characters = "";
};

struct Revision {
    int numMdps;
    Password* passwords;
};

int aleatoire(int max) {
    return rand() % (max + 1);
}

int initLength() {
    int length;
    cout << NC "Veuillez choisir la longueur du mot de passe : \n";
    cin >> length;

    return length;
}

Password generatePassword(int length) { 
    Password pw; 

    int numbers;

    cout << NC "Combien de chiffres voulez-vous ? (0 pour aucun) ";
    cin >> numbers;

    if (numbers > length) {
        cout << RED "[ERREUR] Impossible d'avoir plus de caracteres que de longueur" << endl;
        numbers = 0;
    }
    else if (numbers < 1) {
        cout << RED "[ERREUR] Au moins un nombre doit être présent." << endl;
        numbers = 0;
    }
    else if (numbers == length) {
        cout << RED "[ERREUR] Le mot de passe ne peut pas être composé uniquement de nombres." << endl;
        numbers = 0;
    }
    else {
        for (int i = 0; i < numbers; ++i) {
            int randomNumber = aleatoire(9) + 1;
            pw.numbers.push_back(randomNumber); 
        }
    }

    const char specialChars[6] = { '-', '&', '@', '#', '%', '$' };
    int count;

    cout << NC "Combien de caracteres spéciaux voulez-vous ? (0 pour aucun) ";
    cin >> count;

    if (count > length) {
        cout << RED "[ERREUR] Impossible d'avoir plus de caracteres que de longueur" << endl;
        count = 0;
    }
    else if (count == length) {
        cout << RED "[ERREUR] Le mot de passe ne peut pas être composé uniquement de caracteres spéciaux." << endl;
        count = 0;
    }
    else {
        for (int i = 0; i < count; ++i) {
            pw.characters += specialChars[aleatoire(5)];
        }
    }

    return pw;
}

void generateMdps(Revision* T) {
    cout << "Combien de mots de passe voulez-vous générer ? ";
    cin >> T->numMdps;

    T->passwords = new Password[T->numMdps];

    for (int i = 0; i < T->numMdps; i++) {
        cout << "Mot de passe " << i + 1 << ":" << endl;
        T->passwords[i] = generatePassword(initLength());
    }
}

std::string melangerMotDePasse(const std::string& caracteres, const std::vector<int>& chiffres) {
    std::string motDePasse = caracteres;
    for (const auto& chiffre : chiffres) {
        motDePasse += std::to_string(chiffre);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(motDePasse.begin(), motDePasse.end(), g);
    return motDePasse;
}

int main() {
    srand(time(nullptr));
    Revision T;
    generateMdps(&T);

    cout << "----------------------------------------------------------------" << endl;
    cout << CYN "Nombre de mots de passe générés : " << T.numMdps << endl;
    for (int i = 0; i < T.numMdps; i++) {
        cout << GRN "Mot de passe " << i + 1 << ":" << endl;
        cout << CYN "Nombre de chiffres dans le mot de passe : " << T.passwords[i].numbers.size() << endl;
        cout << CYN "Nombres dans le mot de passe : ";
        for (int j = 0; j < T.passwords[i].numbers.size(); ++j) {
            cout << T.passwords[i].numbers[j] << " ";
        }
        cout << endl;
        std::string motDePasseComplet = melangerMotDePasse(T.passwords[i].characters, T.passwords[i].numbers); // Génération du mot de passe complet
        cout << CYN "Mot de passe : " << motDePasseComplet << endl; // Affichage du mot de passe complet
    }
    cout << GRN "Voulez vous sauvegarder ces informations dans un fichier (.txt) ? [O/n]" NC << endl;
    char choix;
    cin >> choix;
    if (choix == 'o' || choix == 'O') {
        ofstream outfile("infoMdp.txt");
        if (!outfile) {
            cerr << RED "Erreur d'écriture sur le fichier." << endl;
        }
        else {
            outfile << "Informations des mots de passes générés" << endl;
            outfile << "Nombre total de mots de passes : " << T.numMdps << endl;
            for (int i = 0; i < T.numMdps; i++) {
                outfile << "Mot de passe " << i + 1 << " : " << melangerMotDePasse(T.passwords[i].characters, T.passwords[i].numbers) << endl;
            }
            outfile <<"Made By Sen667 alias Sen.eth" << endl;
            outfile.close();
            cout << RED "Fichier infoMdp.txt créé avec succes." NC << endl;
        }
    }

    cout << "----------------------------------------------------------------" << endl;

    delete[] T.passwords;

    return 0;
}
