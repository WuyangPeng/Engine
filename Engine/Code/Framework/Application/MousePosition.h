// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:46)

#ifndef FRAMEWORK_APPLICATION_MOUSE_POSITION_H
#define FRAMEWORK_APPLICATION_MOUSE_POSITION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"
FRAMEWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(MousePosition,MousePositionImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE MousePosition
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(MousePosition);
        using HWnd = System::WindowsHWnd;

    public:
        explicit MousePosition(HWnd hwnd);

        CLASS_INVARIANT_DECLARE;

        //  Û±ÍŒª÷√
        const WindowPoint GetMousePosition() const;
        void SetMousePosition(const WindowPoint& windowPoint);

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_MOUSE_POSITION_H
