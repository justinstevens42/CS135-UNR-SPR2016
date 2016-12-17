/*
Name:  lab10.c
Purpose:  Changes the bits in an input number.
Author:  Justin Stevens   */

#include <stdio.h>

#define VALUES 32

void print_binary(long int n){
  //declare an integer array which we store values in
  int binary[VALUES];
  //start at the top which is the first element of the binary representation
  //this is because in the for loop below it is then the last one to be printed as we want
  int i=VALUES-1;
  while(n){
    //use the division algorithm below by setting the remainder and storing it in an array
    binary[i]=n%2;
    //and then divide the number by 2 (we can exchange this 2 for any quotient we want when doing base conversions)
    n/=2;
    i--;

  }
  //note that if n is 14, then the binary array will then have binary[15]=0, binary[14]=1, binary[13]=1, binary[12]=1 (I start at i=VALUES-1), and the rest being 0
  //this is counterintuitive at first, however, I then print it out in the correct order to give the right result of 1110_2
  for(i=0; i<VALUES; i++){
    printf("%d", binary[i]);
  }
}

int main(){
  //declaration and user inputs number
  unsigned int user_input;
  printf("Enter an integer value: ");
  scanf("%u", &user_input);

  //declarations for sum output and a for loop value
  int sum_bits;
  int i=0;
  //so long as the value of user_input shifted count_digits to the right is not 0
  while(i<VALUES){
    //in this while loop I am going to iterate over the rightmost digit of the number
    sum_bits+= (user_input>>i)&1; //if the rightmost digit is 1, add 1 to sum_bits
    //otherwise, if the rightmost digit is 0, then this returns 0 and changes nothing
    if(i%2==1){
      //make sure that the bit in that place is 1
      user_input|=(1<<i);
    }
    i++;
  }
  printf("The number of bits that are equal to 1 is %d\n", sum_bits);
  printf("After setting odd-bits to 1: ");
  print_binary(user_input);

  int j=0;
  while(j<VALUES){
    if(j%2==0){
      //clear the bit from that place
      //note:  ~(1<<j) contains 1111111011111 with the 0 in the jth position only
      user_input &= ~(1<<j);
    }
    j++;
  }
  printf("\nAfter clearing even-bits: ");
  print_binary(user_input);
  printf("\n");


  return 0;
}
