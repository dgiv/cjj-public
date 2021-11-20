### ROSWTF

a tool for diagnosing issues with a running ROS system  (主要用于检查环境变量和查找配置问题)

#### 一、用法

##### 1.直接检查功能包或数据栈

```c
$  roswtf
```



注意： **roswtf会根据所运行的目录来进行检查**

##### 2.检查launch文件

```c
$ roswtf yourfile.launch
```



#### 二、查找内容

1.文件系统方面： 环境变量、封装配置、堆栈配置以及launch文件的检查

2.线上方面：检查当前节点图表的状态







