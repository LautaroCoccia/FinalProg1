#include"Animal.h"

Animal::Animal(int x, int y,int vidas,int visible){
	_x=x;
	_y=y;
	_vidas=vidas;
	_visible=visible;
}
Animal::~Animal(){

}
bool Animal::estaVivo(){
	return (_vidas>0);
}
int Animal::getVidas(){
	return _vidas;
}
int Animal::getVisible(){
	return _visible;
} 
void Animal::setVidas(int vidas){
	_vidas=vidas;
}
void Animal::setVisible(int visible){
	if(_vidas>0)
			_visible=visible;
		else
			_visible=-1;
}
