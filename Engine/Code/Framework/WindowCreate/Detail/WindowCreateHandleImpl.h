///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 14:57)
#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_IMPL_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/Flags/WindowsFlags.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "Framework/WindowCreate/WindowSize.h"

#include <boost/noncopyable.hpp>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowCreateHandleImpl : private boost::noncopyable
    {
    public:
        using ClassType = WindowCreateHandleImpl;
        using WindowsHWnd = System::WindowsHWnd;

    public:
        WindowCreateHandleImpl(const WindowInstanceParameter& windowInstanceParameter, const WindowCreateParameter& windowCreateParameter, const WindowSize& size);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WindowsHWnd GetHwnd() const noexcept;

        void SetMainWindow();

    private:
        void InitInstance();

    private:
        WindowInstanceParameter windowInstanceParameter;
        WindowCreateParameter windowCreateParameter;
        WindowSize size;
        WindowsHWnd hwnd;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_IMPL_H
