/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:46)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_H

#include "Framework/FrameworkDll.h"

#include "WindowPoint.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

FRAMEWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(WindowCreateParameterImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowCreateParameter
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(WindowCreateParameter);

        using String = System::String;
        using WindowsHWnd = System::WindowsHWnd;
        using WindowsHMenu = System::WindowsHMenu;
        using WindowStyles = System::WindowsStyles;

    public:
        WindowCreateParameter(const String& windowsName, WindowStyles style, WindowsHWnd parent, WindowsHMenu menu, const WindowPoint& leftTopCorner);
        explicit WindowCreateParameter(const String& windowsName);
        WindowCreateParameter(const String& windowsName, WindowStyles style);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetWindowsName() const;
        NODISCARD WindowStyles GetStyle() const noexcept;
        NODISCARD WindowPoint GetLeftTopCorner() const noexcept;
        NODISCARD WindowsHWnd GetParent() const noexcept;
        NODISCARD WindowsHMenu GetMenu() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_H
