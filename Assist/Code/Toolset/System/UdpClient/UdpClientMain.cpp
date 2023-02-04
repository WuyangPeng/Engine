///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/04 0:15)

#include "UdpClient.h"

#include <exception>
#include <iostream>

int main()
{
    try
    {
        SystemToolset::UdpClient();
    }
    catch (const std::exception& exception)
    {
        std::cout << exception.what() << '\n';
    }
    catch (...)
    {
        std::cout << "未知错误！\n";
    }

    return 0;
}
