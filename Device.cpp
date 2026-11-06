#include "Device.h"
#include <iostream>
using namespace std;

// 设置设备信息
void Device::setInfo(string deviceId, string deviceName, string room)
{
    id = deviceId;
    name = deviceName;
    roomName = room;
    isOn = false;
}

// 打开设备
void Device::turnOn()
{
    isOn = true;
}

// 关闭设备
void Device::turnOff()
{
    isOn = false;
}

// 显示设备信息
void Device::display()
{
    cout << "设备编号：" << id
         << "，设备名称：" << name
         << "，所在房间：" << roomName
         << "，状态：" << (isOn ? "开启" : "关闭")
         << endl;
}

// 获取设备编号
string Device::getId()
{
    return id;
}