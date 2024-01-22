/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:28)

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

        using WindowsHWnd = System::WindowsHWnd;
        using WindowsWParam = System::WindowsWParam;
        using DisplayFunction = System::DisplayFunction;

    public:
        explicit WindowMessageLoop(DisplayFunction function);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WindowsWParam EnterMessageLoop(WindowsHWnd hWnd);

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H
