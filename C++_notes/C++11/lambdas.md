# lambda像是一个函数对象, 匿名函数

```C++
auto L = []{
    std::cout<<"hello lambda"<<std::endl;
};
```

`[外界数值](参数)mutable, throwSpec ->retype{函数体};`

```C++
int id = 0;

auto f = [id]()mutable {
    std::cout<<"id:"<<id<<std::endl;
    ++id;
};

id = 42;
f();
f();
f();
std::cout<<id<<std::endl;
```

* `C++`之中的`lambda`和`Python` 中的`lambda`函数表示一种匿名函数，都会出现
一种神奇的事情参见文件夹中的代码示例

```python
def count():
    fs = []
    for i in range(1, 4):
        def f():
             return i*i
        fs.append(f)
    return fs

f1, f2, f3 = count() #调用三个函数对象结果却是三个`9`
```
