#include<iostream>
//fruit base(abstract) class
class Fruit{
	protected:
		std::string fru_name;
	public:
		Fruit(std::string fru):fru_name(fru){
		}
		virtual ~Fruit(){}

		virtual std::string get_name(){
			return this->fru_name;
		}
};

//factory base(abstract) class 
class Factory{
	public:
		virtual Fruit* CreatFruit()=0;
		virtual ~Factory(){
		}
};
