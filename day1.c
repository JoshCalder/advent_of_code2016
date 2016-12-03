/* 
 * Advent of Code: Day 1 (2016)
 * Calculates x, y coordinates of how far away the Easter Bunny HQ is.
 * Calculates how many blocks away the first location that you visit twice is.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 2500

int move;		// How many spaces we need to move
char dir;		// Direction that we're moving
int block[2];		// Our current position on the map
char facing = 'N';	// Direction that we're currently facing
int visited[BUFLEN][2];	// Stores all the visited x,y coordinates
char buffer[BUFLEN];	// Buffer for file input
int final_visited_x;	// Stores the x-coordinate of the first location visited twice
int final_visited_y;	// Stores the y-coordinate of the first location visited twice
int check;		// 1=True 0=False Whether a first location has been found
int v_size;     	// keeps track of visited array size

/* This method checks to see if we have already visited this coordinate. 
 * Stores the value if we have.
 */
void dup_check(int a, int b){
	int z;
	for (z = 0; z < v_size; z++){
		if (visited[z][0] == a && visited[z][1] == b && check == 0){
			final_visited_x = a;
			final_visited_y = b;
			check = 1;
		}
	}
}

int main (int argc, char* argv[]){
	FILE *infile = fopen("input_day1.txt", "r");
	if (infile == NULL){
		printf("File not found");
		exit(1);
	}
	while (fgets(buffer,BUFLEN,infile) != NULL) {
		char *t = strtok(buffer, ",");
		while (t!=NULL){
			int i = 0;
			int z = 0;
			dir = t[0];
			t = t+1;
			move = atoi(t);
			if ((dir == 'R' && facing == 'N') || (dir == 'L' && facing == 'S')){
				for (z = 0; z < move; z++){
					visited[v_size][0] = block[0]+z;
					visited[v_size][1] = block[1];
					if (check == 0)	
						dup_check(visited[v_size][0],visited[v_size][1]);
					v_size++;
				}
				block[0] += move;
				facing = 'E';
			} else if ((dir == 'R' && facing == 'E') || (dir == 'L' && facing == 'W')){
				for (z = 0; z < move; z++){
					visited[v_size][0] = block[0];
					visited[v_size][1] = block[1]-z;
					if (check == 0)	
						dup_check(visited[v_size][0],visited[v_size][1]);
					v_size++;
				}
				block[1] -= move;
				facing = 'S';
			} else if ((dir == 'R' && facing == 'S') || (dir == 'L' && facing == 'N')){
				for (z = 0; z < move; z++){
					visited[v_size][0] = block[0]-z;
					visited[v_size][1] = block[1];
					if (check == 0)	
						dup_check(visited[v_size][0],visited[v_size][1]);
					v_size++;
				}				
				block[0] -= move;
				facing = 'W';
			} else if ((dir == 'R' && facing == 'W') || (dir == 'L' && facing == 'E')){
				for (z = 0; z < move; z++){
					visited[v_size][0] = block[0];
					visited[v_size][1] = block[1]+z;
					if (check == 0)	
						dup_check(visited[v_size][0],visited[v_size][1]);
					v_size++;
				}				
				block[1] += move;
				facing = 'N';
			}
			t = strtok(NULL, ", ");			
			i++;
		}
	}
	int final_block = abs(abs(block[0])+abs(block[1]));
	int final_block_twice = abs(abs(final_visited_x)+abs(final_visited_y));
	printf("We are (%d) blocks away from the start.\n",final_block);
	printf("First visited twice:(%d)\n",final_block_twice);
}

