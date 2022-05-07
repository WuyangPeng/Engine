///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:34)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_H

#include "System/Windows/WindowsProcess.h"

#include "WindowMessageInterface.h"
#include "System/Helper/UnicodeUsing.h"

#include <type_traits>

namespace Framework
{
    template <typename WindowMessage>
    class WindowProcessHandle
    {
    public:
        static_assert(std::is_base_of_v<WindowMessageInterface, WindowMessage>);

    public:
        using MessageType = WindowMessage;
        using ClassType = WindowProcessHandle<MessageType>;
        using String = System::String;
        using HWnd = System::WindowsHWnd;
        using WindowsProcess = System::WindowsProcess;
        using DisplayFunction = System::DisplayFunction;

    public:
        explicit WindowProcessHandle(int64_t delta);
        virtual ~WindowProcessHandle() noexcept;
        WindowProcessHandle(const WindowProcessHandle& rhs) noexcept = default;
        WindowProcessHandle& operator=(const WindowProcessHandle& rhs) noexcept = default;
        WindowProcessHandle(WindowProcessHandle&& rhs) noexcept = default;
        WindowProcessHandle& operator=(WindowProcessHandle&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        NODISCARD static WindowsProcess GetProcess() noexcept;
        NODISCARD static DisplayFunction GetFunction() noexcept;

        NODISCARD static bool IsClassNameExist(const String& className);
        NODISCARD static bool SetNewClassName(const String& className);

        NODISCARD static HWnd GetMainWindowHwnd();

        virtual bool PreCreate(const EnvironmentDirectory& environmentDirectory);
        virtual bool Initialize();
        virtual void PreIdle();
        virtual void Terminate();

    private:
        void ClearWindowMessage();

    private:
        WindowMessageInterfaceSharedPtr windowMessage;
    };

    using WindowProcessInterface = WindowProcessHandle<WindowMessageInterface>;
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_H
