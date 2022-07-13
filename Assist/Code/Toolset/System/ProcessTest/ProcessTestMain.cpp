///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 16:58)

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