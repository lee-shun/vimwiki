### 关于构造函数
将构造函数写成初始化列表的形式

### 关于引用，reference
* 在函数传入值的时候，尽量用引用或者是指针；
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

### 关于const
能写成const的函数就要写成const

### 关于头文件写法
用#ifndef的形式

### 关于临时对象
用classname加上小括号来表示创建一个临时对象
没有名字，生命周期到下一行就结束了
```C++
    class complex;
    inline complex
    operator + (const complex &x, const complex& y)
    {
        return complex(real(x)+real(y),imag(x)+imag(y));
    }
```