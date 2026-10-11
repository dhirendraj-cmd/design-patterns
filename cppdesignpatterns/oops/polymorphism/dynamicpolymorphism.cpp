// it simply means your function should get overidden in child class and which func to run whould be decided at run time
#include <iostream>
#include <string>

using namespace std;


class Shape{
    public:
        virtual void area()=0;
        virtual void perimiter()=0;
        virtual ~Shape() {}; // this is virtual destructor
};


class Circle: public Shape{
    private:
        int radius;

    public:
        Circle(int radius){
            this->radius=radius;
        }

        void area(){
            cout << "Circle Area is: "<< 3.14*radius*radius<<endl;
        }

        void perimiter(){
            cout << "Circle perimiter is: "<< 3.14*2*radius<<endl;
        }
};


class Rectangle: public Shape{
    private:
        int length, breadth;

    public:
        Rectangle(int l, int b){
            this->length=l;
            this->breadth=b;
        }

        void area(){
            cout << "Rectangle Area is: "<< length*breadth <<endl;
        }
        void perimiter(){
            cout << "Rectangle perimiter is: "<< 2*(length+breadth) <<endl;
        }
};

int main(){
    Shape* s;

    // this is where runtime polymorphism has started, where program has to decided whether to run circle or rectangle functions
    s = new Circle(4);
    s->area();
    s->perimiter();

    cout<<"========================\n";

    s=new Rectangle(3,9);
    s->area();
    s->perimiter();

    delete s;

    return 0;
}

