# C++关键字static的注意事项

- [ ] static的变量被存储在了全局变量的位置。全局数据区

- [ ] 作为static的变量只被初始化1次；后续可以改变其值，但是不能用初始化的方法；

```C++
for(i=0;i<10;i++)
{
    static float A =fun(i);
}
```

这时，'fun()'函数只被执行一次。

但是可以这样达到每次调用的效果：

```C++
for(i=0;i<10;i++)
{
   static float A;
   A  =fun(i);
}
```

- [ ] 静态变量没有this指针，所以可以不用使用对象来调用静态函数，可以直接用类名来调用，相当于一种全局函数。


- [ ] 利用static实现一种单例模式；NOTE:第二种写法有些问题

```C++
#include <iostream>
//原始写法
class A {
    public:
        static A &getInstance() {
            return a;
        }
        void setup()const {
            std::cout << "setup func is being called now!" << std::endl;
        }
    private:
        A();
        static A a;
};

//改进写法
class A1 {
    public:
        static A & getInstance();
        void setup()const {
            std::cout << "A1 setup func is being called now!" << std::endl;
        }
    private:
        A1();
};
static A & A::getInstance() {
    static A1 a;
    return a;
}

int main() {
    A::getInstance().setup();
    A1::getInstance().setup();
    return 0;
}
```
