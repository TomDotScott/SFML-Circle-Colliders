/*
Circle Drawing start code for Week 9
*/

#include "Framework.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Circle.h"
#include "main.h"
#include "Vector2.h"

// Global variables - do not rename them, feel free to change values though

// Screen dimensions
int screenWidth{ 800 };
int screenHeight{ 600 };

// Delay to slow things down (needed for Windows but does nothing much on Linux)
int timeDelayMS{ 50 };

using namespace std;

int main()
{
	// Seed the random
	srand((unsigned)time(0));

	// Create a vector container to hold our circles
	vector<Circle> circleVector;

	// Create a circle and add it to our vector
	Circle newCircle(0, 255, 255);

	/*newCircle.radius = rand() % 7 + 3;
	newCircle.x = rand() % (screenWidth - newCircle.radius * 2);
	newCircle.y = rand() % (screenHeight - newCircle.radius * 2);
	newCircle.*/

	circleVector.push_back(newCircle);


	// Create a circle and add it to our vector
	Circle c(0, 255, 255);

	circleVector.push_back(c);

	while (UpdateFramework())
	{
		bool collided = false;

		int x = 0, y = 0;
		bool wasButtonPressed = false;
		
		if (IsButtonPressed(EButton::eRight)) {
			wasButtonPressed = true;
			Circle newCircle;
			circleVector.push_back(newCircle);
		}

		// Loop through all circles in the vector
		for (auto &circle1 : circleVector)
		{
				for (auto& circle2 : circleVector) {
					if (&circle1 != &circle2) {
						//Find the difference in distance of the 2 circles by squaring the difference
						float distanceBetweenCirclesSquared = (circle2.position.x - circle1.position.x) * (circle2.position.x - circle1.position.x) +
							(circle2.position.y - circle1.position.y) * (circle2.position.y - circle1.position.y);
						//Compare distance between 2 radii and see if it is greater than the plural of the radius
						if (distanceBetweenCirclesSquared < (circle1.radius + circle2.radius) * (circle1.radius + circle2.radius)) {
							//cout << "COLLISION!" << endl;
							//Collision Happened
							//Check the angle of the collision
							double angle = atan2f(circle2.position.y - circle1.position.y, circle2.position.x - circle1.position.x);

							//find the distance between the circles
							float distanceBetweenCircles = sqrt((circle2.position.x - circle1.position.x) * (circle2.position.x - circle1.position.x) +
								(circle2.position.y - circle1.position.y) * (circle2.position.y - circle1.position.y));

							//cout << "Circle1: " << circle1.position << " Radius: " << circle1.radius << "Circle2: " << circle2.position << " Radius: " << circle2.radius << " " << distanceBetweenCircles << endl;
							
							
							//find the sum of the radii
							float sumOfRadii = circle1.radius + circle2.radius;


							//Work out the distance to move
							float distanceToMove = sumOfRadii - distanceBetweenCircles;


							//calculate the tangent
							Vector2 tangentVector;
							tangentVector.y = -(circle2.position.x + circle2.radius - circle1.position.x - circle1.radius);
							tangentVector.x = circle2.position.y + circle2.radius - circle1.position.y - circle1.radius;



							//normalise the tangent for projection to work properly
							tangentVector.Normalise();
							//work out the relative velocity using the direction vector
							Vector2 relativeVelocity = Vector2(circle1.direction.x - circle2.direction.x, circle1.direction.y - circle2.direction.y);


							//Work out the length of the velocity compared to the parallel of the tangent
							float length = relativeVelocity.x * tangentVector.x + relativeVelocity.y * tangentVector.y;
							cout << length << endl;
							//multiply the normalised tangent by the length to get the length of the component parallel to the tangent
							Vector2 velocityComponentOnTangent = Vector2(tangentVector.x * length, tangentVector.y * length);

							//Subtract the velocity component parallel to the tangent from the relative velocity ot get the perpendicular to the tangent
							Vector2 velocityComponentPerpendicularToTangent = relativeVelocity - velocityComponentOnTangent;
							//make the circles move!

							circle1.direction.x -= velocityComponentPerpendicularToTangent.x;
							circle1.direction.y -= velocityComponentPerpendicularToTangent.y;

							circle2.direction.x += velocityComponentPerpendicularToTangent.x;
							circle2.direction.y += velocityComponentPerpendicularToTangent.y;

						}
					}
				}
				circle1.Update();
			}

		wasButtonPressed = false;
	}

	return 0;
}
