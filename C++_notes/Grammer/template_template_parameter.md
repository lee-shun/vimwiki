# 模板模板参数

* 一个模板的输入参数是另外一个模板

```C++
//请注意，这里的XCls的第二模板参数要求是一个单参数的模板
template<typename T,
    template<typename U>
    calss Container
    >

    class XCls
{
    private:
        Container<T> c;
    public:
        ...
};
//呼应上面的“注意”：

template<typename T>
using Lst=list<T, allocator<T>>;

XCls<string, list> mylist1; //Error.list has the second template param.
XCls<string, Lst> mylist2;

```

## 这不是一个模板模板参数

```C++
template<class T, class Sequence = deque<T>>
class stack{
    protected:
        Sequence c;
};

//注意，这里deque<T> 已经被特化了，不在算作为模板。
```
