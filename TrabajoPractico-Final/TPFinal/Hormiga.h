#ifndef HORMIGA_H
#define HORMIGA_H

#include <iostream>
#include "Animal.h"
using namespace std;

class Hormiga:public Animal{
	int _clase;
public:
	Hormiga(int x,int y,int vidas,int visible, int clase);
	char getTipo();
	void Atacar(Animal* per);
	void dibujar();
	void borrar();
};

#endif
