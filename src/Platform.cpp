/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-10 23:32:16 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-21 23:32:36
 */

#include "Platform.h"

Platform::Platform(cl_platform_id platformId)
{
    m_platformInfo = std::make_shared<PlatformInfo>(platformId);
    m_devices = std::make_shared<Devices>(platformId);
}

std::shared_ptr<PlatformInfo> Platform::GetPlatformInfo()
{
    return m_platformInfo;
}

std::shared_ptr<Devices> Platform::GetDevices()
{
    return m_devices;
}