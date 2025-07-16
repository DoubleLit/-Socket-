#include <iostream>
#include <cstdint> // 包含uint8_t等类型
int main()
{
    // 定义电机ID（使用uint8_t，因为宇树SDK中电机ID通常为1字节无符号整数）
    uint8_t hip_motor_id = 1;   // 髋关节电机ID
    uint8_t knee_motor_id = 2;  // 膝关节电机ID
    uint8_t ankle_motor_id = 3;  // 脚踝关节电机ID

    // 定义关节角度（单位：弧度，float足够）
    float hip_angle_radian = 0.0f;      // 髋关节角度，初始化为0弧度
    float knee_angle_radian = 1.57f;    // 膝关节角度，初始化为π/2≈1.57弧度
    float ankle_angle_radian = 0.785f;    // 脚踝关节角度，初始化为π/4≈0.785弧度


    // 定义关节角度（单位：角度，float足够）【注：】角度 = 弧度 / 圆周率 * 180.0
    float hip_angle = static_cast<float>(hip_angle_radian*1.80e2/3.14f);      // 髋关节角度，初始化为0.0角度
    float knee_angle = static_cast<float>(knee_angle_radian * 1.80e2 / 3.14f);    // 膝关节角度，初始化为90角度
    float ankle_angle = static_cast<float>(ankle_angle_radian * 1.80e2 / 3.14f);    // 脚踝关节角度，初始化为45角度

    // 打印变量值
    std::cout << "Hip Motor ID: " << static_cast<int>(hip_motor_id) << std::endl;
    std::cout << "Knee Motor ID: " << static_cast<int>(knee_motor_id) << std::endl;
    std::cout << "Ankle Motor ID: " << static_cast<int>(ankle_motor_id) << std::endl;
    // 打印关节角度（单位°）
    std::cout << "Hip Angle: " << hip_angle << " °" << std::endl;
    std::cout << "Knee Angle: " << knee_angle << " °" << std::endl;
    std::cout << "Ankle Angle: " << ankle_angle << " °" << std::endl;


    // 尝试修改变量
    hip_angle_radian = 0.5f;  // 髋关节移动到0.5弧度
    knee_angle_radian = 2.0f; // 膝关节移动到2.0弧度
    ankle_angle_radian = 1.1f; // 脚踝关节移动到2.0弧度
    std::cout << "\nAfter movement:" << std::endl;
    std::cout << "Hip Angle: " << static_cast<float>(hip_angle_radian * 1.80e2 / 3.14f) << " °" << std::endl;
    std::cout << "Knee Angle: " << static_cast<float>(knee_angle_radian * 1.80e2 / 3.14f) << " °" << std::endl;
    std::cout << "Ankle Angle: " << static_cast<float>(ankle_angle_radian * 1.80e2 / 3.14f) << " °" << std::endl;
    return 0;
}