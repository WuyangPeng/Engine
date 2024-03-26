/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 20:38)

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
