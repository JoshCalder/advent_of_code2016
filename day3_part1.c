/* 
 * Advent of Code Day 3 Part 1 (2016)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 16
char buffer[BUFLEN];
int line[3];
int proper_trig = 0;

int main(int argc, char* argv[]){
	FILE* infile = fopen("input3.txt","r");
	while(fgets(buffer,BUFLEN,infile) != NULL){
		char* t = strtok(buffer, " ");
		int i = 0;
		while (t != NULL){
			int tmp = atoi(t);
			line[i] = tmp;
			t = strtok(NULL, " ");
			i++;
		}
		if ((line[0] + line[1] > line[2]) && (line[0] + line[2] > line[1]) && (line[1] + line[2] > line[0])){
			proper_trig++;
		}		
	}
	printf("The number of possible triangles is: %d\n",proper_trig);	
	return 0;
}