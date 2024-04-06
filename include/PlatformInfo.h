/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-09 22:26:59 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-21 23:44:43
 */

#ifndef PLATFORM_INFO_H
#define PLATFORM_INFO_H

#include "define.h"

class PlatformInfo {
public:
    PlatformInfo(cl_platform_id platformId);
    ~PlatformInfo() = default;
    const std::string &GetProfile();
    const std::string &GetVersion();
    const std::string &GetName();
    const std::string &GetVendor();
    const std::string &GetExtension();

private:
    cl_int m_err = CL_SUCCESS;
    std::string m_profile;
    std::string m_version;
    std::string m_name;
    std::string m_vendor;
    std::string m_extensions;
    OCLLibLoader m_oclLibLoader;
};

#endif  // PLATFORM_INFO_H