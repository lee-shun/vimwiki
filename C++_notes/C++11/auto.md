# auto

## *语法糖*

 ```C++
 list<string> c;
 lsit<string>::iterator ite;
 ite = find(c.begin(),c.end(),target);

 lsit<string> c;
 auto ite = find(c.begin(),c.end(),target); //使用编译器直接推断
 ```

## 关于atuo的迭代的类型

```C++
#include<iostream>

using namespace std;

int main(){
    // 定义一个map对象
    map<int, string> mapStudent;

    // 第一种 用insert函數插入pair
    mapStudent.insert(pair<int, string>(000, "student_zero"));

    // 第二种 用insert函数插入value_type数据
    mapStudent.insert(map<int, string>::value_type(001, "student_one"));

    for(auto i : mapStudent){
        cout<<typeid(i).name<<endl;}
    return 0;
}
```


