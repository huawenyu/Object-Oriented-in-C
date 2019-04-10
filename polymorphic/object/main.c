#include "stdio.h"
#include "square.h"
#include "square_color.h"

int main(int argc, char const* argv[])
{
	{
		Square *p;

		p = Square__ctor(123, 456, 11, 44, 0);
		if (!p)
			return 1;

		printf("members: x=%d, y=%d, width=%d, height=%d\n",
		       Square__x(p), Square__y(p), Square__width(p), Square__height(p));

		printf("virtual-members: name=%s sides=%d\n",
		       Shape__name((Shape*)p), Shape__sides((Shape*)p));

		Shape__dtor((Shape*)p);
	}


	{
		struct square_color *color;
		struct Square *p;

		color = square_color__ctor(123, 456, 11, 44, "blue");
		if (!color)
			return 1;
		p = (struct Square *)color;
		printf("members: x=%d, y=%d, width=%d, height=%d\n",
		       Square__x(p), Square__y(p), Square__width(p), Square__height(p));

		printf("virtual-members: name=%s sides=%d color=%s\n",
		       Shape__name((Shape*)p), Shape__sides((Shape*)p),
		       square_color__color(color));

		Shape__dtor((Shape*)color);
	}


	return 0;
}
