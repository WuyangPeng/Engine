///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/05 15:00)

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
        cout << "δ֪����\n";
    }

    return 0;
}
