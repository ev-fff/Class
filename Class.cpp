#include <stdio.h>
#include <math.h>

struct point {
    double x, y;
};

class circle {

    double x, y, r;

    public:
    circle(double ax, double ay, double ar);
    circle(point p, double ar);
    circle(const circle& c);

    double getX() { return x; }
    void setX(double ax) { x = ax; }

    double getY() { return y; }
    void setY(double ay) { y = ay; }

    double getR() { return r; }
    void setR(double ar) { r = fabs(ar); }

    void pr();

    int in_circle(double ax, double ay);
    int in_circle(point p);
    void move_circle(struct point p);

};

