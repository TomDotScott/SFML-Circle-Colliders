#pragma once
#include <iostream>

class Vector2
{
public:
	float x;
	float y;
	Vector2();
	Vector2(float xin, float yin);
	void Normalise();
	float Length() const;


	Vector2& operator += (const Vector2& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vector2& operator -= (const Vector2& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
};

inline std::ostream& operator << (std::ostream &os, const Vector2& v) {
	//std::cout 
	os << v.x << " " << v.y;
	return os;
}

inline Vector2 operator +(Vector2 lhs, const Vector2& rhs) {
	lhs += rhs;
	return lhs;
}

inline Vector2 operator -(Vector2 lhs, const Vector2& rhs) {
	lhs -= rhs;
	return lhs;
}
