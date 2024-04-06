/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-10 23:18:03 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-23 00:17:50
 */

#include "Platforms.h"

Platforms::Platforms()
{
    m_err = clGetPlatformIDs(0, nullptr, &m_platformNum);
    if (m_err != CL_SUCCESS) {
        LOGE("run opencl failed! err=%d", m_err);
        return;
    }
    if (m_platformNum == 0) {
        LOGE("no platform");
        return;
    }
    m_platformIds.reset(new (std::nothrow) cl_platform_id[m_platformNum]);
    if (m_platformIds == nullptr) {
        return;
    }
    m_err = clGetPlatformIDs(m_platformNum, m_platformIds.get(), nullptr);
    if (m_err != CL_SUCCESS) {
        LOGE("run opencl failed! err=%d", m_err);
        m_platformIds.reset();
        m_platformNum = 0;
        return;
    }
    for (int i = 0; i < m_platformNum; i++) {
        m_platforms.push_back(std::make_shared<Platform>(m_platformIds[i]));
    }
}

Platforms::~Platforms()
{
    m_platforms.clear();
    m_platformIds.reset();
}

std::vector<std::shared_ptr<Platform>> Platforms::GetPlatforms()
{
    return m_platforms;
}