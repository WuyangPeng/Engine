/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:53)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_IMPL_H
#define RENDERING_SCENE_GRAPH_VISUAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "VisualData.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/BoundingSphere.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Rendering/Picking/PickRecordContainer.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/SceneGraph/Visual.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VisualImpl
    {
    public:
        using ClassType = VisualImpl;

        using Object = CoreTools::Object;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;

        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using BoundingSphere = Mathematics::BoundingSphereF;
        using Transform = Mathematics::TransformF;

    public:
        VisualImpl() noexcept;
        VisualImpl(const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer) noexcept;
        VisualImpl(const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer, const VisualEffectSharedPtr& visualEffect) noexcept;
        ~VisualImpl() noexcept = default;
        VisualImpl(const VisualImpl& rhs);
        VisualImpl& operator=(const VisualImpl& rhs);
        VisualImpl(VisualImpl&& rhs) noexcept;
        VisualImpl& operator=(VisualImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD IndexFormatType GetPrimitiveType() const;

        void SetVertexBuffer(const VertexBufferSharedPtr& vertexBuffer) noexcept;
        NODISCARD ConstVertexBufferSharedPtr GetConstVertexBuffer() const noexcept;
        NODISCARD VertexBufferSharedPtr GetVertexBuffer() noexcept;

        void SetIndexBuffer(const IndexBufferSharedPtr& indexBuffer) noexcept;
        NODISCARD ConstIndexBufferSharedPtr GetConstIndexBuffer() const noexcept;
        NODISCARD IndexBufferSharedPtr GetIndexBuffer() noexcept;

        void SetVisualEffect(const VisualEffectSharedPtr& aVisualEffect) noexcept;
        NODISCARD ConstVisualEffectSharedPtr GetConstVisualEffect() const noexcept;
        NODISCARD VisualEffectSharedPtr GetVisualEffect() noexcept;

        NODISCARD const BoundingSphere& GetModelBound() const noexcept;
        NODISCARD BoundingSphere& GetModelBound() noexcept;

        NODISCARD BoundingSphere UpdateWorldBound(const Transform& worldTransform) const;

        void UpdateModelBound();
        void UpdateModelNormals();

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        void Register(ObjectRegister& target) const;
        void Link(ObjectLink& source);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        using VisualEffectObjectAssociated = CoreTools::ObjectAssociated<VisualEffect>;
        using Vector3 = Mathematics::Vector3F;

        using Container = std::vector<char>;
        using ContainerConstIter = Container::const_iterator;
        using ConstSpanIterator = CoreTools::SpanIterator<ContainerConstIter>;
        using ContainerIter = Container::iterator;
        using SpanIterator = CoreTools::SpanIterator<ContainerIter>;

    private:
        static void ClearNormals(SpanIterator normals, int numVertices, int difference);
        static void SetNormals(const ConstSpanIterator& positions, SpanIterator normals, IndexFormatType primitiveType, const IndexBuffer& indexBuffer, int stride);
        static void NormalizeNormals(SpanIterator normals, int numVertices, int stride);

    private:
        VisualData visualData;
        BoundingSphere modelBound;
        VisualEffectObjectAssociated visualEffect;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISUAL_IMPL_H
