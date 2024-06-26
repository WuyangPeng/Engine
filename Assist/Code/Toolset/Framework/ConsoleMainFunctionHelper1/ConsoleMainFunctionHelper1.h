///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:32)

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