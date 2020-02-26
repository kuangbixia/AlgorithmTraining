# 算法 + 数据结构
## 经验总结
##### 一、Vector 容器
- 去掉重复元素：先sort(algorithm头文件)排序，再unique(algorithm头文件)将相邻重复的元素放到vector尾部，然后erase尾部的重复元素。**TODO: 迭代器知识有待学习。**
``` C++
    sort(counts.begin(), counts.end());
    counts.erase(unique(counts.begin(), counts.end()), counts.end();
```
若只需要计算不重复元素的个数，简便如下：
```C++
    sort(counts.begin(), counts.end());
    cout << unique(counts.begin(), counts.end()) - counts.begin() << endl;
```
- 初始化，使用[构造函数](https://blog.csdn.net/huang_xw/article/details/8213617)
``` C++
    vector<int>nums1({ 1,3 });
```
##### 二、Link List链表
- 设置指向指针的指针
``` C++
    ListNode** p = &head;
```
在链表尾部追加新节点，正确如下：
``` C++
    ListNode* newNode = new ListNode(sum);
    (*p)->next = newNode;
    p = &(*p)->next;
```
要注意不可以直接将p指针指向newNode，这样的话p指针将一直指向newNode的地址，不再是链表中的末节点，错误示范：
``` C++
    p = &newNode;
```
##### 三、String
- [查找指定元素](http://www.cplusplus.com/reference/string/string/find/)
``` C++
    if (subString.find(s[j]) != subString.npos) {
        break;
    }
```
- 截断字串
``` C++
    string subString = s.substr(i, 1);
```