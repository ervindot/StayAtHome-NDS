
#include <nds.h>
#include <stdio.h>
#include <stdlib.h>	// srand, rand,...
#include <unistd.h>
#include <time.h>       // time 

#include "fondos.h"
#include "sprites.h"
#include "defines.h"
#include "rutserv.h"
#include "teclado.h"
#include "temporizadores.h"
/*--------------------------------------------------------------------------------------------------------------
							Funciones auxiliares
---------------------------------------------------------------------------------------------------------------*/




int touchingScreen() {
	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);
	iprintf("\x1b[00;00H  NORMAL        ");
	iprintf("\x1b[00;10H %d %d", pos_pantalla.px, pos_pantalla.py);
  	if (pos_pantalla.px == 0 && pos_pantalla.py == 0) {
  		return 0;
  	}
  	else {
  		return 1;
  	}
}


int playButton() {
	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);
	iprintf("\x1b[01;00H  PLAYYY  ");
	iprintf("\x1b[01;10H  %d %d ", pos_pantalla.px, pos_pantalla.py);
  	if (pos_pantalla.px > 75 && pos_pantalla.px < 205 &&
  		pos_pantalla.py > 40 && pos_pantalla.py < 95) {
  		return 1;
  	}
  	else {
  		return 0;
  	}
}

int instructionButton() {
	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);
	iprintf("\x1b[02;00H  INSTRUCTION ");
  	if (pos_pantalla.px > 105 && pos_pantalla.px < 175 &&
  		pos_pantalla.py > 108 && pos_pantalla.py < 126) {
  		return 1;
  	}
  	else {
  		return 0;
  	}
}


void printInstructions() {
	iprintf("\x1b[01;00H    Welcome to StayAtHome-NDS  ");
 	iprintf("\x1b[03;00H           Instructions:       ");
 	iprintf("\x1b[05;00H    Press PLAY (touchscreen)   ");
	iprintf("\x1b[07;00H    Kill COVID-19 viruses with ");
	iprintf("\x1b[08;00H    the hidroalcoholic gel     ");
	iprintf("\x1b[09;00H    Press A to shot.           ");
	iprintf("\x1b[11;00H    Move the hidroalcoholic gel");
	iprintf("\x1b[12;00H    pressing UP and DOWN       ");
	iprintf("\x1b[14;00H           BE CAREFUL!!!       ");
	iprintf("\x1b[16;00H      If virus touches people  ");
	iprintf("\x1b[17;00H       they will be infected   ");
	iprintf("\x1b[20;00H    Developed by:              ");
	iprintf("\x1b[22;00H    Iyan A. Unai R. Aleina P.  ");
}


void printBasicInfo() {
	consoleDemoInit();
	iprintf("\x1b[01;00H  +--------------------------+ ");
 	iprintf("\x1b[02;00H  : EC                 19/20 : ");
 	iprintf("\x1b[03;00H  +--------------------------+ ");
	iprintf("\x1b[10;00H    Project StayAtHome - NDS   ");
	iprintf("\x1b[12;00H  Segundos:");
	iprintf("\x1b[20;00H          Grupo 2A03           ");
	iprintf("\x1b[22;00H    Iyan A. Unai R. Aleina P.  ");
}

void printGameScreen() {
	MostrarP1Arriba(1,10,5);
	MostrarP1Abajo (2,10,21);
	MostrarP1Arriba(3,10,40);
	MostrarP1Abajo (4,10,56);
	MostrarP1Arriba(5,10,75);
	MostrarP1Abajo (6,10,91);
	MostrarP1Arriba(7,10,110);
	MostrarP1Abajo (8,10,126);
	MostrarP1Arriba(9,10,145);
	MostrarP1Abajo (10,10,161);
	MostrarSpray(Objetos.Spray.x, Objetos.Spray.y);
}


void initVarGameScreen() {
	Objetos.Virus1.indice = 11;
	Objetos.Virus2.indice = 12;
	Objetos.Virus3.indice = 13;
	Objetos.Virus4.indice = 14;
	Objetos.Virus5.indice = 15;
	Objetos.Virus6.indice = 16;
	Objetos.Spray.x = xSp;
	Objetos.Spray.y = 50;
	Objetos.Spray.dir = 0;

}

void updateSpray() {
	if (Objetos.Spray.dir == UP && Objetos.Spray.y > 3) {
		Objetos.Spray.y--;
	}
	else if (Objetos.Spray.dir == DOWN && Objetos.Spray.y < 160) {
		Objetos.Spray.y++;
	}
	MostrarSpray(Objetos.Spray.x, Objetos.Spray.y);
}

void spawnVirus(){
	//int xVi1 = 240, xVi2 = 240, xVi3 = 240, xVi4 = 240, xVi5 = 240, xVi6 = 240;
	//bool v1Visible = false, v2Visible = false, v3Visible = false, v4Visible = false, v5Visible = false, v6Visible = false;
	//int random1 = 0, random2 = 0, random3 = 0, random4 = 0, random5 = 0, random6 = 0;
	switch(nv){
		case 1:
			// srand(time(NULL));
			v1Visible = true;
			random1 = 10+rand()%(150 + 1 - 10);
			MostrarVirus(Objetos.Virus1.indice, xVi1, random1);
			nv++;
			break;
		case 2:
			// srand(time(NULL));
			v2Visible = true;
			random2 = 10+rand()%(150 + 1 - 10);
			MostrarVirus(Objetos.Virus2.indice, xVi2, random2);
			nv++;
			break;
		case 3:
			// srand(time(NULL));
			v3Visible = true;
			random3 = 10+rand()%(150 + 1 - 10);
			MostrarVirus(Objetos.Virus3.indice, xVi3, random3);
			nv++;
			break;
		case 4:
			// srand(time(NULL));
			v4Visible = true;
			random4 = 10+rand()%(150 + 1 - 10);
			MostrarVirus(Objetos.Virus4.indice, xVi4, random4);
			nv++;
			break;
		case 5:
			// srand(time(NULL));
			v5Visible = true;
			random5 = 10+rand()%(150 + 1 - 10);
			MostrarVirus(Objetos.Virus5.indice, xVi5, random5);
			nv++;
			break;
		case 6:
			// srand(time(NULL));
			v6Visible = true;
			random6 = 10+rand()%(150 + 1 - 10);
			MostrarVirus(Objetos.Virus6.indice, xVi6, random6);
			nv = 1;
			break;
	}
}

void updateVirus(){
	if (v1Visible){
		if (1+rand()%(5) == 1){
			if (1+rand()%(2) == 1 && random1 < 150){
				random1 += 2;
			}else if (1+rand()%(2) == 2 && random1 > 10){
				random1 -= 2;
			}
		}
		xVi1--;
		MostrarVirus(Objetos.Virus1.indice, xVi1, random1);
	}
	if (v2Visible){
		if (1+rand()%(5) == 1){
			if (1+rand()%(2) == 1 && random2 < 150){
				random2 += 2;
			}else if (1+rand()%(2) == 2 && random2 > 10){
				random2 -= 2;
			}
		}
		xVi2--;
		MostrarVirus(Objetos.Virus2.indice, xVi2, random2);
	}
	if (v3Visible){
		if (1+rand()%(5) == 1){
			if (1+rand()%(2) == 1 && random3 < 150){
				random3 += 2;
			}else if (1+rand()%(2) == 2 && random3 > 10){
				random3 -= 2;
			}
		}
		xVi3--;
		MostrarVirus(Objetos.Virus3.indice, xVi3, random3);
	}
	if (v4Visible){
		if (1+rand()%(5) == 1){
			if (1+rand()%(2) == 1 && random4 < 150){
				random4 += 2;
			}else if (1+rand()%(2) == 2 && random4 > 10){
				random4 -= 2;
			}
		}
		xVi4--;
		MostrarVirus(Objetos.Virus4.indice, xVi4, random4);
	}
	if (v5Visible){
		if (1+rand()%(5) == 1){
			if (1+rand()%(2) == 1 && random5 < 150){
				random5 += 2;
			}else if (1+rand()%(2) == 2 && random5 > 10){
				random5 -= 2;
			}
		}
		xVi5--;
		MostrarVirus(Objetos.Virus5.indice, xVi5, random5);
	}
	if (v6Visible){
		if (1+rand()%(5) == 1){
			if (1+rand()%(2) == 1 && random6 < 150){
				random6 += 2;
			}else if (1+rand()%(2) == 2 && random6 > 10){
				random6 -= 2;
			}
		}
		xVi6--;
		MostrarVirus(Objetos.Virus6.indice, xVi6, random6);
	}

}







