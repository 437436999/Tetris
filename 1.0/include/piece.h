#ifndef PIECE_H
#define PIECE_H

#include "../include/print.h"
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

#define WIDTH  10			
#define HEIGHT  20 
#define TEMP  3 

#define I1  0			
#define I2  1

#define O 2				

#define L1 3				
#define L2 4
#define L3 5
#define L4 6

#define J1 7				
#define J2 8 
#define J3 9
#define J4 10

#define T1 11				
#define T2 12
#define T3 13				
#define T4 14

#define Z1 15
#define Z2 16

#define N1 17
#define N2 18

const int shape[19][4][4]={
	{
		{0,1,0,0},
		{0,1,0,0},
		{0,1,0,0},
		{0,1,0,0},
	},
	{
		{0,0,0,0},
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0},
	},
	{
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
	},
	{
		{0,1,0,0},
		{0,1,0,0},
		{0,1,1,0},
		{0,0,0,0},
	},
	{
		{0,0,0,0},
		{0,1,1,1},
		{0,1,0,0},
		{0,0,0,0},
	},
	{
		{0,0,0,0},
		{0,1,1,0},
		{0,0,1,0},
		{0,0,1,0},
	},
	{
		{0,0,0,0},
		{0,0,1,0},
		{1,1,1,0},
		{0,0,0,0},
	},
	{
		{0,0,1,0},
		{0,0,1,0},
		{0,1,1,0},
		{0,0,0,0},
	},
	{
		{0,0,0,0},
		{0,1,0,0},
		{0,1,1,1},
		{0,0,0,0},
	},
	{
		{0,0,0,0},
		{0,1,1,0},
		{0,1,0,0},
		{0,1,0,0},
	},
	{
		{0,0,0,0},
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0},
	},
	{
		{0,0,0,0},
		{0,1,0,0},
		{1,1,1,0},
		{0,0,0,0},
	},
	{
		{0,0,0,0},
		{0,1,0,0},
		{0,1,1,0},
		{0,1,0,0},
	},
	{
		{0,0,0,0},
		{0,0,0,0},
		{1,1,1,0},
		{0,1,0,0},
	},
	{
		{0,0,0,0},
		{0,1,0,0},
		{1,1,0,0},
		{0,1,0,0},
	},
	{
		{0,0,1,0},
		{0,1,1,0},
		{0,1,0,0},
		{0,0,0,0},
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0},
	},
	{
		{0,1,0,0},
		{0,1,1,0},
		{0,0,1,0},
		{0,0,0,0},
	},
	{
		{0,0,0,0},
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0},
	},
};

const int col[19]={1,1,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,7,7};

class Piece{
	public:
		int id;
		int color; 
		int nx;
		int ny;//×óÉÏ½Çxy×ø±ê 
		Piece(int,int,int);
		void renewPie(int,int,int);
		void draw();
		void erase();
		void span();
};


Piece::Piece(int rand=0,int x=3,int y=-2){
	id=rand;
	ny=y;
	nx=x;
	color=col[id];
}

void Piece::renewPie(int rand=0,int x=3,int y=-2){
	switch(rand){
		case 0:{
			id=0;
			break;
		}
		case 1:{
			id=2;
			break;
		}
		case 2:{
			id=3;
			break;
		}
		case 3:{
			id=7;
			break;
		}
		case 4:{
			id=11;
			break;
		}
		case 5:{
			id=15;
			break;
		}
		case 6:{
			id=17;
			break;
		}
	}
	ny=y;
	nx=x;
	color=col[id];
}

void Piece::draw(){
	setColor(color);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(shape[id][i][j]==1){
				gotoxy(X+2*(nx+i),Y+ny+j);
				cout<<"¡ö"; 
			}
		}
	}
}

void Piece::erase(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(shape[id][i][j]==1){
				gotoxy(X+2*(nx+i),Y+ny+j);
				cout<<"  ";  
			}
		}
	}
}

void Piece::span(){
	switch(id)
	{
	case I1: id = I2; break;	
	case I2: id = I1; break;

	case O: id = O; break;

	case L1: id = L2; break;
	case L2: id = L3; break;
	case L3: id = L4; break;
	case L4: id = L1; break; 

	case J1: id = J2; break;
	case J2: id = J3; break;
	case J3: id = J4; break;
	case J4: id = J1; break;
	
	case T1: id = T2; break;
	case T2: id = T3; break;
	case T3: id = T4; break;
	case T4: id = T1; break;

	case Z1: id = Z2; break;
	case Z2: id = Z1; break;	

	case N1: id = N2; break;
	case N2: id = N1; break;
	}
	return;
}

#endif
