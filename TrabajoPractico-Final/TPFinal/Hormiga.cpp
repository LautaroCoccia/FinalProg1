#include "Hormiga.h"

Hormiga::Hormiga(int x, int y,int vidas,int visible, int clase):Animal(x,y,vidas,visible){
	_clase=clase;
	//PREGUNTAR AL PROFE QUE HACE ESTO;
}
char Hormiga::getTipo(){
	return 'H';
}
void Hormiga::Atacar(Animal* per){
int danio=0;
	if(per->estaVivo()){	
		danio=per->getVidas()-1;
		if(danio<0)danio=0;
		per->setVidas(danio);
	}
}	
void Hormiga::borrar(){
	gotoxy(_x,_y);	cout<<"     ";
	gotoxy(_x,_y+1);cout<<"     ";
	gotoxy(_x,_y+2);cout<<"     ";
}
void Hormiga::dibujar(){
	gotoxy(_x,_y);  cout<<"  \O/";	
	gotoxy(_x,_y+1);cout<<"--O--";
	gotoxy(_x,_y+2);cout<<".-o-.";
	gotoxy(_x,_y+4);cout<<_vidas;
}

