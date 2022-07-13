///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/04 18:33)

#include "ConsoleMainFunctionHelperBase1.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <iostream>

using std::cout;

Framework::ConsoleMainFunctionHelperBase1::ConsoleMainFunctionHelperBase1(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ argc, argv, consoleTitle, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ConsoleMainFunctionHelperBase1)

int Framework::ConsoleMainFunctionHelperBase1::DoRun()
{
    PrintConsoleParameterNumber();
    PrintConsoleParameter();
    PrintApplicationProjectDirectory();
    PrintCommand();

    System::SystemPause();

    return 0;
}

void Framework::ConsoleMainFunctionHelperBase1::PrintConsoleParameterNumber()
{
    COUT << SYSTEM_TEXT("命令行参数个数为：")
         << GetArgc()
         << SYSTEM_TEXT('\n');
}

void Framework::ConsoleMainFunctionHelperBase1::PrintConsoleParameter()
{
    for (auto index = 0; index < GetArgc(); ++index)
    {
        const auto* const* aArgv = GetArgv();
        if (aArgv != nullptr)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            COUT << SYSTEM_TEXT("命令行参数第")
                 << index + 1
                 << SYSTEM_TEXT("个为：")
                 << aArgv[index]
                 << SYSTEM_TEXT('\n');

#include STSTEM_WARNING_POP
        }
    }
}

void Framework::ConsoleMainFunctionHelperBase1::PrintApplicationProjectDirectory()
{
    COUT << SYSTEM_TEXT("应用安装目录为：")
         << GetApplicationProjectDirectory()
         << SYSTEM_TEXT('\n');
}

void Framework::ConsoleMainFunctionHelperBase1::PrintCommand()
{
    auto command = GetCommand();

    for (auto index = 0; index < command.GetExcessArgumentsCount(); ++index)
    {
        auto arguments = command.ExcessArguments();
        cout << "命令行参数名为："
             << arguments
             << '\n';
    }
}