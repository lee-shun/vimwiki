### 关于构造函数
将构造函数写成初始化列表的形式

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