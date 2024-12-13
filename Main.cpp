#include <iostream>
using namespace std;

template <typename T>
class AlberoBinario {
private:
    T nodi[100];
    bool occupato[100] = {false};

public:
    AlberoBinario() {}

    bool alberoVuoto() const {
        return !occupato[0];
    }

    void insRadice(const T& valore) {
        if (!occupato[0]) {
            nodi[0] = valore;
            occupato[0] = true;
        } else {
            cout << "La radice esiste già!" << endl;
        }
    }

    void insFiglioSinistro(int indice, const T& valore) {
        int fs = 2 * indice + 1;
        if (occupato[indice] && !occupato[fs]) {
            nodi[fs] = valore;
            occupato[fs] = true;
        }
    }

    void insFiglioDestro(int indice, const T& valore) {
        int fd = 2 * indice + 2;
        if (occupato[indice] && !occupato[fd]) {
            nodi[fd] = valore;
            occupato[fd] = true;
        }
    }

    void rimuovi(int indice) {
        if (occupato[indice] && !occupato[2 * indice + 1] && !occupato[2 * indice + 2]) {
            occupato[indice] = false;
        }
    }

    void stampa() const {
        for (int i = 0; i < 100; ++i) {
            if (occupato[i]) {
                cout << "Posizione " << i << ", Valore: " << nodi[i] << endl;
            }
        }
    }
};

int main() {
    AlberoBinario<int> albero;

    albero.insRadice(20);

    albero.insFiglioSinistro(0, 10);
    albero.insFiglioDestro(0, 30);
    albero.insFiglioSinistro(1, 5);
    albero.insFiglioDestro(1, 15);

    albero.stampa();

    albero.rimuovi(4);

    cout << "Dopo la rimozione:" << endl;
    albero.stampa();

    return 0;
}
