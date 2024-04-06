/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-10 23:53:30 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-21 23:30:57
 */

#include "Device.h"

Device::Device(cl_device_id deviceId)
{
    m_deviceInfo = std::make_shared<DeviceInfo>(deviceId);
}

std::shared_ptr<DeviceInfo> Device::GetDeviceInfo()
{
    return m_deviceInfo;
}