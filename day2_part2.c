/* 
 * Advent of Code: Day 2 Part 2 (2016)
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 712

char buffer[BUFLEN];
char code[10];
int i;

// Converts ints into coressponding value (10=A,11=B,12=C,13=D) and puts into code array.
void convert_c(int a){
	switch(a) {
		case 10:
			code[i] = 'A';
			break;
 		case 11:
 			code[i] = 'B';
 			break;
		case 12:
			code[i] = 'C';
			break;
		case 13:
			code[i] = 'D';
			break;
		default:
			code[i] = a + '0';
	}
	i++;
}

int main(int argc, char* argv[]){
	FILE* infile = fopen("day2_input.txt", "r");
	int cur_num = 5;
	while (fgets(buffer,BUFLEN,infile) != NULL){
		int i = 0;;
		while(buffer[i] != 0){
			switch(buffer[i]) {
				case 'U': 
					if (cur_num != 5 && cur_num != 2 && cur_num != 1 && cur_num != 4 && cur_num != 9) {
						if (cur_num == 3 || cur_num == 13) {
							cur_num -= 2; 
						} else {
							cur_num -= 4;	
						}
					}	
					break;
				case 'D':
					if (cur_num != 5 && cur_num != 10 && cur_num != 13 && cur_num != 12 && cur_num != 9) {
						if (cur_num == 1 || cur_num == 11) {
							cur_num += 2;
						} else {
							cur_num += 4;
						}	
					}	
					break;
				case 'L':
					if (cur_num != 1 && cur_num != 2 && cur_num != 5 && cur_num != 10 && cur_num != 13)
						cur_num -= 1; 
					break;
				case 'R':
					if (cur_num != 1 && cur_num != 4 && cur_num != 9 && cur_num != 12 && cur_num != 13)
						cur_num += 1;
					break;
			}
			i++;
		}
		convert_c(cur_num);
	}
	int x = 0;
	printf("The key to enter the bathroom is: ");
	for (x = 0; x < i; x++){
		printf("%c",code[x]);
	}
	printf("\n");
	return 0;
}