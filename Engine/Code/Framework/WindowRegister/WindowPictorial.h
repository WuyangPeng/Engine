///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/03 19:30)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "System/Windows/Using/WindowsPictorialUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(WindowPictorialImpl);

// 窗口图示类的声明
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowPictorial
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(WindowPictorial);

        using TChar = System::TChar;
        using HIcon = System::WindowsHIcon;
        using HCursor = System::WindowsHCursor;
        using HBrush = System::WindowsHBrush;
        using HInstance = System::WindowsHInstance;
        using BrushTypes = System::WindowsBrushTypes;

    public:
        explicit WindowPictorial(BrushTypes background);
        WindowPictorial(const TChar* icon, const TChar* cursor, BrushTypes background = BrushTypes::WhiteBrush);
        WindowPictorial(HInstance instance, int icon, int cursor, BrushTypes background = BrushTypes::WhiteBrush);
        WindowPictorial(HInstance instance, int icon, const TChar* cursor, BrushTypes background = BrushTypes::WhiteBrush);
        WindowPictorial(HInstance instance, const TChar* icon, int cursor, BrushTypes background = BrushTypes::WhiteBrush);
        WindowPictorial(HInstance instance, bool isDefaultIcon, int icon, bool isDefaultCursor, int cursor, BrushTypes background = BrushTypes::WhiteBrush);

        CLASS_INVARIANT_DECLARE;

        NODISCARD HIcon GetHIcon() const noexcept;
        NODISCARD HCursor GetHCursor() const noexcept;
        NODISCARD HBrush GetHBrush() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_H
