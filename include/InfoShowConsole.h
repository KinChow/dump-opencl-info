/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-09 22:26:52 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2023-03-11 01:33:44
 */

#ifndef INFO_SHOW_CONSOLE_H
#define INFO_SHOW_CONSOLE_H

#include "InfoShow.h"

class InfoShowConsole : public InfoShow {
public:
    void Run() override;
};

#endif  // INFO_SHOW_CONSOLE_H