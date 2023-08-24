///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:29)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_IMPL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Command/Command.h"

#include <string>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE ConsoleMainFunctionHelperBaseImpl
    {
    public:
        using ClassType = ConsoleMainFunctionHelperBaseImpl;

        using String = System::String;
        using Command = CoreTools::CommandHandle;

    public:
        ConsoleMainFunctionHelperBaseImpl(int argc, char** argv, const String& consoleTitle, const String& engineInstallationDirectory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetApplicationProjectDirectory() const;
        NODISCARD Command GetCommand() const noexcept;

    private:
        NODISCARD static String ProduceApplicationProjectDirectory(const String& consoleTitle, const String& engineInstallationDirectory);

    private:
        String consoleTitle;

        // 唯一的命令行参数对象
        Command command;

        // 应用程序项目目录的路径
        String applicationProjectDirectory;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_IMPL_H