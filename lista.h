#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
#include <iostream>
using namespace std;

class lista
{
	public:
		lista();
		~lista();
		
		nodo *h;
		nodo *t;
		
		//lista de operaciones
		
		void inicializa(void);
		void insertaInicio(producto);
		void mostrarTodo();
		bool vacia();
		void eliminar(string);
		nodo* anterior(producto);
		nodo* siguiente(producto);
		void vaciar();
		int size();
};

#endif