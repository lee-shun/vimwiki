# 分配器

  **"幕后英雄"的角色**

```C++
operator new() 和 malloc();
```

* 分配器不同平台的实现方法不太一致，但是基本上是这种流程，
`allocator->operator new();->malloc();`

* `GNU-cpp`的`allocator`没有使用，他自己实现了一个`alloc`，减少了`malloc`的次数，
更加优化，v2.9的是直接使用的，但是在之后的v4.9之中变成了扩展版的allocator
