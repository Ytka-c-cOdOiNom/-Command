#include <iostream>
#include <windows.h>
using namespace std;

// Клас, що представляє освітлення
class Light {
public:
    void turnOn() {
        cout << "Світло увімкнене." << endl;
    }

    void turnOff() {
        cout << "Світло вимкнене." << endl;
    }
};

// Абстрактна команда
class Command {
public:
    virtual void execute() = 0;  // Абстрактний метод для виконання команди
};

// Конкретна команда для увімкнення світла
class LightOnCommand : public Command {
private:
    Light* light;

public:
    LightOnCommand(Light* light) : light(light) {}

    void execute() override {
        light->turnOn();  // Викликаємо метод для увімкнення світла
    }
};

// Конкретна команда для вимкнення світла
class LightOffCommand : public Command {
private:
    Light* light;

public:
    LightOffCommand(Light* light) : light(light) {}

    void execute() override {
        light->turnOff();  // Викликаємо метод для вимкнення світла
    }
};

// Клас, що ініціює виконання команд
class RemoteControl {
private:
    Command* command;

public:
    void setCommand(Command* command) {
        this->command = command;
    }

    void pressButton() {
        command->execute();  // Виконання команди
    }
};


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    Light* light = new Light();

    // Створення команд
    Command* lightOn = new LightOnCommand(light);
    Command* lightOff = new LightOffCommand(light);

    // Створення пульта управління
    RemoteControl* remote = new RemoteControl();

    // Увімкнення світла
    remote->setCommand(lightOn);
    remote->pressButton();

    // Вимкнення світла
    remote->setCommand(lightOff);
    remote->pressButton();


    delete light;
    delete lightOn;
    delete lightOff;
    delete remote;


}

