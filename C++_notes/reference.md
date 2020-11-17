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