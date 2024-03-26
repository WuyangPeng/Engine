/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 20:43)

#include "TcpClient.h"

#include <exception>
#include <iostream>

int main()
{
    try
    {
        SystemToolset::TcpClient();
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
