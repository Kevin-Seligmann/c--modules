#include "Point.hpp"
#include <iostream>
#include <math.h>

float	area(Point const a, Point const b, Point const c)
{
	return fabs((a.x() * (b.y() - c.y()) + b.x() * (c.y() - a.y()) + c.x() * (a.y() - b.y())).toFloat()) / 2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float area_bcp;
	float area_acp;
	float area_abp;
	float area_abc;

	area_abc = area(a, b, c);
	area_abp = area(a, b, point);
	area_acp = area(a, c, point);
	area_bcp = area(b, c, point);

	std::cout << area_abc << " " << area_acp << " " << area_abp << " " << area_bcp << std::endl;
	if (area_abc == 0 || area_acp == 0 || area_abp == 0 || area_bcp == 0)
		return false;
	if (area_abc == area_acp + area_abp + area_bcp)
	{
		return true;
	}
	return false;
}
