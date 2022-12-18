#include <iostream>
#include <vector>
#include <random>
#include "Triangle.h"
#include "Quadrilateral.h"
#include "point.h"
#include <ctime>


using namespace std;

// Rastgele olarak Triangle nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Triangle nesnelerinde yer alacak noktaların x ve y değerleri [0, 100] arasında olabilir.
   Şeklin renk değeri de rastgele olarak belirlenmelidir.
*/
void fillTriangles(vector<Triangle>& v, int numberOfItems = 100)
{
	for (size_t i{ 0 }; i < numberOfItems; ++i)
	{
		default_random_engine engine(static_cast<unsigned int>(time(0)));
		uniform_int_distribution<unsigned int>randomint(0, 6);

		random_device rd;
		auto mt = mt19937(rd());
		auto dist = uniform_int<int>(0, 100);
		int a = dist(mt);
		int b = dist(mt);
		int c = dist(mt);
		int d = dist(mt);
		int e = dist(mt);
		int f = dist(mt);

		int color = randomint(engine);
		v[i].getColor() = color;
		
		v.push_back(Triangle { Point(a,b),Point(c,d),Point(e,f),color });

	}
	


}

// Rastgele olarak Quadrilateral nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Quadrilateral nesnelerinde yer alacak noktaların x ve y değerleri [0, 100] arasında olabilir.
   Şeklin renk değeri de rastgele olarak belirlenmelidir.
*/
void fillQuads(vector<Quadrilateral>& v, int numberOfItems = 100)
{
	for (size_t i{ 0 }; i < numberOfItems; ++i)
	{
		default_random_engine engine(static_cast<unsigned int>(time(0)));
		uniform_int_distribution<unsigned int>randomint(0, 6);

		random_device rd;
		auto mt = mt19937(rd());
		auto dist = uniform_int<int>(0, 100);
		int a = dist(mt);
		int b = dist(mt);
		int c = dist(mt);
		int d = dist(mt);
		int e = dist(mt);
		int f = dist(mt);
		int h = dist(mt);
		int g = dist(mt);

		v.push_back(Quadrilateral{ Point(a,b),Point(c,d),Point(e,f),Point(h,g) });


}


/* Verilen Triangle veya Rectangle vektörününde çevre uzunluğu ve renk değeri eşleşen ilk elemanın indeksini döndürür.
Eleman bulunamazsa -1 döndürülür.*/
template<class T>
int search(const vector<T>& v, const T& key)
{

}


template<class T>
int sortByPerimeter(vector<T>& v)
{


}


int main()
{

	// Point class test
	auto p = Point{ 4.5, 6.2 };

	cout << p.x << " " << p.y << endl;
	cout << p.coords[0] << " " << p.coords[1] << endl;

	// Sample Quad and Triangle Objects
	auto sampleQuad = Quadrilateral{ Point(4, 5), 20, 20 };
	cout << "Color of Sample Quad:" << sampleQuad.getColorAsString() << endl;

	auto sampleTriangle = Triangle{ Point(4, 5),  Point(9, 5),  Point(14, 15) };
	cout << "Color of Sample Triangle:" << sampleTriangle.getColorAsString() << endl;


	// Filling vectors randomly
	auto vectorOfQuads = vector<Quadrilateral>{};
	auto vectorOfTriangles = vector<Triangle>{};

	fillTriangles(vectorOfTriangles);
	fillQuads(vectorOfQuads);

	// Search sample objects in the corresponding vectors
	cout << "Searching a triangle...\n";
	cout << sampleTriangle.printInfo() << endl;
	if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;

	cout << "Searching a quadrilateral...\n";
	cout << sampleQuad.printInfo() << endl;
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;


	// Add sample Triangle object to the vector and sort the vector
	vectorOfTriangles.push_back(sampleTriangle);
	sortByPerimeter(vectorOfTriangles);


	// Search sample item again. Now, you must have a hit.
	cout << "Searching a triangle...\n";
	cout << sampleTriangle.printInfo() << endl;
	if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;



	// Add sample Quad object to the vector and sort the vector
	vectorOfQuads.push_back(sampleQuad);
	sortByPerimeter(vectorOfQuads);

	// Search sample item again. Now, you must have a hit.
	cout << "Searching a quadrilateral...\n";
	cout << sampleQuad.printInfo() << endl;
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;


	// Invalid cases
	try
	{
		auto invalidTriangle1 = Triangle{ Point{4, 0},  Point{9, 0},  Point{14, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle2 = Triangle{ Point{4, 4},  Point{4, 4},  Point{4, 4} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle3 = Triangle{ Point{4, 0},  Point{4, 4},  Point{4, 14} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad2 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{3, 20}, Point{10, 20} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}

	return 0;
}