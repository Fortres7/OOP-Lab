#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getStatus() const = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
private:
    bool isOn;
    int brightness;

public:
    LightBulb() : isOn(false), brightness(0) {}

    void turnOn() override {
        isOn = true;
        brightness = 100;
    }

    void turnOff() override {
        isOn = false;
        brightness = 0;
    }

    string getStatus() const override {
        return "LightBulb is " + string(isOn ? "On" : "Off") + ", Brightness: " + to_string(brightness) + "%";
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature;

public:
    Thermostat() : isOn(false), temperature(20.0) {}

    void turnOn() override {
        isOn = true;
        temperature = 22.0;
    }

    void turnOff() override {
        isOn = false;
        temperature = 15.0;
    }

    string getStatus() const override {
        return "Thermostat is " + string(isOn ? "On" : "Off") + ", Temperature: " + to_string(temperature) + "°C";
    }
};

int main() {
    LightBulb bulb;
    Thermostat thermostat;

    SmartDevice* devices[2];
    devices[0] = &bulb;
    devices[1] = &thermostat;

    for (int i = 0; i < 2; ++i) {
        devices[i]->turnOn();
        cout << devices[i]->getStatus() << endl;
    }

    cout << endl;

    for (int i = 0; i < 2; ++i) {
        devices[i]->turnOff();
        cout << devices[i]->getStatus() << endl;
    }

    return 0;
}
