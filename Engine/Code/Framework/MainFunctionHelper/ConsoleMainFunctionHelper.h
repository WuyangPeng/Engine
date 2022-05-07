///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 14:42)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H

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

        void Initializers();
        void Terminators();

        void InitConsoleProcess() noexcept;
        void InitImpl();

        void DestroyImpl() noexcept;
        void DestroyConsoleProcess() noexcept;

    private:
        BuildSharedPtr build;
        ConsoleMainFunctionSchedule consoleMainFunctionSchedule;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H
