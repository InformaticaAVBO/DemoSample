#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int LARGHEZZA = 20;
const int ALTEZZA = 10;

char griglia[ALTEZZA][LARGHEZZA];

void inizializza() {
    for (int y = 0; y < ALTEZZA; y++)
        for (int x = 0; x < LARGHEZZA; x++)
            griglia[y][x] = '.';
}

void disegna(int px, int py, int ex, int ey) {
    system("clear"); // oppure system("cls") su Windows
    inizializza();

    griglia[ey][ex] = '*'; // stella da raccogliere
    griglia[py][px] = '@'; // giocatore

    // Bordo superiore
    for (int i = 0; i < LARGHEZZA + 2; i++) cout << "#";
    cout << endl;

    for (int y = 0; y < ALTEZZA; y++) {
        cout << "#";
        for (int x = 0; x < LARGHEZZA; x++)
            cout << griglia[y][x];
        cout << "#" << endl;
    }

    // Bordo inferiore
    for (int i = 0; i < LARGHEZZA + 2; i++) cout << "#";
    cout << endl;

    cout << "Raggiungi la stella [*]! (w/a/s/d + INVIO)" << endl;
}

int main() {
    srand(time(0));

    int px = LARGHEZZA / 2, py = ALTEZZA / 2;
    int ex = rand() % LARGHEZZA, ey = rand() % ALTEZZA;
    int punteggio = 0;
    char mossa;

    while (true) {
        disegna(px, py, ex, ey);
        cout << "Punteggio: " << punteggio << endl;

        cin >> mossa;

        if (mossa == 'w' && py > 0) py--;
        if (mossa == 's' && py < ALTEZZA - 1) py++;
        if (mossa == 'a' && px > 0) px--;
        if (mossa == 'd' && px < LARGHEZZA - 1) px++;
        if (mossa == 'q') break;

        if (px == ex && py == ey) {
            punteggio++;
            ex = rand() % LARGHEZZA;
            ey = rand() % ALTEZZA;
            cout << "🎉 Presa! Nuova stella..." << endl;
        }
    }

    cout << "Punteggio finale: " << punteggio << endl;
    return 0;
}
