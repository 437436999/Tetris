#ifndef TETRIS_H
#define TETRIS_H

#include <conio.h>
#include <windows.h>
#include <time.h>
#include "../include/piece.h"
#include "../include/print.h"

class Tetris{
		Piece pic;
		Piece pre;
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
		bool renewPie();
		void exchange();
		void rule();
		bool judge(int x,int y,int id);
		void getScore(int rank); 
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
	Piece cub1(10,2,2);
	cub1.draw();
	Piece cub2(17,6,2);
	cub2.draw();
	Piece cub3(15,10,2);
	cub3.draw();
	Piece cub4(4,14,1);
	cub4.draw();
	Piece cub5(2,4,6);
	cub5.draw();
	Piece cub6(0,8,6);
	cub6.draw();
	Piece cub7(12,12,6);
	cub7.draw();
	setColor(WHITE);
	gotoxy(Q,Y+13);
	cout<<"开始游戏\t空格";
	gotoxy(Q,Y+15);
	cout<<"规则操作\tR键";
	//开始界面
	while(1){
		if(kbhit()){	
			char ch;
			ch=getch();
			switch(ch){
				case ' ':{
					return;
				}
				case 'r':case 'R':{
					rule();
					gotoxy(Q,Y+13);
					cout<<"开始游戏\t空格";
					gotoxy(Q,Y+15);
					cout<<"规则操作\tR键";
					break;
				}
			}
		}
	}
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
	for(int i=0;i<HEIGHT;i++){
		for(int j=0;j<WIDTH;j++){ 
			map[TEMP+j][TEMP+i]=0;
		}
	}
	score=0;
	count=500;
	gotoxy(X+WIDTH*2+8,Y+14);
	cout<<"Score:\t"<<score;
	gotoxy(X+28,Y-1);
	printTimes("■",8);
	for(int i=0;i<6;i++){
		gotoxy(X+28,Y+i);
		cout<<"■";
		printTimes("  ",6);
		cout<<"■";
	} 
	gotoxy(X+28,Y+6);
	printTimes("■",8);
}

/*void Tetris::incTop(){
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
}*/ 

void Tetris::rule(){
	setColor(WHITE);
	gotoxy(P+2,Y+12);
	cout<<"W";
	gotoxy(P,Y+13);
	cout<<"A S D";
	gotoxy(P+2,Y+15);
	cout<<"J";
	gotoxy(P,Y+17);
	cout<<"空格键";
	gotoxy(Q+7,Y+12);
	cout<<"旋转";
	gotoxy(Q,Y+13);
	cout<<"  左移 下落 右移";
	gotoxy(Q,Y+15);
	cout<<"切换(下落不超过3格)";
	gotoxy(Q+5,Y+17);
	cout<<"开始/暂停";
	gotoxy(R,Y+12);
	cout<<"Line\tScore";
	gotoxy(R,Y+14);
	cout<<"1\t10";
	gotoxy(R,Y+15);
	cout<<"2\t40";
	gotoxy(R,Y+16);
	cout<<"3\t80";
	gotoxy(R,Y+17);
	cout<<"4\t160";
	gotoxy(X+12,Y+20);
	cout<<"请按R键返回主选单";
	while(1){
		if(getch()=='r' || getch()=='R'){
		for(int i=0;i<10;i++){
			gotoxy(P,Y+12+i);
			printTimes(" ",50);
		}
		break;
		} 
	}
	return;
}

void Tetris::exchange(){
	if(judge(pic.nx,pic.ny,pre.id) && pic.ny<2){
		pic.erase();
		pre.erase();
		int temp=pic.id;
		pic.id=pre.id;
		pre.id=temp;
		temp=pic.color;
		pic.color=pre.color;
		pre.color=temp;
		pic.draw();
		pre.draw();
	}
	return;
}

bool Tetris::renewPie(){
	pic.id=pre.id;
	pic.nx=3;
	pic.ny=-2;
	pic.color=pre.color;
	while(!judge(pic.nx,pic.ny,pic.id)){
		pic.ny++;
	}
	if(pic.ny>0) return 1;//return true则游戏结束 
	pic.draw();
	pre.erase();
	srand((int)time(NULL)); 
	pre.renewPie(rand()%7);
	pre.draw();
	return 0;
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
		return renewPie();	
		//增加新方块 
	} 
	return 0; 
}

int Tetris::runGame(){//键盘输入接口 
	initMap();
	Sleep(200);
	if(renewPie()) return gameOver();
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
				case 'j':case 'J':{
					exchange();
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
	for(int i=0;i<6;i++){
		gotoxy(X+30,Y+i);
		for(int j=0;j<6;j++){ 
			cout<<"■"; 
		}
	} 
	gotoxy(X+WIDTH*2+2,Y+HEIGHT);
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
				for(int i=0;i<6;i++){
					gotoxy(X+30,Y+i);
					for(int j=0;j<6;j++){ 
						cout<<"  "; 
					}
				} 
				setColor(pic.color);
				pic.draw();
				setColor(pre.color);
				pre.draw();
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
		gotoxy(X+WIDTH*2+8,Y+14);
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
	gotoxy(X+WIDTH*2+8,Y+8);
	cout<<"Game Over";
	gotoxy(X+WIDTH*2+8,Y+10);
	cout<<"请按R键重新开始";
	gotoxy(X+WIDTH*2+8,Y+12);
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
