// Rushdi AL-Hasan
// Professor: Dr. Phillips
// AI 4350 Fall 2018
//***********random_board.cpp**************
// Pupose: Generate a random board based on random seed and amount of shuffles from user input

#include <iostream>
#include  <stdlib.h>

using namespace std;

int main(int argc, char* argv[]){
	
	//variable declarations
	int seed= std::atoi(argv[1]); // random seed
	int numShuffle=std::atoi(argv[2]);//number of times to shuffle puzzle
	int temp; // holds value from board to switch
				
	//creates 3 X 3 board
	int board[3][3]; 
	
	//read goal board from file into a 2d array
	for(int i = 0; i <=2; i++){
		for(int j = 0; j <=2; j++){
			cin >> board[i][j];
				
	} }
	
	//testing purposes(checking for correct values in board)
	cout << "Initial goal state of board :" << endl;
	for(int i = 0; i <=2; i++){
		for(int j= 0; j <=2; j++){
			cout<< board[i][j]<< " ";	
	}
	cout << endl;		
	}
	
	srandom(seed);
	
	
	for (int x = 0; x < numShuffle; x++) {
		//random number to determine move
		int move = int((4.0*random()) / (RAND_MAX + 1.0));	
		
		for (int i = 0; i <=2;i++){			
			for(int j = 0; j <=2;j++){				
				if(board[i][j] == 0){
					switch(move){
					
					//up
					case 0:
						if(i != 0){
							temp = board[i][j];
							board[i][j] = board[i-1][j];
							board[i-1][j] = temp;
						}
						break;
					//down
					case 1:
						if(i != 2){
							temp = board[i][j];
							board[i][j] = board[i+1][j];
							board[i+1][j] = temp;							
						}
						break;
					//left
					case 2:
						if(j != 0){
							temp =board[i][j];
							board[i][j] = board[i][j-1];
							board[i][j-1] = temp;
						}
						break;
					//right
					case 3:
						if(j != 2){
							temp =board[i][j];
							board[i][j] = board[i][j+1];
							board[i][j+1] = temp;
						}
						break;
						
					}
				}
				
			}		
			
		}	
		
		}
	//testing purposes(checking for correct values in board)
	cout << " end state of board after shuffle:" << endl;
	for(int i = 0; i <=2; i++){
		for(int j= 0; j <=2; j++){
			cout<< board[i][j]<< " ";	
	}
	cout << endl;		
	}
	
	
	return 0;
	
}