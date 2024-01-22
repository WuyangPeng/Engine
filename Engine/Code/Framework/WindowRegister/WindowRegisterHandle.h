/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:12)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H

#include "WindowName.h"
#include "WindowPictorial.h"
#include "WindowRegisterParameter.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Command/CommandFwd.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <string>

// ע�ᴰ���ࣨ���ࣩ������
namespace Framework
{
    template <typename WindowProcessHandle>
    class WindowRegisterHandle
    {
    public:
        using ClassType = WindowRegisterHandle<WindowProcessHandle>;

        using String = System::String;
        using WindowsAtom = System::WindowsAtom;
        using HInstance = System::WindowsHInstance;
        using DisplayFunction = System::DisplayFunction;
        using WindowsClassStyle = System::WindowsClassStyle;
        using CommandHandle = CoreTools::CommandHandle;
        using CommandHandleSharedPtr = std::shared_ptr<CommandHandle>;

    public:
        WindowRegisterHandle(const EnvironmentDirectory& environmentDirectory,
                             HInstance instance,
                             const char* commandLine,
                             WindowPictorial pictorial,
                             WindowName name,
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
        NODISCARD CommandHandleSharedPtr GetCommand() const noexcept;
        NODISCARD WindowProcessHandle GetWindowProcess() const noexcept;
        NODISCARD EnvironmentDirectory GetEnvironmentDirectory() const noexcept;

    private:
        void Init();
        NODISCARD WindowsAtom InitApplication();

    private:
        static constexpr auto interval = 60;

        EnvironmentDirectory environmentDirectory;
        WindowProcessHandle windowProcess;
        CommandHandleSharedPtr command;
        WindowRegisterParameter windowRegisterParameter;
        WindowPictorial windowPictorial;
        WindowName windowName;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H