# lab6-example

Lab6 example, Compiler Principle, 2020 Fall, Nankai University

##### 作业要求

在之前已实现的语法和词法分析基础上，完成类型检查和代码生成，最终实现完整的简单SySy语言编译器

## 代码框架

```
#符号表相关文件
symbol.cpp
symbol.h
#语法树相关文件，包括类型检查和代码生成的大致框架
tree.cpp
tree.h
#语法分析和词法分析
本示例中未给出，需要大家根据自己编写的词法语法分析模块填充
#代码示例
example.c //输入源文件
out.s //输出汇编文件
```

## 使用该示例

注意该示例**无法编译通过**，代码库中并没有语法和词法分析相关代码，需要大家根据之前几次作业自己补充

补充语法词法模块后，我们给出了example.c翻译出的out.s的代码，通过下面的命令查看

```
$ cat out.s
```

然后将生成的.s文件编译为可执行文件，可使用如下命令。注意，该示例生成的.s文件还无法正确生成可执行文件

```
$ gcc -o out out.s 
```

## 该代码库做了哪些工作

- 给出了类型检查的基本框架
- 描述了代码生成的基本框架
- 以while为例，给出打label的一个示例
- 以加法为例，给出生成x86汇编代码的一个示例

## 需要同学们完成的工作

参考该示例，继续完成类型检查和代码生成。这两部分的主要框架在tree.h和tree.cpp中。目前代码库实现的功能非常简单，完全无法作为作业提交，希望大家发挥自己的聪明才智，使得编译器尽可能完善