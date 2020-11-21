# specialization, 模板特化

## 全特化

* 特化以及泛化是相对应的

```C++
//泛化
template<class Key>
struct hash{};

//特化为long
template<>
struct hash<long>{};
```

## 偏特化

### 个数上的“偏”

按照顺序，依次来进行特化，有些有默认参数的就直接参数的名字

### 种类上的“偏”

```C++
template <class T>
class C
{
    ...
};

//指定T类型需要作为指针
template <class T>
class C<T*>
{
    ...
};

C<string> obj1;
C<string*> obj2;

```
