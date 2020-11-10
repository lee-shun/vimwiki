#include<iostream>

class States;
class States1;
class States2;
class States3;

class StatesFactory{
    public:
        virtual States* CreatNewStates()=0;
};

class States1Factory: public StatesFactory{
    public:
        States* CreatNewStates(){
            std::cout<<"return A States1"<<std::endl;
            return new States1:
        }
};

class States2Factory: public StatesFactory{
    public:
        States* CreatNewStates(){
            std::cout<<"return A States2"<<std::endl;
            return new States2:
        }
};

class States3Factory: public StatesFactory{
    public:
        States* CreatNewStates(){
            std::cout<<"return A States3"<<std::endl;
            return new States3:
        }
};
