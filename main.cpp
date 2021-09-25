#include<bits/stdc++.h>

using namespace std;

class Point {
    int x, y;
public:
    Point(int x1, int y1);
    Point();
    int get_x() { return x; }
    int get_y() { return y; }
    void set_x(int x1) { x = x1; }
    void set_y(int y1) { y = y1; }
    Point operator+ (Point);
    int operator* (Point);
    Point operator* (int);
    Point operator- (Point);
    bool operator== (Point a);
    bool operator!= (Point a);
    int operator^ (Point a);
    double angle(Point a);
    int square_length() { return (x * x + y * y); }
    friend ostream& operator<<(ostream&, const Point&);
};

Point::Point(int x1, int y1) {
    x = x1;
    y = y1;
}

Point::Point() {
    x = y = 0;
}

Point Point::operator+(Point a) {
    return Point(x + a.x, y + a.y);
};

Point Point::operator-(Point a) {
    return Point(x - a.x, y - a.y);
}
int Point::operator*(Point a) {
    return x * a.x + y * a.y;
}

Point Point::operator*(int a) {
    return Point(x * a, y * a);
}

int Point::operator^(Point a) {
    return (x * a.y - y * a.x);
}

ostream& operator<<(ostream& out, const Point& a) {
    return out << a.x << " " << a.y;
}

bool Point::operator==(Point a) {
    return (x == a.x) && (y == a.y);
}

bool Point::operator!=(Point a) {
    return ((x != a.x) || (y != a.y));
}
double Point::angle(Point a) {
    double t = (*this) ^ a;
    double m = (*this) * a;
    return atan2(t, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x, y;
    cout << "first vector: ";
    cin >> x >> y;
    Point A(x, y);
    cout << endl << "second vector: ";
    cin >> x >> y;
    Point B(x, y);
    cout << endl << "const to computation: ";
    int c; cin >> c;
    cout << endl;
    cout << "squares of lengths: " << A.square_length() << " " << B.square_length() << endl;
    cout << "sum is: " << A + B << endl;
    cout << "difference is: " << A - B << endl;
    cout << "result of multiplication is: " << A * B << endl;
    cout << "psevdoscal is: " << (A ^ B) << endl;
    cout << "Are they equal? " << (A == B) << endl;
    cout << "Aren't they equal? " << (A != B) << endl;
    cout << "Angle from A to B: " << A.angle(B) << endl;
    cout << "Angle from B to A: " << B.angle(A) << endl;
    cout << "multiplication 1st vec on const: " << (A * c) << endl;
    cout << "multiplication 2sd vec on const: " << (B * c) << endl;
    return 0;
}
