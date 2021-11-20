#### Launch语法

##### 启动节点

<node pkg="package-name" type="executable-name" name="node-name"/>

pck: 节点所在的功能包名称

type:节点的可执行文件名称

name:节点运行时的名称

另 ：output、respawn、required、ns、args

##### param

设置ROS系统运行中的参数，存储在参数服务器中

##### arg

launch文件内部的局部变量，仅用于launch文件使用

<arg name="arg-name" default="arg-value"/>

name:参数名

value:参数值

调用：

<param name="foo" value="$(arg arg-name)"/>

<node name="node" pkg="package" type="type" args="$(arg arg-name)"/>



##### 重映射

重映射ROS计算图资源的命名

<remap from="/turtlebot/cmd_vel" to="/cmd_vel"/>

##### 嵌套

包含其他launch文件，类似于C语言中的头文件包含

<include file="$(dirname)/other.launch"/>
