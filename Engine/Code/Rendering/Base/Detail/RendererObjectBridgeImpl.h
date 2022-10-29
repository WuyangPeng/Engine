///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/10 13:42)

#ifndef RENDERING_BASE_RENDERER_OBJECT_BRIDGE_IMPL_H
#define RENDERING_BASE_RENDERER_OBJECT_BRIDGE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Base/BaseFwd.h"
#include "Rendering/Renderers/RenderersFwd.h"

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

    private:
        using RendererObjectContainer = std::map<GraphicsObjectSharedPtr, RendererObjectSharedPtr>;

    private:
        RendererObjectContainer container;
    };
}

#endif  // RENDERING_BASE_RENDERER_OBJECT_BRIDGE_IMPL_H
