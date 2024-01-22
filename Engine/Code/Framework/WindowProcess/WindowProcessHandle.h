/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:28)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_HANDLE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_HANDLE_H

#include "Framework/FrameworkDll.h"

#include "WindowMessageInterface.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/WindowsProcess.h"

#include <type_traits>

namespace Framework
{
    template <typename WindowMessage>
    class WindowProcessHandle
    {
    public:
        static_assert(std::is_base_of_v<WindowMessageInterface, WindowMessage>);

        using ClassType = WindowProcessHandle<WindowMessage>;

        using String = System::String;
        using WindowsHWnd = System::WindowsHWnd;
        using WindowsProcess = System::WindowsProcess;
        using DisplayFunction = System::DisplayFunction;

    public:
        WindowProcessHandle(int64_t delta, const EnvironmentDirectory& environmentDirectory);
        virtual ~WindowProcessHandle() noexcept;
        WindowProcessHandle(const WindowProcessHandle& rhs) = default;
        WindowProcessHandle& operator=(const WindowProcessHandle& rhs) = default;
        WindowProcessHandle(WindowProcessHandle&& rhs) noexcept = default;
        WindowProcessHandle& operator=(WindowProcessHandle&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD static WindowsProcess GetProcess() noexcept;
        NODISCARD static DisplayFunction GetFunction() noexcept;

        NODISCARD static bool IsClassNameExist(const String& className);
        NODISCARD static bool SetNewClassName(const String& className);

        NODISCARD static WindowsHWnd GetMainWindowHWnd();

        NODISCARD virtual bool PreCreate();
        NODISCARD virtual bool Initialize();
        virtual void PreIdle();
        virtual void Terminate();

    private:
        void ClearWindowMessage() const noexcept;

    private:
        WindowMessageInterfaceSharedPtr windowMessage;
    };

    using WindowProcessInterface = WindowProcessHandle<WindowMessageInterface>;
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_HANDLE_H
