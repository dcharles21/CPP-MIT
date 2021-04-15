#include <iostream>
#include "polygon.h"
using namespace std;

int main()
{
    // Rectangle Example
    // Assumes [lower_left, upper_right] or [lower_left, upper_right, lower_right, upper_left] in PointArray
    Point myarray[4];

    myarray[0] = Point (0,0);
    myarray[1] = Point (5,3);
    myarray[2] = Point (5,0);
    myarray[3] = Point (0,3);

    PointArray myparray(myarray, 4);
    Rectangle rect(myparray, 4);
    rect.printAttributes();

    // Triangle Example
    // Assumes [top, left, right] in PointArray     
    Point myarray2[3];

    myarray2[0] = Point (2,11);
    myarray2[1] = Point (0,0);
    myarray2[2] = Point (4,0);
    
    PointArray myparray2(myarray2, 3);
    Triangle tri(myparray2, 3);
    tri.printAttributes();
    
    // Test Polygon out of bounds of array
    // Note Change to size of PointArray not size int
    try 
    {
        Rectangle rect2(myparray2, 3);
        // Triangle tri2(myparray, 4);
    }

    catch(int size) 
    {
        cout << "Out of Bounds of Array. Current Array Size: " << size << endl;
    }
}