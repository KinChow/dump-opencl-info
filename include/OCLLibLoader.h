/*
 * @Author: Zhou Zijian 
 * @Date: 2024-01-22 01:42:05 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-22 02:05:09
 */

#ifndef OCL_LIB_LOADER_H
#define OCL_LIB_LOADER_H

#include <CL/cl.h>
#include "ILibLoader.h"

using clGetPlatformIDsPtrFunc = decltype(&clGetPlatformIDs);
using clGetPlatformInfoPtrFunc = decltype(&clGetPlatformInfo);
using clGetDeviceIDsPtrFunc = decltype(&clGetDeviceIDs);
using clGetDeviceInfoPtrFunc = decltype(&clGetDeviceInfo);
using clCreateContextPtrFunc = decltype(&clCreateContext);
#ifdef CL_VERSION_2_0
using clCreateCommandQueueWithPropertiesPtrFunc = decltype(&clCreateCommandQueueWithProperties);
#else
using clCreateCommandQueuePtrFunc = decltype(&clCreateCommandQueue);
#endif
using clCreateProgramWithSourcePtrFunc = decltype(&clCreateProgramWithSource);
using clBuildProgramPtrFunc = decltype(&clBuildProgram);
using clCreateKernelPtrFunc = decltype(&clCreateKernel);
using clReleaseKernelPtrFunc = decltype(&clReleaseKernel);
using clReleaseProgramPtrFunc = decltype(&clReleaseProgram);
using clReleaseCommandQueuePtrFunc = decltype(&clReleaseCommandQueue);
using clReleaseContextPtrFunc = decltype(&clReleaseContext);
using clSetKernelArgPtrFunc = decltype(&clSetKernelArg);
using clEnqueueNDRangeKernelPtrFunc = decltype(&clEnqueueNDRangeKernel);
using clFinishPtrFunc = decltype(&clFinish);
using clCreateBufferPtrFunc = decltype(&clCreateBuffer);
using clEnqueueReadBufferPtrFunc = decltype(&clEnqueueReadBuffer);
using clReleaseMemObjectPtrFunc = decltype(&clReleaseMemObject);

class OCLLibLoader {
public:
    OCLLibLoader();
    ~OCLLibLoader();

public:
    clGetPlatformIDsPtrFunc GetPlatformIDs = nullptr;
    clGetPlatformInfoPtrFunc GetPlatformInfo = nullptr;
    clGetDeviceIDsPtrFunc GetDeviceIDs = nullptr;
    clGetDeviceInfoPtrFunc GetDeviceInfo = nullptr;
    clCreateContextPtrFunc CreateContext = nullptr;
#ifdef CL_VERSION_2_0
    clCreateCommandQueueWithPropertiesPtrFunc CreateCommandQueueWithProperties = nullptr;
#else
    clCreateCommandQueuePtrFunc CreateCommandQueue = nullptr;
#endif
    clCreateProgramWithSourcePtrFunc CreateProgramWithSource = nullptr;
    clBuildProgramPtrFunc BuildProgram = nullptr;
    clCreateKernelPtrFunc CreateKernel = nullptr;
    clReleaseKernelPtrFunc ReleaseKernel = nullptr;
    clReleaseProgramPtrFunc ReleaseProgram = nullptr;
    clReleaseCommandQueuePtrFunc ReleaseCommandQueue = nullptr;
    clReleaseContextPtrFunc ReleaseContext = nullptr;
    clSetKernelArgPtrFunc SetKernelArg = nullptr;
    clEnqueueNDRangeKernelPtrFunc EnqueueNDRangeKernel = nullptr;
    clFinishPtrFunc Finish = nullptr;
    clCreateBufferPtrFunc CreateBuffer = nullptr;
    clEnqueueReadBufferPtrFunc EnqueueReadBuffer = nullptr;
    clReleaseMemObjectPtrFunc ReleaseMemObject = nullptr;

private:
    void *m_handle;
};

#endif  // OCL_LIB_LOADER_H