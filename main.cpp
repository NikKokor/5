#include <iostream>
#include <string>

using namespace std;

enum TYPE{
    wood,
    stone,
    iron
};

class House
{
    TYPE walls;
    TYPE roof;
    TYPE door;
public:
    void setWalls(TYPE _walls){walls = _walls;}

    void setRoof(TYPE _roof){roof = _roof;}

    void setDoor(TYPE _door){door = _door;}

    void printHouse()
    {
        cout << " walls: " << walls << " roof: " << roof << " door: " << door << endl;
    }
};

class HouseBuilder
{
protected:
    House house;
public:
    House getHouse() { return house;};
    virtual void buildWalls() = 0;
    virtual void buildRoof() = 0;
    virtual void buildDoor() = 0;
};

class WoodenHouseBuilder : public HouseBuilder
{
public:
    void buildWalls() override{house.setWalls(wood);}

    void buildRoof() override{house.setRoof(wood);}

    void buildDoor() override{house.setDoor(iron);}
};

class StoneHouseBuilder : public HouseBuilder
{
public:
    void buildWalls() override{house.setWalls(stone);}

    void buildRoof() override{house.setRoof(stone);}

    void buildDoor() override{house.setDoor(iron);}
};

class Director
{
    HouseBuilder *houseBuilder;
public:
    void setHouse(HouseBuilder *a) {houseBuilder = a;}
    House getHouse() { return houseBuilder->getHouse();}
    void createHouse()
    {
        houseBuilder->buildWalls();
        houseBuilder->buildRoof();
        houseBuilder->buildDoor();
    }
};

int main() {
    Director dir;
    WoodenHouseBuilder woodenHouseBuilder;
    dir.setHouse(&woodenHouseBuilder);
    dir.createHouse();
    House house1 = dir.getHouse();
    house1.printHouse();

    StoneHouseBuilder stoneHouseBuilder;
    dir.setHouse(&stoneHouseBuilder);
    dir.createHouse();
    House house2 = dir.getHouse();
    house2.printHouse();

    return 0;
}