///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:20)

#ifndef RENDERING_WGL_RENDERER_OPENGL_DEVICE_H
#define RENDERING_WGL_RENDERER_OPENGL_DEVICE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/RenderingDeviceImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLDevice : public RenderingDeviceImpl
    {
    public:
        using ClassType = OpenGLDevice;
        using ParentType = RenderingDeviceImpl;

    public:
        OpenGLDevice() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingDeviceSharedPtr Clone() const override;

        void SwapBuffers() override;
        void ResetSize() override;
        void InitDevice() noexcept override;
    };
}

#endif  // RENDERING_WGL_RENDERER_OPENGL_DEVICE_H
