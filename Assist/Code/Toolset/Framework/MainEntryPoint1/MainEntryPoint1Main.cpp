///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 17:18)

#include "MainEntryPoint1.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

int main(int argc, char** argv)
{
    return Framework::MainEntryPoint<Framework::MainEntryPoint1>(argc, argv, SYSTEM_TEXT("MainEntryPoint1"), SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""));
}
