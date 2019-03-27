#include <stdlib.h> // for random numbers
#include "screen.h"
#include <time.h> // for randomization (using system time)
#include <stdio.h>

int main(){
	int dec[COL]; // 80 pieces of sound decibels
	srand(time(NULL));
	for (int i=0; i<COL; i++) dec[i]=rand()%70+30;
	clearScreen();
	setColors(RED, bg(YELLOW));
	barChart(dec);

	resetColors();
	getchar();

}
