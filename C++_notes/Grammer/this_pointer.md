# this指针

```C++
#include <iostream>

class A {
	private:
		int a;

	public:
		A(const int a_in):
			a(a_in)
		{}

		int get() const {
			return a;
		}
};

void show(const A *p) {
	std::cout << p->get() << std::endl;
}

int main() {
	A a1(1);
	A a2(2);
	A a3(3);

	std::cout << a1.get() << std::endl;
	std::cout << a2.get() << std::endl;

	show(&a3);
	return 0;
}
}
```