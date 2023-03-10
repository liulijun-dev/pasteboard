# pb(pasteboard)
pb的功能包括：
- 将文件内容拷贝到粘贴板
- 预览复制的内容
- 输出粘贴板中的内容
- 将粘贴板的内容输出到目标文件
- 清空粘贴板

使用方法：<br>

Usage: pb [options] [-f] file <br>
Allowed options: <br>
  -h [  --help    ]         show help message <br>
  -p [  --preview ]         preview copy to paster content <br>
  -s [  --show    ]         show paster content <br>
  -c [  --clear   ]         clear pasteboard content, donot execute any other options if you specified them <br>
  -f [  --file    ] arg     input file <br>
  -o [  --output  ] arg     output file <br>

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

- 清空粘贴板
```shell
pb -c
```

<br>

# 如何编译
- 安装cmake，版本3.0.0及其以上;
- 安装Boost，版本1.80.0
- 切换到代码根目录，编译代码
```shell
cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=MinSizeRel -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++ -S. -B./build -G "Unix Makefiles" && \
cmake --build ./build --config MinSizeRel --target pb
```
编译出的命令位于`代码根目录/build`内，文件名为pb.

# 参考资料
[Get started with CMake Tools on Linux](https://code.visualstudio.com/docs/cpp/cmake-linux#:~:text=Get%20started%20with%20CMake%20Tools%20on%20Linux%20CMake,tool%20files%20specific%20to%20your%20compiler%20and%20platform.) <br>
[Boost Source Code](https://github.com/boostorg/boost)<br>
[cmake](https://cmake.org/cmake/help/latest/manual/cmake.1.html#)