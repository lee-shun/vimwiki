**NOTE:** 命名空间：https://blog.csdn.net/qq_40416052/article/details/82528676

### C++命名空间的使用：

* 使用整个命名空间：using namespace name;
* 使用命名空间中的变量：using name::variable
* 使用默认命名空间中的变量:  ::variable

```C++

#include <stdio.h>
#include <iostream>
namespace First 
{
int i = 0;
}

namespace Second
{
int i = 1;

namespace Internal //嵌套命名空间
{
struct P  //嵌套命名空间
{
int x;
int y;
};
}
}

int main()
{
using namespace First; //使用整个命名空间
using Second::Internal::P;  //使用嵌套的命名空间

printf("First::i = %d\n", i);
printf("Second::i = %d\n", Second::i);  //使用命名空间中的变量

P p = { 2, 3 };

printf("p.x = %d\n", p.x);
printf("p.y = %d\n", p.y);

system("pause");
return 0;
}
```
