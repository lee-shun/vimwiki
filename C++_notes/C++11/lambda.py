def count():
    fs = []
    for i in range(1, 4):

        def f():
            return i * i

        fs.append(f)

    print(fs) #这个函数里面存储着三个算法，真正调用时才会计算
    return fs


f = count() #调用三个函数对象结果却是三个`9`

print(f[1]())
