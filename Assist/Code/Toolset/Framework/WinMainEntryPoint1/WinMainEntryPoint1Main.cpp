///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:54)

#include "WinMainEntryPoint1.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

int SYSTEM_WINAPI WinMain(SYSTEM_IN System::WindowsHInstance instance, SYSTEM_IN_OPT System::WindowsHInstance previousInstance, SYSTEM_IN char* commandLine, [[maybe_unused]] SYSTEM_IN int showCommand)
{
    return Framework::WinMainEntryPoint<Framework::WinMainEntryPoint1>(instance, commandLine, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), SYSTEM_TEXT("WinMainEntryPoint1"), 1024, 768, previousInstance);
}
