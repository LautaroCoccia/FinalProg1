#include "Rana.h"

Rana::Rana(int x, int y,int vidas,int visible, int salto):Animal(x,y,vidas,visible){
	_salto=salto;
}
char Rana::getTipo(){
	return 'R';
}
void Rana::Atacar(Animal* per){
int danio=0;
	if(per->estaVivo()){
		if(per->getTipo()=='H')	danio=1;
		if(per->getTipo()=='G')	danio=2;
		danio=per->getVidas()-danio;
		if(danio<0)danio=0;
		per->setVidas(danio);
	}
}
void Rana::setSalto(int salto){
	_salto=salto;
}
int Rana::getSalto(){
	return _salto;
}
void Rana::borrar(){
	gotoxy(_x,_y);	cout<<"         ";
	gotoxy(_x,_y+1);cout<<"         ";
	gotoxy(_x,_y+2);cout<<"         ";
}
void Rana::dibujar(){
	gotoxy(_x,_y);  cout<<" o)__";
	gotoxy(_x,_y+1);cout<<"(_  _`\ ";
	gotoxy(_x,_y+2);cout<<" z/z\__)";
}
