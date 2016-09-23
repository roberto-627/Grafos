#include <string>
#include <iostream>
#pragma once

class Grafo
{
public:
	//Constructor.
	Grafo();
	Grafo(bool Dirigido);

	//Atributos.
	bool Grafo_Dirigido;
	std::string Elementos_Grafo[10];
	bool Matriz_Adyacencia[10][10];
	int Matriz_Pesos[10][10];
	
	//Funciones.
	//Funciones para construir el Grafo.
	void Grafo::Anadir_Elemento(std::string ID_Elemento);
	int Grafo::Convertir_Elemento(std::string ID_Elemento);
	void Grafo::Predefinir_Adyacencia();
	void Grafo::Predefinir_Pesos();
	void Grafo::Anadir_Adyacencia(std::string ID_Uno, std::string ID_Dos);
	void Grafo::Anadir_Peso(std::string ID_Uno, std::string ID_Dos,int Peso_Arista);
	void Grafo::Eliminar_Adyacencia(std::string ID_Uno, std::string ID_Dos);
	bool Grafo::Conexo();
	bool Grafo::Completo();

	//Algoritmos.
	bool Grafo::Floyd();
	void Grafo::Warshall();
	void Grafo::Dijkstra(std::string Origen);
	void Grafo::Prim();
	void Grafo::Kruskal();

	//Funciones para Debug.
	void Grafo::Imprimir_Elementos();
	void Grafo::Imprimir_Adyacencia();
	void Grafo::Imprimir_Pesos();

	//Destructor.
	~Grafo();
};

