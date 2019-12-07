#ifndef __SQUARE_H__
#define __SQUARE_H__

// square.h
#include "shape.h"

typedef struct Square {
	struct Shape;

	int x;
	int y;
	int width;
	int height;
} Square;

Square* Square__from_shape(Shape* shape);
Square* Square__ctor(int x, int y, int width, int height, Shape_ops*);

int Square__x(Square*);
int Square__y(Square*);
int Square__width(Square*);
int Square__height(Square*);

#endif
