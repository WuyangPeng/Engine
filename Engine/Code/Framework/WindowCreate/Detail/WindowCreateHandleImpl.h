/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:46)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_IMPL_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "Framework/WindowCreate/WindowSize.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowCreateHandleImpl
    {
    public:
        using ClassType = WindowCreateHandleImpl;

        using WindowsHWnd = System::WindowsHWnd;

    public:
        WindowCreateHandleImpl(WindowInstanceParameter windowInstanceParameter, WindowCreateParameter windowCreateParameter, const WindowSize& size);
        ~WindowCreateHandleImpl() noexcept = default;
        WindowCreateHandleImpl(const WindowCreateHandleImpl& rhs) = delete;
        WindowCreateHandleImpl& operator=(const WindowCreateHandleImpl& rhs) = delete;
        WindowCreateHandleImpl(WindowCreateHandleImpl&& rhs) noexcept = delete;
        WindowCreateHandleImpl& operator=(WindowCreateHandleImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD WindowsHWnd GetHWnd() const noexcept;

        void SetMainWindow();

    private:
        void InitInstance();

    private:
        WindowInstanceParameter windowInstanceParameter;
        WindowCreateParameter windowCreateParameter;
        WindowSize size;
        WindowsHWnd hWnd;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_IMPL_H
