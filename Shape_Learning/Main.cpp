/*
#Rudimentary Algorithim 
#1st of  n iterations
#Weights fixed, no activation function
#Learning not implemented

#  author @fifinonz
	https://github.com/fifinonz
*/

#include <iostream>

#include "Neural Net.h"

using namespace std;

#define maxv 10

NeuralNet *inputs = (NeuralNet *) calloc (maxv, sizeof(NeuralNet));

int main () {

/* array  to store inputs*/


	int v;
	float C1x, C3x, C1y,  C3y; // store net input after multiplication with weights 
	float g1, g2; // gradients of lines forming oblect

cout  << "\n\t\t\t\tSHAPE LEARNING\n -------------------------------------------------------------------------";
cout  <<"\n\n OBJECTIVE: Identify a TRIANGLE, given a geometric object on a Cartesian Plane.\n\n";
cout  <<" -------------------------------------------------------------------------\n\n";

NewVertice:
cout  << "How many vertices does the object have?   "; 
cin >> v;

if	(v==0){
	cout << "\nOOPS! Your object must have vertices! Try again.\n\n";
	cout  << "How many vertices does the object have??   "; 
	cin >> v;
	}
else if (v>3 || v<3){
	cout << "\nA triangle has 3 vertices! Your object IS NOT a Triangle!\n\nNEXT OBJECT:\n\n";

	goto NewVertice;
	}

cout << "\n\nPlease input the (x,y) values for each vertice:-\n\n";


for(int i = 1 ; i <= v; i++) {
	cout  << "x" << i << ":\t";
	cin >> inputs[i].x;
	cout  << "y" << i << ":\t";
	cin >> inputs[i].y;
	cout << "\n";
}
/* Weight the inputs*/

	C1x= inputs[0].x * W1 + inputs[1].x * W2 + inputs[2].x * W3;
	C3x= inputs[0].x * W1 + inputs[1].x * W3 + inputs[2].x * W2;
	C1y= inputs[0].y * W1 + inputs[1].y * W2 + inputs[2].y * W3;
	C3y= inputs[0].y * W1 + inputs[1].y * W3 + inputs[2].y * W2;


/* Gradient of each line*/
if( C1x == 0 || C1y == 0){
	g1=0;
}
else if(C3x == 0 || C3y == 0){
	g2=0;
}
else{
g1= NeuralNet::gradient(C1x,C1y); 
g2= NeuralNet::gradient(C3x,C3y);
}
if ( g1!= g2){
	cout << "\n Your object IS a Triangle!\n\nNEXT OBJECT:\n\n";
	goto NewVertice;
}
else {
	cout << "\n Sorry! Your object IS NOT a Triangle! Try Again...\n\n\n";
	goto NewVertice;
}


return 0;

}
