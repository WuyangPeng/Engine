///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 10:24)

#include "System/Threading/Process.h"
#include "System/Threading/SyncTools.h"

#include <iostream>

int main() noexcept
{
    System::SystemSleep(100);

    System::ExitSystemProcess(0);
}