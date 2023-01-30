#include "lista.h"
#include <iostream>
#include <stdlib.h>

lista::lista()
{
	inicializa();
}

lista::~lista()
{
}

bool lista::vacia()
{
	if(h==NULL and t== NULL)
	return true;
	else
	return false;
}

void lista::inicializa(void)
{
	h=NULL;
	t=NULL;
}

void lista::insertaInicio(producto x)
{
	nodo *tmp=new nodo();
	tmp->dato=x;
	
	if(vacia())
	{
		h=tmp;
		t=tmp;
	}
	else
	{
		tmp->sig=h;
		h->ant=tmp;
		h=tmp;
	}
}


void lista::mostrarTodo()
{
	nodo *aux=h;
	
	if(aux)
	{
		while(aux)
		{
		cout << " ================================ " << endl;
		cout << " |Nombre: *" << aux->dato.getNombre() << endl;
        cout << " |Id:     #" << aux->dato.getId() << endl;
        cout << " |Origen: ->" << aux->dato.getOrigen() << endl;
        cout << " |Destino: <-" << aux->dato.getDestino() << endl;
        cout << " |Peso: " << aux->dato.getPeso() << endl;
        cout << " ================================ " << endl;
			aux=aux->sig;
		}
	}
	else
		cout<<"Lista vacia"<<endl;
}

void lista::eliminar(string nombre)
{	
  	nodo *aux=h;
	nodo *auxR=NULL;
	bool band=true;
	if(aux)
	{
	while(aux and band)
	{
		if(aux->dato.getNombre()!=nombre)
		{
			auxR=aux;
			aux=aux->sig;
		}
		else
		band=false;
	}
	if(aux==NULL)
	{
		cout<<"Dato no encontrado"<<endl;
	}
	else if(aux==h)
	{
		h=h->sig;
		delete aux;
	}
	else
	{
		auxR->sig=aux->sig;
		delete aux;}
	}
	else
	cout<<"Lista vacia"<<endl;

}

void lista::vaciar()
{
	h=NULL;
	t=NULL;
}
 


int lista::size()
{
    int i = 0;
    nodo* p = h;
	
    while(p)
	{
        i++;
        p = p->sig;
    }
    return i;
}



