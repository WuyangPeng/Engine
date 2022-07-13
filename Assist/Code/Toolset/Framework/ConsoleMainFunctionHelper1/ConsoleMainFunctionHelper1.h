///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/04 17:09)

#ifndef CONSOLE_MAIN_FUNCTION_HELPER1_H
#define CONSOLE_MAIN_FUNCTION_HELPER1_H

#include "Framework/ConsoleFrame/ConsoleFrameBuild.h"
#include "Framework/ConsoleFrame/ConsoleProcess.h"
#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelper.h"

namespace Framework
{
    using BaseType = ConsoleMainFunctionHelper<ConsoleFrameBuild, ConsoleProcessInterface>;

    class ConsoleMainFunctionHelper1 final : public BaseType
    {
    public:
        using ClassType = ConsoleMainFunctionHelper1;
        using ParentType = BaseType;

    public:
        ConsoleMainFunctionHelper1(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // CONSOLE_MAIN_FUNCTION_HELPER1_H