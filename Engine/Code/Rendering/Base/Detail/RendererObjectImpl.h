///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/07 17:32)

#ifndef RENDERING_BASE_RENDERER_OBJECT_IMPL_H
#define RENDERING_BASE_RENDERER_OBJECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Base/BaseFwd.h"

#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RendererObjectImpl
    {
    public:
        using ClassType = RendererObjectImpl;
        using GraphicsObjectSharedPtr = std::shared_ptr<GraphicsObject>;
        using GraphicsObjectWeakPtr = std::weak_ptr<GraphicsObject>;

    public:
        RendererObjectImpl(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD GraphicsObjectSharedPtr GetGraphicsObject() const;
        NODISCARD std::string GetName() const;

    private:
        GraphicsObjectWeakPtr graphicsObject;
        std::string name;
    };
}

#endif  // RENDERING_BASE_RENDERER_OBJECT_IMPL_H
