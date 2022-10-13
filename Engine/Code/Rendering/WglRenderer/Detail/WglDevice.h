///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/06 14:29)

#ifndef RENDERING_WGL_RENDERER_WGL_DEVICE_H
#define RENDERING_WGL_RENDERER_WGL_DEVICE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "Rendering/OpenGLRenderer/Detail/OpenGLDevice.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE WglDevice : public OpenGLDevice
    {
    public:
        using ClassType = WglDevice;
        using ParentType = OpenGLDevice;

        using WindowsHDC = System::WindowsHDC;
        using OpenGLHglrc = System::OpenGLHglrc;
        using WindowsHWnd = System::WindowsHWnd;

    public:
        WglDevice(WindowsHWnd hWnd, WindowsHDC device, OpenGLHglrc immediate);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingDeviceSharedPtr Clone() const override;

        void SwapBuffers() override;
        void ResetSize() override;

    private:
        void Init();

    private:
        WindowsHWnd hWnd;
        WindowsHDC device;
        OpenGLHglrc immediate;
    };
}

#endif  // RENDERING_WGL_RENDERER_WGL_DEVICE_H
