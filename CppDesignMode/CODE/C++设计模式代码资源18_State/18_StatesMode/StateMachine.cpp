#include<iostream>
#include"StatesFactory.hpp"

class States{
    private:
        States* pNextState;
    public:
        virtual  void operation1()=0;
        virtual  void operation2()=0;
        virtual  void operation3()=0;

        virtual  States* getNextStates(){
            return pNextStates;
        }
        virtual  States* getInstance(StatesFactory* StFcPtr){
            return StFcPtr->CreatNewStates();
        }
        virtual  ~States(){}
};

class States1:public States{
    private:
    public:

        void operation1(){
            pNextStatus=getInstance(States2Factory* StFcPtr);
            std::cout<<"State1->operation1->States2"<<std::endl;
        }
        void operation2(){
            pNextStatus=getInstance(States3Factory* StFcPtr);
            std::cout<<"State1->operation2->States3"<<std::endl;
        }
        void operation3(){
            pNextStatus=getInstance(States1Factory* StFcPtr);
            std::cout<<"State1->operation3->States1"<<std::endl;
        }
};

int main(){
    return 0;
}
