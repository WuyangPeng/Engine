///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/04 17:09)

#include "ConsoleMainFunctionHelper1.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/ConsoleFrame/ConsoleFrameBuildDetail.h"
#include "Framework/ConsoleFrame/ConsoleProcessDetail.h"
#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelperDetail.h"

Framework::ConsoleMainFunctionHelper1::ConsoleMainFunctionHelper1(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : ParentType(argc, argv, consoleTitle, environmentDirectory)
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    System::SystemPause();
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ConsoleMainFunctionHelper1)
