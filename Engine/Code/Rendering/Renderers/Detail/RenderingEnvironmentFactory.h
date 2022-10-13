///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/05 10:59)

#ifndef RENDERING_RENDERERS_RENDERING_ENVIRONMENT_FACTORY_H
#define RENDERING_RENDERERS_RENDERING_ENVIRONMENT_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersInternalFwd.h"

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

#endif  // RENDERING_RENDERERS_RENDERING_ENVIRONMENT_FACTORY_H
