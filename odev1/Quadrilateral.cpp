#include "Quadrilateral.h"
#include <map>
Quadrilateral::Quadrilateral(const Point& a, const Point& c, const Color& color)
{
	setA(a);
	setC(c);
	this->color = color;


}

Quadrilateral::Quadrilateral(const Point& a, double width, double height, const Color& color)
{
	pts[1].coords[0] = pts[0].coords[0] + width;   //b nin x i
	pts[1].coords[1] = pts[0].coords[0];         //b nin y si

	pts[2].coords[0] = pts[0].coords[0] + width; //c nin x i
	pts[2].coords[1] = pts[0].coords[1] - height; //c nin y si

	pts[3].coords[0] = pts[0].coords[0];         //d nin x i
	pts[3].coords[1] = pts[0].coords[1] - height;  //d nin y si
	this->color = color;
}

Quadrilateral::Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d, const Color& color)
{
	setA(a);
	setB(b);
	setC(c);
	setD(d);
	this->color = color;
}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);
	setD(pts[3]);

	this->color = color;
}

Point Quadrilateral::getA() const noexcept
{
	return a;
}

Point Quadrilateral::getB() const noexcept
{
	return b;
}

Point Quadrilateral::getC() const noexcept
{
	return c;
}

Point Quadrilateral::getD() const noexcept
{
	return Point();
}

auto  Quadrilateral::getColor() const noexcept
{
	return color;
}

string Quadrilateral::getColorAsString() const noexcept
{
	const map<Quadrilateral::Color, string>colorToStringMap = { {Quadrilateral::Color::RED, "Red"},
	{Quadrilateral::Color::BLUE, "Blue"},
	{Quadrilateral::Color::WHITE, "White"},
	{Quadrilateral::Color::BLACK, "Black"},
	{Quadrilateral::Color::GREEN, "Green"}
	};
}

double Quadrilateral::getPerimeter() const noexcept
{
	int x = sqrt(pow((pts[1].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[1].coords[1]) - (pts[0].coords[1]), 2));
	int y = sqrt(pow((pts[2].coords[3]) - (pts[1].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[1].coords[1]), 2));
	int z = sqrt(pow((pts[2].coords[3]) - (pts[0].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[0].coords[1]), 2));
	int t=  sqrt(pow((pts[2].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[0].coords[1]), 2));
}

bool Quadrilateral::isValid() const
{
	if ((a.x = b.x && a.x == c.x) || (a.x == b.x && a.x == d.x) || (b.x = a.x && b.x == c.x) || (b.x == a.x && b.x == d.x)||(c.x = b.x && c.x == d.x) || (d
		.x == b.x && d.x == c.x) || (d.x = b.x && d.x == a.x) )
		return false;
	else
		return true;

}

bool Quadrilateral::setA(const Point& pt)
{
	pts[0].coords[0] = pt.coords[0];
	pts[0].coords[1] = pt.coords[1];
	return false;
	
}

bool Quadrilateral::setB(const Point& pt)
{
	pts[1].coords[0] = pt.coords[0];
	pts[1].coords[1] = pt.coords[1];
	return false;
}

bool Quadrilateral::setC(const Point& pt)
{
	pts[2].coords[0] = pt.coords[0];
	pts[2].coords[1] = pt.coords[1];
	return false;
}

bool Quadrilateral::setD(const Point& pt)
{
	pts[3].coords[0] = pt.coords[0];
	pts[3].coords[1] = pt.coords[1];
	return false;
}

double Quadrilateral::printInfo() const noexcept
{
	cout << "Quadrilateral" << endl << "Number of points: 4" << endl << "Points: " << "(" << a.x << "," << a.y << ")" << "(" << b.x << "," << b.y << ")" << "(" << c.x << "," << c.y << ")" << "(" << d.x << "," << d.y << ")" << endl << "Perimeter: " << getPerimeter() << endl << "Color: " << getColorAsString() << endl;



}


