///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/04 15:19)

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