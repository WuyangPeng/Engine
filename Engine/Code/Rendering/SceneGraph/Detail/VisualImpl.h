///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 19:20)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_IMPL_H
#define RENDERING_SCENE_GRAPH_VISUAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "VisualData.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

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

        NODISCARD const BoundF& GetModelBound() const noexcept;
        NODISCARD BoundF& GetModelBound() noexcept;

        // 存取绘制对象的视觉效果。
        void SetEffectInstance(const VisualEffectInstanceSharedPtr& aEffect) noexcept;
        NODISCARD ConstVisualEffectInstanceSharedPtr GetConstEffectInstance() const noexcept;
        NODISCARD VisualEffectInstanceSharedPtr GetEffectInstance() noexcept;

        // 对几何更新的支持。
        NODISCARD BoundF GetWorldBound(const TransformF& worldTransform);
        void UpdateModelBound();
        void ComputeBounding(const std::vector<APoint>& positions);

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        void Register(CoreTools::ObjectRegister& target) const;
        void Link(CoreTools::ObjectLink& source);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        using ObjectAssociated = CoreTools::ObjectAssociated<VisualEffectInstance>;

    private:
        void DoUpdateModelBound();

    private:
        VisualData visualData;
        BoundF modelBound;

        // 着色器效果用来绘制视觉。
        ObjectAssociated effect;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISUAL_IMPL_H
