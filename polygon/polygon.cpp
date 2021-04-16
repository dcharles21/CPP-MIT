#include <iostream>
#include <math.h>
#include "polygon.h"
using namespace std;

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int a, int b)
{
    x = a;
    y = b;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(int a)
{
    x = a;
}

void Point::setY(int b)
{
    y = b;
}

void Point::printpoint()
{
    cout << "(" << x << "," << y << ") ";
}

PointArray::PointArray()
{
    data = new Point[0];
}

PointArray::PointArray(Point points[], int size)
{
    data = new Point[size];
    this -> size = size;

    for(int i = 0; i < size; i++)
    {
        data[i] = points[i];                                         
    }        
}

PointArray:: PointArray(PointArray &o)
{        
    size = o.size;
    data = new Point[size];

    for(int i = 0; i < size; i++)
    {
        data[i] = o.data[i];
    } 
}

PointArray::~PointArray() 
{
    delete[] data;
}

void PointArray::printpointarray()
{
    for(int i = 0; i < size; i++)
    {
        data[i].printpoint();
    } 

}

void PointArray::resize(int n)
{
    Point *new_data;
    size = n;
    new_data = new Point[size];

    for(int i = 0; i < n; i++)
    {
        new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;

}

void PointArray::push_back(const Point &p)
{
    size += 1;
    resize(size);
    data[size - 1] = p;
}

void PointArray::insert(const int pos, const Point &p)
{
    size += 1;
    resize(size);      

    for(int i = size - 1; i >= pos + 1; i--)
    {
        data[i] = data[i - 1];
    }

    data[pos] = p;
}

void PointArray::remove(const int pos)
{
    for(int i = pos; i < size; i++)
    {
        data[i] = data[i + 1];
    }

    size -= 1;
    resize(size);

}

const int PointArray::getSize() const 
{
    return size;
}

void PointArray::clear()
{
    size = 0;
    resize(size);        
}

Point* PointArray::get(const int pos)
{
    Point *p;
    p = &data[pos];

    return p;    
}

const Point* PointArray::get(const int pos) const
{
    Point *p;
    p = &data[pos];

    return p;        
} 

Polygon::Polygon(PointArray arr, int size) : points(arr)
{
    ++polygons;               
}

Polygon::~Polygon() 
{
    --polygons;
}

int Polygon::getNumPolygons()
{
    return polygons;
}

int Polygon::getNumSides()
{
    return points.getSize();
}

const PointArray* Polygon::getPoints()
{
    PointArray *p;
    p = &points;

    return p;
}   

void Polygon::printAttributes()
{
    cout << "The points of my polygon are: ";
    this -> points.printpointarray();     
    cout << endl;
    cout << "Area of my polygon is: " << this -> area() << endl;
}

int Polygon::polygons = 0;

Rectangle::Rectangle(PointArray arr, int size) : Polygon(arr, size)
{
    // Takes PointArrays of size 2 or 4
    // If using PointArrays of size 2 assumes [lower_left, upper_right] order 
    // If using PointArrays of size 4 assumes [lower_left, upper_right, lower_right, upper_left] order

    if (size != 2 && size != 4)
    {
        throw (size);
    }

    if (size == 4) 
    {
        lower_left = *points.get(0);
        upper_right = *points.get(1);

        lower_right = *points.get(2);        
        upper_left = *points.get(3);        
    }

    else if (size == 2)
    {
        lower_left = *points.get(0);
        upper_right = *points.get(1);

        lower_right = Point(upper_right.getX(), lower_left.getY());
        upper_left = Point(lower_left.getX(), upper_right.getY());
    }

    else
    {
        throw (size);
    }

    width = abs(upper_right.getX() - lower_left.getX());
    height = abs(upper_right.getY() - lower_left.getY());
}

double Rectangle::area()
{
    return width*height;
}

Triangle::Triangle(PointArray arr, int size) : Polygon(arr, size) 
{
    // Takes PointArrays of size 3
    // Assumes [top, left, right] order in PointArray 
    
    if (size != 3)
    {
        throw (size);
    }

    else 
    {
        top = *points.get(0);
        left = *points.get(1);
        right = *points.get(2);              
    }
}

double Triangle::distance(Point p1, Point p2) 
{
    double D;
    D = sqrt(pow((p2.getX() - p1.getX()), 2) + pow((p2.getY() - p1.getY()), 2));
    return D;
}

double Triangle::area() 
{
    a = distance(top, left);
    b = distance(left, right);
    c = distance(top, right);

    s = (a + b + c)/2;
    K = sqrt(s*(s-a)*(s-b)*(s-c));
    
    return K;
}
