///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/14 18:25)

#ifndef RENDERING_RENDERERS_RENDERING_ENVIRONMENT_IMPL_H
#define RENDERING_RENDERERS_RENDERING_ENVIRONMENT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersInternalFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderingDeviceImpl
    {
    public:
        using ClassType = RenderingDeviceImpl;
        using FactoryType = RenderingDeviceFactory;
        using RenderingDeviceSharedPtr = std::shared_ptr<RenderingDeviceImpl>;

    public:
        RenderingDeviceImpl() noexcept;
        virtual ~RenderingDeviceImpl() noexcept = default;
        RenderingDeviceImpl(const RenderingDeviceImpl& rhs) = default;
        RenderingDeviceImpl& operator=(const RenderingDeviceImpl& rhs) = default;
        RenderingDeviceImpl(RenderingDeviceImpl&& rhs) noexcept = default;
        RenderingDeviceImpl& operator=(RenderingDeviceImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual RenderingDeviceSharedPtr Clone() const = 0;
        virtual void ResetSize() = 0;
        virtual void InitDevice() = 0;

        virtual void SwapBuffers() = 0;

        void SetSize(int x, int y) noexcept;

        NODISCARD int GetXSize() const noexcept;
        NODISCARD int GetYSize() const noexcept;

    private:
        int xSize;
        int ySize;
    };
}

#endif  // RENDERING_RENDERERS_RENDERING_ENVIRONMENT_IMPL_H
