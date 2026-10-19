# C-Library-Management-System

基于 C 语言和顺序表（SeqList）实现的控制台图书管理系统。

## 核心功能
- 图书录入（插入）
- 图书删除
- 图书查找（按书名）
- 图书信息修改
- 遍历打印图书列表

## 技术栈
- C 语言
- 纯标准库实现，无第三方依赖

## 编译与运行
本项目为 C 语言命令行程序，使用 GCC 编译器进行编译。

1. 打开终端（命令行），进入项目所在目录。
2. 输入以下命令编译代码：
   gcc seqlist_library_system.c -o library
3. 运行编译出的可执行文件：
   Windows 系统：.\library.exe
   Mac/Linux 系统：./library

## 项目迭代计划 (To-Do)
- [ ] 增加控制台交互菜单（while + switch）
- [ ] 增加按价格/书名排序功能
- [ ] 增加文件读写功能（数据持久化）
