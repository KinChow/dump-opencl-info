/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-11 01:22:27 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-19 00:15:16
 */

#include "InfoShow.h"

InfoShow::InfoShow()
{
    m_platforms = new Platforms();
}

InfoShow::~InfoShow()
{
    delete m_platforms;
}

void InfoShow::Run()
{}
