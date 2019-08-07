#include <iostream>
#include <windows.h>
#include "../include/piece.h"
#include "../include/tetris.h"
#include "../include/print.h"

using namespace std;
 
int main(){
	system("cls");
	system("title ¶íÂÞË¹·½¿é");
	system("mode con cols=60 lines=28");
	Tetris game;
	game.welcome();
	while(game.runGame()){
	}
    return 0;
}
