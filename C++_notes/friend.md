### 友元
* 友元有友元类以及友元函数
* 同一个Type的不同实例之间互为友元；
* A声明B为友元之后可以被B友元可访问到所有成员，但是A没有这个权力，除非互为友元。
* 友元关系不可传递

```C++
#include <iostream>

using namespace std;

class Box
{
    double width;
public:
    friend void printWidth(Box box);
    friend class BigBox;
    void setWidth(double wid);
};

class BigBox
{
public :
    void Print(int width, Box &box)
    {
        // BigBox是Box的友元类，它可以直接访问Box类的任何成员
        box.setWidth(width);
        cout << "Width of box : " << box.width << endl;
    }
};

// 成员函数定义
void Box::setWidth(double wid)
{
    width = wid;
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box box)
{
    /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
    cout << "Width of box : " << box.width << endl;
}

// 程序的主函数
int main()
{
    Box box;
    BigBox big;

    // 使用成员函数设置宽度
    box.setWidth(10.0);

    // 使用友元函数输出宽度
    printWidth(box);

    // 使用友元类中的方法设置宽度
    big.Print(20, box);

    getchar();
    return 0;
}
```


### 两个类互为友元
原本以为这是一件很简单的事，自己去试了一下，才发现问题。
这是代码：
```C++
#include <iostream>
using namespace std;
class PX;
class PY
{
    int a;
public:
    PY() 
	{
		a=6;
	}
     void output( const PX &x)
    {
        cout<<x.b<<endl;
    } 
    friend PX;
};

class PX
{
    int b;
public:
    PX() 
	{
		b=3;
	}
    void output(const PY &y)
    {
        cout<<y.a<<endl;
    } 
	friend   PY;
};

int main()
{   
	PX X;
    PY Y;
    X.output(Y);
    Y.output(X);
    return 0;
}
```
---

就发现编译不过去，通过百度以及博客总算知道了问题所在：由于PX类在后面才定义，这就导致了编译时系统不知道PX是啥，自然const PX &x就编译不过去。
解决办法：把PY的output函数定义在PX后。
改进之后的代码：
```C++
#include <iostream>
using namespace std;
class PX;
class PY
{
    int a;
public:
    PY() 
	{
		a=6;
	}
    void output( const PX &x);
    friend PX;
};

class PX
{
    int b;
public:
    PX() 
	{
		b=3;
	}
    void output(const PY &y)
    {
        cout<<y.a<<endl;
    } 
	friend   PY;
};

 void PY:: output( const PX &x)
    {
        cout<<x.b<<endl;
    } 

int main()
{   
	PX X;
    PY Y;
    X.output(Y);
    Y.output(X);
    return 0;
}
```