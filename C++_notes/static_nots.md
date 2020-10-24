# C++关键字static的注意事项
[] 作为static的变量只被初始化1次；后续可以改变其值，但是不能用初始化的方法；
```C++
for(i=0;i<10;i++)
{
    static float A =fun(i);
}
```
这时，'fun()'函数只被执行一次。

但是可以这样达到每次调用的效果：
```C++
for(i=0;i<10;i++)
{
   static float A;
   A  =fun(i);
}
```

