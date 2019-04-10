#include "stdio.h"
#include "point.h"

int main(int argc, char const* argv[])
{
	Point *p = Point__ctor(123, 456);
	printf("x=%d, y=%d\n", Point__x(p), Point__y(p));
	return 0;
}
