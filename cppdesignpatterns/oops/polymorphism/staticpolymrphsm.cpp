// it simply means your function return type and name remains same but the arguments in fucntion is different
// for achieving static polymorphissm you dont need inheritance

#include <iostream>
#include <string>

using namespace std;


class Animal{
    private:
        string name;
        
    public:
        Animal(string name){
            this->name = name;
        }

        void run(int legs, float km){
            cout << name << " is running " << km << "km/hr with " << legs << " legs" << endl;
        }

        void run(int legs){
            cout << name << " is walking with " << legs << " legs" << endl;
        }

};


int main(){
    Animal* anm = new Animal("Tiger");
    anm->run(4, 67.5);
    anm = new Animal("Duck");
    anm->run(2);

    return 0;
}
