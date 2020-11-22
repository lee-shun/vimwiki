# 关于引用，reference

* 在函数传入值的时候，尽量用引用或者是指针；
* **引用传出来的就是那个东西本身！！！**
* 要获得函数处理的临时变量的时候，不能直接进行返回值引用（局部变量已经消亡）
* 引用的一个好处：传递者无需知道接收者的接收方式是by reference or by value

    ```C++
    #include <iostream>

    void foo(int &var) {
        var += 3;
    }

    //key
    int &bar(int *var) {
        *var += 3;
        return *var;
        /*
         * 传出的是一个值，*var是值，将这个值作为引用返回
         * 接收端就是"int &bar"，传递者无需知道。
         **/
    }

    int main() {
        int hello = 0;
        foo(hello);
        std::cout << hello << std::endl;
        foo(hello);
        std::cout << hello << std::endl;
        std::cout << bar(&hello) << std::endl;
        return 0;
    }
    ```
* 引用被创造的时候，就要被指定初值，而且不可后续更改
* 个人感觉reference是使用pointer like class 实现的，类的内部其实只一个指针
但是在编译器层面直接制作出了下面的假象
* **NOTE**:
    * int& r=x;
    + sizeof(r)=sizeof(x);
    + &x==&r;

## reference 的常见用途：
- [ ] 在定义端
```C++
void fun1(Cls* pobl)(pobl->xxx();)
void fun2(Cls obl)(pobl.xxx();)
void fun3(Cls& obl)(pobl.xxx();)
```
- [ ] 在被调用端
```C++
fun1(&obj);
func2(obj);//传值，拷贝，需要注意拷贝构造函数
func3(obj);
```
