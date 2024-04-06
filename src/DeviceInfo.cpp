/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-10 23:56:34 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-23 00:21:31
 */

#include "DeviceInfo.h"

void GetDeviceInfo(cl_device_id deviceId, cl_device_info param_name, cl_int &err, std::string &info)
{
    size_t infoSize;
    err = clGetDeviceInfo(deviceId, param_name, 0, nullptr, &infoSize);
    if (err != CL_SUCCESS) {
        LOGE("run opencl failed! err=%d", err);
        return;
    }
    std::unique_ptr<char[]> upInfo(new (std::nothrow) char[infoSize]);
    err = clGetDeviceInfo(deviceId, param_name, infoSize, upInfo.get(), nullptr);
    if (err != CL_SUCCESS) {
        LOGE("run opencl failed! err=%d", err);
        return;
    }
    info.assign(upInfo.get(), infoSize);
}

void GetDeviceInfo(cl_device_id deviceId, cl_device_info param_name, cl_int &err, std::vector<size_t> &info)
{
    size_t infoSize;
    err = clGetDeviceInfo(deviceId, param_name, 0, nullptr, &infoSize);
    if (err != CL_SUCCESS) {
        LOGE("run opencl failed! err=%d", err);
        return;
    }
    int count = infoSize / sizeof(size_t);
    std::unique_ptr<size_t[]> upInfo(new (std::nothrow) size_t[count]);
    err = clGetDeviceInfo(deviceId, param_name, infoSize, upInfo.get(), nullptr);
    if (err != CL_SUCCESS) {
        LOGE("run opencl failed! err=%d", err);
        return;
    }
    for (int i = 0; i < count; i++) {
        info.push_back(upInfo[i]);
    }
}

template <typename T>
void GetDeviceInfo(cl_device_id deviceId, cl_device_info param_name, cl_int &err, T &info)
{
    size_t infoSize;
    err = clGetDeviceInfo(deviceId, param_name, sizeof(T), &info, nullptr);
    if (err != CL_SUCCESS) {
        LOGE("run opencl failed! err=%d", err);
        return;
    }
}

void GetDeviceType(cl_device_id deviceId, cl_device_info param_name, cl_int &err, std::string &info)
{
    cl_device_type type;
    GetDeviceInfo(deviceId, CL_DEVICE_TYPE, err, type);
    if (err != CL_SUCCESS) {
        return;
    }
    if (type == CL_DEVICE_TYPE_CPU) {
        info = "CPU";
    } else if (type == CL_DEVICE_TYPE_GPU) {
        info = "GPU";
    } else if (type == CL_DEVICE_TYPE_ACCELERATOR) {
        info = "ACCELERATOR";
    } else {
        info = "DEFAULT";
    }
}

DeviceInfo::DeviceInfo(cl_device_id deviceId)
{
    GetDeviceType(deviceId, CL_DEVICE_TYPE, m_err, m_type);
    GetDeviceInfo(deviceId, CL_DEVICE_VENDOR_ID, m_err, m_vendorId);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_COMPUTE_UNITS, m_err, m_maxComputeUnits);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, m_err, m_maxWorkItemDimensions);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_WORK_ITEM_SIZES, m_err, m_maxWorkItemSizes);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_WORK_GROUP_SIZE, m_err, m_maxWorkGroupSize);
    GetDeviceInfo(deviceId, CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR, m_err, m_preferredVectorWidthChar);
    GetDeviceInfo(deviceId, CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT, m_err, m_preferredVectorWidthShort);
    GetDeviceInfo(deviceId, CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT, m_err, m_preferredVectorWidthInt);
    GetDeviceInfo(deviceId, CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG, m_err, m_preferredVectorWidthLong);
    GetDeviceInfo(deviceId, CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, m_err, m_preferredVectorWidthFloat);
    GetDeviceInfo(deviceId, CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE, m_err, m_preferredVectorWidthDouble);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_CLOCK_FREQUENCY, m_err, m_maxClockFrequency);
    GetDeviceInfo(deviceId, CL_DEVICE_ADDRESS_BITS, m_err, m_addressBits);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_MEM_ALLOC_SIZE, m_err, m_maxMemAllocSize);
    GetDeviceInfo(deviceId, CL_DEVICE_IMAGE_SUPPORT, m_err, m_imageSupport);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_READ_IMAGE_ARGS, m_err, m_maxReadImageArgs);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_WRITE_IMAGE_ARGS, m_err, m_maxWriteImageArgs);
    GetDeviceInfo(deviceId, CL_DEVICE_IMAGE2D_MAX_WIDTH, m_err, m_image2dMaxWidth);
    GetDeviceInfo(deviceId, CL_DEVICE_IMAGE2D_MAX_HEIGHT, m_err, m_image2dMaxHeight);
    GetDeviceInfo(deviceId, CL_DEVICE_IMAGE3D_MAX_WIDTH, m_err, m_image3dMaxWidth);
    GetDeviceInfo(deviceId, CL_DEVICE_IMAGE3D_MAX_HEIGHT, m_err, m_image3dMaxHeight);
    GetDeviceInfo(deviceId, CL_DEVICE_IMAGE3D_MAX_DEPTH, m_err, m_image3dMaxDepth);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_SAMPLERS, m_err, m_maxSamplers);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_PARAMETER_SIZE, m_err, m_maxParameterSize);
    GetDeviceInfo(deviceId, CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, m_err, m_globalMemCachelineSize);
    GetDeviceInfo(deviceId, CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, m_err, m_globalMemCacheSize);
    GetDeviceInfo(deviceId, CL_DEVICE_GLOBAL_MEM_SIZE, m_err, m_globalMemSize);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, m_err, m_maxConstantBufferSize);
    GetDeviceInfo(deviceId, CL_DEVICE_MAX_CONSTANT_ARGS, m_err, m_maxConstantArgs);
    GetDeviceInfo(deviceId, CL_DEVICE_LOCAL_MEM_SIZE, m_err, m_localMemSize);
    GetDeviceInfo(deviceId, CL_DEVICE_PROFILING_TIMER_RESOLUTION, m_err, m_profilingTimerResolution);
    GetDeviceInfo(deviceId, CL_DEVICE_ENDIAN_LITTLE, m_err, m_endianLittle);
    GetDeviceInfo(deviceId, CL_DEVICE_NAME, m_err, m_name);
    GetDeviceInfo(deviceId, CL_DEVICE_VENDOR, m_err, m_vendor);
    GetDeviceInfo(deviceId, CL_DRIVER_VERSION, m_err, m_driverVersion);
    GetDeviceInfo(deviceId, CL_DEVICE_PROFILE, m_err, m_profile);
    GetDeviceInfo(deviceId, CL_DEVICE_VERSION, m_err, m_version);
    GetDeviceInfo(deviceId, CL_DEVICE_EXTENSIONS, m_err, m_extensions);
}

std::string DeviceInfo::GetType() { return m_type; }

cl_uint DeviceInfo::GetVendorId() { return m_vendorId; }

cl_uint DeviceInfo::GetMaxComputeUnits() { return m_maxComputeUnits; }

cl_uint DeviceInfo::GetMaxWorkItemDimensions() { return m_maxWorkItemDimensions; }

std::vector<size_t> DeviceInfo::GetMaxWorkItemSizes() { return m_maxWorkItemSizes; }

size_t DeviceInfo::GetMaxWorkGroupSize() { return m_maxWorkGroupSize; }

cl_uint DeviceInfo::GetPreferredVectorWidthChar() { return m_preferredVectorWidthChar; }

cl_uint DeviceInfo::GetPreferredVectorWidthShort() { return m_preferredVectorWidthShort; }

cl_uint DeviceInfo::GetPreferredVectorWidthInt() { return m_preferredVectorWidthInt; }

cl_uint DeviceInfo::GetPreferredVectorWidthLong() { return m_preferredVectorWidthLong; }

cl_uint DeviceInfo::GetPreferredVectorWidthFloat() { return m_preferredVectorWidthFloat; }

cl_uint DeviceInfo::GetPreferredVectorWidthDouble() { return m_preferredVectorWidthDouble; }

cl_uint DeviceInfo::GetMaxClockFrequency() { return m_maxClockFrequency; }

cl_uint DeviceInfo::GetAddressBits() { return m_addressBits; }

cl_ulong DeviceInfo::GetMaxMemAllocSize() { return m_maxMemAllocSize; }

cl_bool DeviceInfo::GetImageSupport() { return m_imageSupport; }

cl_uint DeviceInfo::GetMaxReadImageArgs() { return m_maxReadImageArgs; }

cl_uint DeviceInfo::GetMaxWriteImageArgs() { return m_maxWriteImageArgs; }

size_t DeviceInfo::GetImage2dMaxWidth() { return m_image2dMaxWidth; }

size_t DeviceInfo::GetImage2dMaxHeight() { return m_image2dMaxHeight; }

size_t DeviceInfo::GetImage3dMaxWidth() { return m_image3dMaxWidth; }

size_t DeviceInfo::GetImage3dMaxHeight() { return m_image3dMaxHeight; }

size_t DeviceInfo::GetImage3dMaxDepth() { return m_image3dMaxDepth; }

cl_uint DeviceInfo::GetMaxSamplers() { return m_maxSamplers; }

size_t DeviceInfo::GetMaxParameterSize() { return m_maxParameterSize; }

cl_uint DeviceInfo::GetGlobalMemCachelineSize() { return m_globalMemCachelineSize; }

cl_ulong DeviceInfo::GetGlobalMemCacheSize() { return m_globalMemCacheSize; }

cl_ulong DeviceInfo::GetGlobalMemSize() { return m_globalMemSize; }

cl_ulong DeviceInfo::GetMaxConstantBufferSize() { return m_maxConstantBufferSize; }

cl_uint DeviceInfo::GetMaxConstantArgs() { return m_maxConstantArgs; }

cl_ulong DeviceInfo::GetLocalMemSize() { return m_localMemSize; }

size_t DeviceInfo::GetProfilingTimerResolution() { return m_profilingTimerResolution; }

cl_bool DeviceInfo::GetEndianLittle() { return m_endianLittle; }

std::string DeviceInfo::GetName() { return m_name; }

std::string DeviceInfo::GetVendor() { return m_vendor; }

std::string DeviceInfo::GetDriverVersion() { return m_driverVersion; }

std::string DeviceInfo::GetProfile() { return m_profile; }

std::string DeviceInfo::GetVersion() { return m_version; }

std::string DeviceInfo::GetExtensions() { return m_extensions; }
