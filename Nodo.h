#ifndef NODO_H
#define NODO_H
#include<iostream>
using namespace std;

class Nodo {
public:
	Nodo(string dato);
	Nodo(string dato,Nodo *Si, Nodo *No);
	void setDato(string dato);
	string getDato();
	void setSi(Nodo *Si);
	Nodo *getSi();
	void setNo(Nodo * No);
    Nodo * getNo();	
	~Nodo();
private:
	Nodo *Si;
	Nodo *No;
	string dato;
	
};

#endif






