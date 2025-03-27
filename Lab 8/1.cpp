
#include <iostream>
using namespace std;

class Light;
class Fan;
class Air_Conditioner;
class Security_System;

class User {
private:
    string user_id, user_role;
    int access_level;

public:
    User(string id, string role, int level) : user_id(id), user_role(role), access_level(level) {}

    void viewAccessibleDevices() const;

    friend class Security_System;
};

class Device {
protected:
    string device_id, device_name;
    double power_usage;

public:
    Device(string id, string name, double power) : device_id(id), device_name(name), power_usage(power) {}

    virtual void turnOn() const = 0;

    virtual double calculatePowerUsage(int hours) const {
        return power_usage * hours;
    }

    friend ostream& operator<<(ostream &out, const Device &device) {
        out << device.device_name << " [ID: " << device.device_id << "]";
        return out;
    }
};

class Light : public Device {
public:
    Light(string id, string name, double power) : Device(id, name, power) {}

    void turnOn() const override {
        cout << *this << " turned ON.\n";
    }
};

class Fan : public Device {
private:
    int speed_level;

public:
    Fan(string id, string name, double power, int speed) : Device(id, name, power), speed_level(speed) {}

    void turnOn() const override {
        cout << *this << " turned ON at Speed " << speed_level << ".\n";
    }

    double calculatePowerUsage(int hours) const override {
        return power_usage * speed_level * hours;
    }
};

class Air_Conditioner : public Device {
private:
    int temperature_setting;

public:
    Air_Conditioner(string id, string name, double power, int temp) : Device(id, name, power), temperature_setting(temp) {}

    void turnOn() const override {
        cout << *this << " turned ON. Cooling to " << temperature_setting << "\u00B0C.\n";
    }

    double calculatePowerUsage(int hours) const override {
        return (power_usage * hours) * (1 + (25 - temperature_setting) * 0.02);
    }
};

class Security_System : public Device {
public:
    Security_System(string id, string name, double power) : Device(id, name, power) {}

    void turnOn() const override {
        cout << *this << " activated.\n";
    }

    double calculatePowerUsage(int hours) const override {
        return power_usage * hours * 1.5;
    }

    void accessSecurityLogs(const User &user) const {
        if (user.access_level >= 2) {
            cout << user.user_id << " - Security Logs Accessed:\n";
            cout << "- Intrusion Detected at 3:00 AM\n- System Reset Required\n";
        } else {
            cout << user.user_id << " has no access to security logs.\n";
        }
    }
};

void User::viewAccessibleDevices() const {
    cout << "User: " << user_id << " - Accessible Devices:\n";
    cout << "- LED Light\n- Ceiling Fan\n- Split AC\n";
    if (access_level >= 2) {
        cout << "- Security System (Restricted Access)\n";
    }
}

int main() {
    User user1("U001", "Regular User", 1);
    User user2("U002", "Maintenance Staff", 2);

    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 75, 3);
    Air_Conditioner ac1("AC001", "Split AC", 1500, 25);
    Security_System secSys1("S001", "Home Alarm", 100);

    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    secSys1.turnOn();

    cout << "\nPower Consumption:\n";
    cout << "LED Light: " << light1.calculatePowerUsage(5) << " Watts\n";
    cout << "Ceiling Fan: " << fan1.calculatePowerUsage(3) << " Watts\n";
    cout << "Split AC: " << ac1.calculatePowerUsage(6) << " Watts\n";
    cout << "Security System: " << secSys1.calculatePowerUsage(24) << " Watts\n\n";

    user1.viewAccessibleDevices();
    secSys1.accessSecurityLogs(user2);

    return 0;
}
