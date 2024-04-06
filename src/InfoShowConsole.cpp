/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-11 01:34:23 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2023-03-11 03:11:08
 */

#include "InfoShowConsole.h"

template <typename T>
void PrintInfo(const char *key, const T &value)
{
    std::cout << key << ": " << value << std::endl;
}

void PrintInfo(const char *key, const std::vector<size_t> &value)
{
    std::cout << key << ": [";
    for (int i = 0; i < value.size(); i++) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << value.at(i);
    }
    std::cout << "]" << std::endl;
}

void InfoShowConsole::Run()
{
    auto platforms = m_platforms->GetPlatforms();
    for (auto &platform : platforms) {
        auto platformInfo = platform->GetPlatformInfo();
        PrintInfo("CL_PLATFORM_NAME", platformInfo->GetName());
        PrintInfo("CL_PLATFORM_VENDOR", platformInfo->GetVendor());
        PrintInfo("CL_PLATFORM_VERSION", platformInfo->GetVersion());
        PrintInfo("CL_PLATFORM_PROFILE", platformInfo->GetProfile());
        PrintInfo("CL_PLATFORM_EXTENSION", platformInfo->GetExtension());
        auto devices = platform->GetDevices()->GetDevices();
        for (auto &device : devices) {
            auto deviceInfo = device->GetDeviceInfo();
            PrintInfo("CL_DEVICE_TYPE", deviceInfo->GetType());
            PrintInfo("CL_DEVICE_VENDOR_ID", deviceInfo->GetVendorId());
            PrintInfo("CL_DEVICE_MAX_COMPUTE_UNITS", deviceInfo->GetMaxComputeUnits());
            PrintInfo("CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS", deviceInfo->GetMaxWorkItemDimensions());
            PrintInfo("CL_DEVICE_MAX_WORK_ITEM_SIZES", deviceInfo->GetMaxWorkItemSizes());
            PrintInfo("CL_DEVICE_MAX_WORK_GROUP_SIZE", deviceInfo->GetMaxWorkGroupSize());
            PrintInfo("CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR", deviceInfo->GetPreferredVectorWidthChar());
            PrintInfo("CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT", deviceInfo->GetPreferredVectorWidthShort());
            PrintInfo("CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT", deviceInfo->GetPreferredVectorWidthInt());
            PrintInfo("CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG", deviceInfo->GetPreferredVectorWidthLong());
            PrintInfo("CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT", deviceInfo->GetPreferredVectorWidthFloat());
            PrintInfo("CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE", deviceInfo->GetPreferredVectorWidthDouble());
            PrintInfo("CL_DEVICE_MAX_CLOCK_FREQUENCY", deviceInfo->GetMaxClockFrequency());
            PrintInfo("CL_DEVICE_ADDRESS_BITS", deviceInfo->GetAddressBits());
            PrintInfo("CL_DEVICE_MAX_MEM_ALLOC_SIZE", deviceInfo->GetMaxMemAllocSize());
            PrintInfo("CL_DEVICE_IMAGE_SUPPORT", deviceInfo->GetImageSupport());
            PrintInfo("CL_DEVICE_MAX_READ_IMAGE_ARGS", deviceInfo->GetMaxReadImageArgs());
            PrintInfo("CL_DEVICE_MAX_WRITE_IMAGE_ARGS", deviceInfo->GetMaxWriteImageArgs());
            PrintInfo("CL_DEVICE_IMAGE2D_MAX_WIDTH", deviceInfo->GetImage2dMaxWidth());
            PrintInfo("CL_DEVICE_IMAGE2D_MAX_HEIGHT", deviceInfo->GetImage2dMaxHeight());
            PrintInfo("CL_DEVICE_IMAGE3D_MAX_WIDTH", deviceInfo->GetImage3dMaxWidth());
            PrintInfo("CL_DEVICE_IMAGE3D_MAX_HEIGHT", deviceInfo->GetImage3dMaxHeight());
            PrintInfo("CL_DEVICE_IMAGE3D_MAX_DEPTH", deviceInfo->GetImage3dMaxDepth());
            PrintInfo("CL_DEVICE_MAX_SAMPLERS", deviceInfo->GetMaxSamplers());
            PrintInfo("CL_DEVICE_MAX_PARAMETER_SIZE", deviceInfo->GetMaxParameterSize());
            PrintInfo("CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE", deviceInfo->GetGlobalMemCachelineSize());
            PrintInfo("CL_DEVICE_GLOBAL_MEM_CACHE_SIZE", deviceInfo->GetGlobalMemCacheSize());
            PrintInfo("CL_DEVICE_GLOBAL_MEM_SIZE", deviceInfo->GetGlobalMemSize());
            PrintInfo("CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE", deviceInfo->GetMaxConstantBufferSize());
            PrintInfo("CL_DEVICE_MAX_CONSTANT_ARGS", deviceInfo->GetMaxConstantArgs());
            PrintInfo("CL_DEVICE_LOCAL_MEM_SIZE", deviceInfo->GetLocalMemSize());
            PrintInfo("CL_DEVICE_PROFILING_TIMER_RESOLUTION", deviceInfo->GetProfilingTimerResolution());
            PrintInfo("CL_DEVICE_ENDIAN_LITTLE", deviceInfo->GetEndianLittle());
            PrintInfo("CL_DEVICE_NAME", deviceInfo->GetName());
            PrintInfo("CL_DEVICE_VENDOR", deviceInfo->GetVendor());
            PrintInfo("CL_DRIVER_VERSION", deviceInfo->GetDriverVersion());
            PrintInfo("CL_DEVICE_PROFILE", deviceInfo->GetProfile());
            PrintInfo("CL_DEVICE_VERSION", deviceInfo->GetVersion());
            PrintInfo("CL_DEVICE_EXTENSIONS", deviceInfo->GetExtensions());
        }
    }
}