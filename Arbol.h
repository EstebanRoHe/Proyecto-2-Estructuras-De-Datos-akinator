#ifndef ARBOL_H
#define ARBOL_H
#include<iostream>
#include "Nodo.h"
#include <fstream>
using namespace std;

class Arbol {
public:
	Arbol() : Raiz() {};
	Arbol(string Nombre);
	~Arbol();
	string getNombre();
    void setRaiz(Nodo * Raiz);
	Nodo * getRaiz();
	void InsertarNodo(Nodo * , bool , string , bool, string);
	void guardarDatos(ofstream& File, Nodo *aux, string n);
	Nodo* cargarDatos(ifstream& File);
	
private:
	Nodo *Aux;
	string Nombre;
	int n;
	Nodo *Raiz;
};

#endif
