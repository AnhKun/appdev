// this file contains screen functions. They are used to display
// sound levels on a PUTTY screen as a bar chart
#include <stdio.h>
#include "screen.h"


void barChart(int db[]){
	int i;
	for (i=0; i<COL; i++){ // for 80 columns
		for (int j=0; j<db[i]/3; j++){
			printf("\033[%d;%dH", 35-j, i+1); // j is row and i is column 
#ifdef UNICODE    // conditional compilation
			printf("%s", BAR);
#else
			printf("%c", '*');
#endif
		}
	}
}

void clearScreen(void){
	printf("\033[2J");
	fflush(stdout);
}

void setColors(short bg, short fg){
	printf("\033[%d;%d;1m", bg, fg);
	fflush(stdout);
}

void resetColors(void){
	printf("\033[0m");
	fflush(stdout);
}
