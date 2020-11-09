#include<iostream>

class Memento{
    private:
        std::string state;
    public:
        Memento(const std::string &s):state(s){}
        std::string getState() const {return state;}
};

class Originator{
    private:
        std::string state;
    public:
        Originator(std::string s):state(s){}
        void setStates(const std::string &s){
            state=s;
        }
        void printStates(){
            std::cout<<"now the state is "<<state<<std::endl;
        }
        Memento creatMemento(){
            Memento m(state);
            std::cout<<"creat mem and save states in it"<<std::endl;
            return m;
        }
        void setMemento(const Memento &m){
            state = m.getState();
            std::cout<<"recover the state from input mem"<<std::endl;
        }
};

int main()
{
    Originator org{"begin"};
    org.printStates();
    Memento mem=org.creatMemento();

    org.setStates("ongoing");
    org.printStates();
    org.setMemento(mem);
    org.printStates();


    return 0;
}

