#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include "air_Catching.h"

using namespace std;

//create ask_For_Distance for speed of sound to travel function
float ask_For_Distance() {
	//create distance variable
	float distance;

	//ask for distance
	cout << "Now please enter the distance in feet that the sound will be traveling." << endl;

	//recieve input for distance
	cin >> distance;

	return distance;
}
	//create speed of sound function
int speed_Of_Sound() {
    
	//define variables
	char choice;
	string schoice;
	float distance = 0, speed, time;
	int continue_Loop = 1;

	//ignore generated input
	cin.ignore();

	while (continue_Loop == 1) {

		//introduction
		cout << "Hello, welcome to the speed of sound calculator! To begin, please (a) for air, (b) for water, and (c) for steel." << endl;

		//receive input choice
		cin.get(choice);
		cin.ignore(1, '/n');

		//define string schoice and float speed based upon char choice
		if (choice == 'a') {
			schoice = "air";
			speed = 1100;
			continue_Loop++;
		}

		else if (choice == 'b') {
			schoice = "water";
			speed = 4900;
			continue_Loop++;
		}

		else if (choice == 'c') {
			schoice = "steel";
			speed = 16400;
			continue_Loop++;
		}
		
		//run is character a or be test in air_Catching.h line 38
		else if (is_Char_a_b_c(choice) == false) {
			system("cls");
			cout << "You entered a totally wrong input, try again!" << endl;
		}
	}

	//relay choice
	system("cls");
	cout << "You chose " << schoice << "." << endl;

	//ask for distance and check to make sure it doesn't equal 0
	while (is_Number_Equal_Less_Zero(distance) == true) {

		//define distance by running ask for distance function on line 10
		distance = ask_For_Distance();
		
		if (is_Number_Equal_Less_Zero(distance) == true) {
			system("cls");
			cout << "You entered a distance that is equal to or less than zero, please try again." << endl;		
		}
	}

	//define time
	time = (distance / speed);

	//print out how long it will take sound to travel through distance feet of schoice 
	cout << "It will take sound " << time << " second(s) to pass through " << distance << " feet of " << schoice << "." << endl;

	cout << endl;
	return 0;
}
//create distance of coordinates function
int distance_Of_Coordinates() {
	
	//define variables
	float height, x1, x2, y1, y2, total_Horizontal_Length, total_Vertical_Length, total_Number_X_Pixels, total_Number_Y_Pixels;
	float diff_Of_X, diff_Of_Y, length_Between_Points;
	float length_Of_Pixel, height_Of_Pixel;
	float nadir[2] = { 2000, 1500 };

	//ask for height of drone
	cout << "We will now be calculating distance of objects from a picture on a drone, please enter the height in feet of the drone." << endl;

	//receive input height
	cin >> height;

	//ask for x value of point 1
	cout << "Now please enter the x coordinate of the first point. (Between 0 and 4000)" << endl;
	cin >> x1;

	//ask for y value of point 1
	cout << "Now please enter the y coordinate of the first point. (Between 0 and 3000)" << endl;
	cin >> y1;

	//ask for x value of point 2
	cout << "Now please enter the x coordinate of the second point. (Between 0 and 4000)" << endl;
	cin >> x2;

	//ask for y value of point 2
	cout << "Now please enter the y coordinate of the second point. (Between 0 and 3000)" << endl;
	cin >> y2;

	//plug in variables to function to find full length in feet of picture while converting degrees to radians
	total_Horizontal_Length = 2 * (tan(47 * 3.14159265 / 180)) * height;

	//plug in horizontal length to find the vertical length in feet of picture
	total_Vertical_Length = total_Horizontal_Length * .75;

	//define number of y pixels
	total_Number_X_Pixels = 4000;
	total_Number_Y_Pixels = 3000;

	//define length of pixel
	length_Of_Pixel = (total_Horizontal_Length / total_Number_X_Pixels);

	//defint height of pixel
	height_Of_Pixel = (total_Vertical_Length / total_Number_Y_Pixels);

	//define x1 by distance from Nadir
	x1 = x1 - nadir[0];

	//define y1 by distance from Nadir
	y1 = -(y1 - nadir[1]);

	//define x1 by distance from Nadir
	x2 = x2 - nadir[0];

	//define y1 by distance from Nadir
	y2 = -(y2 - nadir[1]);

	//define difference of the x's and convert to feet
	diff_Of_X = (abs(x1 - x2)) * length_Of_Pixel;

	//define difference of the y's and convert to feet
	diff_Of_Y = (abs(y1 - y2)) * height_Of_Pixel;

	//calculate the num of pixels between x and y
	length_Between_Points = sqrt((pow(diff_Of_Y, 2)) + (pow(diff_Of_X, 2)));

	//print out length between points
	cout << "The distance between ( " << x1 << " , " << y1 << " ) and ( " << x2 << " , " << y2 << " ) is " << length_Between_Points << " feet, when the drone is ";
	cout << height << " feet high." << endl;
	return 0;
}

char introduction() {
	char choice;

	//Introduction, 
	cout << "Hello, please choose if you would like to solve for speed of sound (a)," << endl;
	cout << "or if you'd like to solve for distance of points on a drone. (b)" << endl;

	//receive input choice
	cin.get(choice);

	return choice;

}

int main()
{
	char restart;
	int loop_Continue = 0;
	char choice;
	//declare variables	

	//preform a loop depending on choice to run either speed_Of_Sound(): line 29, or distance_Of_Coordinates(): line 79 or restart the loop
	while (loop_Continue == 0) {
		
		//run introduction function: line 151
		choice = introduction();

		if (choice == 'a') {
			//run introduction function: line 29
			speed_Of_Sound();
			loop_Continue++;
		}

		else if (choice == 'b') {
			//run introduction function: line 81
			distance_Of_Coordinates();
			loop_Continue++;
		}
		//run is character a or b test in air_Catching.h line 29
		else if (is_Char_a_b(choice) == false) {
			system("cls");
			cout << "You entered a totally incorrect key, please try again" << endl;
			cout << endl;
			cin.ignore();
		}
	}
		//ask if user wants to rerun the program
	cout << "Enter (r) to run the program again; or enter any other key to exit." << endl;
	cin >> restart;
	cin.ignore();
	if (restart == 'r') {
		system("cls");
		main();
	}

}
