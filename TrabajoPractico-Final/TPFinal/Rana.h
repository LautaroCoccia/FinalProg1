#ifndef RANA_H
#define RANA_H

#include <iostream>
#include "Animal.h"
using namespace std;

class Rana:public Animal{
	int _salto;
public:
	Rana(int x,int y,int vidas,int visible, int salto);
	char getTipo();
	void Atacar(Animal* per);
	void setSalto(int salto);
	int getSalto();
	void dibujar();
	void borrar();
};

#endif
