#include <iostream>
#include <stdlib.h>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(int argc, char **argv) {
	if (argc != 9)
	{
		std::cout << "./bsp Ax Ay Bx By Cx Cy Zx Zy" << std::endl;
		return 1;
	}

	bool ans = bsp( \
		Point(atof(argv[1]), atof(argv[2])), \
		Point(atof(argv[3]), atof(argv[4])), \
		Point(atof(argv[5]), atof(argv[6])), \
		Point(atof(argv[7]), atof(argv[8])));

	if (ans)
		std::cout << "Z is inside the ABC triangle" << std::endl;
	else
		std::cout << "Z is not inside the ABC triangle, or the triangle doesn't exists" << std::endl;

	return (0);
}
