///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/14 22:15)

#ifndef RENDERING_RENDERERS_RENDERING_DEVICE_FACTORY_H
#define RENDERING_RENDERERS_RENDERING_DEVICE_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "Rendering/Renderers/RenderersInternalFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderingDeviceFactory
    {
    public:
        using ClassType = RenderingDeviceFactory;
        using RenderingDeviceSharedPtr = std::shared_ptr<RenderingDeviceImpl>;

        using WindowsHDC = System::WindowsHDC;
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

#endif  // RENDERING_RENDERERS_RENDERING_DEVICE_FACTORY_H
