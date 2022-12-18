#include "triangle.h"
# include  < math.h >
# include  < iostream >
# include  < array >
# include  < map >

Triangle::Triangle(const Point& a, const Point& b, const Point& c, const Color& color)
{
	setA(a);
	setB(b);
	setC(c);
	this ->color = color;
}

Triangle::Triangle(const vector<Point>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);
	this->color = color;
}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);
	this->color = color;
}

Point Triangle::getA() const noexcept
{
	return a;

}
Point Triangle::getB() const noexcept
{
	return b;
}
Point Triangle::getC() const noexcept
{
	return c;
}
auto Triangle::getColor() const noexcept
{
	return color;
}
string Triangle::getColorAsString() const noexcept
{
	//PINK, RED, BLUE, WHITE, BLACK, GREEN
	{
		const map<Color, string>map = { {Triangle::Color::RED, "Red"},
	{Triangle::Color::BLUE, "Blue"},
	{Triangle::Color::WHITE, "White"},
	{Triangle::Color::BLACK, "Black"},
	{Triangle::Color::GREEN, "Green"}
		};
		auto selectedColor{ Triangle::color };
		return map.at(selectedColor);
	}
	return string();
}
double Triangle::getPerimeter() const noexcept
{
	 int x = sqrt(pow((pts[1].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[1].coords[1]) - (pts[0].coords[1]), 2));
	 int y = sqrt(pow((pts[2].coords[0]) - (pts[1].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[1].coords[1]), 2));
	 int z = sqrt(pow((pts[2].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[0].coords[1]), 2));
	return x + y + z;
	
};



bool Triangle::setA(const Point& pt)
{
	pts[0].coords[0] = pt.coords[0];
	pts[0].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::setB(const Point& pt)
{
	pts[1].coords[0] = pt.coords[0];
	pts[1].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::setC(const Point& pt)
{
	pts[2].coords[0] = pt.coords[0];
	pts[2].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::isValid() const
{
	int x = sqrt(pow((pts[1].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[1].coords[1]) - (pts[0].coords[1]), 2));
	int y = sqrt(pow((pts[2].coords[0]) - (pts[1].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[1].coords[1]), 2));
	int z = sqrt(pow((pts[2].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[0].coords[1]), 2));
	if ((x + y > z)&&( x + z > y)&&( y + z > x))
		return true;
	else
		return false;
}

double Triangle::printInfo() const noexcept
{// Ekrana þunu basar:
	/* Triangle
	   Number of points: 3
	   Points: (3.00, 4.40), (2.00, 5.00), (4.80, 5.00)
	   Primeter: 5.86
	   Color: Red
	*/
	cout<<"triangle"<<endl<<"number of points:3"<<endl<<"points:"<<"("<<a.x<<","<<a.y<<")"<<","<<"("<<b.x<<", "<<b.y<<")" << "," << "(" << c.x << "," << c.y << ")"<<endl<<"primeter:"<<getPerimeter ()<<"color:"<<getColorAsString ()<<endl;
	
}
