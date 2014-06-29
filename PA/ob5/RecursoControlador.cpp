#include "RecursoControlador.h"

RecursoControlador::RecursoControlador(){

}

RecursoControlador::RecursoControlador(int iduc){
	id = iduc;
}

RecursoControlador::~RecursoControlador(){
	//debemos liberar la memoria de todos los pseudoatributos 
}
RecursoControlador::RecursoControlador(const RecursoControlador& i){
	//debemos liberar la memoria de todos los pseudoatributos 
}

int RecursoControlador::RecursoControlador::getId(){
	return id;
}

list<DataCarpeta> RecursoControlador::listarCarpetasPorUsuario(){
	list<DataCarpeta> ret;
	list<Carpeta*> carpetas = ManejadorRecursos::getInstance()->listarCarpetas();
	list<Carpeta*>::iterator it; 
	for(it = carpetas.begin() ; it != carpetas.end();++it){
		Carpeta* c = *it;
		Usuario* u =c->getUsuarioCreo();
		if(u != NULL && u->getNickname() == usuarioElegido->getNickname()){
			DataUsuario dUsario;
			dUsario = DataUsuario(u->getNickname(),u->getNombre(),u->getSexo(),u->getEdad(),u->getFechaNac());
			DataCarpeta dc = DataCarpeta(c->getNombre(), dUsario, c->getDescripcion(), c->getFechaUltimoAcceso(),c->getFechaCreacion(), c->getUbicacion());
			ret.push_back(dc);
		}
	}
	return ret;
}

void RecursoControlador::agregarColaborador(){

}

void RecursoControlador::ingresarRecurso(DataRecurso recurso, string tipo){
	tiporec = tipo;
	if(tiporec == "carpeta"){
		dataCarpeta =  recurso;
	}else if(tiporec == "archivo"){
		dataArchivo =  recurso;
	}
}

void RecursoControlador::controlDeErrores(){
	Recurso* r;
	if(tiporec == "carpeta"){ 
 		r = new Carpeta(dataCarpeta);  
	}else if(tiporec == "archivo"){
		r =  new Archivo(dataArchivo); 
	}
 
 	errores = r->controlarNombreRecurso();  
	//controla que no exista  
	cout<<carpetaElegida->getNombre()<<endl;
	map<string, Recurso*> recMap = carpetaElegida->getRecursos();
	map<string, Recurso*>::iterator it; 
	
	//Esto se podria hacer con el find del mapa y si no hay elementos esta todo bien 
	bool existe = false;	
	for(it = recMap.begin();it!=recMap.end();++it){
		Recurso* tmp = (it->second);
		if(tmp->existeNombre(r->getNombre())){
			existe = true;
		}
	}
	
	if(existe){
		DataErrores sizeError = DataErrores(7,"El nombre del recurso ya existe dentro de la carpeta seleccionada");
		errores.push_back(sizeError);
	}
}

void RecursoControlador::guardarRecurso(){
	Recurso* r;
	//Preferiria hacer un type of 	 
	if(tiporec == "carpeta"){
 		r = new Carpeta(dataCarpeta); 
	}else if(tiporec == "archivo"){
		r =  new Archivo(dataArchivo);
	}

	if(carpetaElegida != NULL){
		r->setUbicacion(carpetaElegida->getUbicacion()  + "/" + r->getNombre());
	}

	r->setUsuarioCreo(usuarioElegido);

	if(r->getUsuarioCreo() != NULL){
		cout << "ALERTAAA " << r->getUsuarioCreo()->getNombre();
	}

	ManejadorRecursos::getInstance()->ingresarRecurso(r);
}

list<DataErrores> RecursoControlador::imprimirErroresGenerados(){
	return errores;
}

list<DataCarpeta> RecursoControlador::listarCarpetas(){
	list<DataCarpeta> dataCarpetas;	
	list<Carpeta*> carpetas = ManejadorRecursos::getInstance()->listarCarpetas();
	list<Carpeta*>::iterator it; 

	for(it = carpetas.begin() ; it != carpetas.end();++it){
		Carpeta* c = *it;
		Usuario* u = c->getUsuarioCreo();
		DataUsuario dUsario;
		if(u!=NULL){
			dUsario = DataUsuario(u->getNickname(),u->getNombre(),u->getSexo(),u->getEdad(),u->getFechaNac());
		}
		DataCarpeta dc = DataCarpeta(c->getNombre(), dUsario, c->getDescripcion(), c->getFechaUltimoAcceso(),c->getFechaCreacion(), c->getUbicacion());
		dataCarpetas.push_back(dc);
	}

	return dataCarpetas;
}

void RecursoControlador::elegirUsuario(string nickname){
	usuarioElegido = ManejadorUsuario::getInstance()->elegirUsuario(nickname);
}

void RecursoControlador::elegirCarpeta(string path){
	carpetaElegida = ManejadorRecursos::getInstance()->elegirCarpeta(path);
}

list<DataArchivo> RecursoControlador::listarArchivos(){
	list<DataArchivo> dataArchivos;	
	list<Archivo*> carpetas = ManejadorRecursos::getInstance()->listarArchivos();
	list<Archivo*>::iterator it; 

	for(it = carpetas.begin() ; it != carpetas.end();++it){
		Archivo* c = *it;
		Usuario* u =c->getUsuarioCreo();
		DataUsuario dUsario;
		if(u != NULL){
			dUsario = DataUsuario(u->getNickname(),u->getNombre(),u->getSexo(),u->getEdad(),u->getFechaNac());
		}
		DataArchivo dc = DataArchivo(c->getNombre(), dUsario, c->getDescripcion(), c->getFechaUltimoAcceso(),c->getFechaCreacion(), c->getUbicacion());
		dataArchivos.push_back(dc);
	}

	return dataArchivos;
}

void RecursoControlador::elegirArchivo(string path){
	archivoElegido = ManejadorRecursos::getInstance()->elegirArchivo(path);
}

//list<DataComentario> listarComentario(){}

void RecursoControlador::accionSobreComentario(string acc){
	setAccionTipo(acc);
}

void RecursoControlador::agregarComentario(string comentario){

}

void RecursoControlador::responderComentario(string c,int id ){

}

string RecursoControlador::getAccionTipo()const{
	return accionTipo;
}

Comentario RecursoControlador::getNuevoComentario() const{
	return nuevoComentario;
}

Comentario RecursoControlador::getPadreComentario()const{
	return padreComentario;
}

Carpeta* RecursoControlador::getCarpetaElegida()const{
	return carpetaElegida;
}

Archivo* RecursoControlador::getArchivoElegido()const{
	return archivoElegido;
}

Colaborador RecursoControlador::getColaboradorCreado()const{
	return colaboradorCreado;
}

list<DataErrores> RecursoControlador::getErrores()const{
	list<DataErrores> errores;
	return errores;
}

list<Recurso> RecursoControlador::getRecursosLista()const{
	return recursosLista;
}

DataRecurso RecursoControlador::getRecursoNuevo()const{
	return recursoNuevo;
}

Usuario* RecursoControlador::getUsuarioElegido()const{
	return usuarioElegido;
}

Usuario* RecursoControlador::getUsuarioColaborador()const{
	return usuarioColaborador;
}

void RecursoControlador::setAccionTipo (string at){
	accionTipo = at;
}

void RecursoControlador::setNuevoComentario (Comentario c){
	nuevoComentario = c;
}

void RecursoControlador::setPadreComentario (Comentario pc){
	padreComentario = pc;
}

void RecursoControlador::setCarpetaElegida (Carpeta* c){
	carpetaElegida = c;
}

void RecursoControlador::setArchivoElegido (Archivo* a){
	archivoElegido = a;
}

void RecursoControlador::setColaboradorCreado(Colaborador cc){
	colaboradorCreado = cc;
}

void RecursoControlador::setErrores(list<DataErrores> del){
	errores = del;
}

void RecursoControlador::setRecursosLista(list<Recurso> rl){
	recursosLista = rl;
}

void RecursoControlador::setRecursoNuevo(DataRecurso rl){
	recursoNuevo = rl;
}

void RecursoControlador::setUsuarioElegido(Usuario* u){
	usuarioElegido = u;
}

void RecursoControlador::setUsuarioColaborador(Usuario* uc){
	usuarioColaborador = uc;
}

void RecursoControlador::setExisten(bool e){
	existen = e;
}