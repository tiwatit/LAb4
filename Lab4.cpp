#include <iostream>
#include <vector>

class Animal
{
public:
    Animal(int age) : m_age(age) {}
    int GetAge() { return m_age; }
private:
    int m_age;
};

class Dog : public Animal
{
public:
    Dog(int age) : Animal(age) {}
};

class Cat : public Animal
{
public:
    Cat(int age) : Animal(age) {}
};

class Transportation
{
public:
    virtual int getSpeed() = 0;
};

class Car : public Transportation
{
public:
    int getSpeed() override { return 100; }
};

class Plane : public Transportation
{
public:
    int getSpeed() override { return 800; }
};

class Boat : public Transportation
{
public:
    int getSpeed() override { return 50; }
};

class Man : public Transportation
{
public:
    int getSpeed() override { return 5; }
};

class SpeedCalculator
{
public:
    int calculateSpeed(std::vector<Transportation*> transports)
    {
        int totalSpeed = 0;
        for (auto transport : transports)
        {
            totalSpeed += transport->getSpeed();
        }
        return transports.size() > 0 ? totalSpeed / transports.size() : 0;
    }
};

int main()
{
    Dog dog(3);
    Cat cat(5);

    std::vector<Transportation*> transports;
    transports.push_back(new Car());
    transports.push_back(new Plane());
    transports.push_back(new Boat());
    transports.push_back(new Man());

    SpeedCalculator calculator;
    int averageSpeed = calculator.calculateSpeed(transports);

    std::cout << "Average speed: " << averageSpeed << " km/h" << std::endl;

    // Видалення виділених ресурсів
    for (auto transport : transports)
    {
        delete transport;
    }

    return 0;
}