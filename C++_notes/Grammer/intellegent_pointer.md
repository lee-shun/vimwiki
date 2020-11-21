# pointer_like class

## 关于智能指针

* 这个类里面一定有一个真正的指针；
* ->运算符是递归的;

```C++
template<class T>
class shared_ptr{

public:
    T& operator* () const { return *px; }
    T* operator-> () const { return px; }

    shared_ptr(T* p):px(p) {  }

private:
    T* px;
    long pn;

};
```
## 关于迭代器

* 他的用途就是来遍历容器，需要重载++，--运算符；


# function_like class

- [ ] 类中添加了对于（）的运算符的重载，目的就是function like class
