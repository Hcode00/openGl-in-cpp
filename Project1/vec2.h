#pragma once
#include <iostream>
#pragma once
#include <tuple>

class Vec2
{
private:
	float x, y,length;
public:
	Vec2() = default;
	Vec2(float X,float Y)
		:x(X),y(Y),length(this->Length())	{}
	float GetX() const {
		return x;
	}
	float GetY() const {
		return y;
	}
	void SetX(float newX)
	{
		x = newX;
	}
	void SetY(float newY)
	{
		x = newY;
	}
	float Length() const {
		return (float)sqrt(x * x + y * y);
	}
	Vec2 GetUnitVec() const {
		return Vec2(this->GetX()/this->Length(), this->GetY()/this->Length());
	}

	std::tuple<float, float> Point() const
	{
		return { x , y };
	}

	Vec2(const Vec2& other)
		: x(other.x), y(other.y), length(other.length) {};

	Vec2& operator=(const Vec2& other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
			length = other.length;
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Vec2& vec);

};

