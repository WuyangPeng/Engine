///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:38)

#ifndef RENDERING_RENDERERS_RENDERING_DEVICE_H
#define RENDERING_RENDERERS_RENDERING_DEVICE_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "System/OpenGL/Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(RenderingDevice, RenderingDeviceImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderingDevice
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(RenderingDevice);

        using WindowsHDC = System::WindowsHDC;
        using OpenGLHglrc = System::OpenGLHglrc;
        using WindowsHWnd = System::WindowsHWnd;
        using DisableNotThrow = CoreTools::DisableNotThrow;

    public:
        RenderingDevice(WindowsHWnd hWnd, WindowsHDC device, OpenGLHglrc immediate);
        explicit RenderingDevice(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        void SwapBuffers();
        void ResetSize();
        void InitDevice();

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_RENDERING_DEVICE_H
