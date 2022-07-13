///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 10:50)

#include "MainFunctionHelperBase1.h"
#include "System/Time/DeltaTime.h"

#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <iostream>

Framework::MainFunctionHelperBase1::MainFunctionHelperBase1(MAYBE_UNUSED int argc, MAYBE_UNUSED char** argv, MAYBE_UNUSED const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ environmentDirectory }
{
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
