#include "Juego.h"

time_t initial_time;
time_t bicho_time;

Juego::Juego(){
	for(int i=0;i<TOPE;i++) 
		vec[i]=NULL;
	_depredador= NULL;
}

Juego::~Juego(){
	for(int i = 0; i<TOPE; i++){
		if(vec[i]!=NULL){
			delete vec[i];
		}
	}
	if(_depredador!=NULL)
		delete _depredador;
}

void Juego::init(){
	_tecla=' ';
	_gameOver=false;
	srand(time(0));
	_vivos=0;
	_presa=0;
	_tiempo=TIEMPOMAX;
	_intentos= 0;
	_ultimo=0;
	_visibles=0;
	_dificultad=0;

	_tiempoPerdido = 0;
	int top=1;
	int max = 0;
	int h = 0;
	int g = 0;

	gotoxy(10,3);
	while(_dificultad<1||_dificultad>3){
		cout<<"ingrese dificultad:\n\t\t1:principiante\n\t\t2:intermedio\n\t\t3:avanzado\n\t\t";
		cin>>_dificultad;
	}
	_depredador=new Rana(60, 3, VIDAS_R, 1, 1);

	switch(_dificultad){
		case 1:
			_tiempoPerdido = 1;
			max = NIVEL_A;
			for(int i= 0; i<max; i++){
				if(vec[i]==NULL){
					vec[i]=new Hormiga((top++)*7, 12, VIDAS_H, 0, i);
					_vivos++;
				}
			}
			break;
		case 2:
			_tiempoPerdido = 1.5f;
			max = NIVEL_B;
			h = 4;
			g = 3;
			for(int i= 0; i<max; i++){
				if(vec[i]==NULL){
					int ran=rand()%(2);
					if(ran==0){
						if(h>0){
							vec[i]=new Hormiga((top++)*7, 12, VIDAS_H, 0, i);
							h--;
						}else{
							vec[i]=new Grillo((top++)*7, 12, VIDAS_G, 0, i);
							g--;
						}
					}else if(ran==1){
						if(g>0){
							vec[i]=new Grillo((top++)*7, 12, VIDAS_G, 0, i);
							g--;
						}else{
							vec[i]=new Hormiga((top++)*7, 12, VIDAS_H, 0, i);
							h--;
						}
					}
					_vivos++;
				}
			}
			break;
		case 3:
			_tiempoPerdido = 2;
			max = NIVEL_C;
			h = 1+rand()%(9-1);
			g = 10 - h;
			for(int i= 0; i<max; i++){
				if(vec[i]==NULL){
					int ran=rand()%(2);
					if(ran==0){
						if(h>0){
							vec[i]=new Hormiga((top++)*7, 12, VIDAS_H, 0, i);
							h--;
						}else{
							vec[i]=new Grillo((top++)*7, 12, VIDAS_G, 0, i);
							g--;
						}
					}else if(ran==1){
						if(g>0){
							vec[i]=new Grillo((top++)*7, 12, VIDAS_G, 0, i);
							g--;
						}else{
							vec[i]=new Hormiga((top++)*7, 12, VIDAS_H, 0, i);
							h--;
						}
					}
					_vivos++;
				}
			}
			break;
	}
	initial_time = time(NULL);
	clrscr();
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

void Juego::update(){
int hor=rand()%(TOPE);

	static time_t lastTime = initial_time;
    time_t deltaTime;
    deltaTime = time(NULL) - lastTime;
    _tiempo -= deltaTime;
    bicho_time += deltaTime;
	lastTime += deltaTime;

	if(bicho_time>=2){
		if(vec[hor]!=NULL && vec[hor]->getVisible()==0){
			vec[hor]->setVisible(1);
			_visibles++;
			bicho_time = 0;
			_ultimo=hor;
		}
	}

	if(vec[_presa]!=NULL){
		if(vec[_presa]->estaVivo()==true && vec[_presa]->getVisible()==1){
			if(_presa==_ultimo){
				_depredador->Atacar(vec[_presa]);
				vec[_presa]->borrar();
			}			
			if(vec[_presa]->estaVivo()==false){
				_vivos--;
			}
			vec[_presa]->setVisible(0);
			_visibles--;
				if(_intentos>0){
					_intentos--;
				}
			
		}
		else if(vec[_presa]->getVisible()==false ||vec[_presa]->estaVivo()==false){
			_intentos++;
		}
	}
	if(_intentos==INTENTOS){
		_tiempo= (_tiempo- _tiempoPerdido);
		_intentos=0;
	}
	if(_tiempo<0){
		_tiempo = 0;
	}
}

void Juego::result(){
	gotoxy(10,22);
	if(_gameOver){
		if(_vivos>0)
			cout<<"Perdiste !";
		else
			cout<<"Ganaste !";
		gotoxy(30,25);
		cout<<"game over  ";
		cin.get();
	}
}

void Juego::input(){
	if(_tecla=getKey(false)){
		if(_tecla>47&&_tecla<58)
			_presa=_tecla-48;
		if(_tecla==KEY_ESC)
			_gameOver=true;
	}else
		_presa=32;
}

bool Juego::gameOver(){
	if(_vivos<=0||(_visibles>=_vivos && _vivos>1)||_tiempo<=0)
		_gameOver=true;

	return _gameOver;
}

void Juego::draw(){
	_depredador->dibujar();
	for(int i=0;i<TOPE;i++){
		if(vec[i]!=NULL){
			if(vec[i]->estaVivo() && vec[i]->getVisible()==1){
				vec[i]->dibujar();
			}
		}
	}
	gotoxy(10,1);cout<<"Tiempo "<<_tiempo<<" ";

	gotoxy(25,1);cout<<"Visibles "<<_visibles;

	gotoxy(42,1);cout<<"Quedan "<<_vivos<<" Animales";

	gotoxy(65,1);cout<<"INTENTOS "<<_intentos;

	gotoxy(10,5);cout<<"COMELO! "<<_ultimo;
}