#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool verifyFiles(char* file1, char* file2) {
    bool estValide = true;
    ifstream fichier1(file1);
    ofstream fichier2(file2);

    if (!fichier1.is_open()) {
        cerr << "Le premier argument n'est pas un fichier valide." << endl;
        exit(-1);
    }

    if (!fichier2.is_open()) {
        cerr << "Le deuxième argument n'est pas un fichier valide." << endl;
        exit(-1);
    }

    fichier1.close();
    fichier2.close();

    return estValide;
}

bool verifierValeurEntiere(const string& arg) {
    bool estV = true;
    try {
        int value = stoi(arg);
        if (value <= 0) {
            cerr << "La valeur suivant cette argument doit être un entier positif différent de zéro." << endl;
            exit(-1);
        }
    } catch (...) {
        cerr << "La valeur suivant cette argument n'est pas un entier valide." << endl;
        exit(-1);
    }

    return estV;
}

bool verifyArguments(int argc, char** argv) {
    bool argumentsValides = true;

    if (argc >= 3) {
        char* file1 = argv[1];
        char* file2 = argv[2];

        argumentsValides = verifyFiles(file1, file2);
    } else {
        cerr << "Les deux premiers arguments doivent être des noms de fichiers." << endl;
        exit(-1);
    }

    if (argc >= 4) {
        string arg3 = argv[3];

        if (arg3 == "-l" || arg3 == "-h") {
            cout << "Je suis ici"<< endl;
            if (argc >= 5) {
                string arg4 = argv[4];
                try {
                    double value = stod(arg4);
                    // Le reste du code ici si besoin
                } catch (...) {
                    cerr << "Le quatrième argument n'est pas une valeur double valide." << endl;
                    exit(-1);
                }
            } else {
                cerr << "Le troisième argument nécessite une valeur double." << endl;
                exit(-1);
            }

            if (argv[5] == "-f") {
                cout << "Je here ici"<< endl;
                string arg6 = argv[6];
                argumentsValides = verifierValeurEntiere(arg6);
            }

            if (argc >= 7 && argv[5] == "-a") {
                cout << "Je rentre ici\n";
                string arg6 = argv[6];
                argumentsValides = verifierValeurEntiere(arg6);
            }
            
            if (argc >= 7 || argv[5] == "-i") {
                // Recuperer la valeur
            }

            
        } else {
            cerr << "Le troisième argument doit être '-l' ou '-h'." << endl;
            exit(-1);
        }
    } else {
        cerr << "Le programme nécessite un troisième argument." << endl;
        exit(-1);
    }

    return argumentsValides;
}
int main(int argc, char** argv) {
    if (!verifyArguments(argc, argv)) {
        return 1;
    }

    // Le reste du code ici si les arguments sont valides

    return 0;
}
