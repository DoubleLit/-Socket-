#include <iostream>
#include <cstdint> // ����uint8_t������
int main()
{
    // ������ID��ʹ��uint8_t����Ϊ����SDK�е��IDͨ��Ϊ1�ֽ��޷���������
    uint8_t hip_motor_id = 1;   // �Źؽڵ��ID
    uint8_t knee_motor_id = 2;  // ϥ�ؽڵ��ID
    uint8_t ankle_motor_id = 3;  // ���׹ؽڵ��ID

    // ����ؽڽǶȣ���λ�����ȣ�float�㹻��
    float hip_angle_radian = 0.0f;      // �ŹؽڽǶȣ���ʼ��Ϊ0����
    float knee_angle_radian = 1.57f;    // ϥ�ؽڽǶȣ���ʼ��Ϊ��/2��1.57����
    float ankle_angle_radian = 0.785f;    // ���׹ؽڽǶȣ���ʼ��Ϊ��/4��0.785����


    // ����ؽڽǶȣ���λ���Ƕȣ�float�㹻����ע�����Ƕ� = ���� / Բ���� * 180.0
    float hip_angle = static_cast<float>(hip_angle_radian*1.80e2/3.14f);      // �ŹؽڽǶȣ���ʼ��Ϊ0.0�Ƕ�
    float knee_angle = static_cast<float>(knee_angle_radian * 1.80e2 / 3.14f);    // ϥ�ؽڽǶȣ���ʼ��Ϊ90�Ƕ�
    float ankle_angle = static_cast<float>(ankle_angle_radian * 1.80e2 / 3.14f);    // ���׹ؽڽǶȣ���ʼ��Ϊ45�Ƕ�

    // ��ӡ����ֵ
    std::cout << "Hip Motor ID: " << static_cast<int>(hip_motor_id) << std::endl;
    std::cout << "Knee Motor ID: " << static_cast<int>(knee_motor_id) << std::endl;
    std::cout << "Ankle Motor ID: " << static_cast<int>(ankle_motor_id) << std::endl;
    // ��ӡ�ؽڽǶȣ���λ�㣩
    std::cout << "Hip Angle: " << hip_angle << " ��" << std::endl;
    std::cout << "Knee Angle: " << knee_angle << " ��" << std::endl;
    std::cout << "Ankle Angle: " << ankle_angle << " ��" << std::endl;


    // �����޸ı���
    hip_angle_radian = 0.5f;  // �Źؽ��ƶ���0.5����
    knee_angle_radian = 2.0f; // ϥ�ؽ��ƶ���2.0����
    ankle_angle_radian = 1.1f; // ���׹ؽ��ƶ���2.0����
    std::cout << "\nAfter movement:" << std::endl;
    std::cout << "Hip Angle: " << static_cast<float>(hip_angle_radian * 1.80e2 / 3.14f) << " ��" << std::endl;
    std::cout << "Knee Angle: " << static_cast<float>(knee_angle_radian * 1.80e2 / 3.14f) << " ��" << std::endl;
    std::cout << "Ankle Angle: " << static_cast<float>(ankle_angle_radian * 1.80e2 / 3.14f) << " ��" << std::endl;
    return 0;
}