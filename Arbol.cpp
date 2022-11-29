#include "Arbol.h"



Arbol::Arbol(string Nombre) {
	this->Nombre=Nombre; 	
	ifstream File;								
	File.open(Nombre);
	
	if(!File)   {                          
		Raiz = new Nodo("Deportista");	
		Raiz->setSi(new Nodo("Keylor Navas"));	
	}else
	{
		Raiz = cargarDatos(File);             
		File.close();							
	}

}

Arbol::~Arbol() {
	
}

string Arbol::getNombre(){
	return Nombre;
}
void Arbol::setRaiz (Nodo * Raiz) {
	this->Raiz=Raiz;
}

Nodo * Arbol::getRaiz ( ) {
	return Raiz;
}

void Arbol::InsertarNodo(Nodo *Anterior, bool RespuestaAnterior, string PreguntaF, bool Respuesta, string FamosoNuevo){
	Nodo *Nuevo = new Nodo(PreguntaF) ;
	if(Respuesta){
		Nuevo->setSi(new Nodo(FamosoNuevo));
	}else{
		Nuevo->setNo(new Nodo(FamosoNuevo));
	}
	if(RespuestaAnterior){
		Anterior->setSi(Nuevo);
	}else{
		Anterior->setNo(Nuevo);
	}
}

void Arbol::guardarDatos (ofstream& File, Nodo *aux, string n) {
	if(aux->getSi() == NULL && aux->getNo() == NULL ){
		File<<"R"+n+aux->getDato()+"\n";
	}else if(aux->getSi() != NULL && aux->getNo() != NULL){
		File<<"P2"+aux->getDato()+ "\n";
		guardarDatos(File, aux->getSi(), "0");
		guardarDatos(File, aux->getNo(), "1");
	}else if(aux->getSi() == NULL &&  aux->getNo() != NULL){
		File<<"PN"+aux->getDato()+ "\n";
		guardarDatos(File, aux->getNo(), n);
	}else if(aux->getSi() != NULL &&  aux->getNo() == NULL){
		File<<"PS"+aux->getDato()+ "\n";
		guardarDatos(File, aux->getSi(), n);
	}
}

Nodo* Arbol::cargarDatos (ifstream& File) {
	string x;
	Nodo *aux;
	getline(File, x);
	
	aux=new Nodo(&x[2]);
	if(x[0] == 'P' && x[1] =='2'){
		//x.erase(0,1);
		aux->setSi(cargarDatos(File));
		aux->setNo(cargarDatos(File));
	}else if(x[0] == 'P' && x[1] =='S'){
		//x.erase(0,1);
		aux->setSi(cargarDatos(File));
	}else if(x[0] == 'P' && x[1] =='N'){
		//x.erase(0,1);
		aux->setNo(cargarDatos(File));
	}else if(x[0] == 'R' && x[0] == '0' ){
		//x.erase(0,1);
		Raiz->setNo(cargarDatos(File));
	}
	return aux;
}






