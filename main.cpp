#include <iostream>
#include "lista.h"
#include <stdio.h>
#include "nodo.h"
#include <stdlib.h>
#include "paquete.h"
//alfredo amezcua martinez

using namespace std;



int main() {
	lista *productos=new lista;
	
	int opc;

	int id;
	float peso;
	string nombre;
	string destino;
	string origen;

    producto prod;
	do//menu
	{
		cout <<"	\npaqueteria" <<endl;
		cout<<"1.Insertar " <<endl;
		cout<<"2.Mostrar todo" <<endl;
		cout<<"3.Eliminar" <<endl;
		cout<<"4.Guardar archivo" <<endl;
		cout<<"5.Cargar archivo " <<endl;
		cout<<"6.Salir" <<endl;
		cout<<"SELECCIONA UNA OPCION: ";
		cin >>opc;
		cin.ignore();
		
		switch (opc)
		{
			case 1:
				cout<<"Ha elegido insertar al inicio"<<endl;
				
				cout<<"Ingrese el nombre del producto"<<endl;
				getline(cin, nombre);
				prod.setNombre(nombre);

				cout<<"Ingrese el origen del producto"<<endl;
				getline(cin, origen);
				prod.setOrigen(origen);

				cout<<"Ingrese el destino del producto"<<endl;
				getline(cin, destino);
				prod.setDestino(destino);
				
				cout<<"Peso: "<<endl;
				cin>>peso;
				prod.setPeso(peso);
				
				cout<<"Id: "<<endl;
				cin>>id;
				prod.setId(id);
				
				productos->insertaInicio(prod);
				break;
		
			case 2:
				productos->mostrarTodo();//
				cout<<"\n"<<endl;
				break;
		
			case 3:
				cout<<"Ha elegido eliminar"<<endl;
				cout<<"Ingrese el id del paquete a eliminar"<<endl;
				getline(cin,nombre);
				productos->eliminar(nombre);
				cout<<"\n"<<endl;
				break;
			
		
			case 4:
			{

			/*
				[TAM_NOMBRE]["NOMBRE"][PRECIO][ID]...
			*/
				cout<<"Elija el nombre del archivo:"<<endl;
				string nombreArchivo;
				cin >> nombreArchivo;

				// Abrir archivo con el nombre elegido,
				// Si no existe lo crea
				// Si ya existe lo sobreescribe
				// Modo binario
				FILE* archivo = fopen(nombreArchivo.data(), "wb+");

				unsigned char size = productos->size();
				fwrite(&size, 1, 1, archivo);

				// recorrer nuestra lista desde el inicio
				nodo* aux = productos->h;
				while (aux)
				{
					unsigned char longitud;

					// id
					int id = aux->dato.getId();
					fwrite(&id, sizeof(int), 1, archivo);

					// peso
					float peso = aux->dato.getPeso();
					fwrite(&peso, sizeof(float), 1, archivo);

					// nombre
					longitud = aux->dato.getNombre().length();
					fwrite(&longitud, 1, 1, archivo);
					fwrite(aux->dato.getNombre().data(), 1, longitud, archivo);

					// origen
					longitud = aux->dato.getOrigen().length();
					fwrite(&longitud, 1, 1, archivo);
					fwrite(aux->dato.getOrigen().data(), 1, longitud, archivo);

					// destino
					longitud = aux->dato.getDestino().length();
					fwrite(&longitud, 1, 1, archivo);
					fwrite(aux->dato.getDestino().data(), 1, longitud, archivo);

					// continuar con el siguiente producto
					aux = aux->sig;
				}

				fclose(archivo);
				break;
			}

				


			case 5:
			{
				cout<<"Elija el nombre del archivo:"<<endl;
				string nombreArchivo;
				cin >> nombreArchivo;

				// Abrir archivo solo como lectura
				// Si existe lo abre desde el incio
				// Si no existe falla
				// Abrir en binario
				FILE* archivo = fopen(nombreArchivo.data(), "rb");

				// Vaciar lista
				productos->vaciar();

				// leer registros totales
				unsigned char size;
				fread(&size, 1, 1, archivo);

				// Mientras el archivo no haya terminado
				while (size > 0)
				{
					unsigned char longitud;

					// ID
					int id;
					fread(&id, sizeof(int), 1, archivo);

					// peso
					float peso;
					fread(&peso, sizeof(float), 1, archivo);

					// nombre
					fread(&longitud, sizeof(char), 1, archivo);
					string nombre(255, 0);
					fread(nombre.data(), sizeof(char), longitud, archivo);

					// origen
					fread(&longitud, sizeof(char), 1, archivo);
					string origen(255, 0);
					fread(origen.data(), sizeof(char), longitud, archivo);

					// destino
					fread(&longitud, sizeof(char), 1, archivo);
					string destino(255, 0);
					fread(destino.data(), sizeof(char), longitud, archivo);

					// agregarlo a la lista
					producto p(id, peso, nombre, origen, destino);
					productos->insertaInicio(p);
					size--;
				}

				fclose(archivo);
				break;
			}

			case 6:
			
				cout <<"Nos vemos pronto" <<endl <<endl;
				cout<<"\n"<<endl;
				break;



			default:
				cout <<"Opcion no válida" <<endl <<endl;
				cout<<"\n"<<endl;
		}
	}while(opc != 6);
	return 0;
}