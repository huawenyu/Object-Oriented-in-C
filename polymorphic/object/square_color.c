// square_color.c
#include <stdio.h>
#include <stdlib.h>
#include "square_color.h"

static const char* square_color__color_v(struct square_color*);
static void square_color__dtor_v(Shape*);

static struct square_color_ops _square_color_ops = {
	.this_sz = sizeof(struct square_color),
	.color = square_color__color_v,
	.dtor = square_color__dtor_v,
};

static const char* square_color__color_v(struct square_color* this)
{
	return this->color;
}

static void square_color__dtor_v(Shape* this)
{
	free(this);
}

struct square_color *
square_color__ctor(int x, int y, int width, int height, char *color)
{
	struct square_color* this = (struct square_color*)Square__ctor(x, y, width, height, (Shape_ops*)&_square_color_ops);
	if (!this)
		return 0;
	this->color = color;
	return this;
}

const char* square_color__color(struct square_color* this)
{
	return ((struct square_color_ops*)(this->ops))->color(this);
}

