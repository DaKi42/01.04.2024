#include <iostream>
#include <string>
using namespace std;

class Car {
    string model;
    string body;
    int enginePower;
    int wheels;
    string transmission;
public:
    ~Car() {}
    void setModel(const string& m) {model = m;}
    void setBody(const string& b) {body = b;}
    void setEnginePower(int p) {enginePower = p;}
    void setWheels(int w) {wheels = w;}
    void setTransmission(const string& t) {transmission = t;}
    void showInfo() {
        cout << "Model: " << model << endl;
        cout << "Body type: " << body << endl;
        cout << "Engine power: " << enginePower << " hp" << endl;
        cout << "Wheels radius: " << wheels << endl;
        cout << "Transmission type: " << transmission << endl;
    }
};

class CarBuilder {
public:
    virtual ~CarBuilder() {}
    virtual void buildModel() = 0;
    virtual void buildBody() = 0;
    virtual void buildEnginePower() = 0;
    virtual void buildWheels() = 0;
    virtual void buildTransmission() = 0;
    virtual Car* getCar() = 0;
};

class DaewooLanosBuilder : public CarBuilder {
    Car* car;
public:
    DaewooLanosBuilder() {
        car = new Car();
    }
    ~DaewooLanosBuilder() {
        delete car;
    }
    void buildModel() override {
        car->setModel("Daewoo Lanos");
    }
    void buildBody() override {
        car->setBody("Sedan");
    }
    void buildEnginePower() override {
        car->setEnginePower(98);
    }
    void buildWheels() override {
        car->setWheels(13);
    }
    void buildTransmission() override {
        car->setTransmission("Manual");
    }
    Car* getCar() override {
        return car;
    }
};

class FordProbeBuilder : public CarBuilder {
    Car* car;
public:
    FordProbeBuilder() {
        car = new Car();
    }
    ~FordProbeBuilder() {
        delete car;
    }
    void buildModel() override {
        car->setModel("Ford Probe");
    }
    void buildBody() override {
        car->setBody("Coupe");
    }
    void buildEnginePower() override {
        car->setEnginePower(160);
    }
    void buildWheels() override {
        car->setWheels(14);
    }
    void buildTransmission() override {
        car->setTransmission("Auto");
    }
    Car* getCar() override {
        return car;
    }
};

class UazPatriotBuilder : public CarBuilder {
    Car* car;
public:
    UazPatriotBuilder() {
        car = new Car();
    }
    ~UazPatriotBuilder() {
        delete car;
    }
    void buildModel() override {
        car->setModel("UAZ Patriot");
    }
    void buildBody() override {
        car->setBody("Universal");
    }
    void buildEnginePower() override {
        car->setEnginePower(120);
    }
    void buildWheels() override {
        car->setWheels(16);
    }
    void buildTransmission() override {
        car->setTransmission("Manual");
    }
    Car* getCar() override {
        return car;
    }
};

class HyundaiGetzBuilder : public CarBuilder {
    Car* car;
public:
    HyundaiGetzBuilder() {
        car = new Car();
    }
    ~HyundaiGetzBuilder() {
        delete car;
    }
    void buildModel() override {
        car->setModel("Hyundai Getz");
    }
    void buildBody() override {
        car->setBody("Hatchback");
    }
    void buildEnginePower() override {
        car->setEnginePower(66);
    }
    void buildWheels() override {
        car->setWheels(13);
    }
    void buildTransmission() override {
        car->setTransmission("Auto");
    }
    Car* getCar() override {
        return car;
    }
};

class Shop {
public:
    Car* buildCar(CarBuilder* builder) {
        builder->buildModel();
        builder->buildBody();
        builder->buildEnginePower();
        builder->buildWheels();
        builder->buildTransmission();
        return builder->getCar();
    }
};

int main() {
    Shop shop;
    Car* car;
    DaewooLanosBuilder daewooLanosBuilder;

    car = shop.buildCar(&daewooLanosBuilder);
    car->showInfo();
    cout << endl;

    FordProbeBuilder fordProbeBuilder;
    car = shop.buildCar(&fordProbeBuilder);
    car->showInfo();
    cout << endl;

    UazPatriotBuilder uazPatriotBuilder;
    car = shop.buildCar(&uazPatriotBuilder);
    car->showInfo();
    cout << endl;

    HyundaiGetzBuilder hyundaiGetzBuilder;
    car = shop.buildCar(&hyundaiGetzBuilder);
    car->showInfo();
    cout << endl;

    system("pause");
    return 0;
}