#ifndef PRINT_H
#define PRINT_H 

#include <iostream>
#include <windows.h>

#define X 8 
#define Y 4
#define P 9
#define Q 19 
#define R 40 

#define WHITE 0 
#define BLUE 1 
#define GREEN 2
#define RED 3
#define YELLOW 4
#define PURPLE 5
#define CYAN 6
#define PINK 7

using namespace std;

void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// Getting the standard output device handle
    SetConsoleCursorPosition(hOut, pos); //Windows & Position
}

//print a string for n times
void printTimes(string str, int n){
	for(int i = 0; i < n; i++){
		cout << str;
	}
	return;
}

void setColor(int n){
	switch (n){
		case WHITE:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		}
		case BLUE:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_BLUE );
			break;
		}
		case GREEN:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		}
		case RED:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_RED );
			break;
		}
		case YELLOW:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		}
		case PURPLE:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_BLUE | FOREGROUND_RED );
			break;
		}
		case CYAN:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		}
		case PINK:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		}
	}
}


#endif
