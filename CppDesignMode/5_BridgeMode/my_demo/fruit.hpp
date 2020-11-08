#include <iostream>

class Fruit{
    protected:
        std::string nam_fru;
    public:
        Fruit(std::string fru):nam_fru(fru){}
        virtual std::string name(){return "fruit";}
};


class Apple:public Fruit{
    public:
        Apple(std::string fru):Fruit(fru){}
        virtual std::string name(){return "apple";}

};

class Peach:public Fruit{
    public:
        Peach(std::string fru):Fruit(fru){}
        virtual std::string name(){return "Peach";}

};
