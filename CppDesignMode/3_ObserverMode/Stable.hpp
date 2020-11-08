#include <iostream>
#include<vector>

class Animal{

    public:
        virtual void run(){
            std::cout<<"Animal is moving!!"<<std::endl;
        }
        virtual ~Animal(){}
};

class LookAnimal{

    private:
        /**
         * 此部分是核心内容
         */
        std::vector<Animal*> animalsPtrVec;

    public:
        void LookAnimalRun(){
            /* 迭代器 */
            for (
                    std::vector<Animal*>::iterator iter = animalsPtrVec.begin();
                    iter!=animalsPtrVec.end();iter++)
            {
                (*iter)->run();
            }
        }
        void addAnimal(Animal* anmial)
        {
            animalsPtrVec.push_back(anmial);
        }

        /* void removeAnimal(Animal* anmial) */
        /* { */
        /*     animalsPtrVec.erase(anmial); */
        /* } */
};

