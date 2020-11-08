#include <iostream>
namespace test{

class Line{
	public:
		int getLength();
		Line(int len);
		Line(const Line &obj);
		~Line();
	private:
		int *ptr; 
};

Line::Line(int len){
	std::cout<<"call the constructor func"<<std::endl;
	ptr=new int;
	*ptr = len;
}

Line::Line(const Line &obj){
	std::cout<<"call the copy constructor and allocate mem for ptr"
	<<std::endl;
	//obj is the older or existed instance.
	ptr = new int;//allocate the mem
	*ptr = *obj.ptr;//copy the value
}
Line::~Line()
{
    std::cout << "delete instance" << std::endl;
    delete ptr;
}
int Line::getLength(){
	return *ptr;
}
void display(Line obj){
	
	std::cout<<"in the subfunc, Line instance is copyed AND "
			 <<"the length of line is "<<obj.getLength()
			 <<std::endl; 
}

}//namespace test


int main(int argc, char** argv) {
	
	bool trySubFunc=false;
	if(trySubFunc){
	test::Line line(10);
	test::display(line);
	}else{
	test::Line line1(20);
    test::Line line2 = line1; // where the copy constructor is also called!
    test::display(line1);
    test::display(line2);
	}

	return 0;
}
