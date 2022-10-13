///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 17:09)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H

#include "WindowName.h"
#include "WindowPictorial.h"
#include "WindowRegisterParameter.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Command/CommandFwd.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <string>

namespace Framework
{
    // 注册窗口类（基类）的声明
    template <typename WindowProcessHandle>
    class WindowRegisterHandle
    {
    public:
        using WindowProcessType = WindowProcessHandle;
        using ClassType = WindowRegisterHandle<WindowProcessType>;
        using String = System::String;
        using Atom = System::WindowsAtom;
        using HInstance = System::WindowsHInstance;
        using DisplayFunction = System::DisplayFunction;
        using WindowsClassStyle = System::WindowsClassStyle;
        using Command = CoreTools::CommandHandle;
        using CommandSharedPtr = std::shared_ptr<CoreTools::CommandHandle>;

    public:
        WindowRegisterHandle(const EnvironmentDirectory& environmentDirectory,
                             HInstance instance,
                             const char* commandLine,
                             const WindowPictorial& pictorial,
                             const WindowName& name,
                             WindowsClassStyle styles = WindowsClassStyle::CommonUse);
        virtual ~WindowRegisterHandle() noexcept = default;
        WindowRegisterHandle(const WindowRegisterHandle& rhs) noexcept = delete;
        WindowRegisterHandle& operator=(const WindowRegisterHandle& rhs) noexcept = delete;
        WindowRegisterHandle(WindowRegisterHandle&& rhs) noexcept;
        WindowRegisterHandle& operator=(WindowRegisterHandle&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD HInstance GetHInstance() const noexcept;
        NODISCARD String GetWindowClassName() const;
        NODISCARD String GetWindowMenuName() const;
        NODISCARD DisplayFunction GetFunction() const noexcept;
        NODISCARD CommandSharedPtr GetCommand() const noexcept;
        NODISCARD WindowProcessHandle GetWindowProcess() const noexcept;
        NODISCARD EnvironmentDirectory GetEnvironmentDirectory() const noexcept;

    private:
        NODISCARD Atom InitApplication();

    private:
        static constexpr auto interval = 60;

        EnvironmentDirectory environmentDirectory;
        WindowProcessHandle windowProcess;
        CommandSharedPtr command;
        WindowRegisterParameter windowRegisterParameter;
        WindowPictorial windowPictorial;
        WindowName windowName;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H