///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:04)

#include "MainEntryPoint2.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <iostream>

Framework::MainEntryPoint2::MainEntryPoint2(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ argc, argv, consoleTitle, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MainEntryPoint2)

int Framework::MainEntryPoint2 ::DoRun()
{
    std::cout << "运行MainEntryPoint入口点函数\n";

    System::SystemPause();

    return 0;
}
