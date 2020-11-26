# 如何产生`compile_command.json`文件

## 如果是catkin_ws

**catkin_make以及catkin build 均支持**

```bash
catkin_make -DCMAKE_EXPORT_COMPILE_COMMANDS=1

catkin build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
````

## 如果是普通工程

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
```

OR:

```bash
sudo apt install bear

bear make
```

[bear 网站](https://github.com/rizsotto/Bear)

