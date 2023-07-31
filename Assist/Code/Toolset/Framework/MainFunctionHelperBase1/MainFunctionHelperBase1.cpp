///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 13:42)

#include "MainFunctionHelperBase1.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <iostream>

Framework::MainFunctionHelperBase1::MainFunctionHelperBase1(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ environmentDirectory }
{
    System::UnusedFunction(argc, argv, consoleTitle);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MainFunctionHelperBase1)

int Framework::MainFunctionHelperBase1::DoRun()
{
    COUT << SYSTEM_TEXT("引擎安装目录为（为空表示程序当前路径）：")
         << GetEngineInstallationDirectory()
         << SYSTEM_TEXT('\n')
         << SYSTEM_TEXT("函数IsDestroy返回值应该为false：")
         << std::boolalpha
         << IsDestroy()
         << std::noboolalpha
         << SYSTEM_TEXT("。\n");

    System::SystemPause();

    return 0;
}
