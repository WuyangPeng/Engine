///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:13)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H

#include "Framework/FrameworkDll.h"

#include "MainFunctionHelperBase.h"
#include "MainFunctionHelperFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "Framework/Application/ApplicationFwd.h"
#include "Framework/WindowRegister/WindowPictorial.h"

namespace Framework
{
    template <template <typename> class Build, typename Process>
    class WindowMainFunctionHelper : public MainFunctionHelperBase
    {
    public:
        using ClassType = WindowMainFunctionHelper<Build, Process>;
        using ParentType = MainFunctionHelperBase;

        using ClassShareType = CoreTools::NonCopyClasses;
        using BuildType = Build<Process>;
        using WindowsHWnd = System::WindowsHWnd;
        using WindowsHInstance = System::WindowsHInstance;

    public:
        WindowMainFunctionHelper(WindowsHInstance instance,
                                 const char* commandLine,
                                 const WindowApplicationInformation& information,
                                 const EnvironmentDirectory& environmentDirectory);
        ~WindowMainFunctionHelper() noexcept;
        WindowMainFunctionHelper(const WindowMainFunctionHelper& rhs) noexcept = delete;
        WindowMainFunctionHelper& operator=(const WindowMainFunctionHelper& rhs) noexcept = delete;
        WindowMainFunctionHelper(WindowMainFunctionHelper&& rhs) noexcept;
        WindowMainFunctionHelper& operator=(WindowMainFunctionHelper&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Destroy() override;

    protected:
        NODISCARD virtual int EnterMessageLoop();
        NODISCARD WindowsHWnd GetHWnd() const noexcept;

    private:
        using BuildSharedPtr = std::shared_ptr<BuildType>;

    private:
        NODISCARD int DoRun() override;

        void Initializer(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information);
        void Terminators();

        void InitWindowProcess();
        void InitWindowImpl(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information);

        void DestroyWindowImpl() noexcept;
        void DestroyWindowProcess() noexcept;

    private:
        BuildSharedPtr build;
        WindowMainFunctionSchedule windowMainFunctionSchedule;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H