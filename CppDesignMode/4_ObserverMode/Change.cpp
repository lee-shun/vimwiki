#include "Stable.hpp"
class Fish:public Animal{
     void run()
    {
        std::cout<<"Fish is swimming!!"<<std::endl;
    }
};
class Dog:public Animal{
     void run()
     override;
};
void Dog::run()
{
        std::cout<<"Dog is running!!"<<std::endl;
}
class Cat:public Animal{
     void run()
    {
        std::cout<<"Cat is running!!"<<std::endl;
    }
};

int main(){

    Fish fish;
    Dog dog;
    Cat cat;

    LookAnimal look;

    look.addAnimal(&fish);
    look.addAnimal(&dog);
    look.addAnimal(&cat);


    look.LookAnimalRun();
    return 0;

}
