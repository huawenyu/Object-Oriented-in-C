// Header
typedef struct Point Point;  // forward declared for encapsulation
Point* Point__ctor(int x, int y);  // equivalent to "new Point(x, y)"
void Point__dtor(Point* self);  // equivalent to "delete point"
int Point__x(Point* self);  // equivalent to "point->x()"
int Point__y(Point* self);  // equivalent to "point->y()"
