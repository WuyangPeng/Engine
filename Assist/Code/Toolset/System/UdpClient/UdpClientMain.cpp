///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 17:27)

#include "UdpClient.h"

#include <exception>
#include <iostream>

using std::cout;
using std::exception;

int main()
{
    try
    {
        System::UdpClient();
    }
    catch (const exception& exception)
    {
        cout << exception.what() << '\n';
    }
    catch (...)
    {
        cout << "未知错误！\n";
    }

    return 0;
}
