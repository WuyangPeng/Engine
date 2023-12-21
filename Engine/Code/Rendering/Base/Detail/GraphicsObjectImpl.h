/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:40)

#ifndef RENDERING_BASE_GRAPHICS_OBJECT_IMPL_H
#define RENDERING_BASE_GRAPHICS_OBJECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Base/BaseFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GraphicsObjectImpl final
    {
    public:
        using ClassType = GraphicsObjectImpl;

        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;

        using RendererObjectBridgeSharedPtr = std::shared_ptr<RendererObjectBridge>;
        using RendererObjectBridgeWeakPtr = std::weak_ptr<RendererObjectBridge>;

    public:
        explicit GraphicsObjectImpl(GraphicsObjectType graphicsObjectType) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD RendererObjectBridgeSharedPtr GetRendererObjectBridge();
        void SetRendererObjectBridge(const RendererObjectBridgeSharedPtr& aRendererObjectBridge) noexcept;

        NODISCARD GraphicsObjectType GetType() const noexcept;
        void SetGraphicsObjectType(GraphicsObjectType aGraphicsObjectType) noexcept;

        NODISCARD bool IsBuffer() const noexcept;
        NODISCARD bool IsTexture() const noexcept;
        NODISCARD bool IsTextureArray() const noexcept;
        NODISCARD bool IsShader() const noexcept;
        NODISCARD bool IsDrawingState() const noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);

    private:
        GraphicsObjectType graphicsObjectType;
        RendererObjectBridgeWeakPtr rendererObjectBridge;
    };
}

#endif  // RENDERING_BASE_GRAPHICS_OBJECT_IMPL_H
