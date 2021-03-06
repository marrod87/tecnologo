#ifndef DATAUSUARIO_H
#define DATAUSUARIO_H
#include <iostream>
#include <string>
#include "DateTime.h"

using namespace std;

class DataUsuario{
	private:
		string nickname;
		string nombre;
		string sexo;
		int edad;
		DateTime fechaNac;

	public:
		// Constructores	   
	   	DataUsuario(); //por defecto
		DataUsuario(string, string, string, int, DateTime); // por parametro
		DataUsuario(const DataUsuario&); // por copia
		
		// Destructor
		~DataUsuario();
		 
		// Selectores
		string getNickname() const;
		string getNombre() const;
		string getSexo() const;
		int getEdad() const;
		DateTime getFechaNac() const;
		
		// Modificadores
		void setNickname(string);
		void setNombre(string); 		
		void setSexo(string);
		void setEdad(int);
		void setFechaNac(DateTime);		
};
	std::ostream& operator<< (std::ostream& stream, const DataUsuario&);
	std::istream& operator>> (std::istream& stream,  DataUsuario&);
#endif
