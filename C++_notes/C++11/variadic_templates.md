# 变参数模板


```C++
//变成0个参数之后，就直接调用此函数，直接调用后面就会出错
void print(){
}

template<typename T, Typename... Types>
void print(const T& firstArg, const Types&... args){

std::cout<<firstArg<<endl;
print(args..);

}
```

- [ ] 递归的思想，总是被分为一个+一包（0）个
- [ ] 看有几个，直接用sizeof...(args)
