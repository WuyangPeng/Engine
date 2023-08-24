///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:26)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H

#include "Framework/FrameworkDll.h"

#include "ConsoleMainFunctionHelperBase.h"

namespace Framework
{
    template <template <typename> class Build, typename Process>
    class ConsoleMainFunctionHelper : public ConsoleMainFunctionHelperBase
    {
    public:
        using ClassType = ConsoleMainFunctionHelper<Build, Process>;
        using ParentType = ConsoleMainFunctionHelperBase;

        using ClassShareType = CoreTools::NonCopyClasses;
        using BuildType = Build<Process>;

    public:
        ConsoleMainFunctionHelper(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);
        ~ConsoleMainFunctionHelper() noexcept;
        ConsoleMainFunctionHelper(const ConsoleMainFunctionHelper& rhs) noexcept = delete;
        ConsoleMainFunctionHelper& operator=(const ConsoleMainFunctionHelper& rhs) noexcept = delete;
        ConsoleMainFunctionHelper(ConsoleMainFunctionHelper&& rhs) noexcept;
        ConsoleMainFunctionHelper& operator=(ConsoleMainFunctionHelper&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Destroy() override;

    private:
        using BuildSharedPtr = std::shared_ptr<BuildType>;

    private:
        NODISCARD int DoRun() noexcept override;
        NODISCARD virtual int RunConsoleMainLoop() noexcept;

        void Initializer();
        void Terminators();

        void InitConsoleProcess() noexcept;
        void InitConsoleImpl();

        void DestroyConsoleImpl() noexcept;
        void DestroyConsoleProcess() noexcept;

    private:
        BuildSharedPtr build;
        ConsoleMainFunctionSchedule consoleMainFunctionSchedule;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H
