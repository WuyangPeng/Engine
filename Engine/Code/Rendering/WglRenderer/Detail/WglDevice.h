///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 16:58)

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

        using WindowsHDC = System::WindowsHdc;
        using OpenGLHglrc = System::OpenGLHglrc;
        using WindowsHWnd = System::WindowsHWnd;

    public:
        WglDevice(WindowsHWnd hWnd, WindowsHDC device, OpenGLHglrc immediate);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingDeviceSharedPtr Clone() const override;

        void SwapBuffers(int syncInterval) override;
        void ResetSize() override;

    private:
        void Init();

    public:
        void Execute(const ComputeProgramSharedPtr& computeProgram, int numXGroups, int numYGroups, int numZGroups) noexcept override;

    private:
        WindowsHWnd hWnd;
        WindowsHDC device;
        OpenGLHglrc immediate;
    };
}

#endif  // RENDERING_WGL_RENDERER_WGL_DEVICE_H
