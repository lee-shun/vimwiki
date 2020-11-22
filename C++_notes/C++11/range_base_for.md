# range_based_for

```C++
for(decl : coll){
statement
}
```
* 讲右边coll容器之中的每一个“元素“赋给decl，并进行statement
* 此处的赋值动作是”拷贝“，不会影响原来容器之中的内容；
* 可以直接使用”reference“

```C++
vector<double> vec;

...

for(auto elem:vec){
std::cout<<elem<<std::endl;
}

for(auto& elem:vec){
elem *=3;
}
```
