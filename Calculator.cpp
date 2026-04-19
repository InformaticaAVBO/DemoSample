#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;

    cout << "Inserisci: numero operatore numero (es: 5 + 3)" << endl;
    cin >> a >> op >> b;

    switch (op) {
        case '+': cout << "Risultato: " << a + b << endl; break;
        case '-': cout << "Risultato: " << a - b << endl; break;
        case '*': cout << "Risultato: " << a * b << endl; break;
        case '/':
            if (b != 0) cout << "Risultato: " << a / b << endl;
            else cout << "❌ Divisione per zero!" << endl;
            break;
        default: cout << "Operatore non valido" << endl;
    }

    return 0;
}
