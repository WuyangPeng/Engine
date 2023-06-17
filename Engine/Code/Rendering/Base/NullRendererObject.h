///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:07)

#ifndef RENDERING_BASE_NULL_RENDERER_OBJECT_H
#define RENDERING_BASE_NULL_RENDERER_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "RendererObject.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE NullRendererObject : public RendererObject
    {
    public:
        using ClassType = NullRendererObject;
        using ParentType = RendererObject;

    public:
        explicit NullRendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name = "");

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable() noexcept override;
    };
}

#endif  // RENDERING_BASE_NULL_RENDERER_OBJECT_H
