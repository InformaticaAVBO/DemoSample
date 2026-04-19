#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int segreto = rand() % 100 + 1;
    int tentativi = 0;
    int guess;

    cout << "🎯 Indovina il numero tra 1 e 100!" << endl;

    do {
        cout << "Il tuo numero: ";
        cin >> guess;
        tentativi++;

        if (guess < segreto)
            cout << "📈 Troppo basso!" << endl;
        else if (guess > segreto)
            cout << "📉 Troppo alto!" << endl;
        else
            cout << "🎉 Bravo! Trovato in " << tentativi << " tentativi!" << endl;

    } while (guess != segreto);

    return 0;
}
