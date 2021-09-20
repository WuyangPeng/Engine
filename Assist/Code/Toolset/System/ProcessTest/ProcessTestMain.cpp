///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/11 15:47)

#include "System/Console/ConsoleCreate.h"
#include "System/Helper/EnumCast.h"
#include "System/Threading/Process.h"
#include "System/Threading/SyncTools.h"

#include <iostream>

int main() noexcept
{
    System::SystemSleep(100);

    System::ExitSystemProcess(0);
}