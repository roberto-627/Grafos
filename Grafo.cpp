#include "Grafo.h"
#include <stack>

const int Elementos = 10;
const int INF = 999999;

using namespace std;

Grafo::Grafo()
{
}

Grafo::Grafo(bool Dirigido) {
	Grafo_Dirigido = Dirigido;
	Predefinir_Adyacencia();
	Predefinir_Pesos();
}

//Funciones.
//Funciones para construir el Grafo.
void Grafo::Anadir_Elemento(std::string ID_Elemento) {
	for (int p = 0; p < 10; p++) {
		if (Elementos_Grafo[p] == "") {
			Elementos_Grafo[p] = ID_Elemento;
			return;
		}
	}
}

int Grafo::Convertir_Elemento(std::string ID_Elemento) {
	for (int p = 0; p < 10; p++) {
		if (Elementos_Grafo[p] == ID_Elemento) {
			return p;
		}
	}
}

void Grafo::Predefinir_Adyacencia() {
	for (int f = 0; f < 10; f++) {
		for (int c = 0; c < 10; c++) {
			Matriz_Adyacencia[f][c] = false;
		}
	}
}

void Grafo::Predefinir_Pesos() {
	for (int p = 0; p < 10; p++) {
		Matriz_Pesos[p][p] = 0;
	}
	for (int f = 0; f < 10; f++) {
		for (int c = 0; c < 10; c++) {
			if (Matriz_Pesos[f][c] != 0) {
				Matriz_Pesos[f][c] = 999999;
			}
		}
	}
}

void Grafo::Anadir_Adyacencia(std::string ID_Uno, std::string ID_Dos) {
	if (Grafo_Dirigido) {
		Matriz_Adyacencia[Convertir_Elemento(ID_Uno)][Convertir_Elemento(ID_Dos)] = true;
	}
	else {
		Matriz_Adyacencia[Convertir_Elemento(ID_Uno)][Convertir_Elemento(ID_Dos)] = true;
		Matriz_Adyacencia[Convertir_Elemento(ID_Dos)][Convertir_Elemento(ID_Uno)] = true;
	}
}

void Grafo::Anadir_Peso(std::string ID_Uno, std::string ID_Dos, int Peso_Arista){
	Matriz_Pesos[Convertir_Elemento(ID_Uno)][Convertir_Elemento(ID_Dos)] = Peso_Arista;
}

void Grafo::Eliminar_Adyacencia(std::string ID_Uno, std::string ID_Dos){
	if (Grafo_Dirigido) {
		Matriz_Adyacencia[Convertir_Elemento(ID_Uno)][Convertir_Elemento(ID_Dos)] = false;
	}
	else {
		Matriz_Adyacencia[Convertir_Elemento(ID_Uno)][Convertir_Elemento(ID_Dos)] = false;
		Matriz_Adyacencia[Convertir_Elemento(ID_Dos)][Convertir_Elemento(ID_Uno)] = false;
	}
}

bool Grafo::Conexo() {
	int Conexiones = 0;
	for (int f = 0; f < 10; f++) {
		for (int c = 0; c < 10; c++) {
			if (Matriz_Adyacencia[f][c]) {
				Conexiones++;
			}
		}
		if (Conexiones >= 1) {
			Conexiones = 0;
		}
		else {
			return false;
		}
	}
	return true; 
}

bool Grafo::Completo() {
	for (int f = 0; f < 10; f++) {
		for (int c = 0; c < 10; c++) {
			if (Matriz_Adyacencia[f][c]) {
				//Continuar...
			}
			else {
				return false;
			}
		}
	}
	return true; 
}

//Algoritmos.
void Imprimir_Floyd(int dist[][Elementos])
{
	printf("Following matrix shows the shortest distances between every pair of vertices \n");
	for (int i = 0; i < Elementos; i++)
	{
		for (int j = 0; j < Elementos; j++)
		{
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

bool Grafo::Floyd() {
	//Declarar la Matriz de Distancias.
	int Distancias[Elementos][Elementos];

	//Inicializar la matriz de distancias.
	for (int i = 0; i < Elementos; i++) {
		for (int j = 0; j < Elementos; j++) {
			Distancias[i][j] = Matriz_Pesos[i][j];
		}
	}

	//Pivote o referencia.
	for (int k = 0; k < Elementos; k++)
	{
		//Origen.
		for (int i = 0; i < Elementos; i++)
		{
			//Destino.
			for (int j = 0; j < Elementos; j++)
			{
				//Si el camino que pasa por el pivote es el mas corto lo actualiza.
				if (Distancias[i][k] + Distancias[k][j] < Distancias[i][j])
					Distancias[i][j] = Distancias[i][k] + Distancias[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	Imprimir_Floyd(Distancias);
}

void Imprimir_Warshall(int dist[][Elementos])
{
	printf("Following matrix shows the shortest distances between every pair of vertices \n");
	for (int i = 0; i < Elementos; i++)
	{
		for (int j = 0; j < Elementos; j++)
		{
			if (dist[i][j] == INF)
				printf("%7s", "F");
			else
				printf("%7d", "T");
		}
		printf("\n");
	}
}

void Grafo::Warshall() {
	//Declarar la Matriz de Distancias.
	int Distancias[Elementos][Elementos];

	//Inicializar la matriz de distancias.
	for (int i = 0; i < Elementos; i++) {
		for (int j = 0; j < Elementos; j++) {
			Distancias[i][j] = Matriz_Pesos[i][j];
		}
	}

	//Pivote o referencia.
	for (int k = 0; k < Elementos; k++)
	{
		//Origen.
		for (int i = 0; i < Elementos; i++)
		{
			//Destino.
			for (int j = 0; j < Elementos; j++)
			{
				//Si el camino que pasa por el pivote es el mas corto lo actualiza.
				if (Distancias[i][k] + Distancias[k][j] < Distancias[i][j])
					Distancias[i][j] = Distancias[i][k] + Distancias[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	Imprimir_Warshall(Distancias);
}

//Funcion auxiliar de Dijkstra.
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INF;
	int min_index;

	for (int v = 0; v < Elementos; v++) {
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
	}

	return min_index;
}

// A utility function to print the constructed distance array
int Imprimir_Dijkstra(int dist[], int n)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < Elementos; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void Grafo::Dijkstra(std::string Origen) {
	//Almacena las distancias de origen a el resto.
	int Distancias[Elementos];

	//Matriz de visitados.
	bool Visitados[Elementos];

	//Inicializar Distancias en INF y visitados en false.
	for (int i = 0; i < Elementos; i++) {
		Distancias[i] = INF;
		Visitados[i] = false;
	}

	// Distance of source vertex from itself is always 0
	Distancias[Convertir_Elemento(Origen)] = 0;

	//Encontrar las distancias de origen a el resto de vertices.
	for (int count = 0; count < Elementos - 1; count++)
	{
		//mindistance devuelve el vertice mas cercano sin visitar.
		int u = minDistance(Distancias, Visitados);

		// Mark the picked vertex as processed
		Visitados[u] = true;

		//Actualizar las distancias desde el origen hacia el resto.
		for (int v = 0; v < Elementos; v++)
			if (!Visitados[v] && Matriz_Pesos[u][v] && Distancias[u] != INF && Distancias[u] + Matriz_Pesos[u][v] < Distancias[v]) {
				Distancias[v] = Distancias[u] + Matriz_Pesos[u][v];
			}
	}

	// print the constructed distance array
	Imprimir_Dijkstra(Distancias, Elementos);
}

int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INF;
	int min_index;

	for (int v = 0; v < Elementos; v++) {
		if (mstSet[v] == false && key[v] < min) {
			min = key[v]; 
			min_index = v;
		}
	}

	return min_index;
}

// A utility function to print the constructed MST stored in parent[]
int Imprimir_Prim(int parent[], int n, int graph[Elementos][Elementos])
{
	printf("Edge   Weight\n");
	for (int i = 1; i < Elementos; i++) {
		printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
	}
}

void Grafo::Prim() {
	int parent[Elementos]; //Arreglo que almacena el subgrafo mas corto.
	int key[Elementos];   //Arregloq eu almacena valores de referencia.
	bool colocados[Elementos];  //Arreglo que valida si el vertice ya esta incluido en el subgrafo.

	//Inicializar las keys como INF y los colocados como false.
	for (int i = 0; i < Elementos; i++) {
		key[i] = INF;
		colocados[i] = false;
	}

	//Incluir el primero siempre.
	key[0] = 0;

	//El primer nodo siempre va a ser raiz.
	parent[0] = -1;

	//El subgrafo debe contener todos los nodos.
	for (int count = 0; count < Elementos - 1; count++)
	{
		//Igual que dijkstra buscar el vertice no colocado mas cercano.
		int u = minKey(key, colocados);

		//Setear el seleccionado como colocado.
		colocados[u] = true;

		//Actualizar los el subgrafo considerando solo los no colocados.
		for (int v = 0; v < Elementos; v++){

			// graph[u][v] is non zero only for adjacent vertices of m
			// colocados[v] is false for vertices not yet included in MST
			// Update the key only if graph[u][v] is smaller than key[v]
			if (Matriz_Adyacencia[u][v] && colocados[v] == false && Matriz_Pesos[u][v] < key[v]) {}\
				parent[v] = u;
				key[v] = Matriz_Pesos[u][v];
			}
		}

		// print the constructed MST
		Imprimir_Prim(parent, Elementos, Matriz_Pesos);
}

void Grafo::Kruskal() {
	int min = INF;
	int sum = 0;
	int ne = 0; //Contador de registrados
	int u, v, a, b; //Referencias.

	int w[Elementos][Elementos]; //Matriz para trabajar con pesos.
	//Inicializar.
	int Vertices = 0;
	for (int f = 0; f < Elementos; f++) {
		for (int c = 0; c < Elementos; c++) {
			w[f][c] = Matriz_Pesos[f][c];
		}
	}

	//
	int p[Elementos];

	//Extraer cantidad de vertices.
	int Vertices = 0;
	for (int f = 0; f < Elementos; f++) {
		for (int c = 0; c < Elementos; c++) {
			if (Matriz_Adyacencia[f][c]) {
				Vertices++;
			}
		}
	}

	//Inicializar Matriz.
	for (int i = 1; i <= Vertices; i++) {
		p[i] = 0;
	}

	//Extraer los vertices a menor distancia y ordenarlos.
	while (ne < Vertices - 1)
	{
		min = 999;
		for (int i = 1; i <= Vertices; i++)
			for (int j = 1; j <= Vertices; j++)
			{
				if (w[i][j] < min)
				{
					min = w[i][j];
					u = a = i;
					v = b = j;
				}
			}
		while (p[u]) 
			u = p[u];
		while (p[v])
			v = p[v];
		if (u != v)
		{
			ne++;
			sum += min;
			cout << "\nedge " << a << "-->" << b << " is " << min;
			p[v] = u;
		}
		w[a][b] = w[b][a] = 999;
	}
	cout << "\nmin cost spanning tree= " << sum;
}

//Funciones para Debug.
void Grafo::Imprimir_Elementos(){
	for (int p = 0; p < 10; p++) {
		std::cout << Elementos_Grafo[p] << std::endl;
	}
}

void Grafo::Imprimir_Adyacencia(){
	for (int f = 0; f < 10; f++) {
		for (int c = 0; c < 10; c++) {
			if (Matriz_Adyacencia[f][c]) {
				std::cout << "1" << " ";
			}
			else {
				std::cout << "0" << " ";
			}
		}
		std::cout << "\n";
	}
}

void Grafo::Imprimir_Pesos(){
	std::cout << "Matriz Pesos" << std::endl;
	for (int f = 0; f < 10; f++) {
		for (int c = 0; c < 10; c++){
			if (Matriz_Pesos[f][c] == 999999) {
				std::cout << "INF." << " ";
			}
			else {
				std::cout << Matriz_Pesos[f][c] << " ";
			}
		}
		std::cout << "\n";
	}
}

Grafo::~Grafo()
{
}
