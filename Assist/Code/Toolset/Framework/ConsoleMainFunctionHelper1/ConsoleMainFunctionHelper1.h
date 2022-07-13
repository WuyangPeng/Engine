///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/04 17:09)

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