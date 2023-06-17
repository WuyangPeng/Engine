///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/13 15:31)

#ifndef CONSOLE_MAIN_FUNCTION_HELPER_BASE1_H
#define CONSOLE_MAIN_FUNCTION_HELPER_BASE1_H

#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelperBase.h"

namespace Framework
{
    class ConsoleMainFunctionHelperBase1 final : public ConsoleMainFunctionHelperBase
    {
    public:
        using ClassType = ConsoleMainFunctionHelperBase1;
        using ParentType = ConsoleMainFunctionHelperBase;

    public:
        ConsoleMainFunctionHelperBase1(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int DoRun() final;

    private:
        void PrintConsoleParameterNumber();
        void PrintConsoleParameter();
        void PrintApplicationProjectDirectory();
        void PrintCommand();
    };
}

#endif  // CONSOLE_MAIN_FUNCTION_HELPER_BASE1_H