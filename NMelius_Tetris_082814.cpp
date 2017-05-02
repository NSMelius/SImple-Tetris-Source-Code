// NMelius_Tetris_082814.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <ctime>
#include <time.h>
#include "Windows.h"

using namespace std;




const int WIDTH = 12;
const int HEIGHT = 25;
const char EMPTY = ' ';
const char PIECE = 'X';
const char WALL = '=';
int LINES = 0;
int SCORE = LINES * 100;
const int X_Origin = 0;
const int Y_Origin = (WIDTH/2)-1;
int anchor_X = X_Origin;
int anchor_Y = Y_Origin;
int CANT_MOVE = 0;

class TetrisShape{  //class for the game piece
public:
	char m_shapeArray[4][4];  //Shape array
	TetrisShape(int decider);  //default constructor
	TetrisShape(const TetrisShape& TS);  //copy constructor prototype 
	TetrisShape& TetrisShape::operator=(const TetrisShape& TS);

};

TetrisShape::TetrisShape(int decider){  //Class constructor that uses a random number to determine the shape of the current piece
	switch(decider){
	case 0: //T-shape
		m_shapeArray[0][0] = EMPTY; m_shapeArray[1][0] = EMPTY; m_shapeArray[2][0] = EMPTY; m_shapeArray[3][0] = EMPTY;
		m_shapeArray[0][1] = EMPTY; m_shapeArray[1][1] = PIECE; m_shapeArray[2][1] = PIECE; m_shapeArray[3][1] = PIECE;
		m_shapeArray[0][2] = EMPTY; m_shapeArray[1][2] = EMPTY; m_shapeArray[2][2] = PIECE; m_shapeArray[3][2] = EMPTY;
		m_shapeArray[0][3] = EMPTY; m_shapeArray[1][3] = EMPTY; m_shapeArray[2][3] = EMPTY; m_shapeArray[3][3] = EMPTY;
		break;
	case 1:  //Box-shape
		m_shapeArray[0][0] = EMPTY; m_shapeArray[1][0] = EMPTY; m_shapeArray[2][0] = EMPTY; m_shapeArray[3][0] = EMPTY;
		m_shapeArray[0][1] = EMPTY; m_shapeArray[1][1] = PIECE; m_shapeArray[2][1] = PIECE; m_shapeArray[3][1] = EMPTY;
		m_shapeArray[0][2] = EMPTY; m_shapeArray[1][2] = PIECE; m_shapeArray[2][2] = PIECE; m_shapeArray[3][2] = EMPTY;
		m_shapeArray[0][3] = EMPTY; m_shapeArray[1][3] = EMPTY; m_shapeArray[2][3] = EMPTY; m_shapeArray[3][3] = EMPTY;
		break;
	case 2:  //Z-Shape
		m_shapeArray[0][0] = EMPTY; m_shapeArray[1][0] = EMPTY; m_shapeArray[2][0] = EMPTY; m_shapeArray[3][0] = EMPTY;
		m_shapeArray[0][1] = EMPTY; m_shapeArray[1][1] = PIECE; m_shapeArray[2][1] = PIECE; m_shapeArray[3][1] = EMPTY;
		m_shapeArray[0][2] = EMPTY; m_shapeArray[1][2] = EMPTY; m_shapeArray[2][2] = PIECE; m_shapeArray[3][2] = PIECE;
		m_shapeArray[0][3] = EMPTY; m_shapeArray[1][3] = EMPTY; m_shapeArray[2][3] = EMPTY; m_shapeArray[3][3] = EMPTY;
		break;
	case 3:  //S-Shape
		m_shapeArray[0][0] = EMPTY; m_shapeArray[1][0] = EMPTY; m_shapeArray[2][0] = EMPTY; m_shapeArray[3][0] = EMPTY;
		m_shapeArray[0][1] = EMPTY; m_shapeArray[1][1] = EMPTY; m_shapeArray[2][1] = PIECE; m_shapeArray[3][1] = PIECE;
		m_shapeArray[0][2] = EMPTY; m_shapeArray[1][2] = PIECE; m_shapeArray[2][2] = PIECE; m_shapeArray[3][2] = EMPTY;
		m_shapeArray[0][3] = EMPTY; m_shapeArray[1][3] = EMPTY; m_shapeArray[2][3] = EMPTY; m_shapeArray[3][3] = EMPTY;
		break;
	case 4: //I-Shape
		m_shapeArray[0][0] = EMPTY; m_shapeArray[1][0] = PIECE; m_shapeArray[2][0] = EMPTY; m_shapeArray[3][0] = EMPTY;
		m_shapeArray[0][1] = EMPTY; m_shapeArray[1][1] = PIECE; m_shapeArray[2][1] = EMPTY; m_shapeArray[3][1] = EMPTY;
		m_shapeArray[0][2] = EMPTY; m_shapeArray[1][2] = PIECE; m_shapeArray[2][2] = EMPTY; m_shapeArray[3][2] = EMPTY;
		m_shapeArray[0][3] = EMPTY; m_shapeArray[1][3] = PIECE; m_shapeArray[2][3] = EMPTY; m_shapeArray[3][3] = EMPTY;
		break;
	case 5: //L-Shape
		m_shapeArray[0][0] = EMPTY; m_shapeArray[1][0] = PIECE; m_shapeArray[2][0] = EMPTY; m_shapeArray[3][0] = EMPTY;
		m_shapeArray[0][1] = EMPTY; m_shapeArray[1][1] = PIECE; m_shapeArray[2][1] = EMPTY; m_shapeArray[3][1] = EMPTY;
		m_shapeArray[0][2] = EMPTY; m_shapeArray[1][2] = PIECE; m_shapeArray[2][2] = PIECE; m_shapeArray[3][2] = EMPTY;
		m_shapeArray[0][3] = EMPTY; m_shapeArray[1][3] = EMPTY; m_shapeArray[2][3] = EMPTY; m_shapeArray[3][3] = EMPTY;
		break;
	case 6: //J-Shape
		m_shapeArray[0][0] = EMPTY; m_shapeArray[1][0] = EMPTY; m_shapeArray[2][0] = PIECE; m_shapeArray[3][0] = EMPTY;
		m_shapeArray[0][1] = EMPTY; m_shapeArray[1][1] = EMPTY; m_shapeArray[2][1] = PIECE; m_shapeArray[3][1] = EMPTY;
		m_shapeArray[0][2] = EMPTY; m_shapeArray[1][2] = PIECE; m_shapeArray[2][2] = PIECE; m_shapeArray[3][2] = EMPTY;
		m_shapeArray[0][3] = EMPTY; m_shapeArray[1][3] = EMPTY; m_shapeArray[2][3] = EMPTY; m_shapeArray[3][3] = EMPTY;
		break;
	}
			}

TetrisShape& TetrisShape::operator=(const TetrisShape& TS){  //assignment operator
	if(this != &TS){
		for(int i=0 ; i <4; i++){
			for(int j=0; j < 4; j++){
			m_shapeArray[i][j] = TS.m_shapeArray[1][j];
			}
		}
	}
	return *this;
}


TetrisShape::TetrisShape(const TetrisShape& TS){  //copy constructor

	for(int i=0 ; i <4; i++){
			for(int j=0; j < 4; j++){
			m_shapeArray[i][j] =  TS.m_shapeArray[i][j];
			}
		}
}

void Instructions();
void populateBoard(vector<vector<char> > &Board);
void displayBoard(vector<vector<char> > &Board, TetrisShape& CurrentPiece);
void updateBoard(vector<vector<char> > &Board, TetrisShape& CurrentPiece);
char getInput();
void movePiece(vector<vector<char> > &Board, TetrisShape &CurrentPiece, bool &ActivePiece);
void removeShape(vector<vector<char> > &Board, TetrisShape& CurrentPiece);
void destroyLine(vector<vector<char> > &Board);
bool checkCollision(vector<vector<char> > &Board, char move, TetrisShape CurrentPiece);
void setCursorTo(int x, int y);
void sleep(unsigned int mill);

int _tmain(int argc, _TCHAR* argv[])
{
	vector<char> boardVec(WIDTH, EMPTY);
	vector<vector<char> > Board(HEIGHT, boardVec);  // creates a vector of a char vectors to store the bucket

	bool EndGame = false, ActivePiece = false;  //used to initialize the game loops

	srand(static_cast<unsigned int>(time(0)));

	populateBoard(Board); //this will initialize the board so that it displays the edges.
	Instructions();  //this will display the instructions for the player

	srand(static_cast<unsigned int>(time(0)));

	

	while( !EndGame){

	
	

	TetrisShape CurrentPiece(rand()%7); //creates a new Shape Object with the decide variable sent to the constructor

	
		ActivePiece = true;

		while(ActivePiece){
			updateBoard(Board, CurrentPiece);
			displayBoard(Board, CurrentPiece);   //this will display the board with the pieces current location
			movePiece(Board, CurrentPiece, ActivePiece); //this will move the piece according to the players input
			removeShape(Board, CurrentPiece);
			destroyLine(Board);  //this will check to see if all of the y coords per each x coord are filled with X's and destory it if it is true

			if(LINES*5 <100){  //sets a limit for the speed of the speed of the game
			sleep(200-LINES*5); //calculates the game speed based on the number of lines cleared
			}else{
				sleep(100);  //limit of game speed
			}
			char Continue;

			if(CANT_MOVE == 2){  //checks to see if the piece collided twice in a row without moving once.
			system ("cls");  // clear the screen to make room for the game over message
			setCursorTo(HEIGHT/2,WIDTH/2);
			cout<<"YOU LOSE!\n"<<"Would you like to play again?(Y/N):";
			cin>>Continue;
			Continue = toupper(Continue);  //sets the player's answer to uppercase for consistancy
			if( Continue == 'Y'){
				EndGame = false;
				populateBoard(Board);}
			else if(Continue == 'N'){

				EndGame = true;
			}else{
				cout<<"That wasn't a valid answer, so I'm going to take that as a no!";  
				EndGame = true;}
			}
		}
	}
	cout<<"Ok, thank you for playing!\n";
	system ("pause");
	return 0;
}

void Instructions(){  // Will display the instructions for the game
	
	cout<<"Wlecome to Tetris!\n";
	cout<<"Press LEFT to move the piece left\n";
	cout<<"Press RIGHT to move the piece right\n";
	cout<<"The piece will drop on its own slowly, but pressing DOWN will speed up its descent!\n";
	cout<<"Pressing UP will cause the piece to spin clockwise.\n";
	cout<<"Have fun!";

	system ("pause");


}
void populateBoard(vector<vector<char> > &Board){  //populates the base board for display

	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j <WIDTH; j++){
			if (j == 0 || j == WIDTH-1 || i == HEIGHT-1){
				Board[i][j] = WALL;
			}

		}

	}

}

void displayBoard(vector<vector<char> > &Board, TetrisShape& CurrentPiece){  //displays the board

	
	setCursorTo(0,0);

	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			
			cout<<Board[i][j];

		}
		cout<<"\n";
	}

	
	setCursorTo(WIDTH+1, 10);
	cout<<"Score: "<<SCORE<<"     Lines: "<<LINES<<endl;
	


}


void setCursorTo(int x, int y)		// Utility function to place the cursor position anywhere in the console
{
	HANDLE handle;
	COORD position;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(handle, position);
}

void movePiece(vector<vector<char> > &Board, TetrisShape &CurrentPiece, bool& ActivePiece){ 
	char move;
	move = getInput();  //This will get the users keyboard input
	char tempCellVal;
	switch(move){
	case 80:  //DOWN_ARROW drops the piece three spaces
		
		for(int i = 0; i < 3; i++){
			if (checkCollision(Board, move, CurrentPiece) == false){
					for(int i=0; i < 4 ; i++){
									for(int j=0; j < 4; j++){
										if( CurrentPiece.m_shapeArray[i][j] == PIECE){
								Board[anchor_X+i][anchor_Y+j] = EMPTY;
										}
									}
								}

		anchor_X = anchor_X+1;
			
		}
		}
		break;
	case 72:  //UP_ARROW rotates the pice clockwise
		if(checkCollision(Board, move, CurrentPiece) == false){
						for(int i=0; i < 4 ; i++){
									for(int j=0; j < 4; j++){
										if( CurrentPiece.m_shapeArray[i][j] == PIECE){
								Board[anchor_X+i][anchor_Y+j] = EMPTY;
										}
									}
								}

			tempCellVal =  CurrentPiece.m_shapeArray[0][0];

			CurrentPiece.m_shapeArray[0][0] =  CurrentPiece.m_shapeArray[0][3];

			CurrentPiece.m_shapeArray[0][3] =  CurrentPiece.m_shapeArray[3][3];

			CurrentPiece.m_shapeArray[3][3] =  CurrentPiece.m_shapeArray[3][0];

			CurrentPiece.m_shapeArray[3][0] = tempCellVal;


			CurrentPiece.m_shapeArray[0][1] =  CurrentPiece.m_shapeArray[1][3];

			CurrentPiece.m_shapeArray[1][3] =  CurrentPiece.m_shapeArray[3][2];

			CurrentPiece.m_shapeArray[3][2] =  CurrentPiece.m_shapeArray[2][0];

			CurrentPiece.m_shapeArray[2][0] = tempCellVal;

 

			tempCellVal = CurrentPiece.m_shapeArray[0][2];

			CurrentPiece.m_shapeArray[0][2] = CurrentPiece.m_shapeArray[2][3];

			CurrentPiece.m_shapeArray[2][3] =  CurrentPiece.m_shapeArray[3][1];

			CurrentPiece.m_shapeArray[3][1] =  CurrentPiece.m_shapeArray[1][0];

			CurrentPiece.m_shapeArray[1][0] = tempCellVal;

 

			tempCellVal = CurrentPiece.m_shapeArray[1][1];

			CurrentPiece.m_shapeArray[1][1] =  CurrentPiece.m_shapeArray[1][2];

			CurrentPiece.m_shapeArray[1][2] =  CurrentPiece.m_shapeArray[2][2];

			CurrentPiece.m_shapeArray[2][2] =  CurrentPiece.m_shapeArray[2][1];

			CurrentPiece.m_shapeArray[2][1] = tempCellVal;
		}
			break;

	case 75:  //LEFT_ARROW moves left
		if (checkCollision(Board, move, CurrentPiece) == false){
			
			for(int i=0; i < 4 ; i++){
				for(int j=0; j < 4; j++){
					if( CurrentPiece.m_shapeArray[i][j] == PIECE){
			Board[anchor_X+i][anchor_Y+j] = EMPTY;
					}
				}
			}

			anchor_Y = anchor_Y-1;
		
		}
		break;
	case 77:  //RIGHT ARROW moves right
		if (checkCollision(Board, move, CurrentPiece) == false){
			
			for(int i=0; i < 4 ; i++){
				for(int j=0; j < 4; j++){
					if( CurrentPiece.m_shapeArray[i][j] == PIECE){
			Board[anchor_X+i][anchor_Y+j] = EMPTY;
					}
				}
			}
		
		anchor_Y = anchor_Y+1;
			}
		
		break;
	default:  //drops the piece down one space
		if (checkCollision(Board, move, CurrentPiece) == false){
			
			for(int i=0; i < 4 ; i++){
				for(int j=0; j < 4; j++){
					if( CurrentPiece.m_shapeArray[i][j] == PIECE){
			Board[anchor_X+i][anchor_Y+j] = EMPTY;
					}
				}
			}
		anchor_X = anchor_X+1;
		CANT_MOVE = 0;  //since the piece moved this is reset
			}
		else{
			CANT_MOVE++;
		ActivePiece = false;
		anchor_X = X_Origin;  //resets the origin of the piece 
		anchor_Y = Y_Origin;
		}
	}
}

char getInput(){  //takes the players input in order to move the game piece
	char key = 0;
	if(_kbhit()){  //if the user hits a key on the keyboard...

		key = _getch(); // set the value of char key to to the key pressed

	}
	 return key;
}


void destroyLine(vector<vector<char> > &Board){  //this will detroy a line and increment the players score based on how many lines are destroyed
	int count;

	for(int i = 0; i < HEIGHT;i++){  
		count = 0;  //resets the piece count for each line
		for(int j = 0; j < WIDTH; j++){
			if(Board[i][j] == PIECE){ //checks each column of the current row to see if it's occupied
				count++;
			}
			if(count == WIDTH-2){  //checks for the row being filled
				for(int k = i; k> 0; k--){
				for(int j =0; j < WIDTH; j++){
					Board[k][j] = Board[k-1][j]; //lowers every row above the now empty row
				}
				}
				LINES++;  // 
				SCORE = LINES*100;
				}
			}
	}
		
}
bool checkCollision(vector<vector<char> > &Board, char move, TetrisShape CurrentPiece){  //This will check for collisions to prohibit movement
	int Pcount = 0, Bcount =0;



	
	switch (move){

	case 75:  //LEFT_ARROW checks next left space for a collision
		for(int i=0; i < 4; i++)
	{
		for(int j=0; j < 4; j++)
		{			
			if(CurrentPiece.m_shapeArray[i][j] != EMPTY) 
			{
				if(Board[anchor_X+i][(anchor_Y+j)-1] != EMPTY && CurrentPiece.m_shapeArray[i][j-1] !=PIECE)
				{					
					return true;
				}
			}
		}	
	}	
	return false;
	
		break;
	case 77: // RIGHT_ARROW checks the next right space
		for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{			
			if(CurrentPiece.m_shapeArray[i][j] != EMPTY) 
			{
				if(Board[anchor_X+i][anchor_Y+j+1] != EMPTY && CurrentPiece.m_shapeArray[i][j+1] !=PIECE)
				{					
					return true;
				}
			}
		}	
	}	
	return false;
	

		break;
	default:  //check to see if the next movement down is a collision. this is used for both the default drop and the DOWN_ARROW triple drop
		
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{			
			if(CurrentPiece.m_shapeArray[i][j] != EMPTY) 
			{
				if(Board[anchor_X+i+1][anchor_Y+j] != EMPTY && CurrentPiece.m_shapeArray[i+1][j] !=PIECE)
				{					
					return true;
				}
			}
		}	
	}	
	return false;
	}
}


//Maintain game speed
void sleep(unsigned int milli){
    clock_t goal = milli + clock();
    while(goal > clock());
}
void updateBoard(vector<vector<char> > &Board, TetrisShape& CurrentPiece){  //places each occupied elemt of the shapeArray onto the board

	for(int i=0 ; i < 4 ;i++){
		for(int j=0 ; j < 4 ; j++){
			if( CurrentPiece.m_shapeArray[i][j] == PIECE){
			Board[anchor_X+i][anchor_Y+j] = CurrentPiece.m_shapeArray[i][j];
			}
		}


	}

}
//removes the shape from the board after it has moved
void removeShape(vector<vector<char> > &Board, TetrisShape& CurrentPiece){

	for(int i=0; i < 4 ; i++){
				for(int j=0; j < 4; j++){
					if( CurrentPiece.m_shapeArray[i][j] == PIECE){
			Board[anchor_X+i][anchor_Y+j] = EMPTY;
					}
				}
			}



}
