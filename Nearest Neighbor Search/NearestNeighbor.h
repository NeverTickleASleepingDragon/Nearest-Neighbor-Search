#include<vector>
#include<iostream>

////////////////////////////////////////////////////////////////////////////////////////
/* Point2D is a class of 2 dimensional points that can used to represent spatial data */
////////////////////////////////////////////////////////////////////////////////////////

class Point2D
{
	int x;
	int y;
public:
	Point2D(){}
	Point2D(int, int);
	const int operator[](int) const;
	int EuclideanDistance(Point2D*);
	void Display();
};