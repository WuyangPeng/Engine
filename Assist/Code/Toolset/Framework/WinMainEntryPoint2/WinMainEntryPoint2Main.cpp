// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.3.0.1 (2020/05/25 10:35)

#include "WinMainEntryPoint2.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

int SYSTEM_WINAPI WinMain(SYSTEM_IN System::WindowHInstance instance, SYSTEM_IN_OPT System::WindowHInstance previousInstance, SYSTEM_IN char* commandLine, [[maybe_unused]] SYSTEM_IN int showCommand)
{
    return Framework::WinMainEntryPoint<Framework::WinMainEntryPoint2>(instance, commandLine, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), SYSTEM_TEXT("WinMainEntryPoint2.json"), previousInstance);
}