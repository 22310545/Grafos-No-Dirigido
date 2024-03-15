#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class GrafoNDirigido {
private:
    unordered_map<int, vector<int>> listaAdyacencia;

public:
    GrafoNDirigido() {}

    void agregarNodo(int nodo) {
        if (listaAdyacencia.find(nodo) == listaAdyacencia.end()) {
            listaAdyacencia[nodo] = vector<int>();
        }
    }

    void agregarArista(int nodoOrigen, int nodoDestino) {
        agregarNodo(nodoOrigen);
        agregarNodo(nodoDestino);
        listaAdyacencia[nodoOrigen].push_back(nodoDestino);
        listaAdyacencia[nodoDestino].push_back(nodoOrigen);
    }

    void imprimirMatrizAdyacencia() {
        int numNodos = listaAdyacencia.size();
        vector<vector<int>> matrizAdyacencia(numNodos, vector<int>(numNodos, 0));

        for (auto it = listaAdyacencia.begin(); it != listaAdyacencia.end(); ++it) {
            int nodoOrigen = it->first;
            for (int i = 0; i < it->second.size(); ++i) {
                int nodoDestino = it->second[i];
                matrizAdyacencia[nodoOrigen - 1][nodoDestino - 1] = 1;
                matrizAdyacencia[nodoDestino - 1][nodoOrigen - 1] = 1; // como es no dirigido, también agregamos la arista en sentido inverso
            }
        }

        cout << "Matriz de adyacencia:" << endl;
        for (int i = 0; i < numNodos; i++) {
            for (int j = 0; j < numNodos; j++) {
                cout << matrizAdyacencia[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    GrafoNDirigido grafo;

    cout << "Grafo 1:" << endl;
    grafo.agregarArista(1, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(2, 4);
    grafo.agregarArista(3, 4);
    grafo.imprimirMatrizAdyacencia();

    cout << endl << "Grafo 2:" << endl;
    GrafoNDirigido grafo2;
    grafo2.agregarArista(1, 3);
    grafo2.agregarArista(3, 2);
    grafo2.imprimirMatrizAdyacencia();

    cout << endl << "Grafo 3:" << endl;
    GrafoNDirigido grafo3;
    grafo3.agregarArista(1, 3);
    grafo3.agregarArista(2, 3);
    grafo3.agregarArista(3, 4);
    grafo3.imprimirMatrizAdyacencia();

    cout << endl << "Grafo 4:" << endl;
    GrafoNDirigido grafo4;
    grafo4.agregarArista(1, 2);
    grafo4.agregarArista(1, 3);
    grafo4.agregarArista(2, 2);
    grafo4.imprimirMatrizAdyacencia();

    cout << endl << "Grafo 5:" << endl;
    GrafoNDirigido grafo5;
    grafo5.agregarArista(1, 1);
    grafo5.agregarArista(2, 2);
    grafo5.agregarArista(3, 3);
    grafo5.imprimirMatrizAdyacencia();

    return 0;
}