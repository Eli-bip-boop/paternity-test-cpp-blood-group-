#include <iostream>
#include <vector>
using namespace std;

struct Genotype {
    char a1;
    char a2;
};

istream& operator>>(istream& in, Genotype& g) {
    in >> g.a1 >> g.a2;
    return in;
}

ostream& operator<<(ostream& out, const Genotype& g) {
    out << g.a1 << " " << g.a2;
    return out;
}

char mandatoryFatherAllele(Genotype mother, Genotype child) {
    if (child.a1 == mother.a1 || child.a1 == mother.a2)
        return child.a2;

    return child.a1;
}

bool canBeFather(Genotype suspect, char requiredAllele) {
    if (requiredAllele == suspect.a1 || requiredAllele == suspect.a2)
        return true;
    return false;
}

int main() {
    Genotype mother, child;

    cout << "Enter mother's genotype: " << "\n";
    cin >> mother;

    cout << "Enter child's genotype: " << "\n";
    cin >> child;

    vector<Genotype> suspects;
    int n;

    cout << "Enter the number of suspects: " << "\n";
    cin >> n;

    cout << "Enter the suspects' genotypes: " << "\n";

    for (int i = 0; i < n; i++) {
        Genotype suspect;
        cin >> suspect;
        suspects.push_back(suspect);
    }

    int matchFound = 0;
    for (int i = 0; i < n; i++) {
        if (canBeFather(suspects[i], mandatoryFatherAllele(mother, child))) {
            cout << "Suspect " << i + 1 << ": " << suspects[i] << "\n";
            matchFound = 1;
        }
    }

    if (matchFound == 0)
        cout << "NO MATCHING SUSPECTS FOUND";

    return 0;
}