/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-10 23:57:43 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-23 00:18:23
 */

#include "PlatformInfo.h"

void GetPlatformInfo(OCLLibLoader &oclLibLoader, cl_platform_id platformId, cl_platform_info param_name, cl_int &err,
    std::string &info)
{
    size_t infoSize;
    err = oclLibLoader.GetPlatformInfo(platformId, param_name, 0, nullptr, &infoSize);
    if (err != CL_SUCCESS) {
        LOGE("run opencl failed! err=%d", err);
        return;
    }
    std::unique_ptr<char[]> upInfo(new (std::nothrow) char[infoSize]);
    err = oclLibLoader.GetPlatformInfo(platformId, param_name, infoSize, upInfo.get(), nullptr);
    if (err != CL_SUCCESS) {
        LOGE("run opencl failed! err=%d", err);
        return;
    }
    info.assign(upInfo.get(), infoSize);
}

PlatformInfo::PlatformInfo(cl_platform_id platformId)
{
    GetPlatformInfo(m_oclLibLoader, platformId, CL_PLATFORM_PROFILE, m_err, m_profile);
    GetPlatformInfo(m_oclLibLoader, platformId, CL_PLATFORM_VERSION, m_err, m_version);
    GetPlatformInfo(m_oclLibLoader, platformId, CL_PLATFORM_NAME, m_err, m_name);
    GetPlatformInfo(m_oclLibLoader, platformId, CL_PLATFORM_VENDOR, m_err, m_vendor);
    GetPlatformInfo(m_oclLibLoader, platformId, CL_PLATFORM_EXTENSIONS, m_err, m_extensions);
}

const std::string &PlatformInfo::GetProfile()
{
    return m_profile;
}

const std::string &PlatformInfo::GetVersion()
{
    return m_version;
}

const std::string &PlatformInfo::GetName()
{
    return m_name;
}

const std::string &PlatformInfo::GetVendor()
{
    return m_vendor;
}

const std::string &PlatformInfo::GetExtension()
{
    return m_extensions;
}