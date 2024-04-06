/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-10 23:41:37 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-23 00:19:04
 */

#include "Devices.h"

Devices::Devices(cl_platform_id platformId)
{
    m_err = m_oclLibLoader.GetDeviceIDs(platformId, CL_DEVICE_TYPE_ALL, 0, nullptr, &m_deviceNum);
    if (m_err != CL_SUCCESS) {
        LOGE("run opencl failed! err=%d", m_err);
        return;
    }
    m_deviceIds.reset(new (std::nothrow) cl_device_id[m_deviceNum]);
    m_err = m_oclLibLoader.GetDeviceIDs(platformId, CL_DEVICE_TYPE_ALL, m_deviceNum, m_deviceIds.get(), nullptr);
    if (m_err != CL_SUCCESS) {
        LOGE("run opencl failed! err=%d", m_err);
        m_deviceIds.reset();
        m_deviceNum = 0;
        return;
    }
    for (int i = 0; i < m_deviceNum; i++) {
        m_devices.push_back(std::make_shared<Device>(m_deviceIds[i]));
    }
}

Devices::~Devices()
{
    m_devices.clear();
    m_deviceIds.reset();
}

std::vector<std::shared_ptr<Device>> Devices::GetDevices()
{
    return m_devices;
}