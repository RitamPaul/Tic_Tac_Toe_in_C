#include<stdio.h>
#include<stdlib.h>

#define size 9

void display(int *arr, char *p1, char ch1, char *p2, char ch2){
	printf("\n\tNote :- %c's = %s", ch1, p1);
	printf("\n\t        %c's = %s", ch2, p2);
	printf("\n\n");
	for(int i=0; i<size; i++){
		if(arr[i]=='x' || arr[i]=='X' || arr[i]=='o' || arr[i]=='O')
			(i==2 || i==5)?(printf(" %c \n---|---|---\n", arr[i])):( (i!=8)?(printf(" %c |", arr[i])):(printf(" %c", arr[i])) );
		else
			(i==2 || i==5)?(printf(" %d \n---|---|---\n", i+1)):( (i!=8)?(printf(" %d |", i+1)):(printf(" %d", i+1)) );
	}
	printf("\n");
}

int ver_check(int *arr, char ch){
	
	// _1st vertical line checking_
	int count=0;
	for(int i=0 ; (i<=3 && arr[i]==ch) ; i+=3){
		if(arr[i]==arr[i+3])
			count++;
	}
	if(count==2)
		return 1;								// Vertical line 1 have all same sign
	
	// _2nd vertical line checking_
	count=0;
	for(int i=1 ; (i<=4 && arr[i]==ch) ; i+=3){
		if(arr[i]==arr[i+3])
			count++;
	}
	if(count==2)
		return 1;								// Vertical line 2 have all same sign
		
	// _3rd vertical line checking_
	count=0;
	for(int i=2 ; (i<=5 && arr[i]==ch) ; i+=3){
		if(arr[i]==arr[i+3])
			count++;
	}
	if(count==2)
		return 1;								// Vertical line 3 have all same sign
		
	return 0;
}

int hor_check(int *arr, char ch){
	
	// _1st horizontal line checking_
	int count=0;
	for(int i=0 ; (i<=1 && arr[i]==ch) ; i++){
		if(arr[i]==arr[i+1])
			count++;
	}
	if(count==2)
		return 1;								// Horizontal line 1 have all same sign
	
	// _2nd horizontal line checking_
	count=0;
	for(int i=3 ; (i<=4 && arr[i]==ch) ; i++){
		if(arr[i]==arr[i+1])
			count++;
	}
	if(count==2)
		return 1;								// Horizontal line 2 have all same sign
		
	// _3rd horizontal line checking_
	count=0;
	for(int i=6 ; (i<=7 && arr[i]==ch) ; i++){
		if(arr[i]==arr[i+1])
			count++;
	}
	if(count==2)
		return 1;								// Horizontal line 3 have all same sign
		
	return 0;
}

int dia_check(int *arr, char ch){
	
	// _top-left to bottom-right diagonal line checking_
	int count=0;
	for(int i=0 ; (i<=4 && arr[i]==ch) ; i+=4){
		if(arr[i]==arr[i+4])
			count++;
	}
	if(count==2)
		return 1;
		
	// _top-right to bottom-left diagonal line checking_
	count=0;
	for(int i=2 ; (i<=4 && arr[i]==ch) ; i+=2){
		if(arr[i]==arr[i+2])
			count++;
	}
	if(count==2)
		return 1;
	
	return 0;
}

int match_result(int *arr, char ch){
	int vertical = ver_check(arr, ch);
	if(vertical==0){
		int horizontal = hor_check(arr, ch);
		if(horizontal==0){
			int diagonal = dia_check(arr, ch);
			if(diagonal==0)
				return 0;
			else
				return 1;
		}
		else
			return 1;
	}
	else
		return 1;
}

void TicTacToe(int *arr){
	
	char p1[30], p2[30], ch1, ch2;
	int p1_ind, p2_ind, win=0, board_fill=0;
	
	printf("\n    Note :- Player-1 will start the game always");
	printf("\n            So, enter the players name accordingly");
	
	printf("\nEnter player-1 name (single word only) = ");
	scanf("%s", p1);
	printf("Enter player-2 name (single word only) = ");
	scanf("%s", p2);
	
	// _Player-1 mark entry_
	for(int i=1;i>0;i++){								// Taking the mark untill valid mark found
		printf("Enter player-1 choice (X or O) = ");
		scanf(" %c", &ch1);
		if(ch1=='x' || ch1=='X' || ch1=='o' || ch1=='O')
			break;
		else
			printf("\nHere only X or O is accepted. Enter again to continue.\n");
	}
	
	// _Player-2 mark entry_
	for(int i=1;i>0;i++){								// Taking the mark untill valid mark found
		printf("Enter player-2 choice (X or O) = ");
		scanf(" %c", &ch2);
		if(ch2=='x' || ch2=='X' || ch2=='o' || ch2=='O')
			break;
		else
			printf("\nHere only X or O is accepted. Enter again to continue.\n");
	}
	
	// Initially
	display(arr, p1, ch1, p2, ch2);
	
	while( win!=1 ){		
		
		
		// _1st player's turn_
		printf("\n%s's turn : Enter any integer shown to put your mark or anything else to exit = ", p1);
		for(int i=1; i>0; i++){							// Taking index till valid integer found
			scanf(" %d", &p1_ind);
			if(p1_ind>=1 && p1_ind<=9 && arr[p1_ind-1]==0){		// Already vacant, so accepted
				arr[p1_ind - 1] = ch1;
				break;
			}				
			else if(p1_ind>=1 && p1_ind<=9 && arr[p1_ind-1]!=0)	// Not vacant, so taking input again
				printf("\nEnter only the vacant place that doesn't contain any previous mark = ");
			else{												// To exit at any state of game
				printf("\nExited successfully");
				exit(1);
			}
		}
		board_fill+=1;
		display(arr, p1, ch1, p2, ch2);					// Print game baord after every mark entered
		win = match_result(arr, ch1);					// Deciding if player-1 wins immediately or not
		if(win==1){
			printf("Congratulations, %s has won the game", p1);
			return;
		}
		else if(board_fill==9){
			printf("\nOops! No one has won.");
			printf("\nBetter luck next time.");
			return;
		}
		
		
		// _2nd player's turn_
		printf("\n%s's turn : Enter any integer shown to put your mark or anything else to exit = ", p2);
		for(int i=1; i>0; i++){							// Taking index till valid integer found
			scanf(" %d", &p2_ind);
			if(p2_ind>=1 && p2_ind<=9 && arr[p2_ind-1]==0){		// Already vacant, so accepted
				arr[p2_ind - 1] = ch2;
				break;
			}				
			else if(p2_ind>=1 && p2_ind<=9 && arr[p2_ind-1]!=0)	// Not vacant, so taking input again
				printf("\nEnter only the vacant place that doesn't contain any previous mark = ");
			else{												// To exit at any state of game
				printf("\nExited successfully");
				exit(1);
			}
		}
		board_fill+=1;
		display(arr, p1, ch1, p2, ch2);				// Print game baord after every mark entered
		win = match_result(arr, ch2);				// Deciding if player-2 wins immediately or not
		if(win==1){
			printf("Congratulations, %s has won the game", p2);
			return;
		}
		else if(board_fill==9){
			printf("\nOops! No one has won.");
			printf("\nBetter luck next time.");
			return;
		}
	}
}

int main(){
	
	int quit=0;
	
	printf("Welcome to Tic Tac Toe game \n");
	printf("Let's start and have some fun");
	
	// _Start_
	while( quit!=1 ){
		
		// For every new game 9 memory block will allocate
		int *arr = (int *)calloc(size, sizeof(int));
		
		TicTacToe(arr);
		
		// Exit block
		printf("\nEnter 1 to exit or anything to continue = ");
		scanf(" %d", &quit);
		
		free(arr);
	}
	
	printf("\nCome back again. I'll wait to see the fight");
	printf("\nHave a nice day");
	
	return 0;
}