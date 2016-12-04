/* 
 * Advent of Code Day 3 Part 1 (2016)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 18
char buffer[BUFLEN];
int line[3][3];
int proper_trig;

int main(int argc, char* argv[]){
	FILE* infile = fopen("input3.txt","r");
	int x = 0;	
	while(fgets(buffer,BUFLEN,infile) != NULL){
		char* t = strtok(buffer, " ");
		int y = 0;
		while (t != NULL){
			int tmp = atoi(t);
			line[x][y] = tmp;
			t = strtok(NULL, " ");
			y++;
		}
		if (x == 2){
			int i = 0;
			for (i = 0; i < 3; i++){
				if ((line[0][i] + line[1][i] > line[2][i]) && (line[0][i] + line[2][i] > line[1][i]) && (line[1][i] + line[2][i] > line[0][i])){
					proper_trig++;
				}		
			}				
			x = 0;
		} else {
			x++;
		}	
	}
	printf("The number of possible triangles is: %d\n",proper_trig);	
	return 0;
}