/*
Name:  tictactoe.c
Purpose: Plays Tic Tac Toe
Author:  Justin Stevens */

#include <stdio.h>
#include <stdbool.h>
void create_clear_table(char board[3][3]){
  int i, j;
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      board[i][j]=' ';
    }
  }
}

void display_table(char board[3][3]){
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
  int row,col;
  for(row=0; row<3; row++){
    if(board[row][0]==board[row][1] && board[row][1]==board[row][2] && board[row][0]!=' '){
      if(board[row][0]=='X'){
        return 1;
      }
      return 2;
    }
  }
  for(col=0; col<3; col++){
    if(board[0][col]==board[1][col] && board[1][col]==board[2][col] && board[0][col]!=' '){
      if(board[0][col]=='X'){
        return 1;
      }
      return 2;
    }
  }
  if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' '){
    if(board[0][0]=='X'){
      return 1;
    }
    return 2;
  }
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
        return false;
      }
    }
  }
  return true;
}

bool check_legal_option(char board[3][3], int row, int col){
  return board[row][col]==' '?true:false;
}
void update_table(char board[3][3], char move, int row, int col){
  board[row][col]=move;
}

int main(){
  printf("This program plays the game of tic-tac-toe\n");
  char board[3][3];
  create_clear_table(board);
  int player=1;
  char piece='X';
  int row, col;
  while(!(check_table_full(board) || check_three_in_a_row(board))){
    display_table(board);
    bool legal_move=false;
    do{
      printf("\nEnter the selection of %c for Player %d [row,col]: ", piece, player);
      scanf("%d,%d",&row,&col);
      if(!check_legal_option(board,row-1,col-1)){
        printf("Invalid selection");
      }
      else{
        legal_move=true;
      }
    } while(!legal_move);
    update_table(board, piece, row-1,col-1);
    if(player==1){
      player=2;
      piece='O';
    }
    else{
      player=1;
      piece='X';
    }
  }
  display_table(board);

  int winner=check_three_in_a_row(board);
  if(winner){
    printf("\nCongratulations, Player %d wins!\n", winner);
  }
  else{
    printf("\nGame over, no player wins.\n");
  }

  return 0;
}
