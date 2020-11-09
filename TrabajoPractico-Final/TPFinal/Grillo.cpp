#include "Grillo.h"

Grillo::Grillo(int x, int y,int vidas,int visible):Animal(x,y,vidas,visible){
}
char Grillo::getTipo(){
	return 'G';
}
void Grillo::Atacar(Animal* per){
int danio=0;
	if(per->estaVivo()){
		danio=per->getVidas()-2;
		if(danio<0)danio=0;
		per->setVidas(danio);
	}
}
void Grillo::borrar(){
	gotoxy(_x,_y);  cout<<"             ";
	gotoxy(_x,_y+1);cout<<"             ";
	gotoxy(_x,_y+2);cout<<"             ";
}
void Grillo::dibujar(){
	gotoxy(_x,_y);  cout<<" (,')";
	gotoxy(_x,_y+1);cout<<"/(  )\\";
	gotoxy(_x,_y+2);cout<<"  <>";
}
