/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:14)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_H

#include "Framework/FrameworkDll.h"

#include "MainFunctionHelperBase.h"
#include "CoreTools/Command/CommandFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(ConsoleMainFunctionHelperBaseImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE ConsoleMainFunctionHelperBase : public MainFunctionHelperBase
    {
    public:
        NON_COPY_TYPE_DECLARE(ConsoleMainFunctionHelperBase);
        using ParentType = MainFunctionHelperBase;

        using String = System::String;
        using Command = CoreTools::CommandHandle;

    public:
        ConsoleMainFunctionHelperBase(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetArgc() const noexcept;
        NODISCARD char** GetArgv() const noexcept;
        NODISCARD String GetApplicationProjectDirectory() const;
        NODISCARD Command GetCommand() const;

    private:
        void ConsoleMainFunctionHelperInit(const String& consoleTitle);

    private:
        using ConsoleMainFunctionHelperBaseSharedPtr = std::shared_ptr<ImplType>;

    private:
        ConsoleMainFunctionHelperBaseSharedPtr impl;

        int argc;
        char** argv;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_H