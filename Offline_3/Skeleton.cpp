#include <iostream>
// your code
#include<stdlib.h>
#include<cmath>
#define Pi 3.1416
using namespace std;

class Point2D
{
    double x, y;

public:
    Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void print();
    ~Point2D();
    // your code
    // Point2D operators

    friend Point2D operator+(Point2D &A, Point2D &B);
    friend Point2D operator*(Point2D &A, double n);
    friend bool operator==(Point2D &A, Point2D &B);
    friend bool operator!=(Point2D &A, Point2D &B);
};

Point2D::Point2D(double argx, double argy)
{
    x = argx;
    y = argy;
}

void Point2D::setX(double argx)
{
    x = argx;
}

void Point2D::setY(double argy)
{
    y = argy;
}

double Point2D::getX()
{
    return x;
}

double Point2D::getY()
{
    return y;
}

void Point2D::print()
{
    cout << "(" << x << "," << y << ")";
}

Point2D::~Point2D()
{
    x = 0;
    y = 0;
}

// your code

// Point2D operators

Point2D operator+(Point2D &A, Point2D &B)
{

    Point2D C;
    C.x = A.x + B.x;
    C.y = A.y + B.y;
    return C;
}

Point2D operator*(Point2D &A, double n)
{

    Point2D B;
    B.x = A.x * n;
    B.y = A.y * n;
    return B;
}

bool operator==(Point2D &A, Point2D &B)
{

    if (A.x == B.x && A.y == B.y)
        return true;
    return false;
}

bool operator!=(Point2D &A, Point2D &B)
{

    if (A.x != B.x || A.y != B.y)
        return true;
    return false;
}

class Circle
{
    Point2D center;
    double radius;

public:
    Circle();
    Circle(Point2D c, double r);
    void setCenter(Point2D c);
    void setRadius(double r);
    Point2D getCenter();
    double getRadius();
    void print();
    ~Circle();
    // your code
    // circle oprators

    friend Circle operator+(Circle &C, Point2D &P);
    friend Circle operator*(Circle &C, double n);
    friend Circle operator+(Circle &C1, Circle &C2);
    friend Circle operator-(Circle &C1, Circle &C2);
    friend bool operator==(Circle &C1, Circle &C2);
    friend bool operator>(Circle &C1, Circle &C2);
    friend bool operator>=(Circle &C1, Circle &C2);
    friend bool operator<(Circle &C1, Circle &C2);
    friend bool operator<=(Circle &C1, Circle &C2);
    Circle operator++();
    Circle operator++(int unused);
};

Circle::Circle()
{
    center.setX(0);
    center.setY(0);
    radius = 0;
}

Circle::Circle(Point2D c, double r)
{
    center.setX(c.getX());
    center.setY(c.getY());
    radius = r;
}

void Circle::setCenter(Point2D c)
{
    center.setX(c.getX());
    center.setY(c.getY());
}

void Circle::setRadius(double r)
{
    radius = r;
}
Point2D Circle::getCenter()
{
    return center;
}
double Circle::getRadius()
{
    return radius;
}

void Circle::print()
{
    cout << "[Center: ";
    center.print();
    cout << " Radius: " << radius;
    cout << "]"<<endl;
}

Circle::~Circle()
{
    center.setX(0);
    center.setY(0);
    radius = 0;
}

// your code

Circle Circle:: operator++(int unused){

    Circle C=*this;
    radius++;
    return C;

}

Circle Circle:: operator++(){

    ++radius;
    return *this;

}
// Circle operators

Circle operator+(Circle &C, Point2D &P){

    Circle C1=C;
    C1.center=C.center+P;
    return C1;
}

Circle operator*(Circle &C, double n){

    Circle C1;
    C1.center=C.center*n;
    C1.radius=C.radius*n;
    return C1;
}

Circle operator+(Circle &C1, Circle &C2){

    Circle C;
    double a=C1.radius/(C1.radius+C2.radius);
    C.radius=C1.radius+C2.radius;
    //C1.center=(C1.center*a)+(C2.center*(1-a));
    Circle C3,C4;
    C3.center=C1.center*a;
    C4.center=C2.center*(1-a);
    C.center=C3.center+C4.center;
    return C;


}

Circle operator-(Circle &C1, Circle &C2){

    Circle C;
    double a=C1.radius/(C1.radius+C2.radius);
    C.radius=fabs(C1.radius-C2.radius);
    //C1.center=(C1.center*a)+(C2.center*(1-a));
    Circle C3,C4;
    C3.center=C1.center*a;
    C4.center=C2.center*(1-a);
    C.center=C3.center+C4.center;
    return C;


}

bool operator==(Circle &C1, Circle &C2){

    double A1,A2;
    A1=Pi*C1.radius*C1.radius;
    A2=Pi*C2.radius*C2.radius;
    if(A1==A2)return true;
    else return false;

}

bool operator>(Circle &C1, Circle &C2){

    double A1,A2;
    A1=Pi*C1.radius*C1.radius;
    A2=Pi*C2.radius*C2.radius;
    if(A1>A2)return true;
    else return false;

}

bool operator>=(Circle &C1, Circle &C2){

    double A1,A2;
    A1=Pi*C1.radius*C1.radius;
    A2=Pi*C2.radius*C2.radius;
    if(A1>=A2)return true;
    else return false;

}

bool operator<(Circle &C1, Circle &C2){

    double A1,A2;
    A1=Pi*C1.radius*C1.radius;
    A2=Pi*C2.radius*C2.radius;
    if(A1<A2)return true;
    else return false;

}

bool operator<=(Circle &C1, Circle &C2){

    double A1,A2;
    A1=Pi*C1.radius*C1.radius;
    A2=Pi*C2.radius*C2.radius;
    if(A1<=A2)return true;
    else return false;

}




class Rectangle
{
    Point2D topRightPoint, bottomLeftPoint;

public:
    Rectangle();
    Rectangle(Point2D oneCorner, Point2D anotherCorner);
    void setTopRightPoint(Point2D oneCorner);
    void setbottomLeftPoint(Point2D anotherCorner);
    Point2D getTopRightPoint();
    Point2D getBottomLeftPoint();
    void print();
    ~Rectangle();
    // your code

    // Rectangle operators

    friend Rectangle operator+(Rectangle &R, Point2D &P);
    friend Rectangle operator*(Rectangle &R, double n);
};

Rectangle::Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}
Rectangle::Rectangle(Point2D oneCorner, Point2D anotherCorner)
{
    topRightPoint = oneCorner;
    bottomLeftPoint = anotherCorner;
}

void Rectangle::setTopRightPoint(Point2D oneCorner)
{
    topRightPoint = oneCorner;
}
void Rectangle::setbottomLeftPoint(Point2D anotherCorner)
{
    bottomLeftPoint = anotherCorner;
}
Point2D Rectangle::getTopRightPoint()
{
    return topRightPoint;
}
Point2D Rectangle::getBottomLeftPoint()
{
    return bottomLeftPoint;
}

void Rectangle::print()
{
    cout << "[Top Right Point: ";
    topRightPoint.print();
    cout << "  Bottom left Point: ";
    bottomLeftPoint.print();
    cout << "]"<<endl;
}
Rectangle::~Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}

// your code

// Rectangle operators

Rectangle operator+(Rectangle &R, Point2D &P)
{

    Rectangle R1;
    R1.bottomLeftPoint = R.bottomLeftPoint + P;
    R1.topRightPoint = R.topRightPoint + P;
    return R1;
}

Rectangle operator*(Rectangle &R, double n)
{

    Rectangle R1;
    R1.bottomLeftPoint = R.bottomLeftPoint * n;
    R1.topRightPoint = R.topRightPoint * n;
    return R1;
}

int main()
{
    // Create Point2D objects
    Point2D p1(5, 10);
    Point2D p2(15, 10);
    Point2D p3;

    // Create Circle objects
    Circle c1(p1, 10);
    Circle c2;
    Circle c3;

    // Create Rectangle objects
    Rectangle r1(p1, p2);
    Rectangle r2;

    // Perform operations and print the results

    // Point2D operations
    cout<<"Point2D operations:"<<endl;
    cout<<endl;
    cout<<"p1: ";
    //cout<<endl;
    p1.print();
    cout<<endl;
    cout<<endl;
    cout<<"p2: ";
    //cout<<endl;
    p2.print();
    cout<<endl;
    cout<<endl;

    cout<<"1. + Operation:"<<endl;
    cout<<endl;
    p3 = p1 + p2;
    cout << "p1 + p2: ";
    //cout<<endl;
    p3.print();
    cout << endl;
    cout<<endl;
    //p1.print();

    cout<<"2. * Operation:"<<endl;
    cout<<endl;
    p3 = p1 * 2.5;
    cout << "p1 * 2.5: ";
    //cout<<endl;
    p3.print();
    cout << endl;
    cout<<endl;

    cout<<"3. == Operation:"<<endl;
    cout<<endl;
    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout<<endl;

    cout<<"4. != Operation:"<<endl;
    cout<<endl;
    cout << "p1 != p2: " << (p1 != p2) << endl;
    cout<<endl;
    cout<<"*********+**********"<<endl;
    cout<<endl;

    // Circle operations

    cout<<"Circle operations:"<<endl;
    cout<<endl;
    cout<<"c1: ";
    c1.print();
    cout<<endl<<endl;
    // cout<<"c2: ";
    // c2.print();

    cout<<"1. + Operation:"<<endl;
    c2 = c1 + p2;
    cout<<endl;
    cout << "c1 + p2: ";
    //cout<<endl;
    c2.print();
    cout << endl;
    cout<<endl;

    cout<<"2. * Operation:"<<endl;
    cout<<endl;
    c3 = c1 * 1.5;
    cout << "c1 * 1.5: ";
    //cout<<endl;
    c3.print();
    cout << endl;
    cout<<endl;

    cout<<"3. + Operation:"<<endl;
    cout<<endl;
    c3 = c1 + c2;
    cout << "c1 + c2: ";
    //cout<<endl;
    c3.print();
    cout << endl;
    cout<<endl;

    cout<<"4. - Operation:"<<endl;
    cout<<endl;
    c3 = c1 - c2;
    cout << "c1 - c2: ";
    //cout<<endl;
    c3.print();
    cout << endl;
    cout<<endl;

    cout<<"5. ++ Operation:"<<endl;
    cout<<endl;
    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout<<endl;

    cout<<"6. > Operation:"<<endl;
    cout<<endl;
    cout << "c1 > c2: " << (c1 > c2) << endl;
    cout<<endl;

    cout<<"7. >= Operation:"<<endl;
    cout<<endl;
    cout << "c1 >= c2: " << (c1 >= c2) << endl;
    cout<<endl;

    cout<<"8. < Operation:"<<endl;
    cout<<endl;
    cout << "c1 < c2: " << (c1 < c2) << endl;
    cout<<endl;

    cout<<"9. <= Operation:"<<endl;
    cout<<endl;
    cout << "c1 <= c2: " << (c1 <= c2) << endl;
    cout<<endl;

    cout<<"10. ++(pre-increment) Operation:"<<endl;
    cout<<endl;
    ++c1;
    cout << "++c1: ";
    //cout<<endl;
    c1.print();
    cout << endl;
    cout<<endl;

    cout<<"11. ++(post-increment) Operation:"<<endl;
    cout<<endl;
    c2 = c1++;
    cout << "c2 = c1++: "<<endl;
    cout<<endl;
    cout<<"c1: ";
    c1.print();
    cout<<endl;
    cout<<"c2: ";
    c2.print();
    cout << endl;
    cout<<endl;
    cout<<"*********+**********"<<endl;
    cout<<endl;

    // Rectangle operations

    cout<<"Rectangle operations: "<<endl;
    cout<<endl;
    cout<<"r1: ";
    //cout<<endl;
    r1.print();
    cout<<endl;
    cout<<endl;

    cout<<"1. + Operation: "<<endl;
    cout<<endl;
    r2 = r1 + p2;
    cout << "r1 + p2: ";
    //cout<<endl;
    r2.print();
    cout << endl;
    cout<<endl;

    cout<<"2. * Operation: "<<endl;
    cout<<endl;
    r2 = r1 * 1.5;
    cout << "r1 * 1.5: ";
    //cout<<endl;
    r2.print();
    cout << endl;
    cout<<endl;

    return 0;
}
