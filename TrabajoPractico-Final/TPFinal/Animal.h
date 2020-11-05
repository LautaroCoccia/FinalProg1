#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include "libreria.h"
using namespace std;
#define VIDAS 3

class Animal{
protected:
	int _x;
	int _y;	
	int _vidas;
	int _visible;
public:
	Animal(int x, int y,int vidas,int visible);
	virtual ~Animal();
	virtual void Atacar(Animal* per)=0;
	virtual char getTipo()=0;
	virtual void dibujar()=0;
	virtual void borrar()=0;
	bool estaVivo();
	int getVidas();
	int getVisible();
	void setVidas(int vidas);
	void setVisible(int visible);
};
#endif
