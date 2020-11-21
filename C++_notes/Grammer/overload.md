### C++重载

 
 运算符重载：https://blog.csdn.net/liitdar/article/details/80654324
 

 ### 关于运算符重载

* 实现-1: 成员函数法：
    * 编译器处理运算符号的时候，会将运算符作为一个函数作用到左值之上，左值作为一个隐藏参数参与运算符重载操作（this）：
        * 例如：a+=b; 有无此种+=操作？有则调用，没有则在原始语法中寻找。
        * 右值会作为参数传入。

* 实现-2: 全局函数法：
    * 一个例子：新定义的复数这种数据类型，cout这种标准输入输出是无法直接“解析”的，因而要在全局范围内重载<<这种运算符，因为<<作用于左侧的对象，因而不能直接 **实现在complex class** 内部！要声明称全局的！
    ```C++
    ostream& operator << (ostream& os, const complex& x){
        return os <<'('<< real(x)<<','
        <<imag(x)<<')';
    }

    complex a(1,2);
    std::cout<<a<<std::endl;
    ```