#include "Nodo.h"

Nodo::Nodo(string dato)
{
	this->dato=dato;
	this->Si=NULL;
	this->No=NULL;
}
Nodo::Nodo(string dato,Nodo *Si, Nodo * No) {
	this->dato=dato;
	this->Si=Si;
	this->No=No;
}

Nodo::~Nodo() {
	
}
void Nodo::setSi (Nodo * Si) {
	this->Si=Si;
}

Nodo * Nodo::getSi ( ) {
	return Si;
}

void Nodo::setNo (Nodo * No) {
	this->No=No;
}

Nodo * Nodo::getNo ( ) {
	return No;
}
void Nodo::setDato (string dato) {
	this->dato=dato;
}

string Nodo::getDato ( ) {
	return dato;
}

