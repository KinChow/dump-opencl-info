/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-11 01:22:36 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-19 00:27:41
 */

#ifndef INFO_SHOW_H
#define INFO_SHOW_H

#include "Platforms.h"

class InfoShow {
public:
    InfoShow();
    ~InfoShow();
    virtual void Run();

protected:
    Platforms *m_platforms;
};

#endif  // INFO_SHOW_H