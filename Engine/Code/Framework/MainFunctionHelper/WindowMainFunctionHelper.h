///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 14:56)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H

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
        NODISCARD WindowsHWnd GetHwnd() const noexcept;

    private:
        using BuildSharedPtr = std::shared_ptr<BuildType>;

    private:
        NODISCARD int DoRun() override;

        void Initializers(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information);
        void Terminators();

        void InitWindowProcess();
        void InitCamera();
        void InitRendererManager();
        void InitImpl(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information);

        void DestroyImpl() noexcept;
        void DestroyRendererManager() noexcept;
        void DestroyCamera() noexcept;
        void DestroyWindowProcess() noexcept;

    private:
        BuildSharedPtr build;
        WindowMainFunctionSchedule windowMainFunctionSchedule;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H