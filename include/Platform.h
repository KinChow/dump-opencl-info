/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-10 22:58:39 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-21 23:32:44
 */

#ifndef PLATFORM_H
#define PLATFORM_H

#include "Devices.h"
#include "PlatformInfo.h"
#include "define.h"

class Platform {
public:
    Platform(cl_platform_id platformId);
    ~Platform() = default;
    std::shared_ptr<PlatformInfo> GetPlatformInfo();
    std::shared_ptr<Devices> GetDevices();

private:
    std::shared_ptr<PlatformInfo> m_platformInfo;
    std::shared_ptr<Devices> m_devices;
};

#endif  // PLATFORM_H