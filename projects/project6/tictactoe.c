/*
Name:  tictactoe.c
Purpose: Plays Tic Tac Toe
Author:  Justin Stevens   */

#include <stdio.h>
#include <stdbool.h>

void create_clear_table(char board[3][3]){
  int i, j;
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      //make every element of the board a space in order to clear it
      board[i][j]=' ';
    }
  }
}

void display_table(char board[3][3]){
  //print out the board in a nice format
  printf("\nThe current state of the game is:\n\n");
  printf("Column:1   2   3\n");
  printf("Row:  ___ ___ ___\n");
  printf("     |   |   |   |\n");
  printf("1    | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
  printf("     |   |   |   |\n");
  printf("      ___ ___ ___\n");
  printf("     |   |   |   |\n");
  printf("2    | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
  printf("     |   |   |   |\n");
  printf("      ___ ___ ___\n");
  printf("     |   |   |   |\n");
  printf("3    | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
  printf("     |   |   |   |\n");
  printf("      ___ ___ ___\n");


}

int check_three_in_a_row(char board[3][3]){
  //this program checks whether or not there is a three in a row on the board
  int row,col;
  for(row=0; row<3; row++){
    //for each row, checks to see whether all elements of the row are the same
    if(board[row][0]==board[row][1] && board[row][1]==board[row][2] && board[row][0]!=' '){
      if(board[row][0]=='X'){
        //if so, and the player is an 'X', then return 1
        return 1;
      }
      return 2;
    }
  }
  //similarly, for each column, checks to see whether all elements of the column are the same  
  for(col=0; col<3; col++){
    //the board[0][col]!=' ' condition is included to eliminate the case when it is completely empty
    if(board[0][col]==board[1][col] && board[1][col]==board[2][col] && board[0][col]!=' '){
      if(board[0][col]=='X'){
        return 1;
      }
      return 2;
    }
  }
  //diagonal cases
  if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' '){
    if(board[0][0]=='X'){
      return 1;
    }
    return 2;
  }
  //other diagonal
  if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]!=' '){
    if(board[1][1]=='X'){
      return 1;
    }
    return 2;
  }
  return 0;
}

bool check_table_full(char board[3][3]){
  int i,j;
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      if(board[i][j]==' '){
        //if any of the spaces are empty, end the for statements immediately and return false
        return false;
      }
    }
  }
  //otherwise, return true
  return true;
}

bool check_legal_option(char board[3][3], int row, int col){
  //if the space is empty, return true, otherwise, return false
  return board[row][col]==' '?true:false;
}
void update_table(char board[3][3], char move, int row, int col){
  //if it is a legal move, set the value at the row and column inputted to be the user's piece
  board[row][col]=move;
}

int main(){
  printf("This program plays the game of tic-tac-toe\n");
  //initializes board
  char board[3][3];
  //clears the table so it's all empty
  create_clear_table(board);
  //start with player 1/piece x
  int player=1;
  char piece='X';
  int row, col;
  //this while condition will run so long as the table is not full, and there is no three in a row
  while(!(check_table_full(board) || check_three_in_a_row(board))){
    //starts by displaying the table
    display_table(board);
    bool legal_move=false;
    do{
      printf("\nEnter the selection of %c for Player %d [row,col]: ", piece, player);
      scanf("%d,%d",&row,&col);
      //if it is not a valid move, then say that it is in an invalid selection
      if(!check_legal_option(board,row-1,col-1)){
        printf("Invalid selection");
      }
      else{
        //otherwise, set the legal_move to be true, and exit the do while loop
        legal_move=true;
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

  display_table(board);
  //the output of "check_three_in_a_row" is the player who wins
  int winner=check_three_in_a_row(board);
  if(winner){
    printf("\nCongratulations, Player %d wins!\n", winner);
  }
  else{
    //if there is no winner, then it is a tie
    printf("\nGame over, no player wins.\n");
  }

  return 0;
}
