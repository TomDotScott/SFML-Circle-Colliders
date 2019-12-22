#include "Vector2.h"
#include <cmath>

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(float xin, float yin) {
	x = xin;
	y = yin;
}

void Vector2::Normalise()
{
	x /= Length();
	y /= Length();
}

float Vector2::Length() const
{
	return sqrt((x * x) + (y * y));
}
