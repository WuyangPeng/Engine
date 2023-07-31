///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 10:24)

#ifndef RENDERING_BASE_RENDERER_OBJECT_BRIDGE_IMPL_H
#define RENDERING_BASE_RENDERER_OBJECT_BRIDGE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Base/BaseFwd.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"

#include <map>
#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RendererObjectBridgeImpl
    {
    public:
        using ClassType = RendererObjectBridgeImpl;

        using GraphicsObjectSharedPtr = std::shared_ptr<GraphicsObject>;
        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;
        using ConstRendererObjectSharedPtr = std::shared_ptr<const RendererObject>;

    public:
        RendererObjectBridgeImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD RendererObjectSharedPtr BindRendererObject(RendererTypes rendererTypes, const GraphicsObjectSharedPtr& graphicsObject);
        void UnbindRendererObject(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD RendererObjectSharedPtr GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD ConstRendererObjectSharedPtr GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject) const;
        NODISCARD TotalAllocation GetTotalAllocation() const;
        void Release() noexcept;

    private:
        using RendererObjectContainer = std::map<GraphicsObjectSharedPtr, RendererObjectSharedPtr>;

    private:
        RendererObjectContainer container;
    };
}

#endif  // RENDERING_BASE_RENDERER_OBJECT_BRIDGE_IMPL_H
