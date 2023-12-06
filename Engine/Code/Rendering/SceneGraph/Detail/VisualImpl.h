///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:08)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_IMPL_H
#define RENDERING_SCENE_GRAPH_VISUAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "VisualData.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/BoundingSphere.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VisualImpl
    {
    public:
        using ClassType = VisualImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;
        using Object = CoreTools::Object;
        using APoint = Mathematics::APointF;

    public:
        explicit VisualImpl(VisualPrimitiveType type) noexcept;
        VisualImpl(VisualPrimitiveType type, const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD VisualPrimitiveType GetPrimitiveType() const noexcept;

        void SetVertexFormat(const VertexFormatSharedPtr& vertexformat) noexcept;
        NODISCARD ConstVertexFormatSharedPtr GetConstVertexFormat() const noexcept;
        NODISCARD VertexFormatSharedPtr GetVertexFormat() noexcept;

        void SetVertexBuffer(const VertexBufferSharedPtr& vertexbuffer) noexcept;
        NODISCARD ConstVertexBufferSharedPtr GetConstVertexBuffer() const noexcept;
        NODISCARD VertexBufferSharedPtr GetVertexBuffer() noexcept;

        void SetIndexBuffer(const IndexBufferSharedPtr& indexbuffer) noexcept;
        NODISCARD ConstIndexBufferSharedPtr GetConstIndexBuffer() const noexcept;
        NODISCARD IndexBufferSharedPtr GetIndexBuffer() noexcept;

        NODISCARD const Mathematics::BoundingSphereF& GetModelBound() const noexcept;
        NODISCARD Mathematics::BoundingSphereF& GetModelBound() noexcept;

        // 对几何更新的支持。
        NODISCARD Mathematics::BoundingSphereF GetWorldBound(const Mathematics::TransformF& worldTransform);
        void UpdateModelBound();
        void ComputeBounding(const std::vector<APoint>& positions);

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        void Register(CoreTools::ObjectRegister& target) const;
        void Link(CoreTools::ObjectLink& source);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        void DoUpdateModelBound();

    private:
        VisualData visualData;
        Mathematics::BoundingSphereF modelBound;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISUAL_IMPL_H
