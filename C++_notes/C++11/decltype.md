# decltype

* 利用编译器推导出表达式的类型，但是并不去执行表达式
* 返回类型的推导；

```C++
template<typename T1, typename T2>
auto add(T1 x, T2 y)->decltype(x+y);
```

