#include <iostream>
#include <vector>
#include "stdlib.h"
#include "roman.h"
#include "francez.h"
#include "german.h"

using namespace std;

void Meniu() {
    system("cls");
    cout << "Alegeti optiunea dorita:\n";
    cout << "1. Adaugare participant\n";
    cout << "2. Afisare sumar\n";
    cout << "0. Iesire\n";
}

Participant* CreeazaParticipant() {
    system("cls");
    cout << "Alegeti nationalitatea:\n";
    cout << "1. Roman\n";
    cout << "2. Francez\n";
    cout << "3. German\n";
    cout << "4. Alta\n";
    unsigned short opt;
    cin >> opt;
    switch (opt) {
        case 1: {Participant* ro = new Roman(); return ro; break;}
        case 2: {Participant* fr = new Francez(); return fr; break;}
        case 3: {Participant* de = new German(); return de; break;}
        case 4: {Participant* alta = new Participant(); return alta; break;}
        }
}

int main()
{  
    vector<Participant*> pntParticipanti;
    unsigned short opt = 1;
    while (opt != 0) {
        Meniu();
        cin >> opt;
        while (opt > 2) {
            cout << "Optiune gresita\n";
            cin >> opt;
        }
        unsigned short ro = 0, fr = 0, de = 0, alta = 0;
        if(opt == 1)
            pntParticipanti.push_back(CreeazaParticipant());
            else if (opt == 2) {
                system("cls");
                for(unsigned short i = 0; i < pntParticipanti.size(); ++i) {
                    switch (pntParticipanti[i]->Vorbeste()) {
                    case 0: ++alta; break;
                    case 1: ++ro; break;
                    case 2: ++de; break;
                    case 3: ++fr; break;
                    }
                }
                if(ro > 0 || fr > 0 || de > 0 || alta > 0) {
                    cout << "Participanti inscrisi pana acum:\n";
                    cout << ro  << " Romani\n";
                    cout << fr << " Francezi\n";
                    cout << de << " Germani\n";
                    cout << alta << " Altii\n";
                    system("pause");
                }
            }
        }
    pntParticipanti.clear();
    return 0;
}
