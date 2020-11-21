## 转换函数

- [  ] 可以将此种转换为另一种

```C++
class Fraction{
    public:
        operator double() const{
            return (double)(m_num/m_den);
        }
};

double d=4+f;//将f转换为double
```

## no-explicit-one-argument 构造函数

- [  ] 可以将另一种转化为此种

```C++
class Fraction{
    public:
        //可以作为转换函数使用
        Fraction (int num, int den =1):
            m_num(num), m_den(den){}

        Fraction operator+(const Fraction& f){
            return Fraction(f.m_num+this->m_num,f.m_den+this->m_den);
        }
};

double d=f+4;//通过4使用构造函数转化为Fraction
```

## explicit-one-argument 构造函数

- [  ] explicit关键词强制单参数的构造函数按照构造函数使用

```C++
class Fraction{
    public:
        //可以作为转换函数使用
        explicit Fraction (int num, int den =1):
            m_num(num), m_den(den){}

        Fraction operator+(const Fraction& f){
            return Fraction(f.m_num+this->m_num,f.m_den+this->m_den);
        }
};

double d=f+4; //error 不能将4转换为Fraction
```
