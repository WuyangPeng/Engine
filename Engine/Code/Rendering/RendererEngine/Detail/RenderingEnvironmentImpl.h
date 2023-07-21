///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:15)

#ifndef RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_IMPL_H
#define RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/RendererEngine/RendererEngineInternalFwd.h"
#include "Rendering/RendererEngine/RendererParameter.h"
#include "Rendering/RendererEngine/RenderingDevice.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderingEnvironmentImpl
    {
    public:
        using ClassType = RenderingEnvironmentImpl;
        using FactoryType = RenderingEnvironmentFactory;

        using ColourType = Colour<float>;
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

        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD DataFormatType GetColorFormat() const noexcept;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultiSamples() const noexcept;

        NODISCARD ColourType GetClearColor() const noexcept;

    private:
        RendererParameter rendererParameter;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_IMPL_H
