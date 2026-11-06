#include "Device.h"
#include <iostream>
using namespace std;

// 构造函数
Device::Device()
{
    id = "";
    name = "";
    roomName = "";
    isOn = false;
}

// 设置设备信息
void Device::setInfo(string deviceId, string deviceName, string room)
{
    id = deviceId;
    name = deviceName;
    roomName = room;
    isOn = false;
}

// 修改设备名称和房间，不修改设备编号
void Device::changeInfo(string newName, string newRoom)
{
    name = newName;
    roomName = newRoom;
    cout << "设备信息修改成功！" << endl;
}

// 开启设备
void Device::turnOn()
{
    if (isOn)
    {
        cout << "设备已经处于开启状态！" << endl;
        return;
    }

    isOn = true;
    cout << "设备开启成功！" << endl;
}

// 关闭设备
void Device::turnOff()
{
    if (!isOn)
    {
        cout << "设备已经处于关闭状态！" << endl;
        return;
    }

    isOn = false;
    cout << "设备关闭成功！" << endl;
}

// 显示设备信息
void Device::display() const
{
    cout << "设备编号：" << id
         << "，设备名称：" << name
         << "，所在房间：" << roomName
         << "，状态：" << (isOn ? "开启" : "关闭")
         << endl;
}

// 获取设备编号
string Device::getId() const
{
    return id;
}