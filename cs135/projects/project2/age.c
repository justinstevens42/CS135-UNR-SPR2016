/*  Name:  age.c
	Purpose:  Input two people's ages, and determines who is oldest
	Author:  Justin Stevens  
*/

#include <stdio.h>

struct ages{
	//defines a structure to hold all of the ages in, with each of the different parts being integers
	int month;
	int day;
	int year;
};

struct ages WhoIsOlder(struct ages Person1, struct ages Person2){
	//Declare a function, WhoIsOlder, which takes in two inputs(Person1, Person2) and outputs WhoIsOlder  
	if(Person1.year>Person2.year){ //IfPerson1's year is bigger than Person2's year
		return Person2; //Then Person2 is older
	}
	else if(Person1.year<Person2.year){ //Otherwise, if Person1's year is smaller than Person2's year
		return Person1; //Then Person1 is older 
	}
	else{ //Otherwise, their year is equal, and we begin to test for 
		if(Person1.month>Person2.month){ //If Person1's month is bigger than Person2's month
			return Person2; //Then Person2 is older
		}
		else if(Person1.month<Person2.month){ //Otherwise, if Person1's month is smaller than Person2's month
			return Person1; //Then Person1 is older
		}
		else{  //Otherwise, their months are equal, and we compare their days
			if(Person1.day>Person2.day){  //If Person1's day is bigger than Person2's day
				return Person2; //Then Person2 is older
			}
			else if(Person1.day<Person2.day){ //Otherwise, if Person1's day is smaller than Person2's day
				return Person1; //Then Person1 is older
			}
			else{  //Otherwise, they are the same age
				struct ages Null; //In this case, I declare a Null struct with all components 0  
				Null.year=0; //All the components are equal to 0
				Null.month=0;
				Null.day=0;
				return Null;
			}
		}
	}
}

int main(){
	struct ages Person1; //first person Structure with 3 parts:  month, day, year, all of which are integers
	struct ages Person2; //second person  
	printf("Enter the birthday of person 1 (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &Person1.month, &Person1.day, &Person1.year); //Stores the inputs of the scanf function in their respective structure parts
	printf("Enter the birthday of person 2 (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &Person2.month, &Person2.day, &Person2.year);
	//If the function WhoIsOlder(Person1,Person2) is equal to Person2, then print Person1 is the oldest
	//This part was the trickiest, since in C, you can't compare structures for equality
	//Therefore, I tested to see if their individual parts were equal
	printf("\n");
	if(WhoIsOlder(Person1,Person2).year==Person1.year && WhoIsOlder(Person1, Person2).month==Person1.month && WhoIsOlder(Person1,Person2).day==Person1.day){
		printf("Person 1 is the oldest. \n");
	}
	//This is the output of the Null structure declared above, with all parts 0  
	else if(WhoIsOlder(Person1,Person2).year==0 && WhoIsOlder(Person1, Person2).month==0 && WhoIsOlder(Person1,Person2).day==0){
		printf("They are the same age. \n");
	}
	//If neither of the above conditions are satisfied, Person 2 is the oldest 
	else{
		printf("Person 2 is the oldest. \n");
	}
}