///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:31)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(WindowMessageLoopImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowMessageLoop
    {
    public:
        NON_COPY_TYPE_DECLARE(WindowMessageLoop);
        using HWnd = System::WindowsHWnd;
        using WParam = System::WindowsWParam;
        using Display = System::DisplayFunction;

    public:
        explicit WindowMessageLoop(Display function);

        CLASS_INVARIANT_DECLARE;

        WParam EnterMessageLoop(HWnd hwnd);

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H
