///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 14:40)

#ifndef FRAMEWORK_APPLICATION_MOUSE_POSITION_H
#define FRAMEWORK_APPLICATION_MOUSE_POSITION_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"

FRAMEWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(MousePosition, MousePositionImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE MousePosition
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(MousePosition);

        using HWnd = System::WindowsHWnd;

    public:
        explicit MousePosition(HWnd hWnd);

        CLASS_INVARIANT_DECLARE;

        // 鼠标位置
        NODISCARD WindowPoint GetMousePosition() const;
        void SetMousePosition(const WindowPoint& windowPoint);

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_MOUSE_POSITION_H
