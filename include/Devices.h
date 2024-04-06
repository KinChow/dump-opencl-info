/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-09 23:01:07 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-21 23:53:30
 */

#ifndef DEVICES_H
#define DEVICES_H

#include "Device.h"
#include "define.h"

class Devices {
public:
    Devices(cl_platform_id platformId);
    ~Devices();
    std::vector<std::shared_ptr<Device>> GetDevices();

private:
    std::unique_ptr<cl_device_id[]> m_deviceIds;
    cl_uint m_deviceNum = 0;
    cl_int m_err = CL_SUCCESS;
    std::vector<std::shared_ptr<Device>> m_devices;
};

#endif  // DEVICES_H