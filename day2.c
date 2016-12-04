#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 712

char buffer[BUFLEN];

int main(int argc, char* argv[]){
	FILE* infile = fopen("day2_input.txt", "r");
	int cur_num = 5;
	printf("The key to enter the bathroom is: ");
	while (fgets(buffer,BUFLEN,infile) != NULL){
		int i = 0;;
		while(buffer[i] != 0){
			switch(buffer[i]) {
				case 'U': 
					if ((cur_num - 3) >= 1)
						cur_num -= 3;	
					break;
				case 'D':
					if ((cur_num + 3) <= 9)
						cur_num += 3;
					break;
				case 'L':
					if (cur_num != 1 && cur_num != 4 && cur_num != 7)
						cur_num -= 1; 
					break;
				case 'R':
					if (cur_num != 3 && cur_num != 6 && cur_num != 9)
						cur_num += 1;
					break;
			}
			i++;
		}
		printf("%d",cur_num);
	}
	printf("\n");
	return 0;
}