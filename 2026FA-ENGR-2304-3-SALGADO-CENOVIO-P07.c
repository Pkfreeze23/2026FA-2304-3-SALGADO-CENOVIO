#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char b[9];

void board() {
	int i;
	printf("\n");
	for (i = 0; i < 9; i++) {
		printf(" %c ", b[i]);
		if (i % 3 == 2) {
		    if (i < 6) printf("---+---+---\n");
	    } else printf("|");
	}
}
	
int win(char p) {
    int w[8][3] = {
	    {0,1,2},{3,4,5},{6,7,8},
	    {0,3,6},{1,4,7},{2,5,8},
	    {0,4,8},{2,4,6}
};
int i;
for (i = 0; i < 8; i++)
    if (b[w[i][0]] == p &&
        b[w[i][1]] == p &&
        b[w[i][2]] == p) return 1;
return 0;
}

int main() {
   int mode, i, move, turn, again;
   char human, cpu, p;

   srand((unsigned)time(NULL));
   
   do {
	   for (i = 0; i < 9; i++) b[i] = '1' + i;
	   
	   printf("\n1. Play computer\n2. Two players\nChoice: ");
	   scanf("%d", &mode);
	   if (mode != 1 && mode != 2) mode = 1;
	
	   printf("Choose X or O: ");
	   scanf(" %c", &human);
	   if (human == 'x') human = 'X';
	   if (human == 'o') human = 'O';
	   if (human == 'O') human = 'X';
	   cpu = (human == 'X') ? 'O' : 'X';
	
	   turn = rand() % 2;
	   printf("\nRandom first player: %s\n",
	          turn == 0 ? "Player 1" : "Player 2/Computer");
	   
	   for (i = 0; i < 9; i++) {
		   board();
		
		   if (mode == 1 && turn == 1) {
			   p = cpu;
			   do {
				  move = rand() % 9;
			}while (b[move] == 'X' || b[move] == 'O');
			printf("Computer choose %d\n", move + 1);
		} else {
			p = (mode == 1) ? human : (turn == 0 ? 'X' : 'O');
			printf("Player %d (%c), enter position 1-9: ",
			       turn + 1, p);
			if (scanf("%d", &move) != 1) return 0;
			if (move < 1 || move > 9 ||
			    b[move - 1] == 'X' || b[move - 1] == 'O') {
				printf("Invalid move. Try again.\n");
				i--;
				continue;
			}
			move--;
		}
		b[move] = p;
		
		if (win(p)) {
			board();
			printf("%c wins!\n", p);
			break;
		}
		turn = 1 - turn;
	}
	if (i == 9) {
		board();
		printf("Draw!\n");
	}
	
	printf("Play again? (1=Yes, 0=No): ");
	scanf("%d", &again);
	
} while (again == 1);
printf("Thanks for playing!\n");
return 0;
}



		 
    



