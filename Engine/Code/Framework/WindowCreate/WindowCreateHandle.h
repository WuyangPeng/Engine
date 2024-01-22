/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:46)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_H

#include "Framework/FrameworkDll.h"

#include "WindowCreateFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(WindowCreateHandleImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowCreateHandle
    {
    public:
        NON_COPY_TYPE_DECLARE(WindowCreateHandle);

        using WindowsHWnd = System::WindowsHWnd;

    public:
        WindowCreateHandle(const WindowInstanceParameter& windowInstanceParameter, const WindowCreateParameter& windowCreateParameter, const WindowSize& size);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WindowsHWnd GetHWnd() const noexcept;

        void SetMainWindow();

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_H