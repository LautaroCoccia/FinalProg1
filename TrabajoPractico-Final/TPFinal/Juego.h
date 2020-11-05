#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Animal.h"
#include "Hormiga.h"
#include "Rana.h"
#include "Grillo.h"
#include "libreria.h"

#define MIN_FIL 1
#define MIN_COL 1
#define MAX_FIL 24
#define MAX_COL 80
#define TOPE 10
#define TIEMPOMAX 3000
#define INTENTOS 3

using namespace std;
class Juego{
	int _tecla;
	bool _gameOver;
	Animal* vec[TOPE];	// reprersenta a las hormigas y/o grillos
	Animal* _depredador;// representa a la rana
	int _vivos;			// cuantas presas vivas hay
	int _presa;			// numero de presa a ser atacada
	int _intentos;		// intentos de atacar
	int _tiempo;		// tiempo 
	int _ultimo;		// ultima presa atacada
	int _visibles;		// cuantas presas estan visibles
	int _dificultad;	// nivel del juego
public:
	Juego();
	~Juego();
	void init();
	bool gameOver();
	void play();
	void input();
	void update();
	void draw();
	void result();
};

#endif
