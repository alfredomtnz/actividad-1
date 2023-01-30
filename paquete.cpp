#include "paquete.h"

producto::producto()
{
}

producto::producto(int id, float peso, string nombre, string origen, string destino)
{
	this->id = id;
	this->peso = peso;
	this->nombre = nombre;
	this->origen = origen;
	this->destino = destino;
}

producto::~producto()
{
}

int producto::getId(void){return id;}
void producto::setId(int id){this->id = id;}

float producto::getPeso(void){return peso;}
void producto::setPeso(float peso){this->peso = peso;}

string producto::getNombre(void){return nombre;}
void producto::setNombre(string nombre){this->nombre = nombre;}

string producto::getDestino(void){return destino;}
void producto::setDestino(string destino){this->destino = destino;}

string producto::getOrigen(void){return origen;}
void producto::setOrigen(string origen){this->origen = origen;}
