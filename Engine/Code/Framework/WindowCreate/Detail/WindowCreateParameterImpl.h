///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:11)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_IMPL_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
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
        WindowCreateParameterImpl(const String& windowsName, WindowStyles style, WindowsHWnd parent, WindowsHMenu menu, const WindowPoint& leftTopCorner);

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