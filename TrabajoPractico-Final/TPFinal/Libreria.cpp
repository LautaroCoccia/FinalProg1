#include "libreria.h"

void miliSleep(int n) {
	Sleep(n);
}

int getKey(bool wait) {
	if (!wait && !_kbhit()) return 0;
	int ch = _getch();
	if ( ch == 0 || ch == 224 )
		ch = 256 + _getch();
	return ch;
}

int getScreenWidth() {
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleScreenBufferInfo(hstdout,&csbiInfo))	return 80;
	return csbiInfo.srWindow.Right/*-csbiInfo.srWindow.Left*/+1;
}

int getScreenHeight() {
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleScreenBufferInfo(hstdout,&csbiInfo))	return 80;
	return csbiInfo.srWindow.Bottom/*-csbiInfo.srWindow.Top*/+1;
}

void setBackColor(int c) {	
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wAttrib = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole,&csbi);
	wAttrib = csbi.wAttributes;
	wAttrib &= ~(BACKGROUND_BLUE |
		BACKGROUND_GREEN | 
		BACKGROUND_RED |
		BACKGROUND_INTENSITY);
	if (c & 1)		wAttrib |= BACKGROUND_BLUE;
	if (c & 2)		wAttrib |= BACKGROUND_GREEN;
	if (c & 4)		wAttrib |= BACKGROUND_RED;
	if (c & 8)		wAttrib |= BACKGROUND_INTENSITY;
	SetConsoleTextAttribute(hConsole, wAttrib);
}

void setForeColor(int c) {	
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	WORD wAttrib = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbi;	
	GetConsoleScreenBufferInfo(hConsole,&csbi);
	wAttrib = csbi.wAttributes;	
	wAttrib &= ~(FOREGROUND_BLUE |
		FOREGROUND_GREEN |
		FOREGROUND_RED |
		FOREGROUND_INTENSITY);
	if (c & 1)		wAttrib |= FOREGROUND_BLUE;
	if (c & 2)		wAttrib |= FOREGROUND_GREEN;
	if (c & 4)		wAttrib |= FOREGROUND_RED;
	if (c & 8)		wAttrib |= FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(hConsole, wAttrib);
}

void clrscr() {
	cout.flush();
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {0, 0};	
	DWORD dw;	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwSize;
	GetConsoleScreenBufferInfo(hConsole,&csbi);
	dwSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole,
		' ',
		dwSize,
		coord,
		&dw);
	FillConsoleOutputAttribute(hConsole,
		csbi.wAttributes,
		dwSize,
		coord,
		&dw);
	SetConsoleCursorPosition(hConsole, coord);
}

void gotoxy(int x, int y) {
	HANDLE screen_buffer_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x-1;
	coord.Y = y-1;
	SetConsoleCursorPosition(screen_buffer_handle, coord);
}

void hideCursor() {
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 100;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&ConCurInf);
}

void showCursor() {
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 100;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&ConCurInf);
}

void setTitle(const char* title) {
	SetConsoleTitle(title);
}

void marco(int x1,int y1,int x2, int y2){
	for(int i=x1+1;i<x2;i++){
		gotoxy(i,y1);
		cout<<(char)205;
		gotoxy(i,y2);
		cout<<(char)205;
	}
	for(int j=y1+1;j<y2;j++){
		gotoxy(x1,j);
		cout<<(char)186;
		gotoxy(x2,j);
		cout<<(char)186;
	}
	gotoxy(x2,y1);cout<<(char)187;
	gotoxy(x1,y1);cout<<(char)201;
	gotoxy(x1,y2);cout<<(char)200;
	gotoxy(x2,y2);cout<<(char)188;
}
