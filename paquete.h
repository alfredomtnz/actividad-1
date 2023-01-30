#ifndef PAQUETE_H
#define PAQUETE_H

#include <iostream>
#include <stdlib.h>
//clases
using namespace std;

class producto
{		
	private:
        int id;
        float peso;
        string nombre;
		string origen;
		string destino;

    public:
        producto();
        producto(int id, float peso, string nombre, string origen, string destino);
        ~producto();

        int getId(void);
        void setId(int);

        float getPeso(void);
        void setPeso(float);

        string getNombre(void);
        void setNombre(string);

        string getDestino(void);
        void setDestino(string);

        string getOrigen(void);
        void setOrigen(string);
};
#endif

