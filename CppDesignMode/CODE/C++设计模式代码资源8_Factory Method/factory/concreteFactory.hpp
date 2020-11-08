#include<iostream>
#include"factory.hpp"
//fruit concrete class
class Apple: public Fruit{
	public:
		Apple(std::string fru):Fruit(fru){
		}
		virtual ~Apple(){
		}
};

//fruit concrete class
class Banana: public Fruit{
	public:
		Banana(std::string fru):Fruit(fru){
		}
		virtual ~Banana(){
		}
};

//fruit concrete class
class Peach: public Fruit{
	public:
		Peach(std::string fru):Fruit(fru){
		}
		virtual ~Peach(){
		}
};

//concrete factory class
class PeachFactory:public Factory{
	public:
		Fruit* CreatFruit(){
			return new Peach("fruit peach!");
		}
};

//concrete factory class
class AppleFactory:public Factory{
	public:
		Fruit* CreatFruit(){
			return new Apple("fruit apple!");
		}
};

//concrete factory class
class BananaFactory:public Factory{
	public:
		Fruit* CreatFruit(){
			return new Banana("fruit banana!");
		}
};
