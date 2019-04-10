// square.c
#include <stdio.h>
#include <stdlib.h>
#include "square.h"

static int Square__sides_v(Shape*);
static void Square__dtor_v(Shape*);

static Shape_ops square_ops = {
	.this_sz = sizeof(Square),
	.sides = Square__sides_v,
	.dtor = Square__dtor_v,
};

static int Square__sides_v(Shape* this)
{
	return 4;
}

static void Square__dtor_v(Shape* this)
{
	free(this);
}

Square* Square__from_shape(Shape* shape)
{
	if (!shape)
		return ((Square*) 0);

	if (shape->ops != &square_ops) {
		return ((Square*) 0);
	}

	return ((Square*) shape);
}

Square* Square__ctor(int x, int y, int width, int height, Shape_ops *ops)
{
	Square* this = (Square*) Shape__ctor(&square_ops);
	if (!this)
		return 0;
	OBJ_NEW(this, this->ops, ops);
	snprintf(this->name, sizeof(this->name), "Square");
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	return this;
}

int Square__x(Square* this)
{
	return this->x;
}

int Square__y(Square* this)
{
	return this->y;
}

int Square__width(Square* this)
{
	return this->width;
}

int Square__height(Square* this)
{
	return this->height;
}

