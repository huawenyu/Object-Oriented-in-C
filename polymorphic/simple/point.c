// Source file
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
	int x;
	int y;
} Point;

// Constructor (without allocation)
void Point__init(Point *this, int x, int y)
{
	this->x = x;
	this->y = y;
}

// Allocation + initialization (equivalent to "new Point(x, y)")
Point* Point__ctor(int x, int y)
{
	Point *this = (Point*) malloc(sizeof(Point));
	Point__init(this, x, y);
	return this;
}

// Destructor (without deallocation)
void Point__reset(Point *this)
{
}

// Destructor + deallocation (equivalent to "delete point")
void Point__dtor(Point *this)
{
	if (this) {
		Point__reset(this);
		free(this);
	}
}

// Equivalent to "Point::x()" in C++ version
int Point__x(Point *this)
{
	return this->x;
}

// Equivalent to "Point::y()" in C++ version
int Point__y(Point *this)
{
	return this->y;
}

