///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:19)

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
