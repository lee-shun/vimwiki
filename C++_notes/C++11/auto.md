# auto

*语法糖*
 ```C++
 list<string> c;
 lsit<string>::iterator ite;
 ite = find(c.begin(),c.end(),target);

 lsit<string> c;
 auto ite = find(c.begin(),c.end(),target); //使用编译器直接推断
 ```
