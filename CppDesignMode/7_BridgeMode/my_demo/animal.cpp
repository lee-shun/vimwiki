#include "fruit.hpp"
#include <iostream>

class Animal {
    protected:
        Fruit* fruitPtr;
    public:
        Animal(Fruit* fru):fruitPtr(fru){};
        virtual void eat() { std::cout << "Animal is eating " <<fruitPtr->name()<< std::endl; }

        ~Animal();
};

class Cat : public Animal {
    public:
        Cat(Fruit* fru):Animal(fru){}
        void eat(){std::cout<<"Cats don't like "<<fruitPtr->name();}
};


class Horse : public Animal {
    public:
        Horse(Fruit* fru):Animal(fru){}
        void eat(){std::cout<<"Horses like "<<fruitPtr->name();}
};

int main(){

    Fruit *apple=new Apple("apple");
    Animal *cat = new Cat(apple);
    Animal *horse = new Horse(apple);

    cat->eat();
    horse->eat();

    return 0;

}
