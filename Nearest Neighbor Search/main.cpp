#include<conio.h>
#include "NearestNeighbor.h"
#include "SyntheticDatasetGenerator.h"

/////////////////////////////////////////////////////////////////////////
/* Implements a brute force algorithm to calculate the nearest neighbor 
of a query point in a given set*/
/////////////////////////////////////////////////////////////////////////
Point2D* NearestNeighborSearch(std::vector<Point2D*>& buffer, Point2D *queryPoint)
{
	int minDistance = -1;
	std::vector<Point2D*>::iterator result;

	for (std::vector<Point2D*>::iterator it = buffer.begin(); it != buffer.end(); it++)
	{
		int distance = queryPoint->EuclideanDistance((*it));

		if (minDistance < 0 || distance < minDistance)
		{
			minDistance = distance;
			result = it;
		}
	}
	return (*result);
}

void DeleteBuffer(std::vector<Point2D*>& buffer)
{
	for (std::vector<Point2D*>::iterator it = buffer.begin(); it != buffer.end(); it++)
	{
		delete (*it);
	}
}
int main()
{
	std::vector<Point2D*> buffer;

	RandomData(2, 10);
	
	Point2D* point;
	int x, y;

	std::ifstream fin;
	fin.open("data.txt");

	while (1)
	{
		fin >> x >> y;
		if (fin.eof())
		{
			break;
		}
		point = new Point2D(x, y);
		buffer.push_back(point);
	}
	fin.close();

	Point2D *qPoint = new Point2D(1, 1);
	std::cout << "The nearest neighbor is :\n";
	point = NearestNeighborSearch(buffer, qPoint);
	point->Display();

	DeleteBuffer(buffer);

	_getch();

}