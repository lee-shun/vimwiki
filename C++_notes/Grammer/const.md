# const

* const是函数签名的一部分！

```C++
//下面的函数可以并存
double hello(int i) const{}
double hello(int i) {}
```

## const修饰普通类型的变量

### 修饰普通变量

```C++
const int a=7;
//此时的a 不能再被修改
```

### 修饰指针变量

* 修饰指针指向的内容

```C++
const int* p = 8;//左定值，8不可改变
```

* 修饰指针本身

```C++
int× const p =&a;//右定值，指针指向的地址不可改变，但该地址的内容可改变
```

* 修饰指针以及指针指向的内容

```C++
const int* const p = &a;//全部固定
```

## 参数传递以及返回值

* <font color=#FF0000>**值传递一般不用const修饰，因为是复制传值**</font>

```C++
#include<iostream>
using namespace std;

void Cpf(const int a) {
    cout<<a;
    // ++a;  是错误的，a 不能被改变
}

int main(void) {
    Cpf(8);
    system("pause");
    return 0;
}

```

* 指针传参

```C++
#include<iostream>
using namespace std;

void Cpf(int* const a) {
    cout<<*a<<" ";
    *a = 9;
}

int main(void){
    int a = 8;
    Cpf(&a);
    cout<<a; // a 为 9
    system("pause");
    return 0;
}
```

* 自定义类型的参数传递， 需要临时对象复制参数，对于临时对象的构造，
需要调用构造函数，比较浪费时间，因此我们采取 const 外加引用传递的方法。
并且对于一般的 int、double 等内置类型，我们不采用引用的传递方式。

```C++
#include <iostream>
using namespace std;

class Test {
    public:
        Test(int m_in) : m(m_in) {}
        ~Test(){};

        int& get_m_val() { return m; }//这里使用了引用，反回了一个内部reference的引用；
        int get_m_val() const {
            cout << "call the const version!" << endl;
            return m;
        }//此处不能使用引用，因为他使得int变成了&int，违背了const

    private:
        int m;
};

void test_const_call(const Test& t)
{
    int a = t.get_m_val();
    cout<<"a="<<a<<endl;
}
void test_call(Test& t)
{
    int a = t.get_m_val();
    cout<<"a="<<a<<endl;
}

int main(int argc, char **argv) {
    Test t(2);
    cout << t.get_m_val() << endl;

    test_call(t);//结果显式是运行的const版本
    cout<<"---------------"<<endl;
    test_const_call(t);//结果显式是运行的const版本
    cout<<"下面是邪恶的事情："<<endl;

    int* p = &(t.get_m_val());
    *p+=1;
    cout<<"*p="<<*p<<endl;//3
    cout << t.get_m_val() << endl;//3
    return 0;
}

```

