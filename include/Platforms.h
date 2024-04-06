/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-09 23:01:11 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-21 23:40:58
 */

#ifndef PLATFORMS_H
#define PLATFORMS_H

#include "Platform.h"
#include "define.h"

class Platforms {
public:
    Platforms();
    ~Platforms();
    std::vector<std::shared_ptr<Platform>> GetPlatforms();

private:
    std::unique_ptr<cl_platform_id[]> m_platformIds;
    cl_uint m_platformNum = 0;
    cl_int m_err = CL_SUCCESS;
    std::vector<std::shared_ptr<Platform>> m_platforms;
    OCLLibLoader m_oclLibLoader;
};

#endif  // PLATFORMS_H