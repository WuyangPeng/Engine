///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 14:43)

#ifndef RENDERING_RENDERER_ENGINE_NULL_ENVIRONMENT_H
#define RENDERING_RENDERER_ENGINE_NULL_ENVIRONMENT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/RendererEngine/Detail/RenderingEnvironmentImpl.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE NullEnvironment final : public RenderingEnvironmentImpl
    {
    public:
        using ClassType = NullEnvironment;
        using ParentType = RenderingEnvironmentImpl;

    public:
        explicit NullEnvironment(const RendererParameter& rendererParameter) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingEnvironmentSharedPtr Clone() const override;

        void InitEnvironment() noexcept override;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_NULL_ENVIRONMENT_H
