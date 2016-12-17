/*
Name:  tictactoe.c
Purpose: Plays Tic Tac Toe for a 4x4 board
Author:  Justin Stevens   */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void clear_table(char board[4][4]){
  int i, j;
  for(i=0; i<4; i++){
    for(j=0; j<4; j++){
      //make every element of the board a space in order to clear it
      board[i][j]=' ';
    }
  }
}

void display_table(char board[4][4]){
  //print out the 4 by 4 board in a nice format
  printf("\nColumn:1   2   3   4\n");
  printf("Row:  ___ ___ ___ ___\n");
  printf("     |   |   |   |   |\n");
  printf("1    | %c | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2], board[0][3]);
  printf("     |   |   |   |   |\n");
  printf("      ___ ___ ___ ___\n");
  printf("     |   |   |   |   |\n");
  printf("2    | %c | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2], board[1][3]);
  printf("     |   |   |   |   |\n");
  printf("      ___ ___ ___ ___\n");
  printf("     |   |   |   |   |\n");
  printf("3    | %c | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2], board[2][3]);
  printf("     |   |   |   |   |\n");
  printf("      ___ ___ ___ ___\n");
  printf("     |   |   |   |   |\n");
  printf("4    | %c | %c | %c | %c |\n", board[3][0], board[3][1], board[3][2], board[3][3]);
  printf("     |   |   |   |   |\n");
  printf("      ___ ___ ___ ___\n");


}

void display_image(char board[4][4]){
  //we want each square to be 5x5, therefore, we make the board size equal to 23
  int board_size=23;
  printf("P2\n");
  //formatting stuff
  printf("# image.pgm\n");
  printf("%d %d\n", board_size, board_size);
  printf("%d\n", 255);
  //declare an array X which will hold all the numbers
  int X[board_size][board_size];
  int row, col, board_row, board_col;
  //quotient which is used to divide the board into 4 parts
  int quotient=board_size/4;
  //iterate over every row and every column
  for(row=0; row<board_size; row++){
    for(col=0; col<board_size; col++){
      //we want a black line to make plus signs at all intersections when the board is divided into fourths
      //this will happen when the row or column is equal to the quotient (which is board_size/4), 2*quotient+1, or 3*quotient+2
      //the reason we use 2*quotient+1 and 3*quotient+2 is so that they are equidistant away
      if(row==quotient || row==2*quotient+1 || row==3*quotient+2 || col==quotient || col==2*quotient+1 || col==3*quotient+2){
        X[row][col]=0;

      }
      else{
        //first row of the board
        if(0<=row && row<quotient){
          //use this variable to hash into the board
          board_row=0;
        }
        //second row of the board
        else if(quotient<row && row<2*quotient+1){
          //use this variable to hash into the board
          board_row=1;
        }
        //third row of the board
        else if(2*quotient+1<row && row<3*quotient+2){
          board_row=2;
        }
        //fourth row of the board
        else if(3*quotient+2<row){
          board_row=3;
        }
        //first column of the board
        if(0<=col && col<quotient){
          board_col=0;
        }
        //second column of the board
        else if(quotient<col && col<2*quotient+1){
          board_col=1;
        }
        else if(2*quotient+1<col && col<3*quotient+2){
          board_col=2;
        }
        else if(3*quotient+2<col){
          board_col=3;
        }
        //now that we can hash into the board, we do a switch statement
        switch(board[board_row][board_col]){
          case ' ':
            X[row][col]=255; //if it is blank, make it white
            break;
          case 'X':
            X[row][col]=128; //X's moves show up as a gray square
            break;
          case 'O':
            X[row][col]=0; //O's moves show up as a black suqare
            break;
        }

      }
      printf("%d ", X[row][col]);
    }
  printf("\n");
  }
}

int check_four_in_a_row(char board[4][4]){
  //this program checks whether or not there is a four in a row on the board, if there is it returns which player won
  int row,col;
  for(row=0; row<4; row++){
    //for each row, checks to see whether all elements of the row are the same
    if(board[row][0]==board[row][1] && board[row][1]==board[row][2] && board[row][2]==board[row][3] && board[row][0]!=' '){
      if(board[row][0]=='X'){
        //if so, and the player is an 'X', then return 1
        return 1;
      }
      return 2;
    }
  }
  //similarly, for each column, checks to see whether all elements of the column are the same
  for(col=0; col<4; col++){
    //the board[0][col]!=' ' condition is included to eliminate the case when it is completely empty
    if(board[0][col]==board[1][col] && board[1][col]==board[2][col] && board[2][col]==board[3][col] && board[0][col]!=' '){
      if(board[0][col]=='X'){
        return 1;
      }
      return 2;
    }
  }
  //diagonal cases
  if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]==board[3][3] && board[0][0]!=' '){
    if(board[0][0]=='X'){
      return 1;
    }
    return 2;
  }
  //other diagonal
  if(board[0][3]==board[1][2] && board[1][2]==board[2][1] && board[2][1]==board[3][0] && board[0][3]!=' '){
    if(board[0][3]=='X'){
      return 1;
    }
    return 2;
  }
  //if neither of them hae won
  return 0;
}

bool check_table_full(char board[4][4]){
  int i,j;
  for(i=0; i<4; i++){
    for(j=0; j<4; j++){
      if(board[i][j]==' '){
        //if any of the spaces are empty, end the for statements immediately and return false
        return false;
      }
    }
  }
  //otherwise, return true
  return true;
}

bool check_legal_option(char board[4][4], int row, int col){
  //if the space is empty, return true, otherwise, return false

  return board[row][col]==' '?true:false;
}
void update_table(char board[4][4], char move, int row, int col){
  //if it is a legal move, set the value at the row and column inputted to be the user's piece
  board[row][col]=move;
}

int main(){
  printf("This program plays the game of tic-tac-toe\n");
  //initializes board
  char board[4][4];
  //clears the table so it's all empty
  clear_table(board);
  //start with player 1/piece x
  int player=1;
  char piece='X';
  int row, col;
  char move[4]="";
  //this while condition will run so long as the table is not full, and there is no three in a row
  while(!(check_table_full(board) || check_four_in_a_row(board))){
    //starts by displaying the table
    bool legal_move=false;
    do{

      printf("\nEnter a command for Player %d ([row,col], c, s, p):", player);
      //the user has several valid inputs they can choose from (such as entering two numbers, or a character), therefore I store this as a string
      gets(move);
      //if the first number they entered was an integer
      if('0'<=move[0] && move[0]<='9'){
        //make the row the integer value (using a nice ASCII method by subtracting the difference from '0')
        row=move[0]-'0';
        //if the next number is a comma, then the third number is the column
        if(move[1]==','){
          //use the same trick as above
          col=move[2]-'0';
        }
        //weird case, included in case the user entered "12" thinking that meant row 1, col 2
        else if('0'<=move[1] && move[1]<='9'){
          col=move[1]-'0';
        }
        //if it is not a valid move, then say that it is in an invalid selection
        if(!check_legal_option(board,row-1,col-1)){
          printf("Invalid selection");
        }
        else{
          //otherwise, set the legal_move to be true, and exit the do while loop
          legal_move=true;
        }
      }
      else if(move[0]=='c'){
        //clear the board
        clear_table(board);
      }
      else if(move[0]=='s'){
        //display the board
        display_table(board);
      }
      else if(move[0]=='p'){
        //display the board as an image file
        display_image(board);
      }
      else{
        printf("Invalid selection");
      }

      //the do while loop only runs when there is not a legal move
    } while(!legal_move);
    //update the table with the piece inputted (note that I use row-1 and col-1 since the user inputs numbers from 1 to 3, while the board array starts indexing at 0)
    update_table(board, piece, row-1,col-1);
    //switch player
    if(player==1){
      player=2;
      piece='O';
    }
    else{
      player=1;
      piece='X';
    }
  }
  //after the game is over now
  //the output of "check_four_in_a_row" is the player who wins
  int winner=check_four_in_a_row(board);
  if(winner){
    printf("\nCongratulations, Player %d wins!\n", winner);
  }
  else{
    //if there is no winner, then it is a tie
    printf("\nGame over, no player wins.\n");
  }

  return 0;
}
