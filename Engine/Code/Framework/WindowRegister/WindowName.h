///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 17:02)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(WindowNameImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowName
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(WindowName);
        using String = System::String;

    public:
        explicit WindowName(const String& className, const String& menuName = String{});

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetWindowClassName() const;
        NODISCARD String GetWindowMenuName() const;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_H