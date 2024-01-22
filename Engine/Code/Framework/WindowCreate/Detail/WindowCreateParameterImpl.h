/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:46)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_IMPL_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Framework/WindowCreate/WindowPoint.h"

#include <string>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowCreateParameterImpl
    {
    public:
        using ClassType = WindowCreateParameterImpl;

        using String = System::String;
        using WindowsHWnd = System::WindowsHWnd;
        using WindowsHMenu = System::WindowsHMenu;
        using WindowStyles = System::WindowsStyles;

    public:
        WindowCreateParameterImpl(String windowsName, WindowStyles style, WindowsHWnd parent, WindowsHMenu menu, const WindowPoint& leftTopCorner) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetWindowsName() const;
        NODISCARD WindowStyles GetStyle() const noexcept;
        NODISCARD WindowPoint GetLeftTopCorner() const noexcept;
        NODISCARD WindowsHWnd GetParent() const noexcept;
        NODISCARD WindowsHMenu GetMenu() const noexcept;

    private:
        String windowsName;
        WindowStyles style;
        WindowPoint leftTopCorner;
        WindowsHWnd parent;
        WindowsHMenu menu;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_IMPL_H