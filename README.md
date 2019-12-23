# hash
测试hash速度

最近遇到一个查找对应关系的需求，第一时间想到map，但是千万级的数据，于是使用了unordered_map。时间

降低了3倍左右。

但是偶然看见网上有有人说手撸一个hashmap，最基本的链式的，都要比unordered_map要快，于是试了一下。



编译命令

```bash
g++ testhashmap.cc hashtable.cc mslist.cc  -o testhashmap -std=c++11
```





测试数据见博客

https://blog.csdn.net/qq_24889575/article/details/103672682



