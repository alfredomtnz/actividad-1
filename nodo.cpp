#include "nodo.h"
#include "paquete.h"

nodo::nodo()
{
	sig=NULL;
	ant=NULL;
}

nodo::~nodo()
{
}

void nodo::eliminar_todo()
{
	if(sig and ant)
	sig->eliminar_todo();
	delete this;
}