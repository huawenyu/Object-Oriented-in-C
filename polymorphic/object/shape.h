#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "object.h"

typedef struct Shape Shape;
typedef struct Shape_ops Shape_ops;

struct Shape {
	Shape_ops* ops;
	char name[32];
	char data[0];
};

struct Shape_ops {
	uintptr_t this_sz; /* beginwith 'this_sz' */

	const char* (*name)(Shape*);
	int (*sides)(Shape*);
	void (*dtor)(Shape*);
};

Shape* Shape__ctor(Shape_ops* ops);
const char* Shape__name(Shape* this);
int Shape__sides(Shape* self);
void Shape__dtor(Shape* shape);

#endif

