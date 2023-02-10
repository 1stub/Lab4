/*
 * Course: CS215-014
 * Project: Lab 4
 * Purpose: This program builds a pyramid and validates userinput
 * Author: Anthony Arnold
 */
// note to self, don't use goto again
#include <iostream>
#include <string>
using namespace std;

void drawTri(int n) {  // a function that takes in value n and creates a normal pyramid
	for (int i = 0; i <= n; i++) { 
		for (int j = 0; j < (n - i); j++) {
			cout << " ";
		}
		for (int j = 0; j < (2*i-1); j++) {
			cout << "*";
		}
		cout << endl;
	}	
}

void drawTri90(int n) { // a function that creates a pyramid rotated 90 degrees by creating two half pyramids
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl; 
	} // this for loop prints top half of pyramid
	
	for (int i = n - 1; i >= 1; i--){
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	} // this for loop prints bottom half of pyramid 
}

void drawTri180(int n) { // a function that creates a pyramid inverted 
	for (int i = n; i >= 1; i--) { // sets i equal to n, and for i >= 1 it removes one value from i
		for (int j = i; j < n; j++) { // j is equal to i, and for j < n adds 1 to j 
			cout << " ";
		}
		for (int j = 1; j <= (2* i - 1); j++) { // j = 1, and for j less than 2* value of i minus 1 adds 1 to j 
			cout << "*";
		}
		cout << endl;
	}
}

int main() { // main function 
	int x = 1;
	int rows;
	string q = "q";
	string Q = "Q";
	while (x != 0) { // while loop that ends once user has entered q or Q
	start:
		cout << "Please enter the size of your triangle (integer in [1, 30])" << endl;
		cout << "Type Q to quit the program: ";
		cin >> rows;
		if (cin.fail()) // detects whether ints or string inputed
		{
			cin.clear();
			string rownum;
			cin >> rownum; // creates value to store string from rows

			if (rownum == q || rownum == Q) // if rownum contains q or Q
			{
				cout << "Thank you have a great day!";
				break; //ends the program
			}
			else
			{
				cout << "Invalid Input" << endl;
				cin.ignore(256, '\n'); // ignores strings
				goto start; // takes to start: at beginning of while loop
			}
		}
		if (rows > 30 || rows < 1) 
		{
				cout << "The size is not in the correct range!" << endl;
				cin.ignore(256, '\n'); // ignores strings
				goto start; // takes to start: at beginning of while loop
		}
		else 
		{
			cout << "The triangle with size " << rows << " is: " << endl;
			drawTri(rows); // calls drawTri function
			cout << endl;
			cout << "Triangle rotated 90 degrees: " << endl;
			cout << endl;
			drawTri90(rows); // calls drawTri90 function
			cout << "Triangle rotated 180 degrees: " << endl;
			cout << endl;
			drawTri180(rows); // calls drawTri180 function 
		}
		cin.ignore(100000000, '\n'); // ignores strings
	}
	return 0;
}