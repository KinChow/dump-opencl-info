/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-09 22:27:03 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-19 00:29:30
 */

#ifndef DEVICE_INFO_H
#define DEVICE_INFO_H

#include "define.h"

class DeviceInfo {
public:
    DeviceInfo(cl_device_id deviceId);
    ~DeviceInfo() = default;
    std::string GetType();
    cl_uint GetVendorId();
    cl_uint GetMaxComputeUnits();
    cl_uint GetMaxWorkItemDimensions();
    std::vector<size_t> GetMaxWorkItemSizes();
    size_t GetMaxWorkGroupSize();
    cl_uint GetPreferredVectorWidthChar();
    cl_uint GetPreferredVectorWidthShort();
    cl_uint GetPreferredVectorWidthInt();
    cl_uint GetPreferredVectorWidthLong();
    cl_uint GetPreferredVectorWidthFloat();
    cl_uint GetPreferredVectorWidthDouble();
    cl_uint GetMaxClockFrequency();
    cl_uint GetAddressBits();
    cl_ulong GetMaxMemAllocSize();
    cl_bool GetImageSupport();
    cl_uint GetMaxReadImageArgs();
    cl_uint GetMaxWriteImageArgs();
    size_t GetImage2dMaxWidth();
    size_t GetImage2dMaxHeight();
    size_t GetImage3dMaxWidth();
    size_t GetImage3dMaxHeight();
    size_t GetImage3dMaxDepth();
    cl_uint GetMaxSamplers();
    size_t GetMaxParameterSize();
    cl_uint GetGlobalMemCachelineSize();
    cl_ulong GetGlobalMemCacheSize();
    cl_ulong GetGlobalMemSize();
    cl_ulong GetMaxConstantBufferSize();
    cl_uint GetMaxConstantArgs();
    cl_ulong GetLocalMemSize();
    size_t GetProfilingTimerResolution();
    cl_bool GetEndianLittle();
    std::string GetName();
    std::string GetVendor();
    std::string GetDriverVersion();
    std::string GetProfile();
    std::string GetVersion();
    std::string GetExtensions();

private:
    cl_int m_err = CL_SUCCESS;
    std::string m_type;
    cl_uint m_vendorId;
    cl_uint m_maxComputeUnits;
    cl_uint m_maxWorkItemDimensions;
    std::vector<size_t> m_maxWorkItemSizes;
    size_t m_maxWorkGroupSize;
    cl_uint m_preferredVectorWidthChar;
    cl_uint m_preferredVectorWidthShort;
    cl_uint m_preferredVectorWidthInt;
    cl_uint m_preferredVectorWidthLong;
    cl_uint m_preferredVectorWidthFloat;
    cl_uint m_preferredVectorWidthDouble;
    cl_uint m_maxClockFrequency;
    cl_uint m_addressBits;
    cl_ulong m_maxMemAllocSize;
    cl_bool m_imageSupport;
    cl_uint m_maxReadImageArgs;
    cl_uint m_maxWriteImageArgs;
    size_t m_image2dMaxWidth;
    size_t m_image2dMaxHeight;
    size_t m_image3dMaxWidth;
    size_t m_image3dMaxHeight;
    size_t m_image3dMaxDepth;
    cl_uint m_maxSamplers;
    size_t m_maxParameterSize;
    cl_uint m_globalMemCachelineSize;
    cl_ulong m_globalMemCacheSize;
    cl_ulong m_globalMemSize;
    cl_ulong m_maxConstantBufferSize;
    cl_uint m_maxConstantArgs;
    cl_ulong m_localMemSize;
    size_t m_profilingTimerResolution;
    cl_bool m_endianLittle;
    std::string m_name;
    std::string m_vendor;
    std::string m_driverVersion;
    std::string m_profile;
    std::string m_version;
    std::string m_extensions;
};

#endif  // DEVICE_INFO_H