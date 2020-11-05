#ifndef GRILLO_H
#define GRILLO_H

#include <iostream>
#include "Animal.h"
using namespace std;

class Grillo:public Animal{
public:
	Grillo(int x,int y,int vidas,int visible);
	char getTipo();
	void Atacar(Animal* per);
	void dibujar();
	void borrar();
};

#endif
