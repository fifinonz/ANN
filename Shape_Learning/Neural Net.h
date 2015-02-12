/*
#  author @fifinonz
	https://github.com/fifinonz
*/

#ifndef NeuralNet_H
#define NeuralNet_H

#include <stdlib.h>
#define W1 -1
#define W2 0
#define W3 1

class NeuralNet{

/* Input and weights*/

public:
	float x,y;
	NeuralNet(float, float); // constuctor

	static float gradient (float cx, float cy) {return (cy/cx);} // gradient function

	~NeuralNet(); // deconstuctor
};

 // constuctor definition

NeuralNet :: NeuralNet(float a, float b) {
	x = a;
	y = b;
}
#endif
