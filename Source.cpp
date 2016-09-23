#include "Grafo.h"

using namespace std;

int main() {
	cout << "Tarea Grafos" << endl;
	Grafo Mi_Grafo_ND(true);
	Mi_Grafo_ND.Anadir_Elemento("A");
	Mi_Grafo_ND.Anadir_Elemento("B");
	Mi_Grafo_ND.Anadir_Elemento("C");
	Mi_Grafo_ND.Anadir_Elemento("D");
	Mi_Grafo_ND.Imprimir_Adyacencia();
	Mi_Grafo_ND.Anadir_Adyacencia("A", "B");
	cout << endl;
	Mi_Grafo_ND.Imprimir_Adyacencia();
	Mi_Grafo_ND.Imprimir_Pesos();
	Mi_Grafo_ND.Anadir_Peso("A", "B", 5);
	Mi_Grafo_ND.Anadir_Peso("A", "D", 10);
	Mi_Grafo_ND.Anadir_Peso("B", "C", 3);
	Mi_Grafo_ND.Anadir_Peso("C", "D", 1);
	Mi_Grafo_ND.Imprimir_Pesos();
	Mi_Grafo_ND.Camino_Minimo("A","B");
	int j;
	cin >> j;
}