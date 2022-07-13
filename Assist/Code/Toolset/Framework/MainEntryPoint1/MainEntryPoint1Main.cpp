///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 10:39)

#include "MainEntryPoint1.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

int main(int argc, char** argv)
{
    return Framework::MainEntryPoint<Framework::MainEntryPoint1>(argc, argv, SYSTEM_TEXT("MainEntryPoint1"), SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""));
}
