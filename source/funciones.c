
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
	iprintf("\x1b[01;00H  PLAYYY      ");
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
	initVarGameScreen();
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
	MostrarSpray(xSp, ySp);
}


void initVarGameScreen() {
	ySp = 50;
	speSp = false;
}

void updateSpray() {
	if (speSp) {
		if (dirSp == UP && ySp > 3) {
			ySp--;
		}
		else if (dirSp == DOWN && ySp < 160) {
			ySp++;
		}
		MostrarSpray(xSp, ySp);
	}
}






