# pb(pasteboard)
pb的功能包括：
- 将文件内容拷贝到粘贴板
- 预览复制的内容
- 输出粘贴板中的内容
- 将粘贴板的内容输出到目标文件

使用方法：<br>

Usage: pb [options] [-f] file <br>
Allowed options: <br>
  -h [ --help ]         show help message <br>
  -p [ --preview ]      preview copy to paster content <br>
  -s [ --show ]         show paster content <br>
  -f [ --file ] arg     input file <br>
  -o [ --output ] arg   output file <br>

使用示例：
- 将文件拷贝到粘贴板
```shell
pb README.md
pb -f README.md
```
- 预览待拷贝文件的内容
```shell
pb -p README.md
```
- 显示粘贴板中的内容
```shell
pb -s #显示粘贴板中的内容
pb -s README.md #将README.md的内容拷贝到粘贴板后再显示
```
- 拷贝粘贴板内容到目标文件
```shell
pb -o target.md #直接拷贝粘贴板内容到target.md
pb -o target.md README.md #将README.md的内容拷贝到粘贴板后，再将粘贴板的内容输出到target.md
```

<br>

# 参考资料
[Get started with CMake Tools on Linux](https://code.visualstudio.com/docs/cpp/cmake-linux#:~:text=Get%20started%20with%20CMake%20Tools%20on%20Linux%20CMake,tool%20files%20specific%20to%20your%20compiler%20and%20platform.)
[Boost Source Code](https://github.com/boostorg/boost)