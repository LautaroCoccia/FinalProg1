#include <iostream>
#include "Juego.h"
using namespace std;

void main() {
Juego* j=new Juego();
	j->play();
	delete j;
	cin.get();
}