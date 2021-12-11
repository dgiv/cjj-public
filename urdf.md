### URDF(Unified Robot Description Format 统一机器人描述格式)

#### 一.urdf语法规范

##### 1.< robot >element 机器人

< link>  < joint> < transmission> < gazebo>

标签选项：name 

例：

```xml
<robot name="robot1">
<!-- robot1 robot links and joints and more -->
</robot>
```

##### 2.< sensor>element 传感器

标签选项：

a. name （required）(字符串)  传感器名称

b. type (required)  (字符串)   传感器类型

c. id (optional)  (字符串) 传感器id

d. update_rate (optional) (float) (Hz) 传感器数据产生频率，默认为每次循环一次

#####  3.< link>element  具有惯性，视觉外观和碰撞体积的机器人环节

标签属性：name

elements:

a.< inertial(**惯性**)>   (optional  默认为零质量和零惯性)

  **< origin>**

 定义惯性坐标系相对于参考坐标系的姿态。惯性坐标系的原点需要在重心处。惯性参考系的轴线不需要与主轴对齐。

​	**xyz**: 代表 轴向向量

​	**rpy**:以弧度表示固定轴的滚转，俯仰与偏航角

**< mass>**

该元素的值代表该刚体的质量

**< inertia>**

3*3的转动惯量矩阵，用惯性坐标系表示。由于转动惯量矩阵的对称性，只需指定该矩阵对角线上方的6个元素：ixx,ixy,ixz,iyy,iyz,izz.

b.< visual>(optional) 刚体的视觉属性，可指定目标对象的形状 （**同一link标签可存在多个< visual>标签，它们的并集形成了刚体的视觉外观）

**< name>**(optional)

**< origin>**(optional)

**< geometry>**(required) *表征该对象的几何形状*

**< box>**  size属性指定该长方体的三个边长，原点在其几何中心

**< cylinder>**指定该圆柱体的半径和长度，原点在其几何中心

**< sphere>** 指定该球体的半径，原点在其几何中心

**< mesh>** 网格

c.< collision>(optional)  刚体的碰撞体积

比上述视觉外观更简单以缩减计算时间

例：

```xml
<link name="my_link">
   <inertial>
     <origin xyz="0 0 0.5" rpy="0 0 0"/>
     <mass value="1"/>
     <inertia ixx="100"  ixy="0"  ixz="0" iyy="100" iyz="0" izz="100" />
   </inertial>

   <visual>
     <origin xyz="0 0 0" rpy="0 0 0" />
     <geometry>
       <box size="1 1 1" />
     </geometry>
     <material name="Cyan">
       <color rgba="0 1.0 1.0 1.0"/>
     </material>
   </visual>

   <collision>
     <origin xyz="0 0 0" rpy="0 0 0"/>
     <geometry>
       <cylinder radius="1" length="0.5"/>
     </geometry>
   </collision>
 </link>
```



#### 4. < joint>element 描述了关节的运动学与动力学，同时表征了它的安全极限。

标签属性：

name(*required*)

type(*required*) 具体类型见ROS-Wiki

element:

**< origin>**( optional) 从父连接向子连接的转换，关节原点为子连接坐标原点。

**< parent>**(required) 父连接

**< child>** (required) 子连接

**< axis>** (optional 默认为(1,0,0))

**< calibration>**

**< dynamics>**

**< limit>**

例：

```xml
 <joint name="my_joint" type="floating">
    <origin xyz="0 0 1" rpy="0 0 3.1416"/>
    <parent link="link1"/>
    <child link="link2"/>

    <calibration rising="0.0"/>
    <dynamics damping="0.0" friction="0.0"/>
    <limit effort="30" velocity="1.0" lower="-2.2" upper="0.7" />
    <safety_controller k_velocity="10" k_position="15" soft_lower_limit="-2.0" soft_upper_limit="0.5" />
 </joint>
```



