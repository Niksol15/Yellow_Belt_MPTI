#include <iostream>
#include <string>
#include <memory>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

constexpr double PI = 3.14;
class Figure{
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Rect: public Figure{
public:
    Rect(int w, int h): width(w), height(h){}
    string Name() const  {
        return "RECT";
    }
    double Perimeter() const  {
        return 2*(width + height);
    }
    double Area() const  {
        return width * height;
    }
private:
    int width;
    int height;
};

class Triangle: public Figure{
public:
    Triangle(int _a, int _b, int _c): a(_a), b(_b), c(_c){}
    string Name() const  {
        return "TRIANGLE";
    }
    double Perimeter() const  {
        return a+b+c;
    }
    double Area() const  {
        double p = static_cast<double>(a + b + c)/2.0;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
private:
    int a;
    int b;
    int c;
};

class Circle: public Figure{
public:
    Circle(int _r): r(_r){}
    string Name() const  {
        return "CIRCLE";
    }
    double Perimeter() const  {
        return 2*PI*r;
    }
    double Area() const  {
        return PI*r*r;
    }
private:
    int r;
};

shared_ptr<Figure> CreateFigure(istream& is){
    string type;
    is >> type;
    if(type == "RECT"){
        int w, h;
        is >> w >> h;
        return make_shared<Rect>(w,h);
    } else if(type == "TRIANGLE"){
        int a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a,b,c);
    } else{
        int r;
        is >> r;
        return make_shared<Circle>(r);
    }
}
int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}