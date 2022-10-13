///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/05 10:59)

#ifndef RENDERING_RENDERERS_RENDERING_ENVIRONMENT_IMPL_H
#define RENDERING_RENDERERS_RENDERING_ENVIRONMENT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RendererParameter.h"
#include "Rendering/Renderers/RenderersInternalFwd.h"
#include "Rendering/Renderers/RenderingDevice.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderingEnvironmentImpl
    {
    public:
        using ClassType = RenderingEnvironmentImpl;
        using FactoryType = RenderingEnvironmentFactory;
        using RenderingEnvironmentSharedPtr = std::shared_ptr<RenderingEnvironmentImpl>;

    public:
        explicit RenderingEnvironmentImpl(const RendererParameter& rendererParameter) noexcept;
        virtual ~RenderingEnvironmentImpl() noexcept = default;
        RenderingEnvironmentImpl(const RenderingEnvironmentImpl& rhs) = default;
        RenderingEnvironmentImpl& operator=(const RenderingEnvironmentImpl& rhs) = default;
        RenderingEnvironmentImpl(RenderingEnvironmentImpl&& rhs) noexcept = default;
        RenderingEnvironmentImpl& operator=(RenderingEnvironmentImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual RenderingEnvironmentSharedPtr Clone() const = 0;

        virtual void InitEnvironment() = 0;

        virtual void Release() noexcept;

        NODISCARD virtual RenderingDevice GetRenderingDevice() const;

    protected:
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;

    private:
        RendererParameter rendererParameter;
    };
}

#endif  // RENDERING_RENDERERS_RENDERING_ENVIRONMENT_IMPL_H
