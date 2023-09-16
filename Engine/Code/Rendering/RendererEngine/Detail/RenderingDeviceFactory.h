///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:03)

#ifndef RENDERING_RENDERER_ENGINE_RENDERING_DEVICE_FACTORY_H
#define RENDERING_RENDERER_ENGINE_RENDERING_DEVICE_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "Rendering/RendererEngine/RendererEngineInternalFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderingDeviceFactory
    {
    public:
        using ClassType = RenderingDeviceFactory;
        using RenderingDeviceSharedPtr = std::shared_ptr<RenderingDeviceImpl>;

        using WindowsHDC = System::WindowsHdc;
        using OpenGLHglrc = System::OpenGLHglrc;
        using WindowsHWnd = System::WindowsHWnd;

    private:
        RenderingDeviceFactory() noexcept;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static RenderingDeviceSharedPtr Create(WindowsHWnd hWnd, WindowsHDC device, OpenGLHglrc immediate);
        NODISCARD static RenderingDeviceSharedPtr Create();
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERING_DEVICE_FACTORY_H
