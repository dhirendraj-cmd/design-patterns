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
            cout << brand << " " << model << " Engine Started "<< endl;
        }

        void shiftGear(int gear){
            if (isEngineOn){
                currentGear = gear;
                cout << "Shifted to gear " << currentGear << endl;
            } else{
                cout << " Engine is off, so Cannot change Gear." << endl;
                return;
            }
        }

        void accelerate(){
            if (isEngineOn){
                currentSpeed += 10;
                cout << "Car is on " << currentSpeed << "km/h" << endl;
            } else{
                cout << "Engine is off, Cannot accelerate." << endl;
                return;
            }
        }
        void brake(){
            if(isEngineOn){
                currentSpeed -= 10;
                if (currentSpeed < 0) currentSpeed = 0;
                cout << "applying brake, Speed is now " << currentSpeed << " km/h" << endl;
            } else{
                cout << "Engine is off, no need to apply brake" << endl;
            }
        }
        void stopEngine(){
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout << "Engine is turned off now" << endl;
        }

};


int main(){
    Car* car = new LuxuryCar("BMW", "XMZ9");
    
    // calling all functions
    car->startEngine();
    car->shiftGear(1);
    car->accelerate();
    car->accelerate();
    car->accelerate();
    car->accelerate();
    car->shiftGear(3);
    car->brake();
    car->brake();
    car->brake();
    car->brake();
    car->stopEngine();
    car->brake();

    delete car;

    return 0;
}

