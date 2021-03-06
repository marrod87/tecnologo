#ifndef IUSUARIOCONTROLADOR_H
#define IUSUARIOCONTROLADOR_H
#include <iostream>
#include <string>
#include "DataUsuario.h"
#include "DataInformacionUsuario.h"
#include "Usuario.h"

using namespace std;

class IUsuarioControlador{
	public:
		virtual bool checkeoNickname(string) = 0;
		virtual void ingresarDatosUsuario(DataUsuario usuario) = 0;
		virtual void guardarUsuario() = 0;
		virtual DataInformacionUsuario obtenerInformacionUsuario() = 0;
		virtual list<DataUsuario> listarUsuarios() = 0;
		virtual void elegirUsuario(string) = 0;
		virtual int getId() = 0;
		virtual Usuario* getUsuarioElegido() = 0;

};
#endif