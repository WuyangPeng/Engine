///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/14 22:03)

#ifndef RENDERING_RENDERERS_NULL_DEVICE_H
#define RENDERING_RENDERERS_NULL_DEVICE_H

#include "Rendering/RenderingDll.h"

#include "RenderingDeviceImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE NullDevice : public RenderingDeviceImpl
    {
    public:
        using ClassType = NullDevice;
        using ParentType = RenderingDeviceImpl;

    public:
        NullDevice() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingDeviceSharedPtr Clone() const override;

        void SwapBuffers() noexcept override;

        void ResetSize() noexcept override;
        void InitDevice() noexcept override;
    };
}

#endif  // RENDERING_RENDERERS_NULL_DEVICE_H
