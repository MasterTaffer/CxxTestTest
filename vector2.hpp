#pragma once

struct Vector2
{
	int x,y;

	Vector2()
	{

	}
	Vector2(int x, int y)
	: x(x), y(y)
	{
	}
	
	Vector2(const Vector2& b)
	: x(b.x), y(b.y)
	{
	}

	Vector2	operator+(const Vector2& b) const
	{
		return Vector2(x+b.x, y+b.y);
	}
	Vector2 operator-(const Vector2& b) const
        {
                return Vector2(x+b.x, y-b.y);
        }
	Vector2 operator*(const Vector2& b) const
        {
                return Vector2(x*b.x, y*b.y);
        }
	Vector2 operator/(const Vector2& b) const
        {
                return Vector2(x/b.x, y/b.y);
        }

	Vector2 operator*(const int b) const
	{
		return Vector2(x*b,y*b);
	}

	Vector2 operator/(const int b) const
        {
                return Vector2(x/b,y/b);
        }

	Vector2& operator+=(const Vector2& b)
        {
		x = x + b.x;
		y = y + b.y;
                return *this;
        }
	Vector2& operator-=(const Vector2& b)
        {
                x = x - b.x;
                y = y - b.y;
                return *this;
        }
	Vector2& operator*=(const Vector2& b)
        {
                x = x * b.x;
                y = y * b.y;
                return *this;
        }
	Vector2& operator/=(const Vector2& b)
        {
                x = x / b.x;
                y = y / b.y;
                return *this;
        }
	Vector2& operator*=(const int b)
        {
                x = x * b;
                y = y * b;
                return *this;
        }
        Vector2& operator/=(const int b)
        {
                x = x / b;
                y = y / b;
                return *this;
        }

	bool operator==(const Vector2& b) const
	{
		return (x==b.x)&&(y==b.y);
	}


	int dot(const Vector2& b) const
	{
		return (x*b.x) + (y*b.y);
	}
};
