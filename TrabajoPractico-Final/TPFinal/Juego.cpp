#include "Juego.h"

Juego::Juego(){
	for(int i=0;i<TOPE;i++) 
		vec[i]=NULL;
	_depredador= NULL;
}
Juego::~Juego(){
	for(int i = 0; i<TOPE; i++){
		if(vec[i]!=NULL){
			// COMPLETAR
		}
	}
}
void Juego::init(){
	_tecla=' ';
	_gameOver=false;
	srand(time(0));
	_vivos=0;
	_presa=0;
	_tiempo=TIEMPOMAX;
	_intentos=INTENTOS;
	_ultimo=0;
	_visibles=0;
	_dificultad=0;
	int top=1;
	//int i=0;

	gotoxy(10,3);
	while(_dificultad<1||_dificultad>3){
		cout<<"ingrese dificultad:\n\t\t1:principiante\n\t\t2:intermedio\n\t\t3:avanzado";
		cin>>_dificultad;
	}
	_depredador=new Rana(60, 3, VIDAS, 1, 1);
	
	switch(_dificultad){
		case 1:
			int max = 6;
			for(int i= 0; i<max; i++){
				if(vec[i]==NULL){
					vec[i]=new Hormiga((top++)*7, 12, VIDAS, 1, 1);
					_vivos++;
				}
			}
			break;
	}
	clrscr();
}
void Juego::update(){
int hor=rand()%(TOPE);
vec[3]->setVisible(0);
	
}
void Juego::play(){
	init();
	hideCursor();
	marco(1,2,80,24);
	draw();
	while(!gameOver()){
		input();
		update();
		draw();
		miliSleep(200);
	}
	result();
}
void Juego::result(){
	gotoxy(10,22);
	if(_gameOver){
		if(_vivos<0)
			cout<<"Perdiste !";
		else 
			cout<<"Ganaste !";	
		gotoxy(30,25);
		cout<<"game over  ";
		cin.get();
	}
}
void Juego::input(){
	if(_tecla=getKey(true)){
		if(_tecla>47&&_tecla<57)
			_presa=_tecla-48;
		if(_tecla==KEY_ESC)
			_gameOver=true;
	}
}

bool Juego::gameOver(){
	return _gameOver;
}
void Juego::draw(){
	_depredador->dibujar();
	for(int i=0;i<TOPE;i++){
		if(vec[i]!=NULL){
			if(vec[i]->estaVivo() && vec[i]->getVisible()){
				vec[i]->dibujar();
			}
		}
	}
	gotoxy(50,1);cout<<"Quedan "<<_vivos<<" Animales";
	gotoxy(30,1);cout<<"Visibles "<<_visibles;
}
