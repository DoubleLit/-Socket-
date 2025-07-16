                                                                                                             C++基础语法学习
     我们聚焦于C++基础语法中的数据类型和变量定义，结合机器人开发中“定义关节角度(float)、电机ID(int)”的案例，设计一个三天的高效学习计划。该计划完全不需要硬件，通过纯代码练习掌握核心概念。
总体的学习目标
1. 理解基本数据类型：重点掌握`int`, `float`, `uint8_t`等。
2. 学会定义变量：包括初始化、赋值、作用域。
3. 掌握常量定义：`const`和`constexpr`。
4. 应用案例：定义关节角度（float）和电机ID（整数类型）。
5. 了解枚举和结构体（拓展，因为宇树SDK中用到）。

  **  三天学习计划（每天2-3小时）**

 Day 1: 基础数据类型与变量定义
学习内容：
1. 整型：`int`, `short`, `long`, `unsigned`及固定宽度类型（如`uint8_t`）。
2. 浮点型：`float`, `double`。
3. 字符型：`char`。
4. 布尔型：`bool`。
5. 变量定义、初始化与赋值。

机器人案例练习：
```cpp
#include <iostream>
#include <cstdint> // 包含uint8_t等类型
int main() {
    // 定义电机ID（使用uint8_t，因为宇树SDK中电机ID通常为1字节无符号整数）
    uint8_t hip_motor_id = 1;   // 髋关节电机ID
    uint8_t knee_motor_id = 2;  // 膝关节电机ID
    // 定义关节角度（单位：弧度，float足够）
    float hip_angle = 0.0f;      // 髋关节角度，初始化为0弧度
    float knee_angle = 1.57f;    // 膝关节角度，初始化为π/2≈1.57弧度（90度）
    // 打印变量值
    std::cout << "Hip Motor ID: " << static_cast<int>(hip_motor_id) << std::endl;
    std::cout << "Knee Motor ID: " << static_cast<int>(knee_motor_id) << std::endl;
    std::cout << "Hip Angle: " << hip_angle << " rad" << std::endl;
    std::cout << "Knee Angle: " << knee_angle << " rad" << std::endl;
    // 尝试修改变量
    hip_angle = 0.5f;  // 髋关节移动到0.5弧度
    knee_angle = 2.0f; // 膝关节移动到2.0弧度
    std::cout << "\nAfter movement:" << std::endl;
    std::cout << "Hip Angle: " << hip_angle << " rad" << std::endl;
    std::cout << "Knee Angle: " << knee_angle << " rad" << std::endl;
    return 0;
}
```
任务：
1. 运行上述代码，理解变量定义和初始化。
2. 添加一个名为`ankle_motor_id`的电机ID（值为3）和`ankle_angle`（初始值为0.78f，约45度）。
3. 修改代码，将角度值从弧度转换为度（输出时显示，变量存储仍用弧度）。

 Day 2: 常量、枚举与结构体
学习内容：
1. 常量：`const`和`constexpr`。
2. 枚举类型：`enum`。
3. 结构体：`struct`。

机器人案例练习：
```cpp
#include <iostream>
#include <cstdint>
// 使用枚举定义电机控制模式（模仿宇树SDK）
enum class MotorMode : uint8_t {
    DAMPING = 0,  // 阻尼模式
    TORQUE,       // 扭矩控制
    VELOCITY,     // 速度控制
    POSITION      // 位置控制
};
// 定义一个结构体表示电机状态（模仿宇树SDK的MotorState简化版）
struct MotorState {
    uint8_t id;           // 电机ID
    MotorMode mode;       // 当前模式
    float angle;          // 当前角度（rad）
    float velocity;       // 当前速度（rad/s）
};
int main() {
    // 使用常量定义电机数量
    constexpr uint8_t MOTOR_COUNT = 2;
    // 创建两个电机的状态结构体
    MotorState hip_motor = {1, MotorMode::POSITION, 0.0f, 0.0f};
    MotorState knee_motor = {2, MotorMode::POSITION, 1.57f, 0.0f};
    // 打印电机状态
    std::cout << "Hip Motor State:" << std::endl;
    std::cout << "  ID: " << static_cast<int>(hip_motor.id) << std::endl;
    std::cout << "  Mode: " << static_cast<int>(hip_motor.mode) << std::endl;
    std::cout << "  Angle: " << hip_motor.angle << " rad" << std::endl;
    // 尝试修改模式（从位置控制切换到扭矩控制）
    hip_motor.mode = MotorMode::TORQUE;
    std::cout << "\nHip Motor switched to torque mode: " 
              << static_cast<int>(hip_motor.mode) << std::endl;
    return 0;
}
```
任务：
1. 添加第三个电机（脚踝）的状态。
2. 为`MotorState`结构体增加一个成员`temperature`（温度，float类型），并在初始化时赋值（假设为25.0f）。
3. 打印所有三个电机的温度。
 Day 3: 数组、向量与多关节控制
学习内容：
1. 数组：`std::array`（固定大小）或C风格数组。
2. 向量：`std::vector`（动态数组）。
3. 使用容器管理多个关节。
机器人案例练习：
```cpp
#include <iostream>
#include <vector>
#include <array>
#include <cstdint>
struct JointState {
    uint8_t id;
    float angle; // 单位：弧度
};
int main() {
    // 使用数组存储3个关节的角度（固定大小）
    std::array<float, 3> joint_angles = {0.0f, 1.57f, 0.78f}; // 髋、膝、踝
    // 打印数组中的关节角度
    std::cout << "Joint angles (array):" << std::endl;
    for (int i = 0; i < joint_angles.size(); ++i) {
        std::cout << "Joint " << i+1 << ": " << joint_angles[i] << " rad" << std::endl;
    }
    // 使用向量存储关节状态（动态大小，更灵活）
    std::vector<JointState> leg_joints;
    leg_joints.push_back({1, 0.0f});    // 髋关节
    leg_joints.push_back({2, 1.57f});   // 膝关节
    leg_joints.push_back({3, 0.78f});   // 踝关节
    // 打印向量中的关节状态
    std::cout << "\nJoint states (vector):" << std::endl;
    for (const auto& joint : leg_joints) {
        std::cout << "Motor ID: " << static_cast<int>(joint.id)
                  << ", Angle: " << joint.angle << " rad" << std::endl;
    }
    // 修改踝关节角度
    leg_joints[2].angle = 1.0f; // 修改第三个元素（踝关节）
    std::cout << "\nAnkle joint angle updated to: " << leg_joints[2].angle << " rad" << std::endl;
    return 0;
}
```
任务：
1. 创建一个包含4个关节（例如：髋、膝、踝、腰）的向量，并初始化它们的ID和角度。
2. 编写一个循环，将向量中所有关节的角度增加0.1弧度（模拟运动），然后打印新的角度值。
 资源推荐
1. 在线编译器：[Compiler Explorer (gcc)](https://godbolt.org/) - 快速测试代码片段。
2. 学习网站：
   - [Learn C++](https://www.learncpp.com/)：免费高质量教程。
   - [C++ Reference](https://en.cppreference.com/)：权威参考。
3. 书籍：《C++ Primer》（第5版）前几章。
 验收标准
- 完成每天的任务代码，并成功编译运行。
- 理解每个案例中变量和数据类型的含义。
- 能够独立定义类似宇树SDK中的电机ID和关节角度变量。
此计划可在三天内集中学习核心数据类型和变量定义，并通过机器人案例加深理解，无需硬件即可完成。
