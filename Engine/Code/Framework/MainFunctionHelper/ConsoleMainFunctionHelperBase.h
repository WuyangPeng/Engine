// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:46)

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

        int GetArgc() const noexcept;
        char** GetArgv() const noexcept;
        String GetApplicationProjectDirectory() const;
        Command GetCommand() const noexcept;

    private:
        void ConsoleMainFunctionHelperInit(const String& consoleTitle);

    private:
        using ConsoleMainFunctionHelperBaseImplPtr = std::shared_ptr<ImplType>;

    private:
        ConsoleMainFunctionHelperBaseImplPtr impl;

        int m_Argc;
        char** m_Argv;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_H