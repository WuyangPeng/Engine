///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 17:27)

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
