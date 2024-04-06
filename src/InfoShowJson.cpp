/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-11 01:56:15 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2023-03-11 01:56:41
 */

#include "InfoShowJson.h"
#include "nlohmann/json.hpp"

static std::vector<std::string> split(const std::string &s, const std::string &delimiter)
{
    size_t posStart = 0, posEnd, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;
    while ((posEnd = s.find(delimiter, posStart)) != std::string::npos) {
        token = s.substr(posStart, posEnd - posStart);
        posStart = posEnd + delim_len;
        res.push_back(token);
    }
    res.push_back(s.substr(posStart));
    return res;
}

static void AddItem(nlohmann::json &json, const char *key, const std::string &value)
{
    json[key] = value.c_str();
}

static void AddItem(nlohmann::json &json, const char *key, const std::string &value, const std::string &delimiter)
{
    json[key] = split(value.c_str(), delimiter);
}

template <typename T>
static void AddItem(nlohmann::json &json, const char *key, const T &value)
{
    json[key] = value;
}

void InfoShowJson::Run()
{
    auto platforms = m_platforms->GetPlatforms();
    std::vector<nlohmann::json> platformsJson;
    for (auto &platform : platforms) {
        nlohmann::json platformJson;
        auto platformInfo = platform->GetPlatformInfo();
        AddItem(platformJson, "CL_PLATFORM_NAME", platformInfo->GetName());
        AddItem(platformJson, "CL_PLATFORM_VENDOR", platformInfo->GetVendor());
        AddItem(platformJson, "CL_PLATFORM_VERSION", platformInfo->GetVersion());
        AddItem(platformJson, "CL_PLATFORM_PROFILE", platformInfo->GetProfile());
        AddItem(platformJson, "CL_PLATFORM_EXTENSION", platformInfo->GetExtension(), " ");
        auto devices = platform->GetDevices()->GetDevices();
        nlohmann::json devicesJson;
        for (auto &device : devices) {
            auto deviceInfo = device->GetDeviceInfo();
            nlohmann::json deviceJson;
            AddItem(deviceJson, "CL_DEVICE_TYPE", deviceInfo->GetType());
            AddItem(deviceJson, "CL_DEVICE_VENDOR_ID", deviceInfo->GetVendorId());
            AddItem(deviceJson, "CL_DEVICE_MAX_COMPUTE_UNITS", deviceInfo->GetMaxComputeUnits());
            AddItem(deviceJson, "CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS", deviceInfo->GetMaxWorkItemDimensions());
            AddItem(deviceJson, "CL_DEVICE_MAX_WORK_ITEM_SIZES", deviceInfo->GetMaxWorkItemSizes());
            AddItem(deviceJson, "CL_DEVICE_MAX_WORK_GROUP_SIZE", deviceInfo->GetMaxWorkGroupSize());
            AddItem(deviceJson, "CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR", deviceInfo->GetPreferredVectorWidthChar());
            AddItem(deviceJson, "CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT", deviceInfo->GetPreferredVectorWidthShort());
            AddItem(deviceJson, "CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT", deviceInfo->GetPreferredVectorWidthInt());
            AddItem(deviceJson, "CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG", deviceInfo->GetPreferredVectorWidthLong());
            AddItem(deviceJson, "CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT", deviceInfo->GetPreferredVectorWidthFloat());
            AddItem(deviceJson, "CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE", deviceInfo->GetPreferredVectorWidthDouble());
            AddItem(deviceJson, "CL_DEVICE_MAX_CLOCK_FREQUENCY", deviceInfo->GetMaxClockFrequency());
            AddItem(deviceJson, "CL_DEVICE_ADDRESS_BITS", deviceInfo->GetAddressBits());
            AddItem(deviceJson, "CL_DEVICE_MAX_MEM_ALLOC_SIZE", deviceInfo->GetMaxMemAllocSize());
            AddItem(deviceJson, "CL_DEVICE_IMAGE_SUPPORT", deviceInfo->GetImageSupport());
            AddItem(deviceJson, "CL_DEVICE_MAX_READ_IMAGE_ARGS", deviceInfo->GetMaxReadImageArgs());
            AddItem(deviceJson, "CL_DEVICE_MAX_WRITE_IMAGE_ARGS", deviceInfo->GetMaxWriteImageArgs());
            AddItem(deviceJson, "CL_DEVICE_IMAGE2D_MAX_WIDTH", deviceInfo->GetImage2dMaxWidth());
            AddItem(deviceJson, "CL_DEVICE_IMAGE2D_MAX_HEIGHT", deviceInfo->GetImage2dMaxHeight());
            AddItem(deviceJson, "CL_DEVICE_IMAGE3D_MAX_WIDTH", deviceInfo->GetImage3dMaxWidth());
            AddItem(deviceJson, "CL_DEVICE_IMAGE3D_MAX_HEIGHT", deviceInfo->GetImage3dMaxHeight());
            AddItem(deviceJson, "CL_DEVICE_IMAGE3D_MAX_DEPTH", deviceInfo->GetImage3dMaxDepth());
            AddItem(deviceJson, "CL_DEVICE_MAX_SAMPLERS", deviceInfo->GetMaxSamplers());
            AddItem(deviceJson, "CL_DEVICE_MAX_PARAMETER_SIZE", deviceInfo->GetMaxParameterSize());
            AddItem(deviceJson, "CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE", deviceInfo->GetGlobalMemCachelineSize());
            AddItem(deviceJson, "CL_DEVICE_GLOBAL_MEM_CACHE_SIZE", deviceInfo->GetGlobalMemCacheSize());
            AddItem(deviceJson, "CL_DEVICE_GLOBAL_MEM_SIZE", deviceInfo->GetGlobalMemSize());
            AddItem(deviceJson, "CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE", deviceInfo->GetMaxConstantBufferSize());
            AddItem(deviceJson, "CL_DEVICE_MAX_CONSTANT_ARGS", deviceInfo->GetMaxConstantArgs());
            AddItem(deviceJson, "CL_DEVICE_LOCAL_MEM_SIZE", deviceInfo->GetLocalMemSize());
            AddItem(deviceJson, "CL_DEVICE_PROFILING_TIMER_RESOLUTION", deviceInfo->GetProfilingTimerResolution());
            AddItem(deviceJson, "CL_DEVICE_ENDIAN_LITTLE", deviceInfo->GetEndianLittle());
            AddItem(deviceJson, "CL_DEVICE_NAME", deviceInfo->GetName());
            AddItem(deviceJson, "CL_DEVICE_VENDOR", deviceInfo->GetVendor());
            AddItem(deviceJson, "CL_DRIVER_VERSION", deviceInfo->GetDriverVersion());
            AddItem(deviceJson, "CL_DEVICE_PROFILE", deviceInfo->GetProfile());
            AddItem(deviceJson, "CL_DEVICE_VERSION", deviceInfo->GetVersion());
            AddItem(deviceJson, "CL_DEVICE_EXTENSIONS", deviceInfo->GetExtensions(), " ");
            devicesJson.push_back(deviceJson);
        }
        platformJson["devices"] = devicesJson;
        platformsJson.push_back(platformJson);
    }
    std::cout << std::setw(4) << platformsJson << std::endl;
}