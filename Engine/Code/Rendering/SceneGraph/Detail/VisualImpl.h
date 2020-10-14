// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/22 11:00)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_IMPL_H
#define RENDERING_SCENE_GRAPH_VISUAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Bound.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"
#include "Rendering/SceneGraph/VisualData.h"

#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

#include <string>
#include <vector>

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
    class ObjectRegister;
    class ObjectLink;
    class Object;
}

namespace Rendering
{
    class VisualEffectInstance; 

    class RENDERING_HIDDEN_DECLARE VisualImpl
    {
    public:
        using ClassType = VisualImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;
        using Object = CoreTools::Object;
        using APoint = Mathematics::FloatAPoint;

    public:
        explicit VisualImpl(VisualPrimitiveType type = VisualPrimitiveType::None);
        VisualImpl(VisualPrimitiveType type, const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer);

        CLASS_INVARIANT_DECLARE;

        VisualPrimitiveType GetPrimitiveType() const;

        void SetVertexFormat(const VertexFormatSharedPtr& vertexformat);
        ConstVertexFormatSharedPtr GetConstVertexFormat() const;
        VertexFormatSharedPtr GetVertexFormat();

        void SetVertexBuffer(const VertexBufferSharedPtr& vertexbuffer);
        ConstVertexBufferSharedPtr GetConstVertexBuffer() const;
        VertexBufferSharedPtr GetVertexBuffer();

        void SetIndexBuffer(const IndexBufferSharedPtr& indexbuffer);
        ConstIndexBufferSharedPtr GetConstIndexBuffer() const;
        IndexBufferSharedPtr GetIndexBuffer();

        const FloatBound& GetModelBound() const noexcept;
        FloatBound& GetModelBound() noexcept;

        // 存取绘制对象的视觉效果。
        void SetEffectInstance(const VisualEffectInstanceSharedPtr& effect) noexcept;
        const ConstVisualEffectInstanceSharedPtr GetConstEffectInstance() const noexcept;
        const VisualEffectInstanceSharedPtr GetEffectInstance() noexcept;

        // 对几何更新的支持。
        const FloatBound GetWorldBound(const FloatTransform& worldTransform);
        void UpdateModelBound();
        void ComputeBounding(const std::vector<APoint>& positions);

        void Load(const CoreTools::BufferSourceSharedPtr& source);
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        int GetStreamingSize() const;
        void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;
        void Link(const CoreTools:: ObjectLinkSharedPtr& source);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        void DoUpdateModelBound();

    private:
        VisualData m_VisualData;
        FloatBound m_ModelBound;

        // 着色器效果用来绘制视觉。
        VisualEffectInstanceSharedPtr m_Effect;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISUAL_IMPL_H
