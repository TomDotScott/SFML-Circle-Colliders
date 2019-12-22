#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H


#include "Vector2.h"

class Circle
{
private:
	unsigned char red{ 255 };
	unsigned char green{ 0 };
	unsigned char blue{ 0 };
	unsigned char alpha{ 255 };
	bool sizeHit;
	int screenHeight = 600, screenWidth = 800;
	void Draw();
	void Move();
public:
	Circle();
	Circle(unsigned char r, unsigned char g, unsigned char b);
	int radius;
	Vector2 position;
	Vector2 direction;
	void Update();


	//Getters and Setters	
	unsigned char GetRed() {
		return red;
	}
	void SetRed(unsigned char r) {
		red = r;
	}
	unsigned char GetGreen() {
		return green;
	}
	void SetGreen(unsigned char g) {
		green = g;
	}
	unsigned char GetBlue() {
		return blue;
	}
	void SetBlue(unsigned char b) {
		blue = b;
	}

	
};


#endif // !CIRCLE_H
