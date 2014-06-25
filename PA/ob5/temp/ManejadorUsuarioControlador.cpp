#include "ManejadorUsuarioControladorControlador.h"

ManejadorUsuarioControlador * ManejadorUsuarioControlador::instance = NULL;

ManejadorUsuarioControlador * ManejadorUsuarioControlador::getInstance(){
	if(ManejadorUsuarioControlador::instance == NULL){
		ManejadorUsuarioControlador::instance = new ManejadorUsuarioControlador();
	}
	return ManejadorUsuarioControlador::instance;

}
ManejadorUsuarioControlador::ManejadorUsuarioControlador(){

}
ManejadorUsuarioControlador::~ManejadorUsuarioControlador(){
	// delete lista de controllers antes de borrar
}

UsuarioControlador ManejadorUsuarioControlador::obtenerControlerPorId(int id){
	map<int, UsuarioControlador>::iterator it= usuarioControladores.find(nicknamide);
	return &it->second;		
}

int ManejadorUsuarioControlador::getUltimoEnMapa(){
	return ultimoEnMapa;
}

void ManejadorUsuarioControlador::agregarController(UsuarioController ucont){
	usuarioControladores.insert(pair<int, UsuarioControlador>(ucont.getId(),ucont));
	ultimoEnMapa++;
}