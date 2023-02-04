///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/04 0:15)

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
        std::cout << "δ֪����\n";
    }

    return 0;
}
