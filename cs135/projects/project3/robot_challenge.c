/*  Name:  robot_challenge.c
	Purpose:  Gives the user a list of options to control a simualted robot
	Challenge:  Make it so that you can input a specific number of steps too
	Author:  Justin Stevens */

#include <stdio.h>

struct Coordinates{
	//Used a struct for the (x,y) coordinates as it was easier to hold the variables this way
	//And to use the Drive function this way so that it outputs a struct, rather than having a bunch of nested if statements in the main function
	int x;
	int y;
};
/*  Note:  Members of this enumeration are counterclockwise 
(i.e. going left) */
enum Direction
{
	//I used an enumeration for the direction, because when each value is incremented, it goes to the next value in the enumerations
	//Which made changing directions easier without the use of a ton of if statements also  
	East, //Assigned value 0
	North,  //Assigned value 1
	West, //Assigned value 2
	South //Assigned value 3
};
struct Coordinates Drive(struct Coordinates Robot, enum Direction dir, int val){
	//Value is the number of steps which the robot is going to move in the intended direction
	//When the user inputs 2, the function is called with the parameter "-steps", therefore, making the robot move backwards in that direction
	if(dir==East){
		Robot.x+=val; //Move in the positive x direction east
	}
	if(dir==North){
		Robot.y+=val; //Move in the positive y direction north
	}
	if(dir==West){
		Robot.x-=val;  //Move in the negative x direction west
	}
	if(dir==South){
		Robot.y-=val; //Move in the negative y direction south
	}
	return Robot;
}


int main(void){
	int cmd; //Command user enters
	int steps; //Number of steps robot moves (accessed in Case 1 and Case 2)
	struct Coordinates Robot; //The robot that is being moved:  the advantage of using a struct is in case we had more than 1 robot :)
	Robot.x=0; //Initialize x and y coordinates to be 0
	Robot.y=0;
	char* direction; //This is in order to print the direction as I couldn't figure out how to print out a string from an enumeration
	enum Direction dir=East; //Initial direction is East (assigned value 0)
	
	for(;;){
		printf("\n");
		printf("#This program controls the movement of a simulated robot.\n");
		printf("(1) Drive forward \n");
		printf("(2) Drive backward \n");
		printf("(3) Turn left \n");
		printf("(4) Turn right \n");
		printf("(5) Display robot position \n");
		printf("(6) Reset to start position \n");
		printf("(7) Quit program \n");
		printf("Please select from the above options: ");
		//User inputs command
		scanf("%d", &cmd);
		switch(cmd){
			case 1:
				printf("Please enter the number of steps: ");
				scanf("%d", &steps); //Number of steps user enters
				Robot=Drive(Robot, dir, steps);
				//Robot is changed to be the result of the Drive function, when moving a certain number of steps, steps, in a direction, dir
				break;
			case 2:
				printf("Please enter the number of steps: ");
				scanf("%d", &steps);
				Robot=Drive(Robot, dir, -steps);
				//The reason we use negative steps is because the robot is moving backwards in this case
				break;
			case 3:
				/*The value of South is 3, therefore, incrementing it would give 4, out of the range of the enumeration
				Therefore, we manually make it so that if the direction is South, it loops back to East */
				if(dir==South){
					dir=East;
				}
				else{
					//Otherwise, increment the direction in the enumeration to make it go left (see the comment above the Enumeration) 
					dir++;
				}
				break;
			case 4:
				/*The value of East is 0, therefore, decrementing it would give -1
				Therefore, I manually make it South */ 
				if(dir==East){
					dir=South;
				}
				else{
					//Decrement the enumeration to make it go right  
					dir--;
				}
				break;
			case 5:
				/*  This is all for printing formatting
				I couldn't figure out how to print out the value that the enumeration held, therefore, just assigned it to a string 
				This is by far my least favorite part of the code and I'd be curious to learn an easier way to do this */  
				switch(dir){
					case 0:
						direction="East";
						break;
					case 1:
						direction="North";
						break;
					case 2:
						direction="West";
						break;
					case 3:
						direction="South";
						break;
				}
				printf("\n");
				printf("#Robot location is (%d, %d); Heading: %s \n", Robot.x,Robot.y,direction);
				break;
			case 6:
				//Reset the robot's coordinates to (0,0) and direction to East
				Robot.x=0;
				Robot.y=0;
				dir=East;
				break;
			case 7:
				return 0;
			default:
				printf("\n");
				printf("Selected option not valid. \n");
		}
		
	}
}