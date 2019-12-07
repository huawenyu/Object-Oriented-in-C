// shape.c
#include <stdlib.h>
#include "shape.h"

static Shape_ops shape_ops = {
	.this_sz = sizeof(Shape),
	.name = Shape__name,
	.sides = Shape__sides,
	.dtor = Shape__dtor,
};

Shape* Shape__ctor(Shape_ops* ops)
{
	Shape* this;
	return OBJ_NEW(this, &shape_ops, ops);
}

const char* Shape__name(Shape* this)
{
	return this->name;
}

int Shape__sides(Shape* this)
{
	return this->ops->sides(this);
}

void Shape__dtor(Shape* shape)
{
	if (shape) {
		shape->ops->dtor(shape);
	}
}

