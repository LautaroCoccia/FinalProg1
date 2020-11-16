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
#define TIEMPOMAX 30
#define INTENTOS 3
#define NIVEL_A 6
#define NIVEL_B 8
#define NIVEL_C 10

using namespace std;
class Juego{
	int _tecla;
	bool _gameOver;
	Animal* vec[TOPE];	// reprersenta a las hormigas y/o grillos
	Animal* _depredador;// representa a la rana
	int _vivos;			// cuantas presas vivas hay
	int _presa;			// numero de presa a ser atacada
	int _intentos;		// intentos de atacar
	float _tiempo;		// tiempo  LO CAMBIE A FLOAT
	int _ultimo;		// ultima presa atacada
	int _visibles;		// cuantas presas estan visibles
	int _dificultad;	// nivel del juego

	float _tiempoPerdido;
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
