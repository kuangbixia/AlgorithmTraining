# 算法 + 数据结构
## 经验总结
#### 写在前面
- 牛客网刷题严防特殊测试用例，如空数组、空链表，不合常规的长度等情况。**考验代码的鲁棒性，即健壮性。**

#### Vector 容器
- 去掉重复元素：先sort(algorithm头文件)排序，再unique(algorithm头文件)将相邻重复的元素放到vector尾部，然后erase尾部的重复元素。**TODO: 迭代器知识有待学习。**
``` C++
    sort(counts.begin(), counts.end());
    counts.erase(unique(counts.begin(), counts.end()), counts.end());
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
- 坑点！！
使用迭代器访问元素时，假如中途有更新vector，比如添加元素等，则迭代器会失效，访问异常。
因此，一般要转换方式，比如一开始就初始化整个vector，通过更新指定位置的元素，取代添加元素的需求。

#### map 容器
- 不允许出现重复键值
- 所有元素会自动排序
- key不可以修改，但value可以修改
- 常用函数
``` C++
    map<int,string>amap;
    int i=1;
    string str="aaa";
    amap.insert(make_pair(i,str)); // 插入元素，需要查找，效率低
    amap.erase(it); // 删除指定位置/迭代器的元素，返回下一个元素的位置/迭代器
    amap.erase(i); // 删除指定key的元素，跟set一样，返回删除元素的个数，0或1，其实标识了map内是否有指定元素
    amap.clear(); // 清除整个map
    amap.find(i); // 查找指定key的元素，返回指定key的元素的位置/迭代器
```
- 插入数据，可用**数组**的方式插入，比insert()好用
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

#### multimap
- 允许key重复
- multimap在插入时，调用的是红黑树的insert_equal，而map调用的是insert_unique
- 其他功能跟map基本一样

#### set 集合
- 不允许出现重复键值
- 所有元素会自动排序
- 只有key，没有value
- 不能通过迭代器来改变set的值，因为set没有值，它的值就是它的键
 - 要修改键值的话，首先要删除这个键，然后调节平衡
 - 之后插入修改后的键值，再调节平衡
 - 会导致迭代器失效，不知道该指向哪里
- 常用函数
``` C++
    set<string> aset;
    string in="aaa";
    aset.insert(in);
    aset.erase(in); // 返回擦除元素的个数，0或1，标识原本是否有这个元素
    aset.clear(); // 清除整个set
    aset.find(in); // 返回迭代器/位置
    aset.count(in); // 返回指定元素的个数，0或1，标识这个元素是否在集合中
    aset.lower_bound(in); // 返回小于指定元素的第一个可插入的位置
    aset.upper_bound(in); // 返回大于指定元素的第一个可插入的位置
```
#### multiset
- 允许出现重复键值
- multiset在插入时，调用的是红黑树的insert_equal，而set调用的是insert_unique
- 其他功能跟set基本一样

#### Stack 容器
- 常用函数
``` C++
    stack<int> st; // 声明，类似vector 
    st.push(element); // 压入新元素
    st.pop(); // 去除顶部元素
    st.top(); // 访问顶部元素
    st.size(); // 元素个数
    st.clear(); // 清空容器/删除容器
```
- 判断出栈序列是否合法
1. [出栈序列中元素i之后的所有**在入栈序列中排在i之前**的元素j->k必须倒序排列，即k->j。](https://www.nowcoder.com/profile/632328871/codeBookDetail?submissionId=67471967)
2. [借助辅助栈模拟入栈和出栈的过程。](https://www.nowcoder.com/profile/632328871/codeBookDetail?submissionId=67508504)

#### Queue 队列
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

#### Link List链表
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
- 链表中有环，如何找到环的入口
    - 我的做法：用vector存起每个节点，在插入新节点时，检查vector中是否已经插入过此节点，若是，则此节点就是换的入口
    - [牛人做法-有图](https://www.nowcoder.com/profile/2357118/codeBookDetail?submissionId=16466807)：用快（步长为2）慢（步长为1）两个指针，先找到快慢指针相遇的节点，然后用两个指针分别从表头和相遇节点开始移动，步长为1，它们总会在环的入口节点相遇。

#### Binary Tree二叉树
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

#### [Binary Search Tree二叉搜索树](https://www.jianshu.com/p/ff4b93b088eb)
- 对于树中的每个节点，若左子树存在，则左子树的每个节点的值都不大于该节点的值；若右子树存在，则右子树的每个节点的值都不小于该节点的值。

#### String类
- 实际上还是以'\0'结尾的char数组
- string::npos表示字符串的最大长度
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

- int转string
    - 函数to_string()
    - 包含string头文件

#### 字符指针
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
- 字符串转字符指针
    - 字符指针的内存 
    ``` C++
    char* c=new char[str.length()+1];
    ```

#### 递归中传指针
- 为了确保递归的过程中，指针会不逆向移动，需要传递指针的指针，这样可以通过间址指针的指针，来实际改变指针。

#### 位运算
- &，|，~，<<（左移），>>（右移）。**PS：右移后最左边的填充会跟原最左边的符号一致，即正数右移最左边会填充‘0’，负数右移会填充‘1’。**
- [新鲜例子：通过位与运算和移位运算实现计算十进制整数对应二进制（补码）的1的个数](https://www.nowcoder.com/profile/632328871/codeBookDetail?submissionId=67226684)
- 取反后打印，会作为补码输出对应的十进制数值。

#### cin
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

#### sizeof() vs getsize()
- sizeof() 返回所占空间的字节数
