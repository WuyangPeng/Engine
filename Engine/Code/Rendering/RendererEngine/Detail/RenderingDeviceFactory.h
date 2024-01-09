/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/02 15:12)

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

        using WindowsHdc = System::WindowsHdc;
        using OpenGLRcHandle = System::OpenGLRcHandle;
        using WindowsHWnd = System::WindowsHWnd;

    private:
        RenderingDeviceFactory() noexcept;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static RenderingDeviceSharedPtr Create(WindowsHWnd hWnd, WindowsHdc device, OpenGLRcHandle immediate);
        NODISCARD static RenderingDeviceSharedPtr Create();
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERING_DEVICE_FACTORY_H
