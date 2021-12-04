### ros_comm

ros_comm本质为通信中间件，包含了许多通信功能包，他们就是我们熟知的图表层，图表层基本概念有：

#### 1.master

ROS master为ROS中其余节点提供命名与注册服务，它跟踪主题和服务的发布者和订阅者。ROS主节点使得其余节点能够互相定位，同时，它还提供Parameter server(参数服务器)

**通常由roscore命令运行**

#### 2.parameter server

是可以通过网络API访问的共享多变量字典（**即结构体**），全局可见，以便节点在运行时存储和检索数据。

#### 3.topic

是被命名的节点间交换信息所用的总线，具有匿名发布和订阅信息的功能。Topic主要用于单向流通信，远程程序调用则需要service。

**topic tools**

```markdown
$ rostopic list  //列出当前所有话题
$ rostopic echo /topic_name  //呈现某个话题的具体内容
```

#### 4.service

服务由一对消息定义：一条用于请求，一条用于回复一个给定的ROS节点提供一个被命名好的服务，客户端通过发送请求消息并等待回复来调用服务。

#### 5.messages

节点通过将消息发布到主题来互相通信。消息是一种简单的数据结构，通常为msg文件

消息类型的标准命名约定： **功能包名称/msg文件名称**   例：std_msgs/msg/String.msg的消息类型为std_msgs/String

#### 6.bags

bag是 ROS 中用于存储 ROS消息数据的文件格式。

##### rosbag: 用于录制，回放和其他操作的统一控制工具

##### rqt_bag:用于可视化bag文件的图形工具

