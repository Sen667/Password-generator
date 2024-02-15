# Générateur de mots de passe

Ce programme permet de générer des mots de passe personnalisés avec une longueur spécifiée et des caractéristiques particulières. Il offre également la possibilité d'enregistrer les mots de passe générés dans un fichier texte.

## Prérequis

Le code utilise la bibliothèque standard C++, assurez-vous donc d'avoir un compilateur C++ installé. Testé avec g++ version 9.3.0.

## Utilisation

Compilez le code à l'aide d'un compilateur C++. Par exemple, avec g++ :

g++ -o passwordGenerator passwordGenerator.cpp

Exécutez le programme compilé :

./passwordGenerator

Suivez les invites pour générer les mots de passe souhaités avec les spécifications personnalisées.

Après la génération des mots de passe, le programme demandera si vous souhaitez enregistrer les informations dans un fichier texte. Tapez 'o' ou 'O' pour enregistrer le fichier sous le nom "infoMdp.txt".

## Fonctionnalités

- Générer plusieurs mots de passe avec une longueur personnalisée
- Inclure un nombre spécifié de chiffres et de caractères spéciaux dans les mots de passe
- Mélanger les caractères et les chiffres pour créer le mot de passe final
- Enregistrer les informations des mots de passe générés dans un fichier texte

## Structure du code

Le code est composé de plusieurs fonctions et structures :

- `Password` : Structure qui contient un vecteur d'entiers (chiffres) et une chaîne de caractères (caractères spéciaux)
- `Revision` : Structure qui contient le nombre de mots de passe et un tableau d'instances de `Password`
- `aleatoire(int max)` : Fonction qui génère un nombre aléatoire dans une plage donnée
- `initLength()` : Fonction qui obtient la longueur de mot de passe souhaitée auprès de l'utilisateur
- `generatePassword(int length)` : Fonction qui génère un mot de passe unique avec des spécifications personnalisées
- `generateMdps(Revision* T)` : Fonction qui génère plusieurs mots de passe en fonction des entrées utilisateur
- `melangerMotDePasse(const std::string& caracteres, const std::vector<int>& chiffres)` : Fonction qui mélange les caractères et les chiffres pour créer le mot de passe final

## Remarque

Le code utilise des codes d'échappement ANSI pour la coloration de la console, ce qui peut ne pas être pris en charge sur tous les terminaux. Si les couleurs ne s'affichent pas correctement, supprimez simplement les définitions de couleur (`NC`, `RED`, `GRN`, `CYN`) et les codes d'échappement dans les instructions `cout`.
