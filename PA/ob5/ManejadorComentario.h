#ifndef MANEJADORCOMENTARIO_H
#define MANEJADORCOMENTARIO_H
#include <map>
#include <list>
#include <string>
#include "Comentario.h"

using namespace std;

class ManejadorComentario {	
	private:
		static ManejadorComentario * instance;
		map<int, Comentario*> comentarios;
		ManejadorComentario();
		
	public:
		static ManejadorComentario * getInstance();
		~ManejadorComentario();

		void guardarComentario(Comentario*);
		list<Comentario*> listarComentarios();
		Comentario* buscarPadre(int);
};
#endif