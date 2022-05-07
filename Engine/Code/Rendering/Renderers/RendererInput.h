///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 10:42)

#ifndef RENDERING_RENDERERS_RENDERER_INPUT_H
#define RENDERING_RENDERERS_RENDERER_INPUT_H

#include "Rendering/RenderingDll.h"

#include "Flags/RendererTypes.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include <boost/noncopyable.hpp>

RENDERING_NON_COPY_EXPORT_IMPL(RendererInputImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererInput
    {
    public:
        NON_COPY_TYPE_DECLARE(RendererInput);
        using HWnd = System::WindowsHWnd;

    public:
        explicit RendererInput(RendererTypes type);

        CLASS_INVARIANT_DECLARE;

        void SetWindowID(int windowID);
        void SetWindowHandle(HWnd windowID);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_INPUT_H
