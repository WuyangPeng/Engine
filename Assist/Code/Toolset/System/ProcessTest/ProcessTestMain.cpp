///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/11 15:47)

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