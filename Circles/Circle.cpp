#include "Circle.h"
#include "Framework.h"
#include <stdlib.h>
#include "Vector2.h"
#include <iostream>

using namespace std;


Circle::Circle() {
	radius = 30;
	position.x = (float)(rand() % (800 - radius * 2));
	position.y = (float)(rand() % (600 - radius * 2));
	//direction.x = (float)(rand() % 11 - 5);
	direction.x = 5;
	direction.y = 5;
	//direction.y = (float)(rand() % 11 - 5);
}

Circle::Circle(unsigned char r, unsigned char g, unsigned char b) {
	radius = 30;
	position.x = (float)(rand() % (800 - radius * 2));
	position.y = (float)(rand() % (600 - radius * 2));
	//direction.x = (float)(rand() % 11 - 5);
	//direction.y = (float)(rand() % 11 - 5);
	direction.x = 5;
	direction.y = 5;
	SetRed(r);
	SetBlue(b);
	SetGreen(g);
}

void Circle::Update() {
	Draw();
	Move();
	
	/*if (!sizeHit) {
		radius += 1;
		if (radius >= 100) {
			sizeHit = true;
		}
	}
	else {
		radius -= 1;
		if (radius <= 0) {
			sizeHit = false;
		}
	}*/
}

void Circle::Draw()
{
	// Set the draw colour
	ChangeColour(GetRed(), GetGreen(), GetBlue());

	// Draws a circle at x, y
	// Draws a cirDcle at x, y
	DrawCircle((int)position.x, (int)position.y, radius);

	if (rand() % 100 == 0) {
		SetRed(rand() % 255);
		SetGreen(rand() % 255);
		SetBlue(rand() % 255);
	}
}

void Circle::Move() {
	// Move in direction
	position.x += direction.x;
	position.y += direction.y;

	// Check for hitting the edges and bounce
	if (position.x < 0 || position.x > screenWidth - 2 * radius)
	{
		direction.x = -direction.x;
		position.x = position.x < 0 ? 1 : (screenWidth - 2 * radius);

	}
		

	if (position.y < 0 || position.y > screenHeight - 2 * radius)
	{
		direction.y = -direction.y;
		position.y = position.y < 0 ? 1 : (screenHeight - 2 * radius);
	}
		
}

/*void Circle::Bounce() {
	direction.x = -direction.x;
	direction.y = -direction.y;
}*/
