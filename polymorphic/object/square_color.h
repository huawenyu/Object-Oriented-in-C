#ifndef __SQUARE_COLOR_H__
#define __SQUARE_COLOR_H__

// square.h
#include "square.h"

struct square_color;
struct square_color_ops {
	Shape_ops;
	const char *(*color)(struct square_color*);
};

struct square_color {
	struct Square;
	char *color;
};

struct square_color *square_color__ctor(int x, int y, int width, int height, char *color);
const char* square_color__color(struct square_color*);

#endif
