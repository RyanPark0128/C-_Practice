#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <cmath>

class line{

    public:
        line(int x1, int y1, int x2, int y2);
        bool operator==(const line &l);
        friend std::ostream &operator<<(std::ostream &out, const line &l);
        line operator+(int x);
        line operator*(int x);
        friend line operator+(int y, const line &l);

    private :
        struct point{
            int x, y;

            double dist(point p) const
            {
                return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
            }
            std ::string to_string() const
            {
                std::string str = "(";
                str += std::to_string(x) + "," + std::to_string(y) + ")";
                return str;
            }
        }; 
        point p1, p2;
};
line line::operator+(int x)
{
    return line(p1.x + x, p1.y, p2.x + x, p2.y);
}
line line::operator*(int x)
{
    return line(p1.x, p1.y, p2.x * x, p2.y*x);
}
line operator+(int y, const line &l)
{
    return line(l.p1.x, l.p1.y+y, l.p2.x, l.p2.y+y);
}
std::ostream &operator<<(std::ostream &out, const line &l)
{
    out << l.p1.to_string() << l.p2.to_string() << " dist = " << l.p1.dist(l.p2);
    return out;
}
bool line::operator==(const line &l)
{
    return p1.dist(p2) == l.p1.dist(l.p2);
}

line::line(int x1, int y1, int x2, int y2)
{
    p1 = {x1, y1};
    p2 = {x2, y2};
}

#endif