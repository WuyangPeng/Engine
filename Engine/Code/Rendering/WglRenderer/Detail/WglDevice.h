/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/22 10:01)

#ifndef RENDERING_WGL_RENDERER_WGL_DEVICE_H
#define RENDERING_WGL_RENDERER_WGL_DEVICE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "Rendering/OpenGLRenderer/Detail/OpenGLDevice.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE WglDevice final : public OpenGLDevice
    {
    public:
        using ClassType = WglDevice;
        using ParentType = OpenGLDevice;

        using WindowsHdc = System::WindowsHdc;
        using OpenGLRcHandle = System::OpenGLRcHandle;
        using WindowsHWnd = System::WindowsHWnd;

    public:
        WglDevice(WindowsHWnd hWnd, WindowsHdc device, OpenGLRcHandle immediate);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingDeviceSharedPtr Clone() const override;

        /// 支持清除颜色、深度和模具背面缓冲区。
        void DisplayColorBuffer(int syncInterval) override;

        void Resize(int width, int height) override;

    private:
        void Init();

    private:
        WindowsHWnd hWnd;
        WindowsHdc device;
        OpenGLRcHandle immediate;
    };
}

#endif  // RENDERING_WGL_RENDERER_WGL_DEVICE_H
