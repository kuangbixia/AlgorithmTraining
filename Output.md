# 算法 + 数据结构
## 经验总结
##### 写在前面
- 牛客网刷题严防特殊测试用例，如空数组、空链表，不合常规的长度等情况。**考验代码的鲁棒性，即健壮性。**

##### Vector 容器
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
    vector<int>nums1({ 1,3 }); // 一维
    vector<int>nums2({ 1,3 }，{3，4}); // 二维
```

##### map 容器
- 插入数据，可用**数组**的方式插入
``` C++
    map<int, int>temp;
    for (int i = 0; i < data.size(); i++) {
        temp[data[i]]++;
    }
```
- 遍历数据，要用到**迭代器**辅助
``` C++
    bool find1 = false;
    map<int, int>::iterator it;
    for (it = temp.begin(); it != temp.end(); it++) {
        if (it->second == 1) {
            if (!find1) {
                *num1 = it->first;
                find1 = true;
            }
            else {
                *num2 = it->first;
                break;
            }
        }
    }
```

##### Stack 容器
- 常用函数
``` C++
    stack<int> st; // 声明，类似vector 
    st.push(element); // 压入新元素
    st.pop(); // 去除顶部元素
    st.top(); // 访问顶部元素
    st.size(); // 元素个数
```
- 判断出栈序列是否合法
1. [出栈序列中元素i之后的所有**在入栈序列中排在i之前**的元素j->k必须倒序排列，即k->j。](https://www.nowcoder.com/profile/632328871/codeBookDetail?submissionId=67471967)
2. [借助辅助栈模拟入栈和出栈的过程。](https://www.nowcoder.com/profile/632328871/codeBookDetail?submissionId=67508504)

##### Queue 队列
- 常用函数
``` C++
    queue<int> aq; // 声明，类似vector
    aq.push(element); // 加入新元素
    aq.pop(); // 移除第一个元素
    aq.front(); // 访问第一个元素
    aq.back(); // 访问最后一个元素
    aq.size(); // 元素个数
```
- [队列实现二叉树的从上到下从左到右的遍历](https://www.nowcoder.com/profile/632328871/codeBookDetail?submissionId=67517960)

##### Link List链表
- 设置指向指针的指针
``` C++
    ListNode** p = &head;
```
在链表尾部追加新节点，正确如下：**PS：当使用new一个新节点时，会重新分配新的空间，即newNode的地址会不断改变。(\*p)->next不会指向同一个地址。**
``` C++
    ListNode* newNode = new ListNode(sum);
    (*p)->next = newNode;
    p = &(*p)->next;
```
要注意不可以直接将p指针指向newNode，这样的话p指针将一直指向newNode的地址，不再是链表中的末节点，错误示范：
``` C++
    p = &newNode;
```
- [复制指针，通过交换实现链表反向](https://www.nowcoder.com/profile/632328871/codeBookDetail?submissionId=67270834)。**PS：慎用指针的指针**
- *间址符：取指针指向的内容；&取址符：取指针的地址；指针本身的值，即指针指向内容的地址。

##### Binary Tree二叉树
- 构造二叉树，节点定义
``` C++
    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x):val(x),left(NULL),right(NULL){}
    };
```
- [已知前序遍历和中序遍历，递归实现重构二叉树](https://www.nowcoder.com/profile/632328871/codeBookDetail?submissionId=67091042)
- **TODO: 实现前序遍历，中序遍历，后序遍历**

##### [Binary Search Tree二叉搜索树](https://www.jianshu.com/p/ff4b93b088eb)
- 对于树中的每个节点，若左子树存在，则左子树的每个节点的值都不大于该节点的值；若右子树存在，则右子树的每个节点的值都不小于该节点的值。

##### String
- 查找指定字符/字符串 **string.find()**
    - 若存在，返回该查找元素的下标
    - 若不存在，返回一个比string长度还要大的数，用下面示例的npos更加规范
``` C++
    if (subString.find(s[j]) != subString.npos) {
        break;
    }
```
- 截断字串 **string.substr()**
``` C++
    string subString = s.substr(i, 1);
```
- 插入字符/字符串 **string.insert()**
``` C++
    string ans("");
    for (int i = arr.size() - 1; i >= 0; i--) {
        ans.insert(ans.length(), arr[i]);
    }
```
- 字母的ASCII码
    - a ~ z: 65 ~ 90
    - A ~ Z: 97 ~ 122
    - 用于查找字符串中第一个出现且只出现一次的字母（Hash）

##### 字符指针
- 计算长度跟字符串类似，要加上最后'/0'
``` C++
    char _str[] = " helloworld";
	char* str = _str;
	int length = 12;
```
- 指向的是字符，不是字符串，比较字符时要用单引号''，不是双引号""
- 可以通过 + 运算符移动指针，访问不同的字符
``` C++
    int blank = 0;
    for (int i = 0; i < length; i++) {
        cout << *(str + i) << endl;
        if (*(str+i)==' ') {
            blank++;
        }
    }
```
- 可以扩充指针指向的空间，延长字符串

##### 位运算
- &，|，~，<<（左移），>>（右移）。**PS：右移后最左边的填充会跟原最左边的符号一致，即正数右移最左边会填充‘0’，负数右移会填充‘1’。**
- [新鲜例子：通过位与运算和移位运算实现计算十进制整数对应二进制（补码）的1的个数](https://www.nowcoder.com/profile/632328871/codeBookDetail?submissionId=67226684)
- 取反后打印，会作为补码输出对应的十进制数值。

##### cin
- cin
    1. 输入数字，过滤掉不可见字符（如：空格，回车，Tab等）
    ``` C++
        cin>>a>>b;
    ```
    2. 输入字符串，过滤掉不可见字符（如：空格，回车，Tab等）
- cin.get()
    1. 接收字符
    ``` C++
        char ch;
        ch=cin.get(); //cin.get(ch);
    ```
    2. 接收一行字符串（包含空格）
    ``` C++
        char str[20];
        cin.get(str,20); // 将只输入一行字符串中的前19个字符，结尾+'\0'
    ```
- cin.getline(char*,int,char) **第三个参数是接收字符串的结束符，即遇到endChar结束输入，省略时默认为'\n'**，输入字符串（包含空格）
``` C++
    char str[20];
    cin.getline(str,5); // 将只输入一行字符串中的前4个字符，结尾+'\0'
```
- getline() 是属于string流，需要包含头文件\<string\>，输入一行字符串（包含空格）
``` C++
    string str;
    getline(cin,str);
```

##### sizeof() vs getsize()
- sizeof() 返回所占空间的字节数


## C++
##### static变量
- 在函数内声明，也可以在函数外共用。
- 作为全局变量。

##### 野指针问题
- 创建指针后要初始化为NULL，否则他的缺省值是随机的。
- 当使用delete释放空间后，要设为NULL，否则会被随机分配，可能导致和其他指针指向同一块地址，造成后续访问或者写入冲突。

##### 一个类A包含另一个已经包含类A的类B
- 直接include会导致死循环，编译错误。
- 解决方法
    - 在类A头文件中声明类B
    ``` C++
    #ifndef AH
    #define AH
    class B;
    class A {
    public:
        B* b;
        ~A();
    };
    #endif
    ```
    - 在类A的cpp文件中除了包含类A，还要**包含类B**
    ``` C++
    #include "A.h"
    #include "B.h"
    A::~A() {
    }
    ```
##### 内存对齐
- 根据有效对齐单位确定 #pragma back(n)，一般是4个字节
- [参考](https://zhuanlan.zhihu.com/p/30007037)

##### sizeof
所占内存的字节数
- 指针：无论指向什么类型，都是四个字节。
- 结构体：要注意内存对齐问题

## 操作系统
##### 进程和线程
- 线程共享了进程的上下文，因此同一进程的线程之间要进行同步和互斥
- 线程是CPU调度的基本单元，是更小的cpu时间段

##### 死锁
- 产生死锁四个必要条件
    - 互斥条件：一段时间内某资源仅为一个进程所占用
    - 请求和保持条件：当进程因请求资源而阻塞时，对已获得的资源保持不放
    - 不剥夺条件：进程已获得的资源在未使用完之前不可剥夺，只能在使用完后自己释放
    - 环路等待条件：在发生死锁时，必然存在一个进程-资源的环形链
- 预防死锁
    - 破坏请求条件：一次性分配所有资源
    - 破坏保持条件：只要有一个资源没得到分配，就不给这个进程分配其他资源
    - 破坏不可剥夺条件：当进程已获得部分资源，但得不到其他资源，则释放已占有的资源
    - 破坏环路等待条件：系统给每一类资源编号，每个进程按编号递增的顺序请求资源，释放则相反

##### 虚拟内存和物理内存
