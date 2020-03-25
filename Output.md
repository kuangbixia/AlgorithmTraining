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


## C++基础
#### 琐碎
##### static变量
- 在函数内声明，也可以在函数外共用。
- 作为全局变量。

##### 定义常量
1. #define
2. const

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
- 指针：无论指向什么类型，都是4个字节。
- 数组名：整个数组占的字节
- 结构体：要注意内存对齐问题

#### C++存储类
##### auto
- 用于自动推断变量的类型
- C++11 中已删除
##### static ▲
1. 修饰局部变量时，可以在函数调用之间保持局部变量的值，即不需要再每次进入和离开作用域时重复进行创建和销毁
2. 可以应用于全局变量，作用域为**声明它的文件**
3. 可以用于类的数据成员上，表示被类的所有对象共享
##### extern ▲
- 提供全局变量的引用
- 对**所有的程序文件**都可见

#### 函数参数
##### 传值调用
- 将参数的实际**值**复制给函数的形式参数
- 修改函数内的形式参数**不会**影响实际参数
##### 指针调用
- 将参数的**地址**复制给函数的形式参数
- 因此，修改函数内的形式参数**会影响**到实际参数
##### 引用调用
- 将引用的**地址**复制给函数的形式参数，该引用用于访问调用中要用到的实际参数
- 因此，修改函数内的形式参数**会影响**实际参数
##### 传递数组 √
*实际上传的都是地址*
1. 形式参数是一个指针
``` C++
void myFunction(int *param)
{
.
.
.
}
```
2. 形式参数是一个已定义大小的数组
``` C++
void myFunction(int param[10])
{
.
.
.
}
```
3. 形式参数是一个未定义大小的数组
``` C++
void myFunction(int param[])
{
.
.
.
}
```
##### 返回数组/指针 √
*C++不允许返回一个完整的数组，可以通过数组名返回一个指向数组的指针*
``` C++
int * getRandom( )
{
  static int  r[10];
 
  // 设置种子
  srand( (unsigned)time( NULL ) );
  for (int i = 0; i < 10; ++i)
  {
    r[i] = rand();
    cout << r[i] << endl;
  }
 
  return r;
}
```
##### 返回引用
*跟返回指针类似*
``` C++
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
 
double& setValues( int i )
{
  return vals[i];   // 返回第 i 个元素的引用
}
```
*返回的被引用的对象不能超过作用域，即返回函数内的局部变量的引用是非法的*
``` C++
int& func() {
   int q;
   //! return q; // 在编译时发生错误
   static int x;
   return x;     // 安全，x 在函数作用域外依然是有效的
}
```

#### Lambda函数（C++11提供）
- 匿名函数
- Lambda表达式把函数看作对象
- 与js不同，变量传递有传值和传引用的区别
``` C++
    [](int x, int y) -> int { int z = x + y; return z + x; }
```
``` C++
    [this]() { this->someFunc(); }();
```
- []传入已定义的变量，传值或传引用的方式都可以
```C++
    []      // 沒有定义任何变量。使用未定义变量会引发错误。
    [x, &y] // x以传值方式传入（默认），y以引用方式传入。
    [&]     // 任何被使用到的外部变量都隐式地以引用方式加以引用。
    [=]     // 任何被使用到的外部变量都隐式地以传值方式加以引用。
    [&, x]  // x显式地以传值方式加以引用。其余变量以引用方式加以引用。
    [=, &z] // z显式地以引用方式加以引用。其余变量以传值方式加以引用。
```

#### 随机数
1. srand(...)设置种子
2. rand()生成实际的随机数

#### 指针
##### 指针vs数组名
- 指向数组开头的指针可以通过指针的算术运算来访问数组
-  数组名也可以应用*，+，-等运算符，但不可以使用++，--，因为修改数组名的值是非法的，数组名是一个指向数组开头的**常量**，不能作为左值
##### 指向指针的指针
**冷静区别** & 是对变量取地址，* 是对变量取值即可。

#### 引用
##### 引用和指针的区别
- 不存在空引用。可以有空指针，而且最好在创建指针时初始化为NULL。
- 引用必须在创建时初始化。指针可以随时初始化。
``` C++
int i = 17;
int&  r = i;
```
- 一旦引用被初始化为一个对象，就不能被指向另一个对象。指针可以随时指向另一个对象。


## C++数据抽象 & 数据封装
- 数据抽象：仅向用户暴露接口而隐藏具体的实现细节的机制。用**类**来定义抽象的数据类型。
- 数据封装：把数据和操作数据的函数捆绑在一起的机制。

## C++抽象类
- 含有至少一个**纯虚函数**
- **不可以被实例化**
- 被当作**接口**来使用

## C++面向对象
#### 类
##### 访问修饰符
- public 公有成员：在类的外部可访问
- private 私有成员：类定义中未加修饰符的**默认为私有**，除了**类内部和友元函数**，在类的外部不可访问
- protected 受保护成员：除了**派生类**，在类的外部不可访问
##### 类的继承
- is a关系
- 可以多继承
``` C++
class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,…
{
<派生类类体>
};
```
- 继承类别
    - public 继承：基类public，protected，private ->派生类public，protected，private
    - protected 继承：基类public，protected，private ->派生类protected，protected，private
    - private 继承：基类public，protected，private ->派生类private，private，private
##### 构造函数 & 析构函数
- 构造函数：创建类的新对象时执行的函数。
    - **不返回任何类型，也不返回void类型**
    - 默认的构造函数不带参数，必要时可以自己添加参数
    - 使用**初始化列表**来初始化字段，经常在题库中节点结构体中出现
    ``` C++
    C::C( double a, double b, double c): X(a), Y(b), Z(c)
    {
      ....
    }
    ```
- [拷贝构造函数](https://www.runoob.com/cplusplus/cpp-copy-constructor.html)
- 析构函数：删除对象是执行的函数。
    - 形式类似于构造函数，只是在函数名前加~
    - 有助于在跳出程序时，释放资源
##### 静态成员 static
**1. 静态成员变量**
- 无论创建多少个类的对象，静态成员都只有一个副本
- 静态成员在类的所有对象中是共享的
- **不可以在类的定义(.h)中初始化静态成员**
*声明，要带双冒号*
``` C++
int Box::objectCount = 0;
```
*使用，要带双冒号*
``` C++
cout << "Total objects: " << Box::objectCount << endl;
```

**2. 静态成员函数**
- 静态成员函数在类的对象还没被创建的条件下也可以被调用，只要使用**类名带上双冒号**
- 静态成员函数与任何特定的对象独立开来，所以**不能使用this指针**访问
- 只能访问静态成员，静态成员变量和静态成员函数
``` C++
    static int getCount()
      {
         return objectCount;
      }
```

##### 友元函数 & 友元类 √
- **友元函数**
    - 不是成员函数
    - 在函数原型前加关键字**friend**

- 友元类
    - 在类的声明前加关键字**friend**
    - 友元类的所有成员函数都是那个类的友元函数
##### 内联函数 ？
- 在函数原型前添加关键字**inline**
- 在类定义中定义的函数都是内联函数，即使没有使用inline关键字
- 如果一个函数是内联函数，那么在编译时，编译器会将该函数的代码副本放置在每个调用该函数的地方。(减少编译时在调用时写成函数开销？)
##### this指针
- 每个对象都可以通过this指针访问自己的地址
- this指针是类的所有成员函数的隐式参数，可以在成员函数内部直接使用this指针访问调用对象
``` C++
    double Volume()
      {
         return length * breadth * height;
      }
      int compare(Box box)
      {
         return this->Volume() > box.Volume();
      }
```
- 友元函数没得使用this指针，因为友元函数不是类的成员函数
##### 指向类的指针
- 类似于指向结构体的指针
- 和所有指针一样，在**使用指针前必须先初始化指针**

## C++重载运算符 & 重载函数
*调用重载函数或重载运算符时，编译器会进行重载决策，选择合适的重载函数或重载运算符*
- 函数重载：函数名相同，但参数列表必须不同
- 运算符重载
    - 是一个带有特殊名称的**函数**
    - 函数名是由关键字**operator**和运算符符号构成，和其他函数一样有返回类型和参数列表

## C++多态
#### 虚函数
- 基类声明函数要加关键字**virtual**，即**虚函数**
- 派生类重新定义基类的虚函数时，会告诉编译器不要静态链接到基类的函数
- 派生类对象调用此函数时，编译器会根据对象类型**动态链接**到派生类的函数
#### 纯虚函数
- 在基类定义虚函数时，又不对虚函数给出实现，这时候会用到纯虚函数
- 用=0告诉编译器，这个虚函数没有主体
``` C++
virtual int area() = 0;
```

## C++模板
*库容器也就使用了模板的概念*
#### 函数模板

#### 类模板


## C++动态内存 √
#### C++程序中内存
- 栈：管理函数内部声明的所有**变量**
- 堆：管理程序中为使用的内存，在程序运行时可用于**动态分配**内存
#### new & delete
##### new
- 用来请求分配内存，并用指针指向这块内存
- **new vs malloc()函数 √**
    - new：返回指定类型的指针
    - malloc()：用于申请一块连续的指定大小的内存空间
        - 返回void*，需要强制类型转换成对应的指针类型
        - 用free()函数释放内存
##### delete
- 用来释放指针指向的内存
#### 数组的动态内存分配 √
``` C++
int **array;
// 假定数组第一维长度为 m， 第二维长度为 n
// 动态分配空间
array = new int *[m];
for( int i=0; i<m; i++ )
{
    array[i] = new int [n]  ;
}
//释放
for( int i=0; i<m; i++ )
{
    delete [] arrary[i];
}
delete [] array;
```
#### 对象的动态内存分配
和普通的数据类型雷同，创建一个对象则调用一次构造函数，删除一个对象就调用一次析构函数
``` C++
#include <iostream>
using namespace std;
 
class Box
{
   public:
      Box() { 
         cout << "调用构造函数！" <<endl; 
      }
      ~Box() { 
         cout << "调用析构函数！" <<endl; 
      }
};
 
int main( )
{
   Box* myBoxArray = new Box[4];
 
   delete [] myBoxArray; // 删除数组
   return 0;
}
```
输出
``` C++
调用构造函数！
调用构造函数！
调用构造函数！
调用构造函数！
调用析构函数！
调用析构函数！
调用析构函数！
调用析构函数！
```



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
