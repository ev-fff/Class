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

circle::circle(double ax, double ay, double ar) {
    x = ax;
    y = ay;
    r = fabs(ar);   
}

circle::circle(point p, double ar) {
    x = p.x;
    y = p.y;
    r = fabs(ar);
}

circle::circle(const circle& c) {
    x = c.x;
    y = c.y;
    r = c.r;
}

int circle::in_circle(double ax, double ay) {
    return (x - ax) * (x - ax) + (y - ay) * (y - ay) < r * r;
}

int circle::in_circle(point p) {
    return (p.x-x)*(p.x-x)+(p.y-y)*(p.y-y) < r*r;
}

void circle::move_circle(struct point p) {
    x = p.x;
    y = p.y;
}

void circle::pr() {
    printf("x = %f, y = %f, r = %f\n", x, y, r);
}

main() {
    point p = {1.0, -3.56};

    circle c1(2.5, -1.2, 6.5);
    circle c2(1.5, -0.2, 8.0);
    circle c3(p, 2.5);
    circle c4(c1);

    c1.pr();
    c2.pr();
    c3.pr();
    c4.pr();

    printf("%d\n", c1.in_circle(0.002, -1.44));
    printf("%d\n", c1.in_circle(p));
    c4.move_circle(p);
    c4.pr();
}