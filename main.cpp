#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

#include "Device.h"

using namespace std;

int main()
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    Device devices[100];  
    int count = 0;        

    while (true)
    {
        cout << "\n========== 智能家居设备控制系统 ==========\n";
        cout << "1. 创建设备\n";
        cout << "2. 显示所有设备\n";
        cout << "3. 查询设备\n";
        cout << "4. 打开设备\n";
        cout << "5. 关闭设备\n";
        cout << "0. 退出系统\n";
        cout << "请选择：";

        string choice;
        getline(cin, choice);

        if (choice == "1")
        {
            if (count >= 100)
            {
                cout << "设备数量已达到上限！\n";
                continue;
            }

            string id, name, room;

            cout << "请输入设备编号：";
            getline(cin, id);

            cout << "请输入设备名称：";
            getline(cin, name);

            cout << "请输入所在房间：";
            getline(cin, room);

            // 检查编号和名称是否为空
            if (id.empty() || name.empty())
            {
                cout << "创建失败：设备编号和名称不能为空！\n";
                continue;
            }

            // 检查编号是否重复
            bool duplicate = false;

            for (int i = 0; i < count; i++)
            {
                if (devices[i].getId() == id)
                {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate)
            {
                cout << "创建失败：设备编号已经存在！\n";
                continue;
            }

            devices[count].setInfo(id, name, room);
            count++;

            cout << "设备创建成功！\n";
        }
        else if (choice == "2")
        {
            if (count == 0)
            {
                cout << "当前没有设备。\n";
            }
            else
            {
                cout << "\n========== 设备列表 ==========\n";

                for (int i = 0; i < count; i++)
                {
                    devices[i].display();
                }
            }
        }
        else if (choice == "3" || choice == "4" || choice == "5")
        {
            string id;
            cout << "请输入设备编号：";
            getline(cin, id);

            int index = -1;

            // 根据编号查找设备
            for (int i = 0; i < count; i++)
            {
                if (devices[i].getId() == id)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "操作失败：没有找到该设备！\n";
                continue;
            }

            if (choice == "3")
            {
                devices[index].display();
            }
            else if (choice == "4")
            {
                devices[index].turnOn();
                cout << "设备已开启！\n";
                devices[index].display();
            }
            else
            {
                devices[index].turnOff();
                cout << "设备已关闭！\n";
                devices[index].display();
            }
        }
        else if (choice == "0")
        {
            cout << "系统已退出。\n";
            break;
        }
        else
        {
            cout << "输入无效，请重新选择！\n";
        }
    }

    return 0;
}