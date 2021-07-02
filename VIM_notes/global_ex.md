# global 命令以及Ex命令

## global命令

**对匹配的行做`cmd`**

```vim
:[range] global[!] /{pattern}/ [cmd]
```

- 默认的范围就是整个文件（即 `%`)
- `pattern` 字段与搜索历史继承，留空使用上一次的搜索匹配
- `cmd` 可以是任何的Ex命令，不指定的话就会用p(print)
- 使用`global!`或者是`vglobal`来反选

## Ex命令

**命令行扩展**

- `ctrl-r ctrl-w`将光标的单词放到命令行处
