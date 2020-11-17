
### 构造函数

 构造函数初始化：https://blog.csdn.net/Tostick/article/details/80688082

### 构造函数后面增加冒号一般有三种作用

1. 对成员变量的初始化

2. 对类成员对象初始化

3. 对父类进行初始化

#### 示例1-对成员变量的初始化

```C++
#include <stdlib.h>
#include <iostream>
 
using namespace std;
 
class A {
 
private:
    int key;
public:
    A():key(8) { cout << "A()"<< endl; }
    int get_key() { return this->key; }
 
};
 
 
int main ()
{ 
  A a;
 
  cout << a.get_key() << endl;
 
  return 0;
}
```

#### 示例2-对类成员对象初始化

```C++
#include <stdlib.h>  
#include <iostream>  
  
using namespace std;  
 
class B {
private:
    int key;
public:
    B(int k) { this->key = k; }
    int get_key() { return this->key; }
};
 
class A {
 
private:
    int key;
    B b;     // 类对象
public:
    A():key(8),b(9) { cout << "A()"<< endl; }   // 类对象初始化
    int get_key() { return this->key; }
    int get_bkey() { return this->b.get_key(); }
};
  
 
int main ()  
{  
  A a;
 
  cout << a.get_key() << endl;
  cout << a.get_bkey() << endl;
 
  return 0;  
}
```

#### 示例3-对父类进行初始化

```C++
#include <iostream>  
  
using namespace std;  
 
class B {
private:
    int key;
public:
    B(int k) { this->key = k; }
    int get_key() { return this->key; }
};
 
class A : public B {
public:
    int value;
    A():B(9),value(10) { cout << "A()"<< endl; }   // 初始化父类
};
 
int main ()  
{  
  B *b(new A());    // 通过A类初始化父类
  cout << b->get_key() << endl;   // 遗留问题，怎么通过b调用子类A的成员变量？？？
  delete b;
 
  return 0;  
}
```

### 拷贝构造函数

### 拷贝复制

* 一般情况下使用深拷贝，重载=运算符，之后再动态分配内存。
* 浅拷贝，默认的拷贝方式，没有指针的情况下可以。
* **IMPORTANT** 拷贝赋值时，一定要检查是不是自我赋值！
* Steps:
  * 检测自我赋值？
  * 杀掉原来的左侧的数据
  * 重新分配内存
  * 内存填充

### 析构函数

一个String的例子（自己实现String类）：

```C++
#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
public:                                 
   String(const char* cstr=0);                     
   String(const String& str);                    
   String& operator=(const String& str);         
   ~String();                                    
   char* get_c_str() const { return m_data; }
private:
   char* m_data;
};

#include <cstring>

inline
String::String(const char* cstr)
{
   if (cstr) {
      m_data = new char[strlen(cstr)+1];
      strcpy(m_data, cstr);
   }
   else {   
      m_data = new char[1];
      *m_data = '\0';
   }
}

inline
String::~String()
{
   delete[] m_data;
}

inline
String& String::operator=(const String& str)
{
   if (this == &str)
      return *this;

   delete[] m_data;
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
   return *this;
}

inline
String::String(const String& str)
{
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
}

#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const String& str)
{
   os << str.get_c_str();
   return os;
}

#endif

```
