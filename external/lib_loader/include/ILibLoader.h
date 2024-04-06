/*
 * @Author: Zhou Zijian 
 * @Date: 2023-04-05 23:59:59 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2023-04-06 01:29:49
 */

#ifndef ILIBLOADER
#define ILIBLOADER

// 打开动态链接库
int OpenLib(const char *libName, void **handle);

// 加载函数指针
void *LoadFunc(void *handle, const char *funcName);

// 关闭动态链接库
int CloseLib(void *handle);

#endif  // ILIBLOADER