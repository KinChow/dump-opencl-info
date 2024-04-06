/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-10 22:58:36 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-21 23:30:03
 */

#ifndef DEVICE_H
#define DEVICE_H

#include "DeviceInfo.h"
#include "define.h"

class Device {
public:
    Device(cl_device_id deviceId);
    ~Device() = default;
    std::shared_ptr<DeviceInfo> GetDeviceInfo();

private:
    std::shared_ptr<DeviceInfo> m_deviceInfo;
};

#endif  // DEVICE_H