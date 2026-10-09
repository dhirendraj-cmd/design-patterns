#include <iostream>
#include <string>

using namespace std;


class Shape{

    public:
        virtual void area() = 0;
        virtual ~Shape(){}
};


class Rectangle : public Shape{
    protected:
        int l, b;

    public:
        Rectangle(int l, int b){
            this->l = l;
            this->b = b;
        }

        void area(){
            cout << "Area of Rectangle is: " << l*b << endl;
        }
    
};

class Triangle: public Shape{
    private:
        int base, height;

    public:
        Triangle(){}

        void setBase(int b){
            this->base = b;
        }

        void setHeight(int h){
            this->height = h;
        }

        void area(){
            cout << "Area of Triangle is: " << (0.5) * base * height << endl;
        }

};


int main(){
    Rectangle* r = new Rectangle(5, 7);
    r->area();
    delete r;

    Triangle* t = new Triangle();
    t->setBase(5);
    t->setHeight(10);
    t->area();

    delete t;


}

