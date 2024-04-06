/*
 * @Author: Zhou Zijian 
 * @Date: 2024-01-22 02:00:34 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-22 02:06:15
 */

#include <string>
#include "log.h"
#include "OCLLibLoader.h"

#ifndef CHECK_FUNC
#define CHECK_FUNC(func)              \
    do {                              \
        if (func == nullptr) {        \
            LOGE(#func " not found"); \
            return;                   \
        }                             \
    } while (0)
#endif

OCLLibLoader::OCLLibLoader()
{
    std::string libName;
#ifdef _WIN32
    libName = "OpenCL.dll";
#else
    libName = "libOpenCL.so";
#endif
    int ret = OpenLib(libName.c_str(), &m_handle);
    if (ret != 0) {
        LOGE("OpenCL lib open failed");
        return;
    }
    GetPlatformIDs = reinterpret_cast<clGetPlatformIDsPtrFunc>(LoadFunc(m_handle, "clGetPlatformIDs"));
    CHECK_FUNC(GetPlatformIDs);
    GetPlatformInfo = reinterpret_cast<clGetPlatformInfoPtrFunc>(LoadFunc(m_handle, "clGetPlatformInfo"));
    CHECK_FUNC(GetPlatformInfo);
    GetDeviceIDs = reinterpret_cast<clGetDeviceIDsPtrFunc>(LoadFunc(m_handle, "clGetDeviceIDs"));
    CHECK_FUNC(GetDeviceIDs);
    GetDeviceInfo = reinterpret_cast<clGetDeviceInfoPtrFunc>(LoadFunc(m_handle, "clGetDeviceInfo"));
    CHECK_FUNC(GetDeviceInfo);
    CreateContext = reinterpret_cast<clCreateContextPtrFunc>(LoadFunc(m_handle, "clCreateContext"));
    CHECK_FUNC(CreateContext);
#ifdef CL_VERSION_2_0
    CreateCommandQueueWithProperties = reinterpret_cast<clCreateCommandQueueWithPropertiesPtrFunc>(
        LoadFunc(m_handle, "clCreateCommandQueueWithProperties"));
    CHECK_FUNC(CreateCommandQueueWithProperties);
#else
    CreateCommandQueue = reinterpret_cast<clCreateCommandQueuePtrFunc>(LoadFunc(m_handle, "clCreateCommandQueue"));
    CHECK_FUNC(CreateCommandQueue);
#endif
    CreateProgramWithSource =
        reinterpret_cast<clCreateProgramWithSourcePtrFunc>(LoadFunc(m_handle, "clCreateProgramWithSource"));
    CHECK_FUNC(CreateProgramWithSource);
    BuildProgram = reinterpret_cast<clBuildProgramPtrFunc>(LoadFunc(m_handle, "clBuildProgram"));
    CHECK_FUNC(BuildProgram);
    CreateKernel = reinterpret_cast<clCreateKernelPtrFunc>(LoadFunc(m_handle, "clCreateKernel"));
    CHECK_FUNC(CreateKernel);
    ReleaseKernel = reinterpret_cast<clReleaseKernelPtrFunc>(LoadFunc(m_handle, "clReleaseKernel"));
    CHECK_FUNC(ReleaseKernel);
    ReleaseProgram = reinterpret_cast<clReleaseProgramPtrFunc>(LoadFunc(m_handle, "clReleaseProgram"));
    CHECK_FUNC(ReleaseProgram);
    ReleaseCommandQueue = reinterpret_cast<clReleaseCommandQueuePtrFunc>(LoadFunc(m_handle, "clReleaseCommandQueue"));
    CHECK_FUNC(ReleaseCommandQueue);
    ReleaseContext = reinterpret_cast<clReleaseContextPtrFunc>(LoadFunc(m_handle, "clReleaseContext"));
    CHECK_FUNC(ReleaseContext);
    SetKernelArg = reinterpret_cast<clSetKernelArgPtrFunc>(LoadFunc(m_handle, "clSetKernelArg"));
    CHECK_FUNC(SetKernelArg);
    EnqueueNDRangeKernel = reinterpret_cast<clEnqueueNDRangeKernelPtrFunc>(LoadFunc(m_handle, "clEnqueueNDRangeKernel"));
    CHECK_FUNC(EnqueueNDRangeKernel);
    Finish = reinterpret_cast<clFinishPtrFunc>(LoadFunc(m_handle, "clFinish"));
    CHECK_FUNC(Finish);
    CreateBuffer = reinterpret_cast<clCreateBufferPtrFunc>(LoadFunc(m_handle, "clCreateBuffer"));
    CHECK_FUNC(CreateBuffer);
    EnqueueReadBuffer = reinterpret_cast<clEnqueueReadBufferPtrFunc>(LoadFunc(m_handle, "clEnqueueReadBuffer"));
    CHECK_FUNC(EnqueueReadBuffer);
    ReleaseMemObject = reinterpret_cast<clReleaseMemObjectPtrFunc>(LoadFunc(m_handle, "clReleaseMemObject"));
    CHECK_FUNC(ReleaseMemObject);
}

OCLLibLoader::~OCLLibLoader()
{
    if (m_handle != nullptr) {
        CloseLib(m_handle);
    }
}