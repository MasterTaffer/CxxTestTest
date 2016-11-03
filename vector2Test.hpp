#include <cxxtest/TestSuite.h>
#include "vector2.hpp"

class Vector2TestSuite : public CxxTest::TestSuite
{
public:
	void testSum()
	{
		Vector2 a;
		Vector2 b;


		a.x = 4;
		a.y = 8;

		b.x = 5; 
		b.y = 11;

		Vector2 c(a+b);

		a += b;

		TSM_ASSERT_EQUALS("Vector2 addition not correct", a.x, c.x);
		TSM_ASSERT_EQUALS("Vector2 addition not correct", a.y, c.y);
		TSM_ASSERT_EQUALS("Vector2 equality test not correct", a, c);		
	}

	void testEquality()
	{
		Vector2 a;
		Vector2 b;
		Vector2 c;

		a.x = 5;
		a.y = 98;

		b.x = 5; 
		b.y = 98;
		
		c = b;
		Vector2 d(b);
		Vector2 e = {a.x, a.y};

		TSM_ASSERT_EQUALS("Vector2 equality test not correct", a, b);
		TSM_ASSERT_EQUALS("Vector2 equality test not correct", b, c);
		TSM_ASSERT_EQUALS("Vector2 equality test not correct", c, d);
		TSM_ASSERT_EQUALS("Vector2 equality test not correct", d, e);
		TSM_ASSERT_EQUALS("Vector2 equality test not correct", e, a);
	}
	
	void testSubtract()
	{
		Vector2 a;
		Vector2 b;


		a.x = 25;
		a.y = 50;

		b.x = -90; 
		b.y = 65;

		Vector2 c = a - b;
		
		a -= b;

		TSM_ASSERT_EQUALS("Vector2 subtraction not correct", a.x, c.x);
		TSM_ASSERT_EQUALS("Vector2 subtraction not correct", a.y, c.y);
		TSM_ASSERT_EQUALS("Vector2 subtraction not correct", a.x, 25-(-90));
		TSM_ASSERT_EQUALS("Vector2 subtraction not correct", a.y, 50-65);
		TSM_ASSERT_EQUALS("Vector2 equality test not correct", a, c);
	}
	
	void testScalarMultiplication()
	{
		Vector2 a;
		a.x = 8;
		a.y = -3;
		
		Vector2 b;
		b = a;
		
		a = a * 3;
		b *= 3;
		
		TSM_ASSERT_EQUALS("Vector2 scalar multiplication not correct", a.x, b.x);
		TSM_ASSERT_EQUALS("Vector2 scalar multiplication not correct", a.y, b.y);
		TSM_ASSERT_EQUALS("Vector2 scalar multiplication not correct", a.x, 8*3);
		TSM_ASSERT_EQUALS("Vector2 scalar multiplication not correct", a.y, (-3)*3);
		TSM_ASSERT_EQUALS("Vector2 equality test not correct", a, b);
	}
	
	void testScalarDivision()
	{
		Vector2 a;
		a.x = -17653;
		a.y = 3213;
		
		Vector2 b;
		b = a;
		
		a = a / 77;
		b /= 77;
		
		TSM_ASSERT_EQUALS("Vector2 scalar division not correct", a.x, b.x);
		TSM_ASSERT_EQUALS("Vector2 scalar division not correct", a.y, b.y);
		TSM_ASSERT_EQUALS("Vector2 scalar division not correct", a.x, (-17653)/77);
		TSM_ASSERT_EQUALS("Vector2 scalar division not correct", a.y, 3213/77);
		TSM_ASSERT_EQUALS("Vector2 equality test not correct", a, b);
	}
	
	void testChainedAssignment()
	{
		Vector2 a,b,c;
		a.x = 12345;
		a.y = 6789;
		
		b.x = 223;
		b.y = 556;
		
		c = b = a;
		
		TSM_ASSERT_EQUALS("Vector2 chained assignment not correct", c.x, 12345);
		TSM_ASSERT_EQUALS("Vector2 chained assignment not correct", c.y, 6789);
		TSM_ASSERT_EQUALS("Vector2 chained assignment test not correct", a, b);
		TSM_ASSERT_EQUALS("Vector2 chained assignment test not correct", b, c);
	}
	
	void testChainedAssignmentWithOperations()
	{
		Vector2 a,b,c;
		a.x = 6;
		a.y = 7;
		
		b.x = 2;
		b.y = 3;
		
		c = b -= a *= 13;
		
		TSM_ASSERT_EQUALS("Vector2 chained assignment with operations not correct", c.x, 2 - (6*13));
		TSM_ASSERT_EQUALS("Vector2 chained assignment with operations not correct", c.y, 3 - (7*13));
		TSM_ASSERT_EQUALS("Vector2 chained assignment with operations not correct", b.x, 2 - (6*13));
		TSM_ASSERT_EQUALS("Vector2 chained assignment with operations not correct", b.y, 3 - (7*13));
		TSM_ASSERT_EQUALS("Vector2 chained assignment with operations not correct", a.x, (6*13));
		TSM_ASSERT_EQUALS("Vector2 chained assignment with operations not correct", a.y, (7*13));
	}

	void testMultiplication()
	{
		Vector2 a;
		Vector2 b;


		a.x = 99;
		a.y = 0;

		b.x = 3; 
		b.y = 66766;

		Vector2 c = a * b;
		
		a *= b;

		TSM_ASSERT_EQUALS("Vector2 multiplication not correct", a.x, c.x);
		TSM_ASSERT_EQUALS("Vector2 multiplication not correct", a.y, c.y);
		TSM_ASSERT_EQUALS("Vector2 multiplication not correct", a.x, 99*3);
		TSM_ASSERT_EQUALS("Vector2 multiplication not correct", a.y, 0*66766);
		TSM_ASSERT_EQUALS("Vector2 equality test not correct", a, c);
	}
	
		
	void testDivision()
	{
		Vector2 a;
		Vector2 b;


		a.x = 99;
		a.y = 11311;

		b.x = 5; 
		b.y = -8;

		Vector2 c = a / b;
		
		a /= b;

		TSM_ASSERT_EQUALS("Vector2 division not correct", a.x, c.x);
		TSM_ASSERT_EQUALS("Vector2 division not correct", a.y, c.y);
		TSM_ASSERT_EQUALS("Vector2 division not correct", a.x, 99/5);
		TSM_ASSERT_EQUALS("Vector2 division not correct", a.y, (11311)/(-8));
		TSM_ASSERT_EQUALS("Vector2 equality test not correct", a, c);
	}

	void testDot()
	{
		Vector2 a, b;
		a.x = 7;
		a.y = -67;
		b.x = 231;
		b.y = 1;
		int c = a.dot(b);
		int d = b.dot(a);
		TSM_ASSERT_EQUALS("Vector2 dot product not correct", c, d);
		TSM_ASSERT_EQUALS("Vector2 dot product not correct", c, (7*231)+(-67*1));
	}
};
