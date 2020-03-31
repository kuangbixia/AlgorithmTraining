# 复盘
## 计算机网络
#### 四个层
- 应用层（HTTP，DNS）
- 传输层（TCP，UDP）
- 网络层（IP）
- 链路层
#### a day in the life of a web request
##### 1. 连接到网络
- 接收端：DHCP服务器
- 局域网
- 使用DHCP（动态主机配置协议）
- 客户端：获取本机的 ip 地址，第一跳转路由器的地址，DNS 服务器的地址
##### 2. ARP
- 接收端：DHCP服务器
- 客户端：ARP请求，获取第一跳转路由器接口的MAC地址
- 使用ARP（解析地址的协议，根据ip地址查出MAC地址）
##### 3. 使用DNS
- 接收端：DNS服务器
- **解析域名**的DNS服务
- 客户端：获取到web服务器的ip地址
##### 4. 为了http请求建立tcp连接
- 使用TCP协议，著名的**三次握手**
- 接收端：web服务器
- 客户端：向web服务器打开tcp socket
##### 5. http请求/响应
- 客户端：http请求（应用层）发送到tcp socket（传输层）里面，被包含在ip数据包（网络层）中，发送到web服务器
- web服务器：http响应（web页面），包含在ip数据包，发送到客户端