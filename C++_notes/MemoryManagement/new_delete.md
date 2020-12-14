# new&delete

## new

`new --> operator new() --> malloc()`

```C++
/* Usr Call 1 */
Foo* p = new Foo(x);
...
delete p;

/* 1 Call 2 */
Foo* p = (Foo*)operator new(sizeof(Foo));
new(p) Foo(x);

...

p->~Foo();
operator delete(p);
```


## delete

`delete --> destructor --> operator delete() --> free()`

## array new

```C++
Complex* pca = new Complex[3];
```

## placement new(并没有分配内存)

- 将对象构建在一个已经分配的内存之中。

```C++
char* buf = new char[sizeof(Complex)*3 ];

Complex* pc = new(buf) Complex(1,2);
```

