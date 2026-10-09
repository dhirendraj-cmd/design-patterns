// encapsulation is a way of hiding sensitive members of a class which cannot be exposed directly to prevent any misuse, itt basically focuses on security 

#include <iostream>
#include <string>

using namespace std;


class Rectangle{
    // private access modifier for setting length and breadth as private to the class
    private:
        int length, breadth;

    public:
        int area(){
            return length*breadth;
        }

        // getters to get length and breadth
        int getLength(){
            return length;
        }

        int getBreadth(){
            return breadth;
        }

        int setLength(int l){
            if(l < 0){
                return 0;
            } else {
                length = l;
                return 1;
            }
        }

        int setBreadth(int b){
            if(b < 0){
                return 0;
            } else {
                breadth = b;
                return 1;
            }
        }
};


int main(){
    Rectangle* rect = new Rectangle();
    int l = rect->setLength(2);
    int b = rect->setBreadth(3);

    if (l==0){
        cout << "cannot pass -ve nos for length, please pass a positive nos " << endl; 
    }
    if (b==0){
        cout << "cannot pass -ve nos for breadth, please pass a positive nos " << endl; 
    }

    int area = rect->area();
    cout << "Area is: "<< area << endl;

    cout << "length is: " << rect->getLength()<<endl;
    cout << "breadth is: " << rect->getBreadth()<<endl;

}



