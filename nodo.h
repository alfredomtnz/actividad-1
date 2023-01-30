#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "paquete.h"


using namespace std;

class nodo
{
	public:
		nodo();
		~nodo();
		producto dato;
		nodo *sig;
		nodo *ant;
		void eliminar_todo();
	protected:
};

#endif
