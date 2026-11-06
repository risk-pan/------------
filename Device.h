#ifndef DEVICE_H
#define DEVICE_H

#include <string>
using namespace std;

class Device
{
private:
    string id;          // 设备编号
    string name;        // 设备名称
    string roomName;    // 所在房间
    bool isOn;          // 开关状态

public:
    Device();
    void setInfo(string deviceId, string deviceName, string room);
    void changeInfo(string newName, string newRoom);
    void turnOn();
    void turnOff();
    void display() const;
    string getId() const;
};

#endif