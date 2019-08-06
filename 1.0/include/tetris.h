#ifndef TETRIS_H
#define TETRIS_H

#include <conio.h>
#include <windows.h>
#include <time.h>
#include "../include/piece.h"
#include "../include/print.h"

class Tetris{
		Piece pic;
		int map[WIDTH+6][HEIGHT+6]={
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
			{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		};
		int score;
		int count;
	public:
		Tetris();
		void welcome();//初始化界面 
		void initMap();//初始化地图 
		void pause();//空格暂停游戏 
		int runGame();//键盘输入接口 
		int update();//实现自动下降、地图更新
		int gameOver(); 
		bool judge(int x,int y,int id);
		void getScore(int rank); 
		void incTop();
};

Tetris::Tetris():pic(rand()%19){
	score=0;
	count=500;
}

void Tetris::welcome(){
	system("cls");
	setColor(WHITE);
	gotoxy(X+15,Y-1);
	cout<<"俄罗斯方块";
	Piece cub1(10,2,3);
	cub1.draw();
	Piece cub2(17,6,3);
	cub2.draw();
	Piece cub3(15,10,3);
	cub3.draw();
	Piece cub4(4,14,2);
	cub4.draw();
	Piece cub5(2,4,7);
	cub5.draw();
	Piece cub6(0,8,7);
	cub6.draw();
	Piece cub7(12,12,7);
	cub7.draw();
	setColor(WHITE);
	gotoxy(X+11,Y+14);
	cout<<"W";
	gotoxy(X+9,Y+15);
	cout<<"A S D";
	gotoxy(X+26,Y+14);
	cout<<"旋转";
	gotoxy(X+21,Y+15);
	cout<<"左移 下落 右移";
	gotoxy(X+9,Y+17);
	cout<<"空格键";
	gotoxy(X+26,Y+17);
	cout<<"暂停";
	gotoxy(X+11,Y+20);
	cout<<"请按空格键开始游戏";
	//开始界面
	while(1){
		if(getch()==' '){
		break;
		} 
	}
	return;
} 

void Tetris::initMap(){
	system("cls"); 
	gotoxy(X-2,Y-1);
	printTimes("■",12);
	for(int i=0;i<20;i++){
		gotoxy(X-2,Y+i);
		cout<<"■";
		printTimes("  ",10);
		cout<<"■";
	} 
	gotoxy(X-2,Y+20);
	printTimes("■",12); 
	gotoxy(X+WIDTH*2+10,Y+14);
	for(int i=0;i<HEIGHT;i++){
		for(int j=0;j<WIDTH;j++){ 
			map[TEMP+j][TEMP+i]=0;
		}
	}
	score=0;
	count=500;
	cout<<"Score:\t"<<score;
	//gotoxy(X+WIDTH*2+10,Y+16);
	//cout<<"Top:\t"<<top;
}

void Tetris::incTop(){
	int ntop=0;
	for(int i=0;i<HEIGHT;i++){
		for(int j=0;j<WIDTH;j++){
			if(map[TEMP+j][TEMP+i]>0){
				ntop++;
				break;
			}
		}
	} 
	//top=ntop;
	return;
}
 
int Tetris::update(){
	if(judge(pic.nx,pic.ny+1,pic.id)){//若下方有空位，自动下降
		pic.erase();
		pic.ny++;
		pic.draw();
	}
	else{
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(shape[pic.id][i][j]==1){
					map[pic.nx+TEMP+i][pic.ny+TEMP+j]=pic.color;
				}
			}
		}
		//方块触底 ，加入背景中 
		Sleep(100);
		int rank=0;
		for(int j=0;j<HEIGHT;j++){
			int flag=0;
			for(int i=0;i<WIDTH;i++){
				if(map[TEMP+i][TEMP+j]==0){
					break;
				}
				flag++;
			}
			if(flag==10){//一整行消除 
				rank++;
				for(int t=j;t>0;t--){
					for(int i=0;i<WIDTH;i++){
						map[TEMP+i][TEMP+t]=map[TEMP+i][TEMP+t-1];
					}
				} 
			}
		}
		if(rank>0) getScore(rank);
		//incTop(); 
		for(int i=0;i<HEIGHT;i++){
					gotoxy(X,Y+i);
					for(int j=0;j<WIDTH;j++){
						if(map[TEMP+j][TEMP+i]>0){
							setColor(map[TEMP+j][TEMP+i]);
							cout<<"■"; 
						}
						else cout<<"  "; 
					}
			} 		
		srand((int)time(NULL)); 
		pic.renewPie(rand()%7);
		while(!judge(pic.nx,pic.ny,pic.id)){
			pic.ny++;
		}
		if(pic.ny>0) return 1;
		pic.draw();	
		//增加新方块 
	} 
	return 0; 
}

int Tetris::runGame(){//键盘输入接口 
	initMap();
	srand((int)time(NULL)); 
	pic.renewPie(rand()%7);
	while(!judge(pic.nx,pic.ny,pic.id)){
		pic.ny++;
	}
	pic.draw();
	int i=0;
	while(1){
		if(i>=count){
			i=0;
			if(update()) return gameOver();
		}
		if(kbhit()){	
			char ch;
			ch=getch();
			switch(ch){
				case 'a':case 'A':{//左移 
					if(judge(pic.nx-1,pic.ny,pic.id)){
						pic.erase();
						pic.nx--;
						pic.draw();
					}
					break;
				}
				case 'd':case 'D':{//右移 
					if(judge(pic.nx+1,pic.ny,pic.id)){
						pic.erase();
						pic.nx++;
						pic.draw();
					}
					break;
				}
				case 'w':case 'W':{//选择 
					Piece temp=pic;
					temp.span();
					if(judge(temp.nx,temp.ny,temp.id)){
						pic.erase();
						pic.span();
						pic.draw();
					}
					break;
				}
				case 's':case 'S':{//下移 
					if(judge(pic.nx,pic.ny+1,pic.id)){
						pic.erase();
						pic.ny++;
						pic.draw();
					}
					break;
				}
				case ' ':{
					pause();
					break;
				}
				default:
					break;
			}
		}
		Sleep(1);
		i++;
		gotoxy(X+WIDTH*2+2,Y+HEIGHT);
	}
}

bool Tetris::judge(int x,int y,int id){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(shape[id][i][j]==1 && map[x+TEMP+i][y+TEMP+j]>0){
				return false; 
			}
		}
	}
	return true;
}

void Tetris::pause(){
	setColor(WHITE);
	for(int i=0;i<HEIGHT;i++){
		gotoxy(X,Y+i);
		for(int j=0;j<WIDTH;j++){ 
			cout<<"■"; 
		}
	} 
	while(1){
		if(kbhit()){	
			char ch;
			ch=getch();
			if(ch==' '){
				for(int i=0;i<HEIGHT;i++){
					gotoxy(X,Y+i);
					for(int j=0;j<WIDTH;j++){
						if(map[TEMP+j][TEMP+i]>0){
							setColor(map[TEMP+j][TEMP+i]);
							cout<<"■"; 
						}
						else cout<<"  "; 
					}
				}
				setColor(pic.color);
				pic.draw();
				return;
			}
		}
	}
}

void Tetris::getScore(int rank){
		switch(rank){
			case 1:{
				score+=10;
				break;
			}
			case 2:{
				score+=40;
				break;
			}
			case 3:{
				score+=80;
				break;
			}
			case 4:{
				score+=160; 
				break;
			}
		}
		setColor(WHITE);
		gotoxy(X+WIDTH*2+10,Y+14);
		cout<<"Score:\t"<<score;
		if(count>300 && score>200)count=300;
		else if(count>200 && score>500)count=200;
		else if(count>100 && score>800)count=100;//更改速度 
}

int Tetris::gameOver(){
	setColor(WHITE);
	for(int i=0;i<HEIGHT;i++){
		gotoxy(X,Y+i);
		for(int j=0;j<WIDTH;j++){ 
			cout<<"■"; 
		}
	}
	gotoxy(X+WIDTH*2+10,Y+8);
	cout<<"Game Over";
	gotoxy(X+WIDTH*2+10,Y+10);
	cout<<"请按R键重新开始";
	gotoxy(X+WIDTH*2+10,Y+12);
	cout<<"或按空格退出游戏";
	while(1){
		if(kbhit()){	
			char ch;
			ch=getch();
			switch(ch){
				case ' ':{
					return 0;
				}
				case 'r':case 'R' :{
					return 1;
				}
			}
		}
	}
}

#endif
