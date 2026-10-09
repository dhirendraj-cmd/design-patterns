#include <iostream>
#include <string>

using namespace std;


class Car{
    public:
        virtual void startEngine() = 0;
        virtual void shiftGear(int gear) = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void stopEngine() = 0;
        virtual ~Car(){}

};


class LuxuryCar: public Car{
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentGear;
        int currentSpeed;

        LuxuryCar(string carBrand, string carModel){
            this->brand = carBrand;
            this->model = carModel;
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << "Engine Started "<< endl;
        }

        void shiftGear(int gear){
            if (isEngineOn){
                currentGear = gear;
                cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
            } else{
                cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
                return;
            }
        }

        

};

