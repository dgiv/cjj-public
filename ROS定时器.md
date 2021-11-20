### ROS定时器的使用

#### 1.定时器的创建

```c
ros::NodeHandle n;
ros::Timer timer = n.createtimer(ros::Duration(0.1),<callback>,bool oneshot = false);
//Duration: 时间间隔
//<callback>:回调函数（类型：functions函数，class methods,functor objects）
//oneshot: 表示是否只执行一次，一般可省
```

#### 2.回调函数的数据结构体

ros::TimerEvent结构体说明：

ros::Time last_expected 上次回调期望发生的时间

ros::Time last_real 上次回调实际发生的时间

ros::Time current_expected 本次回调期待发生的时间

ros::Time current_real 本次回调实际发生的时间

ros::WallTime profile.last_duration 上次回调的时间间隔