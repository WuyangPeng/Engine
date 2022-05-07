///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 17:53)

#ifndef FRAMEWORK_WINDOWS_API_FRAME_BUILD_H
#define FRAMEWORK_WINDOWS_API_FRAME_BUILD_H

#include "Framework/Application/ApplicationFwd.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/WindowCreate/WindowCreate.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowRegister/WindowRegister.h"

namespace Framework
{
    template <typename Process>
    class WindowsAPIFrameBuild
    {
    public:
        using ClassType = WindowsAPIFrameBuild<Process>;
        using String = System::String;
        using HWnd = System::WindowsHWnd;
        using HInstance = System::WindowsHInstance;

    public:
        explicit WindowsAPIFrameBuild(HInstance instance,
                                      const char* commandLine,
                                      const WindowApplicationInformation& information,
                                      const EnvironmentDirectory& environmentDirectory);
        virtual ~WindowsAPIFrameBuild() noexcept = default;
        WindowsAPIFrameBuild(const WindowsAPIFrameBuild& rhs) noexcept = delete;
        WindowsAPIFrameBuild& operator=(const WindowsAPIFrameBuild& rhs) noexcept = delete;
        WindowsAPIFrameBuild(WindowsAPIFrameBuild&& rhs) noexcept;
        WindowsAPIFrameBuild& operator=(WindowsAPIFrameBuild&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD HWnd GetHwnd() const noexcept;
        NODISCARD HInstance GetHInstance() const noexcept;

        int EnterMessageLoop();

    private:
        using WindowRegister = WindowRegisterHandle<Process>;

    private:
        WindowRegister windowRegister;
        WindowCreateHandle windowCreate;
        WindowMessageLoop windowMessageLoop;
    };
}

#endif  // FRAMEWORK_WINDOWS_API_FRAME_BUILD_H