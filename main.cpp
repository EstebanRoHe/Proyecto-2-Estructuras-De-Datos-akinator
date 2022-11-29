#include<iostream>
using namespace std;
#include "Arbol.h"
/*
Integrantes:
Sebastian Brenes Murillo
Esteban Rojas Herrera
Oscar Zamora Ramirez
*/
bool Respuesta();
int main (int argc, char *argv[]) {
	Arbol *Dato = new Arbol("Akinator.txt");
	
	Nodo *P , *Anterior;
	bool Resp, RespuestaAnterior;
	string RespuestaF, PreguntaF;
	
	do{
		cout<<"----------Akinator----------"<<endl;
		cout<<"Adivinare al famositico en el que piensas. \n";
		P = Dato->getRaiz();
		Anterior = NULL;
		bool flag;
		do{
			flag=false;
			cout<<"Es "<<P->getDato()<<"? \n";
			Resp=Respuesta();
			if(Resp)
			{
				if(P->getSi() == NULL){
					flag = true;
				}else{
					P=P->getSi();
				}
				
			}else{
				if(P->getNo() == NULL){
					flag = true;
					Anterior=P;
					RespuestaAnterior=Resp;
				}else{
					P=P->getNo();
					
				}
				
			}
			
		
		}while(!flag);		
		
		
		if(Resp){
			cout<<"YO GANE!!!\n";
		}else{
			cout<<"No conozco este famoso, pero si me das una pregunta lo incluire en mi juego.\n";
		
		do{
			cout<<"De que famoso se trata?\n";
			cin.get();
		    getline(cin,RespuestaF);
			cout<<"Dame una pregunta para saber que famoso es.\n";
			getline(cin,PreguntaF);
			cout<<"Que respuesta se ha de dar a esta pregunta: "<<PreguntaF<<"\n";
			cout<<"Para obtener al famoso: "<<RespuestaF<<"\n";

			cout<<"con la respuesta: Si o No:\n";
			Resp = Respuesta();	
				
		
				cout<<"Veamos si lo he entendido bien:\n";
				cout<<"A la pregunta: "<<PreguntaF<<"\n";
				if(Resp)
				{
					cout<<"Si se responde que si se trata de "<<RespuestaF<<"\n";
					
				}
				else
				{
					
					cout<<"Si se responde que no se trata de "<< RespuestaF<<"\n";
				}
				cout<<"Es correcto? \n";
			
		} while(!Respuesta());
		
		Dato->InsertarNodo(Anterior,RespuestaAnterior,PreguntaF,Resp,RespuestaF);
		
		}
		cout<<"Deseas seguir jugando? \n";
	} while(Respuesta());
	
	ofstream File;	
	File.open(Dato->getNombre(), ios::out);
	
	Dato->guardarDatos(File, Dato->getRaiz(), "0");	
	File.close();			
	
	return 0;
}
bool Respuesta()
{
	string Respuesta;  
	
	cin>>Respuesta;
	return Respuesta == "Si" || Respuesta == "si" || Respuesta == "SI" || Respuesta == "sI"; 

}

