/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/02 15:12)

#ifndef RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_FACTORY_H
#define RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Rendering/RendererEngine/RendererEngineInternalFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderingEnvironmentFactory
    {
    public:
        using ClassType = RenderingEnvironmentFactory;
        using RenderingEnvironmentSharedPtr = std::shared_ptr<RenderingEnvironmentImpl>;

    private:
        RenderingEnvironmentFactory() noexcept;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static RenderingEnvironmentSharedPtr Create(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter);
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_FACTORY_H
