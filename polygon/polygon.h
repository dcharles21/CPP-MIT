#ifndef POLYGON_H
#define POLYGON_H

class Point 
{
private:
   int x, y;

public:
   Point();

   Point(int x, int y);

   int getX() const;

   int getY() const;

   void setX(int x);

   void setY(int y);

   void printpoint();
};

class PointArray
{
private:
   int size;
   Point *data;    

public:
   PointArray();

   PointArray(Point points[], int size);
   
   PointArray(PointArray &o);

   ~PointArray(); 
   
   void printpointarray();
   
   void resize(int n);
   
   void push_back(const Point &p);
   
   void insert(const int pos, const Point &p);
   
   void remove(const int pos);
   
   const int getSize() const; 
   
   void clear();
   
   Point* get(const int pos);
   
   const Point* get(const int pos) const;
   
};

class Polygon
{
protected:
   PointArray points;
   static int polygons;
   

public:
   Polygon(PointArray arr, int size);
   
   ~Polygon(); 

   int getNumPolygons();
   
   int getNumSides();
   
   const PointArray* getPoints();   

   virtual double area() = 0;

   void printAttributes();
      
};

// int Polygon::polygons = 0;

class Rectangle : public Polygon
{
private:
   int width, height; 
   Point lower_left, lower_right, upper_left, upper_right;

public:
   Rectangle(PointArray arr, int size);   

   double area();   
      
};

class Triangle : public Polygon
{
private:
   double a, b, c, s, K;
   Point top, left, right;

public:
   Triangle(PointArray arr, int size);

   double distance(Point p1, Point p2);

   double area();

};

#endif // POLYGON_H