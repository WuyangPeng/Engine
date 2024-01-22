/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:24)

#ifndef FRAMEWORK_APPLICATION_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_FONT_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "Flags/ApplicationTrait.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(FontInformationImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE FontInformation
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(FontInformation);

        using TChar = System::TChar;
        using String = System::String;
        using WindowsHWnd = System::WindowsHWnd;

    public:
        // GLUT 平台
        explicit FontInformation(PlatformTypes type);

        // Window 平台
        explicit FontInformation(WindowsHWnd hWnd);

        CLASS_INVARIANT_DECLARE;

        // 字体信息。这些是特定于平台的。
        NODISCARD int GetStringWidth(const String& text) const;
        NODISCARD int GetCharacterWidth(TChar character) const;
        NODISCARD int GetFontHeight() const;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_FONT_INFORMATION_H
