///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/23 22:47)

#include "System/Threading/Process.h"
#include "System/Threading/SyncTools.h"

#include <iostream>

int main() noexcept
{
    System::SystemSleep(100);

    System::ExitSystemProcess(0);
}