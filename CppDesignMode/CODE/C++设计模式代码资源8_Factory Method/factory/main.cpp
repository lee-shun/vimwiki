#include <iostream>
#include"concretefactory.hpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class People{
	private:
		Factory* FruFactory;

	public:
		People(Factory* factory){
			this->FruFactory=factory;
		}
		
		void eat(){
			Fruit* fruPtr=FruFactory->CreatFruit();
			std::cout<<"people eat "+ fruPtr->get_name()<<std::endl;
			std::cout<<"before delete fruPtr-->"<<fruPtr<<std::endl;
			delete fruPtr;
			std::cout<<"after delete fruPtr-->"<<fruPtr<<std::endl;
			//std::cout<<"after people eat "+ fruPtr->get_name()<<std::endl;
		}
};
int main(int argc, char** argv) {
	std::cout<<"hello factory!!"<<std::endl;
	PeachFactory peach_fac;
	People lee_shun(&peach_fac);
	lee_shun.eat();
		
	AppleFactory apple_fac;
	People ls(&apple_fac);
	ls.eat();
	return 0;
	
	
}
