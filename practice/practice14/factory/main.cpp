#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <cmath>
#include <stdexcept>

// ───────── shapes ─────────
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double r;
public:
    explicit Circle(double r):r(r){}
    double area() const override { return M_PI*r*r; }
};

class Square : public Shape {
    double a;
public:
    explicit Square(double a):a(a){}
    double area() const override { return a*a; }
};

class Rectangle : public Shape {
    double w,h;
public:
    Rectangle(double w,double h):w(w),h(h){}
    double area() const override { return w*h; }
};

// ───────── factory ─────────
class ShapeFactory {
public:
    static std::unique_ptr<Shape> create(const std::string& type,
                                         const std::vector<double>& d){
        if(type=="circle" && d.size()==1)      return std::make_unique<Circle>(d[0]);
        if(type=="square" && d.size()==1)      return std::make_unique<Square>(d[0]);
        if(type=="rectangle" && d.size()==2)   return std::make_unique<Rectangle>(d[0],d[1]);
        throw std::invalid_argument("Bad line in file");
    }
};

int main(){
    std::ifstream file("shapes.txt");
    if(!file){ std::cerr<<"shapes.txt not found\n"; return 1; }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    while(std::getline(file,line)){
        std::istringstream iss(line);
        std::string type; iss>>type;
        std::vector<double> dims;
        double x;
        while(iss>>x) dims.push_back(x);
        try{
            shapes.push_back(ShapeFactory::create(type,dims));
        }catch(const std::exception& e){
            std::cerr<<"Skipping line: "<<line<<" ("<<e.what()<<")\n";
        }
    }
    double total=0;
    for(const auto& s:shapes) total+=s->area();
    std::cout<<"Total area = "<<total<<'\n';
}
